# CAT-3 TASK-3A

| **Field** | **Details** |
|---|---|
| **EXP** | Continuous Lab Evaluation-3 (CAT3 / TASK3A) |
| **DATE** | 31/07/2026 |
| **NAME OF EXP** | [Fill in] |
| **TASK NO** | [Task 3A — Multi-Mode LED Pattern Generator & Switch Control |

## HARDWARE SETUP / PLATFORM

- **Development Board:** 8051 Development Board
- **Microcontroller IC & Model:** Atmel `AT89S52` (8-bit 8051 Architecture)
- **Toolchain / IDE:** Keil µVision
- **Firmware Approach:** Bare-metal Embedded C using direct SFR bit-addressable access (`<reg51.h>`).
- **Peripherals:** Four LEDs (Yellow, Blue, Green and Red) with 1 kΩ resistors; 4×4 Matrix Keypad.
- **Pin Mapping:**
  - `P1.1` — Yellow LED.
  - `P1.2` — Blue LED.
  - `P1.3` — Green LED.
  - `P1.4` — Red LED.
  - `P2.3` — Keypad output.
  - `P2.6` — Keypad input.

## Core Logic / Pseudocode / Code Base

### Working Principle
- Four LEDs are controlled through GPIO pins `P1.1` to `P1.4`.
- Button input is detected through `P2.3` and `P2.6` using polling.
- Software debouncing and button-release detection ensure one mode change per valid press.
- Four operating modes are implemented: running LED sequence, 4-bit binary counter, alternating LED pattern (`1010` / `0101`) and simultaneous LED flashing (`1111` / `0000`).

### Pseudocode
- Initialize LED and keypad GPIO pins.
- Continuously scan the button input and debounce valid presses.
- Advance the operating mode on each valid press.
- Execute the selected LED pattern using a `switch-case` structure.
- Repeat indefinitely.

### Code Base


- `led_4_blink.c` — Implements GPIO control, button scanning, debouncing, software delay and all four LED operating modes through separate functions.

## INFERENCE

- Implemented a four-mode LED pattern generator using the AT89S52.
- Demonstrated direct GPIO control and software-based button debouncing.
- Implemented running, binary counting, alternating and simultaneous LED flashing patterns using modular Embedded C functions.
