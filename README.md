# iSpyPort
Educational TCP port scanner built in Python (v1.0)

## ⚠️ Legal Disclaimer

**This program only allows scanning of `localhost` and `127.0.0.1` for safety. DO NOT modify this restriction to scan networks or devices that you do not own or have explicit written permission to scan.**

This project is for educational purposes only. The author is not responsible for any misuse of this software.

**A good legal target to scan is `scanme.nmap.org`, created by the developers of Nmap. Do not abuse this service, as stated on their website.**

---

## Features

- Scans specified TCP port ranges on localhost  
- Input validation for target and port ranges  
- Error handling for invalid inputs  
- Built-in safety restriction to prevent unauthorized scanning  
- Displays open and closed ports  

---

## Requirements

- Python 3.x  
- Standard library only (no external dependencies)  

---

## Usage

``` bash
python3 scanner.py
```

Follow the prompts:

1. Enter target (`localhost` or `127.0.0.1`)
2. Enter starting port (0–65535)
3. Enter ending port (0–65535)

### Example Output

```
Enter target: localhost
Starting port: 20
Ending port: 25

Port 20: CLOSED
Port 21: CLOSED
Port 22: OPEN
Port 23: CLOSED
Port 24: CLOSED
```

## How It Works

Uses Python's `socket` library to perform TCP connect scans on specified ports:

1. Creates a TCP socket for each port
2. Uses `connect_ex()` to attempt a connection
3. Returns `0` if the port is open (successful connection)
4. Returns an error code if the port is closed (failed connection)
5. Closes the socket after each attempt

## Future Improvements (v2.0)

- [ ] Command-line arguments for automation
- [X] Multi-threading for faster port scanning
- [ ] Service detection (identify what's running on open ports)
- [ ] Color-coded output (green for open, red for closed)
- [ ] Progress bar for large port ranges
- [ ] Export scan results to file (txt/csv)
- [ ] Timeout customization

## License

MIT License — see the LICENSE file for details
