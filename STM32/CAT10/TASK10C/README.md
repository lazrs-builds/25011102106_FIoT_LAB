# CAT-10 TASK-10C

| **Field** | **Details** |
|---|---|
| **EXP** | Continuous Lab Evaluation-10 (`CAT10` / `TASK10C`) |
| **DATE** | |
| **NAME OF EXP** | |
| **TASK NO** | |

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

- Initializes `USART1` and `USART2` at 115200 baud (8-N-1).
- Sends AT commands to the ESP8266 through `USART2`.
- Executes `AT`, `AT+CWMODE=1` and `AT+CWJAP` to configure Wi-Fi station mode and connect to the specified network.
- After a delay, sends `AT+CIFSR` to retrieve the ESP8266's IP address.
- Forwards received responses to the PC terminal through `USART1`.

### Pseudocode

- Initialize HAL, system clock, GPIO and both UART peripherals.
- Send basic AT command and receive response.
- Configure Wi-Fi station mode using `AT+CWMODE=1`.
- Connect to the Wi-Fi network using `AT+CWJAP`.
- Send `AT+CIFSR` to retrieve the IP address.
- Forward modem responses to the PC terminal.

### Code Base

- `SystemClock_Config()` – Configures the 72 MHz system clock.
- `MX_GPIO_Init()` – Initializes GPIO clocks.
- `MX_USART1_UART_Init()` – Configures UART communication with the PC.
- `MX_USART2_UART_Init()` – Configures UART communication with the ESP8266.
- `HAL_UART_Transmit()` – Sends AT commands to the ESP8266.
- `HAL_UART_Receive()` – Receives modem responses.
- `memset()` – Clears the receive buffer between commands.

## INFERENCE

- Established UART communication between STM32 and ESP8266.
- Configured the ESP8266 in Wi-Fi station mode and initiated network connection.
- Retrieved the ESP8266 IP address using `AT+CIFSR` and forwarded the response to the PC terminal.