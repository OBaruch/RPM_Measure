# Intent

Back to [README](../../README.md) · Next: [Specification](spec.md) → [Plan](plan.md)

> This document was reconstructed after the fact from the existing repository. It describes the intent of the original 2021 sketch and the intent of the later repository reorganization. Nothing here was written at the time the code was developed.

## 1. Original Project Intent (Reconstructed)

### Problem
Know how fast a spinning object is turning, in revolutions per minute, with inexpensive hardware.

### Desired outcome
A microcontroller turns sensor pulses into a live RPM number that can be watched on a computer over USB serial.

### Who it served
The author, Baruch Lopez, for their own hands-on measurement. No other audience is documented. Whether this was coursework or a personal project is **Unknown**.

### Success criteria (Inferred from the code)
- A new RPM value appears on the serial port roughly every 1.4 seconds.
- A stationary object reads `0`.
- The reading scales linearly with pulse rate (`60 × pulses per second`).

### Constraints (Confirmed from the code)
- A single digital sensor on pin 5.
- Arduino core only, no external libraries.
- Serial output at 9600 baud.

### Non-goals (Confirmed by absence)
- On-device display, storage or logging.
- Sub-60-RPM resolution, calibration, or multi-pulse-per-revolution correction.

## 2. Repository Reorganization Intent (2026)

### Why
The repository had one uncommented sketch and a license, and no explanation of what it does, how to wire it or how to run it. The goal is to make it understandable and presentable as a historical portfolio piece.

### Guiding principle
**Modernize the repository, not the project.** The sketch is a historical record and stays byte-for-byte identical.

### Outcomes
- A reader understands the project from the README without opening the code.
- Confirmed facts, inferences and unknowns are clearly separated.
- The sketch can be opened directly in the Arduino IDE (`<name>/<name>.ino` layout).
- Automated or human contributors have explicit guardrails ([AGENTS.md](../../AGENTS.md)).

### Non-goals
- Fixing, optimizing, reformatting or re-commenting the sketch.
- Adding build systems, CI/CD, containers, tests or tooling that the original project never had.
- Inventing context (course, board, sensor) that cannot be proven.
