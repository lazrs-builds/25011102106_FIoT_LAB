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
- **Peripherals:** Blue LED with a current-limiting resistor.
- **Pin Mapping:**
  - `P1.0` — LED output (PWM brightness control).

## Core Logic / Pseudocode / Code Base

### Working Principle
- Timer 0 is configured in Mode 1 (16-bit timer mode) to generate periodic overflow events.
- Software PWM is generated using a 20-step counter to control the LED duty cycle.
- The duty cycle gradually increases from 0% to 100% and decreases back to 0%, producing a fading effect.
- Timer overflow polling controls PWM updates without using software delay loops.

### Pseudocode
- Initialize LED and configure Timer 0.
- Start the timer and continuously monitor its overflow flag.
- On each overflow:
  - Reload Timer 0.
  - Update the PWM counter.
  - Control LED ON/OFF according to the duty cycle.
  - Gradually increase or decrease the duty cycle.
- Repeat to produce continuous LED fading.

### Code Base

- `main.c` — Configures Timer 0, generates software PWM, updates the duty cycle and controls LED brightness through periodic timer overflow polling.

## INFERENCE

- Implemented software PWM-based LED brightness control using Timer 0.
- Demonstrated gradual LED fading through variable duty-cycle adjustment.
- Achieved continuous brightness variation without using software delay loops.