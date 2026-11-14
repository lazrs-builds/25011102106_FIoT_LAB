# CAT-8 TASK-8B

| **Field** | **Details** |
|---|---|
| **EXP** | Continuous Lab Evaluation-8 (`CAT8` / `TASK8B`) |
| **TASK NO** | **Task 8B — Event-Based Control** |
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
- `PA9` is continuously monitored for button presses using `HAL_GPIO_ReadPin()`.
- A 30 ms delay is introduced for software debouncing.
- On a confirmed press, `HAL_GPIO_TogglePin()` changes the LED state.
- The program waits for the button to be released before detecting another press.

### Pseudocode
- Initialize HAL, system clock and GPIO pins.
- Continuously:
  - Check whether the button is pressed.
  - Apply a 30 ms debounce delay.
  - Confirm the button state.
  - Toggle the LED using `HAL_GPIO_TogglePin()`.
  - Wait until the button is released.
- Repeat indefinitely.

### Code Base

- `main.c` — Implements push-button detection, software debouncing, LED state toggling and button-release detection using STM32 HAL functions.

## INFERENCE

- Successfully implemented push-button-controlled LED toggling using STM32 GPIO.
- Demonstrated software debouncing to prevent multiple triggers from a single press.
- Achieved state-based LED control using `HAL_GPIO_TogglePin()`.
