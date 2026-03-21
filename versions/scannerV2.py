import socket
import threading
import time

# Only 'localhost' and '127.0.0.1' are allowed for safety.
def scan_port(target_scan, port):
    # Scan each port from start_port to end_port
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.settimeout(0.5)
    connection = sock.connect_ex((target_scan, port))
    if connection == 0:
        print(f'Port {port}: OPEN')
    else:
        print(f'Port {port}: CLOSED')
    sock.close()


def threaded_scan(target_scan, start_port, end_port):
    threads = []
    for port in range(start_port, end_port + 1):
        thread = threading.Thread(target=scan_port, args=(target_scan, port))
        thread.start()
        threads.append(thread)
    for thread in threads:
        thread.join()


def main():
    target_scan = input("Enter target: ")
    if target_scan not in ["localhost", "127.0.0.1"]:
        print("This target may be invalid or not permitted.")
        exit()

    start_port = int(input("Starting port: "))
    if start_port < 0:
        print("This is not a valid port to scan.")
        exit()

    end_port = int(input("Ending port: "))
    if end_port > 65535:
        print("This is not a valid port to scan.")
        exit()

    start_time = time.time()
    threaded_scan(target_scan, start_port, end_port)
    end_time = time.time()
    result = end_time - start_time
    print(f"{result:.3f} seconds")

main()