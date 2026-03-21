# iSpyPort Performance Benchmarks

## Test Environment
- OS: macOS (M3 MacBook Air)
- Python: 3.x
- Date: March 21, 2026
- Socket timeout: 0.5 seconds
- Target: scanme.nmap.org (remote network)

---

## Test 1: 50 Ports (1-50)

### V1 (scannerV1.py)
- Run 1: 4.173 seconds
- Run 2: 4.209 seconds
- Run 3: 4.779 seconds
- **Average:** 4.387 seconds

### V2 (scannerV2.py)
- Run 1: 0.520 seconds
- Run 2: 0.527 seconds
- Run 3: 0.526 seconds
- **Average:** 0.524 seconds

**Improvement:** 88.1%

---

## Test 2: 100 Ports (1-100)

### V1 (scannerV1.py)
- Run 1: 7.978 seconds
- Run 2: 7.878 seconds
- Run 3: 7.938 seconds
- **Average:** 7.931 seconds

### V2 (scannerV2.py)
- Run 1: 0.533 seconds
- Run 2: 0.526 seconds
- Run 3: 0.537 seconds
- **Average:** 0.532 seconds

**Improvement:** 93.3%

## Summary

Multi-threaded implementation achieves approximately 90% performance 
improvement across tested port ranges (88.1% for 50 ports, 93.3% for 100 ports).

Testing revealed system resource limits between 100-200 ports due to macOS 
file descriptor constraints. Future implementation (V3) will use thread 
pooling to enable larger port ranges while maintaining stability.