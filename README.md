# iSpyPort

A TCP port scanner written in Python. Supports configurable port ranges and uses multi-threading to scan network targets efficiently.

## Features

- Multi-threaded port scanning
- Customizable port ranges
- Socket timeout configuration
- Built-in safety restrictions (localhost scan only by default)

## Performance

Multi-threaded implementation achieves **~90% performance improvement** over sequential scanning:

| Ports | Sequential | Multi-threaded | Improvement |
|-------|-----------|----------------|-------------|
| 50    | 4.387s    | 0.524s         | 88.1%       |
| 100   | 7.931s    | 0.532s         | 93.3%       |

*Tested on scanme.nmap.org with 0.5s socket timeout. See [BENCHMARKS.md](BENCHMARKS.md) for detailed testing methodology.*

## Installation
```bash
git clone https://github.com/eac554/iSpyPort.git
cd iSpyPort
```

No dependencies required - uses Python standard library only.

## Usage
```bash
python3 scanner.py
```

**Example:**
```
Enter target to scan: localhost
Enter starting port: 1
Enter ending port: 100
```

## Safety Features
- **Restricts scanning to localhost**
- Prevents malicious use while maintaining educational value
- Requires the user to manually modify targets to scan others than localhost

## Technical Implementation

### V1 (Sequential)
- Single-threaded socket connections
- Iterates through ports one at a time
- Located in `versions/scannerV1.py`

### V2 (Multi-threaded - Current)
- Creates one thread per port
- Concurrent socket connections
- Tested successfully up to 100 ports on remote targets

### V3 (Thread Pooling - Planned)
- Will use `ThreadPoolExecutor` to limit concurrent connections
- Enables scanning of larger port ranges (1000+)
- Balances performance with system stability

## Current Limitations

V2 tested successfully up to 100 ports on remote targets.

**Future Enhancement:** Thread pooling will enable scanning of unlimited port ranges by controlling concurrent connections.

## Project Structure
```
iSpyPort/
├── scanner.py              # Production multi-threaded scanner (V2)
├── versions/
│   ├── scannerV1.py       # Sequential implementation with benchmarking
│   └── scannerV2.py       # Multi-threaded with benchmarking
├── BENCHMARKS.md          # Detailed performance testing results
├── README.md
├── LICENSE
└── .gitignore
```

## Educational Purpose

This project was built to:
- Understand network socket programming in Python
- Explore multi-threading and concurrency concepts
- Learn performance optimization through benchmarking
- Practice responsible security tool development

**Note:** By default, this tool only allows scanning of localhost. To scan other targets, you must modify the allowed targets list in the scanner.py file. Only scan networks you own or have explicit written permission to test.

## License

MIT License - See [LICENSE](LICENSE) for details.

## Acknowledgments

- Tested on [scanme.nmap.org](http://scanme.nmap.org) - a public scanning test target
- Inspired by nmap and other professional network scanning tools

---

**Author:** Elester Charleston  
**Portfolio:** [eac554.github.io](https://eac554.github.io)  
**GitHub:** [@eac554](https://github.com/eac554)