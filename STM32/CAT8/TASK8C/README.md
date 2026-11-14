# CAT-8 TASK-8C

| **Field** | **Details** |
|---|---|
| **EXP** | Continuous Lab Evaluation-8 (`CAT8` / `TASK8C`) |
| **TASK NO** | **Task 8C — Short Press vs Long Press** |
| **DATE** | 24/09/2026  |
| **NAME OF EXP** | STM32 GPIO Bring-Up and Switch-Controlled LED |

## HARDWARE SETUP / PLATFORM

- **Development Board:** STM32 Blue Pill (`STM32F103C8T6`, ARM Cortex-M3, 72 MHz SYSCLK).
- **Toolchain / IDE:** STM32CubeMX + Keil MDK-ARM.
- **Firmware Libraries:** STM32 HAL Drivers, CMSIS.
- **Peripherals:** Push-button switch and Blue LED with 220 Ω current-limiting resistor.
- **Pin Mapping:**
  - `PA9` — Push-button input (GPIO input with pull-up).
  - `PC13` — LED output (GPIO push-pull).

### Hardware Schematic
![Circuit Diagram](circuit.png)

## Core Logic / Pseudocode / Code Base

### Working Principle
- `PA9` is monitored to detect button presses and releases.
- `HAL_GetTick()` measures the button press duration.
- A press shorter than 1 second toggles the LED state.
- A press longer than 1 second activates continuous LED blinking at 100 ms intervals.
- A 30 ms delay is used for button debouncing.

### Pseudocode
- Initialize HAL, system clock and GPIO pins.
- Continuously monitor the button state.
- On button press, record the start time.
- On button release:
  - If press duration is below 1 second, toggle the LED.
  - Otherwise, activate blinking mode.
- In blinking mode, toggle the LED every 100 ms.
- Repeat indefinitely.

### Code Base

- `main.c` — Implements button press-duration detection, short-press LED toggling, long-press blinking and software debouncing using STM32 HAL functions.

## INFERENCE

- Implemented short-press and long-press detection using STM32 GPIO.
- Demonstrated time-based event handling using `HAL_GetTick()`.
- Achieved LED toggling and periodic blinking based on button press duration.
