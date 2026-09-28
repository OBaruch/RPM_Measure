# Project Context

Back to [README](../README.md)

This page records what can and cannot be established about the project's origin. Each claim is labeled **Confirmed**, **Inferred** or **Unknown**.

## Evidence Inventory

The original repository contained exactly three items:

| File | Type | Content |
|---|---|---|
| `spinnerRPM_v2.2.ino` | Source code | Arduino sketch, 45 lines, CRLF line endings, no comments |
| `LICENSE` | License | MIT License, "Copyright (c) 2021 Baruch Lopez" |
| Git history | Metadata | Two commits on 2021-02-20 (UTC-6): "Initial commit" and "Add files via upload" |

It contained **no** PDFs, Word or PowerPoint documents, images, diagrams, datasets, notebooks, configuration files, sample outputs or README. The context below therefore comes only from the code, the file name, the license and the Git metadata.

## Findings

| Question | Answer | Status |
|---|---|---|
| Author | Baruch Lopez | Confirmed (LICENSE, commits) |
| When | February 2021 | Confirmed (commit dates) |
| Origin (university / personal / other) | Not determinable | **Unknown**. No course, institution, assignment or report is referenced anywhere. |
| Category | Technical Experiment / small hardware prototype | Inferred |
| Language / platform | Arduino C/C++ | Confirmed (`.ino`, Arduino API calls) |
| Board | Arduino-compatible, probably AVR (Uno/Nano class) | Board is **Unknown**. The AVR guess is Inferred from common usage only. |
| Measured object | A "spinner" | Confirmed (file name). Whether this is a fidget spinner, a motor, a fan or a wheel is **Unknown**. |
| Sensor | Digital-output sensor on pin 5 | Pin and digital input Confirmed. Sensor model (IR, optical, Hall-effect…) is **Unknown**. |
| Pulses per revolution | Code assumes 1 | Confirmed from the formula. Whether this matched the real setup is **Unknown**. |
| Version history | File named `v2.2` | Confirmed name. Versions before 2.2 are not in the repository; the name suggests earlier iterations existed (Inferred). |
| Planned features | `maxRPM = 10000` and `rpmMaximum = 0` are declared but never used | Confirmed. They may point to a planned limit or peak-hold feature (Inferred; not verifiable). |

## Objective (Inferred)

Build a cheap tachometer: count sensor pulses for a fixed window, convert them to RPM, and stream the value over serial for monitoring or plotting.

## Scope

- **In scope (Confirmed):** one input pin, one fixed 1-second measurement window, serial text output.
- **Out of scope (Confirmed by absence):** display hardware, data logging, calibration, multiple sensors, interrupts, configuration at runtime.

## Contradictions

None found. With a single source file and no documents, there is nothing to contradict.

## See Also

- [Code overview](code-overview.md)
- [Specification](sdlc/spec.md)
