# Possible Improvements

Back to [README](../README.md)

> **None of these improvements have been applied.** The original source code is preserved exactly as written in 2021 to keep its historical context. This list is for reference only. Any future work should go in a new, clearly separated version, not into `src/spinnerRPM_v2.2/`.

## Correctness

| # | Observation | Effect | Possible change |
|---|---|---|---|
| 1 | `int countRpm = int(60000/float(sampleTime))*count;` uses 16-bit `int` on AVR boards | Overflows above 546 pulses/s (~32 760 RPM at 1 pulse/rev) | Use `long` / `unsigned long` for the result |
| 2 | One pulse per revolution is assumed | Wrong readings if the target produces several pulses per turn (for example, a 3-arm fidget spinner passing an optical sensor) | Add a `pulsesPerRev` constant and divide by it |
| 3 | No debounce or noise filtering | Noisy or bouncing signals inflate the count | Hardware RC filter, Schmitt trigger, or a minimum-pulse-width check |
| 4 | `pinMode(5, INPUT)` without a pull-up | Open-collector sensors (many Hall modules) leave the pin floating | `INPUT_PULLUP`, or an external resistor |

## Measurement Quality

| # | Observation | Possible change |
|---|---|---|
| 5 | Resolution is 60 RPM per pulse | Measure the period between edges (`micros()`) instead of counting in a fixed window |
| 6 | Pulses during `delay(400)` are lost | Count with an interrupt (`attachInterrupt`) and read the counter periodically |
| 7 | Busy-wait polling blocks the CPU for 1 s | Interrupt-driven or non-blocking `millis()` scheduling |

## Code Clarity

| # | Observation | Possible change |
|---|---|---|
| 8 | `maxRPM` and `rpmMaximum` are declared but unused | Remove them, or implement the limit / peak-hold they suggest |
| 9 | Pin `5` is hard-coded three times | A `const byte sensorPin = 5;` |
| 10 | `Serial.print(rpm); Serial.print("\n");` | `Serial.println(rpm);` (note: this sends `\r\n`) |
| 11 | No comments or header | Document wiring, board and sensor in a header comment |
| 12 | `boolean`, with `LOW`/`HIGH` used as boolean values | `bool` with `true`/`false` |

## Project / Documentation

- Record the actual board, sensor model and wiring (photos or a schematic), if they can be recovered.
- Capture a real serial output sample from the device.
- Verify compilation with `arduino-cli` for the intended board.
