# CAT-12 TASK-12A

| **Field** | **Details** |
|---|---|
| **EXP** | Continuous Lab Evaluation-12 (`CAT12`) |
| **TASK NO** | **Task 12A – LED Blinking Using STM32 Nucleo** |
| **DATE** | |
| **NAME OF EXP** | GPIO-Based LED Interfacing Using STM32 Nucleo-F401RE |

## HARDWARE SETUP / PLATFORM

- **Development Board:** STM32 Nucleo-F401RE (`STM32F401RET6`, 84 MHz).
- **Toolchain / IDE:** STM32CubeMX + Keil MDK-ARM.
- **Firmware Libraries:** STM32F4 HAL Drivers, CMSIS.
- **Peripheral:** On-board User LED (LD2).
- **Pin Mapping:**
  - `PA5` – Connected to onboard LED (LD2).

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