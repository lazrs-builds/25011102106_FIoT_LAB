# CAT-10 TASK-10A

| **Field** | **Details** |
|---|---|
| **EXP** | Continuous Lab Evaluation-10 (`CAT10` / `TASK10A`) |
| **DATE** | 09/10/2026 |
| **NAME OF EXP** | STM32–Wemos Wi-Fi Modem Interface Using AT Commands |
| **TASK NO** | Task 10A — Establish STM32 ↔ Wemos UART Communication |

## HARDWARE SETUP / PLATFORM

- **Development Board:** STM32 Blue Pill (`STM32F103C8T6`, ARM Cortex-M3, 72 MHz).
- **Toolchain / IDE:** STM32CubeMX + Keil MDK-ARM.
- **Firmware Libraries:** STM32F1xx HAL Drivers, CMSIS.
- **Peripherals:** Wemos D1 Mini (ESP8266), FT232RL USB-to-UART Converter.
- **Pin Mapping:**
  - `PA2` (`USART2_TX`) — Connected to Wemos RX.
  - `PA3` (`USART2_RX`) — Connected to Wemos TX.
  - `PA9` (`USART1_TX`) — Connected to FT232RL RXD.
  - `PA10` (`USART1_RX`) — Connected to FT232RL TXD.
  - `GND` — Common ground.

## CORE LOGIC / PSEUDOCODE / CODE BASE

### Working Principle
- Two UART peripherals (`USART1` and `USART2`) are initialized at 115200 baud (8-N-1).
- `USART2` communicates with the Wemos D1 Mini, while `USART1` connects to the PC terminal.
- The STM32 transmits the AT command `"AT\r\n"` to the Wemos through `USART2`.
- The Wemos response is received into `rx_data1`.
- The received response is forwarded to the PC terminal through `USART1`.

### Pseudocode
- Initialize HAL, system clock, GPIO, USART1 and USART2.
- Configure both UART peripherals at 115200 baud.
- Transmit `"AT\r\n"` to the Wemos using `HAL_UART_Transmit()`.
- Receive the Wemos response using `HAL_UART_Receive()`.
- Forward the received response to the PC terminal using `HAL_UART_Transmit()`.

### Code Base
- `HAL_Init()` – Initializes the HAL library.
- `SystemClock_Config()` – Configures the 72 MHz system clock.
- `MX_GPIO_Init()` – Initializes GPIO clocks.
- `MX_USART1_UART_Init()` – Configures UART communication with the PC.
- `MX_USART2_UART_Init()` – Configures UART communication with the Wemos.
- `HAL_UART_Transmit()` – Sends the AT command and forwards the response.
- `HAL_UART_Receive()` – Receives the Wemos response.

## INFERENCE

- Established dual-UART communication between STM32, Wemos D1 Mini and PC terminal.
- Transmitted the AT command to the ESP8266 and attempted to receive its response.
- Demonstrated UART-based modem interfacing using STM32 HAL libraries.