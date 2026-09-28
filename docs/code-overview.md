# Code Overview

Back to [README](../README.md)

This page explains the original sketch [`src/spinnerRPM_v2.2/spinnerRPM_v2.2.ino`](../src/spinnerRPM_v2.2/spinnerRPM_v2.2.ino) **without modifying it**. Line numbers refer to the unchanged file.

## File Summary

| Item | Value |
|---|---|
| Lines | 45 |
| Functions | `setup()`, `loop()`, `getRPM()` |
| Global state | 3 variables/constants |
| Libraries | Arduino core only |
| Comments in code | None |

## Global Declarations (lines 2–4)

| Line | Declaration | Used? | Meaning |
|---|---|---|---|
| 2 | `const unsigned long sampleTime = 1000;` | Yes | Measurement window in milliseconds |
| 3 | `const int maxRPM = 10000;` | **No** | Declared, never referenced |
| 4 | `int rpmMaximum = 0;` | **No** | Declared, never referenced |

## `setup()` (lines 6–10)

- `pinMode(5, INPUT)`: pin 5 is a plain digital input with no internal pull-up, so the sensor must drive the line both HIGH and LOW.
- `Serial.begin(9600)`: opens the serial port at 9600 baud.

## `loop()` (lines 12–19)

1. Calls `getRPM()`, which blocks for about 1 second.
2. Prints the returned integer, then `"\n"`, as two separate `Serial.print` calls.
3. `delay(400)`: pauses 400 ms before the next measurement. Pulses during this pause are not counted.

## `getRPM()` (lines 22–43)

The measurement routine, which polls the pin instead of using interrupts:

```text
count = 0, countFlag = LOW, startTime = millis()
while elapsed <= sampleTime:
    if pin5 == HIGH:                  countFlag = HIGH
    if pin5 == LOW and countFlag==HIGH: count++, countFlag = LOW
    elapsed = millis() - startTime
return int(60000 / float(sampleTime)) * count      // = 60 * count
```

- **Edge detection:** a pulse counts on the HIGH → LOW transition (falling edge), after the pin has been seen HIGH at least once. A pin that stays HIGH or LOW for the whole window returns 0.
- **Two reads per iteration:** `digitalRead(5)` is called twice per pass, so the two checks may see different pin states. This does not cause a double count because of `countFlag`.
- **Window:** `currentTime <= sampleTime` runs until elapsed time exceeds 1000 ms, so the effective window is about 1001 ms.
- **Conversion:** `60000 / float(1000)` = `60.0` → `int` → `60`. RPM = 60 × pulses per second, which assumes **one pulse per revolution**.
- **Types:** `boolean countFlag` stores `LOW`/`HIGH` (0/1). `boolean` is the Arduino alias for `bool`.

## Execution Timeline

```text
|<------- getRPM(): ~1001 ms polling ------->|print|<-- delay 400 ms -->|<------- getRPM() ...
```

About one reading every ~1.4 s. Only ~71 % of the time is spent measuring.

## Output Format

Plain ASCII integers, one per line, for example (illustrative, not captured from the original device):

```text
0
1200
1260
1200
```

Values are always multiples of 60.

## Observations (not fixed)

These are recorded for understanding only. The code was deliberately left as is. See [possible-improvements.md](possible-improvements.md).

- `maxRPM` and `rpmMaximum` are unused.
- On 16-bit `int` boards (AVR), `60 * count` overflows when count > 546 (≈ 32 760 RPM).
- No debouncing or noise filtering.
- The pin number `5` is hard-coded in three places rather than being a named constant.
