# CAT-12 TASK-12A

| **Field** | **Details** |
|---|---|
| **EXP** | Continuous Lab Evaluation-12 (`CAT12` / `TASK12A`) |
| **TASK NO** | **Task 12A — Onboard LED Blink (GPIO Output)** |
| **DATE** | 15/10/2026 |
| **NAME OF EXP** | STM32F401RE Cortex-M4: GPIO and User Input Programming |

## HARDWARE SETUP / PLATFORM

- **Development Board:** STM32 Nucleo-F401RE (`STM32F401RET6`, 84 MHz).
- **Toolchain / IDE:** STM32CubeMX + Keil MDK-ARM.
- **Firmware Libraries:** STM32F4 HAL Drivers, CMSIS.
- **Peripheral:** On-board User LED (LD2).
- **Pin Mapping:**
  - `PA5` – Connected to onboard LED (LD2).

### Hardware Schematic
![Circuit Diagram](circuit.png)

## CORE LOGIC / PSEUDOCODE / CODE BASE

### Working Principle

- Configures GPIO pin PA5 as a push-pull output.
- Toggles the LED state continuously with a 500 ms delay.
- Uses the STM32 HAL GPIO functions to control the LED.

### Pseudocode

- Initialize HAL and system clock (84 MHz).
- Enable GPIOA peripheral clock.
- Configure PA5 as output.
- Toggle PA5 using `HAL_GPIO_TogglePin()`.
- Introduce a 500 ms delay using `HAL_Delay()`.
- Repeat continuously.

### Code Base

- `HAL_Init()` – Initializes the HAL library.
- `SystemClock_Config()` – Configures the system clock to 84 MHz.
- `MX_GPIO_Init()` – Configures PA5 as GPIO output.
- `HAL_GPIO_TogglePin()` – Toggles the LED state.
- `HAL_Delay(500)` – Provides a 500 ms delay.

## INFERENCE

- Successfully configured GPIO output on the STM32 Nucleo-F401RE.
- Verified LED blinking through continuous GPIO toggling at 500 ms intervals.
