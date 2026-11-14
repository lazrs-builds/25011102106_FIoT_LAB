# CAT-12 TASK-12C

| **Field** | **Details** |
|---|---|
| **EXP** | Continuous Lab Evaluation-12 (`CAT12` / `TASK12C`) |
| **TASK NO** | **Task 12C — Short Press vs Long Press Pattern Control** |
| **DATE** | 15/10/2026 |
| **NAME OF EXP** | STM32F401RE Cortex-M4: GPIO and User Input Programming |

## HARDWARE SETUP / PLATFORM

- **Development Board:** STM32 Nucleo-F401RE (`STM32F401RET6`, 84 MHz).
- **Toolchain / IDE:** STM32CubeMX + Keil MDK-ARM.
- **Firmware Libraries:** STM32F4 HAL Drivers, CMSIS.
- **Peripherals:** On-board User LED (LD2) and User Push Button (B1).
- **Pin Mapping:**
  - `PA5` – On-board LED (LD2).
  - `PC13` – User Push Button (B1).

### Hardware Schematic
![Circuit Diagram](circuit.png)

## CORE LOGIC / PSEUDOCODE / CODE BASE

### Working Principle

- Detects button press and release using GPIO input.
- Measures press duration using `HAL_GetTick()`.
- **Short press (less than 1 second):** Toggles LED state or stops blinking.
- **Long press (1 second or more):** Enables continuous LED blinking at 500 ms intervals.
- Uses non-blocking timing for LED blinking.

### Pseudocode

- Initialize HAL, system clock and GPIO.
- Detect button press and record start time.
- Detect button release and calculate press duration.
- If duration is less than 1000 ms, perform short-press action.
- Otherwise, enable blinking mode.
- Toggle LED every 500 ms while blinking is enabled.

### Code Base

- `HAL_GetTick()` – Retrieves system tick count for measuring press duration.
- `HAL_GPIO_ReadPin()` – Detects button press and release.
- `HAL_GPIO_TogglePin()` – Toggles LED state.
- `HAL_GPIO_WritePin()` – Sets LED output state.
- `SystemClock_Config()` – Configures the 84 MHz system clock.
- `MX_GPIO_Init()` – Configures PC13 as input and PA5 as output.

## INFERENCE

- Successfully implemented short-press and long-press detection using GPIO.
- Short and long presses trigger different LED operations.
- Achieved non-blocking LED blinking using system tick-based timing.
