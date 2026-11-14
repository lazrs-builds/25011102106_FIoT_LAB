# CAT-14 TASK-14

| **Field** | **Details** |
|---|---|
| **EXP** | Continuous Lab Evaluation-14 (`CAT14`) |
| **TASK NO** | **Task 14 – MQTT Publishing Using Custom ESP8266 API** |
| **DATE** | |
| **NAME OF EXP** | MQTT Communication Using Custom Built ESP8266 API |

## HARDWARE SETUP / PLATFORM

- **Development Board:** STM32 Nucleo-F410RB (`STM32F410RBT6`, 100 MHz)[cite: 11].
- **Toolchain / IDE:** STM32CubeMX + Keil MDK-ARM[cite: 13].
- **Firmware Libraries:** STM32F4 HAL Drivers, CMSIS, Custom Built ESP8266 API (`ESPLib.h` / `ESPLib.c`)[cite: 12, 13].
- **Peripherals:** `USART1` (115200 baud, 8N1) and Wemos D1 Mini (ESP8266 Wi-Fi Module)[cite: 11, 12].
- **Pin Mapping:**
  - `PA10` / `D2` – `USART1_RX` (Connected to Wemos D1 Mini `TX`)[cite: 11, 12].
  - `PA9` / `D8` – `USART1_TX` (Connected to Wemos D1 Mini `RX`)[cite: 11, 12].
  - `GND` – Common Ground connected to Wemos D1 Mini `G`[cite: 11].

## CORE LOGIC / PSEUDOCODE / CODE BASE

### Working Principle

- Configures `USART1` at `115200` baud in `main.c` to interface with the Wemos D1 Mini (ESP8266) module[cite: 11, 12].
- Initializes the ESP8266 in Station Mode (`StationMode`) and connects to the local Wi-Fi access point (`"SNUC"`)[cite: 12].
- Establishes a TCP connection to the MQTT broker (`"broker.emqx.io"`) on port `1883`[cite: 12].
- Configures MQTT client parameters (`keepAlive = 500`, `CleanSession`, `clientID = "STM32_Triti_Test_2026"`) and completes the broker handshake[cite: 12].
- Periodically publishes the payload `"vanakkam"` to topic `"stm32/triti/data"` with `QoS0` at `1000 ms` intervals inside `while(1)`[cite: 12].

### Pseudocode

- Initialize HAL, 84 MHz system clock (HSI + PLL), GPIO, and `USART1`[cite: 12].
- Initialize ESP8266 in `StationMode` over `huart1`[cite: 12].
- Connect to Wi-Fi network `"SNUC"` using `ESP8266_wifiConnect()`[cite: 12].
- Open TCP socket to `"broker.emqx.io"` on port `"1883"` using `ESP8266_portConnect()`[cite: 12].
- Populate `MQTT_InitTypeDef_t` structure and connect to the broker via `MQTT_connectBroker(&mqttSetting)`[cite: 12].
- Inside `while(1)`, publish `"vanakkam"` to `"stm32/triti/data"` (`QoS0`) every `1000 ms`[cite: 12].

### Code Base

- `HAL_Init()` – Initializes HAL[cite: 12].
- `SystemClock_Config()` – Configures the 84 MHz system clock using HSI and PLL[cite: 12].
- `MX_USART1_UART_Init()` – Configures `USART1` at 115200 baud (8-bit word length, 1 stop bit, no parity)[cite: 12].
- `ESP8266_Init()` – Initializes the ESP8266 module in `StationMode` via `huart1`[cite: 12].
- `ESP8266_wifiConnect()` – Authenticates and connects the ESP8266 to the `"SNUC"` Wi-Fi network[cite: 12].
- `ESP8266_portConnect()` – Establishes a TCP connection to `"broker.emqx.io"` on port `"1883"`[cite: 12].
- `MQTT_connectBroker()` – Performs the MQTT connect handshake using `mqttSetting` (`clientID = "STM32_Triti_Test_2026"`, `keepAlive = 500`, `CleanSession`)[cite: 12].
- `MQTT_publishTopic()` – Publishes `"vanakkam"` to topic `"stm32/triti/data"` with `QoS0` inside `while(1)`[cite: 12].

## INFERENCE

- Successfully interfaced the STM32 Nucleo-F410RB with the Wemos D1 Mini (ESP8266) over `USART1` (`D8`/`D2`) using the custom `ESPLib` API[cite: 11, 12].
- Implemented Wi-Fi association, TCP socket setup to `broker.emqx.io:1883`, and MQTT client session initialization in `main.c`[cite: 12].
- Configured periodic `QoS0` MQTT message publishing on topic `"stm32/triti/data"` every `1000 ms`[cite: 12].