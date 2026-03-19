import socket
# Only 'localhost' and '127.0.0.1' are allowed for safety.
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

# Scan each port from start_port to end_port
for ports in range(start_port, end_port):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    connection = sock.connect_ex((target_scan, ports))
    
    if connection == 0:
        print(f'Port {ports}: OPEN')
    else:
        print(f'Port {ports}: CLOSED')

    sock.close()

