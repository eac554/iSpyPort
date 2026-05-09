import socket
from concurrent.futures import ThreadPoolExecutor

MAX_WORKERS = 100
# Only 'localhost' and '127.0.0.1' are allowed for safety.
def scan_port(target_scan, port):
    # Scan each port from start_port to end_port
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.settimeout(0.5)
    connection = sock.connect_ex((target_scan, port))
    sock.close()
    if connection == 0:
        return f'Port {port}: OPEN'
    else:
        return f'Port {port}: CLOSED'


def threaded_scan(target_scan, start_port, end_port):
    ports = range(start_port, end_port + 1)
    with ThreadPoolExecutor(max_workers = MAX_WORKERS) as executor:
        results = executor.map(lambda port: scan_port(target_scan, port), ports)
        
    for result in results:
        print(result)

def main():
    target_scan = input("Enter target: ")
    if target_scan not in ["localhost", "127.0.0.1"]:
        print("This target may be invalid or not permitted.")
        exit()

    start_port = int(input("Starting port: "))
    if start_port < 0:
        print("This is not a valid port to scan.")
        main()

    end_port = int(input("Ending port: "))
    if end_port > 65535:
        print("This is not a valid port to scan.")
        main()

    threaded_scan(target_scan, start_port, end_port)
  
main()