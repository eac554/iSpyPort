# iSpyPort

A lightweight Python port scanner that demonstrates the performance benefits of multi-threading in network scanning applications.

## Features

- [X] Multi-threaded port scanning
- [X] Customizable port ranges
- [X] Socket timeout configuration
- [X] Built-in safety restrictions (blocks localhost and private IPs)
- [ ] Thread pooling for larger port ranges (V3 - planned)

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
Enter target to scan: scanme.nmap.org
Enter starting port: 1
Enter ending port: 100
```

## Safety Features

- Blocks scanning of localhost (127.0.0.1)
- Blocks scanning of private IP ranges (10.x.x.x, 172.16.x.x, 192.168.x.x)
- Prevents malicious use while maintaining educational value

## Technical Implementation

### V1 (Sequential)
- Single-threaded socket connections
- Iterates through ports one at a time
- Located in `versions/scannerV1.py`

### V2 (Multi-threaded - Current)
- Creates one thread per port
- Concurrent socket connections
- Tested successfully up to 100 ports on remote targets
- System resource limits encountered at ~150-200 ports (macOS file descriptor limit)

### V3 (Thread Pooling - Planned)
- Will use `ThreadPoolExecutor` to limit concurrent connections
- Enables scanning of larger port ranges (1000+)
- Balances performance with system stability

## Current Limitations

V2 tested successfully up to 100 ports on remote targets. Larger port ranges encounter macOS file descriptor limits due to concurrent socket connections.

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

**Note:** Only scan networks you own or have explicit permission to test. This tool is for educational purposes only.

## License

MIT License - See [LICENSE](LICENSE) for details.

## Acknowledgments

- Tested on [scanme.nmap.org](http://scanme.nmap.org) - a public scanning test target
- Inspired by nmap and other professional network scanning tools

---

**Author:** Elester Charleston  
**Portfolio:** [eac554.github.io](https://eac554.github.io)  
**GitHub:** [@eac554](https://github.com/eac554)