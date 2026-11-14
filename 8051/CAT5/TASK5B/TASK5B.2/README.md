# [Experiment Title]

| **Field** | **Details** |
|---|---|
| **EXP** | [Fill in] |
| **DATE** | [Fill in] |
| **NAME OF EXP** | [Fill in] |
| **TASK NO** | [Fill in] |

## HARDWARE SETUP / PLATFORM

- **Development Board:** 8051 Development Board
- **Microcontroller IC & Model:** Atmel `AT89S52` (8-bit 8051 Architecture)
- **Toolchain / IDE:** Keil µVision
- **Firmware Approach:** Bare-metal Embedded C using direct SFR and Timer 0 register access (`<reg52.h>`).
- **Peripherals:** Oscilloscope for waveform monitoring.
- **Pin Mapping:**
  - `P1.1` — Square-wave output.
  - `GND` — Oscilloscope ground reference.

## Core Logic / Pseudocode / Code Base

### Working Principle
- Timer 0 is configured in Mode 1 (16-bit timer mode).
- A `wave_mode` variable selects the timer reload values corresponding to different frequencies (100 Hz, 500 Hz, 1 kHz, 2 kHz and 5 kHz).
- Timer overflow is monitored through the `TF0` flag using polling.
- On each overflow, the timer is reloaded and `P1.1` is toggled to generate a square wave.
- The output waveform is observed using an oscilloscope.

### Pseudocode
- Initialize the output pin and select the waveform frequency.
- Configure and start Timer 0.
- Continuously monitor the timer overflow flag.
- On overflow:
  - Clear the overflow flag.
  - Reload Timer 0.
  - Toggle the output pin.
- Repeat to generate a continuous square wave.

### Code Base

- `main.c` — Selects the waveform frequency, configures Timer 0, handles overflow polling and toggles `P1.1` to generate the square wave.

## INFERENCE

- Implemented timer-based square-wave generation using the AT89S52 microcontroller.
- Demonstrated variable-frequency selection through timer reload values.
- Observed the generated waveform using an oscilloscope.
- Demonstrated hardware timer-based signal generation without software delay loops.