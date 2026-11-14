# Fundamentals of Internet of Things (`25CS2741`) — Lab Repository

This repository contains the embedded C source code, hardware schematics, and lab documentation for all Continuous Assessment Tasks completed as part of the **Fundamentals of Internet of Things** laboratory course.

---

## Repository Structure

```text
repo/
├── README.md
├── 8051/
│   ├── CAT2/       # Bare-Metal GPIO Output & LED Blink
│   ├── CAT3/       # Switch-Controlled LED & Pattern State Machine
│   ├── CAT4/       # 4×4 Matrix Keypad, 7-Segment Display & LED Interface
│   ├── CAT5/       # Hardware Timer Square-Wave, PWM & Burst Signal Generation
│   ├── CAT6/       # UART Serial Transmission & Full-Duplex Character Echo
│   └── CAT7/       # 16×2 HD44780 LCD Driver & Keypad-Controlled Cursor Movement
└── STM32/
    ├── CAT8/       # GPIO Polling, Software Debouncing & Short/Long Press Detection
    ├── CAT9/       # UART Echo & String Command-Based LED Control
    ├── CAT10/      # STM32–ESP8266 Wi-Fi AT Command Interface & IP Retrieval
    ├── CAT11/      # ESP8266 TCP Server & Dynamic HTTP Web Page Generation
    ├── CAT12/      # STM32 Nucleo-F401RE GPIO LED Blinking, Debounce & Press Timing
    ├── CAT13/      # Bosch BME280 Environmental Sensor Interfacing via I²C
    ├── CAT14/      # MQTT Cloud Publishing via Custom ESP8266 API
    └── CAT15/      # Smart Fisherman Advisory System with Real-Time Weather Telemetry
```

---

## Experiment Index

### 1. 8051 Microcontroller (`Atmel AT89S52`)

All 8051 experiments are implemented in bare-metal Embedded C (`<reg51.h>` / `<reg52.h>`) using direct Special Function Register (SFR) manipulation in **Keil µVision**.

| CAT | Experiment / Focus Area | Technical Summary | Key Peripherals & Deliverables |
| :--- | :--- | :--- | :--- |
| **CAT2** | Bare-Metal GPIO Bring-Up & LED Blink | Direct port-level GPIO manipulation to toggle an external LED using calibrated software delay loops. | `AT89S52`, GPIO (`P1`), LED, `main.c`, `.hex` |
| **CAT3** | Switch-Controlled LED & Pattern State Machine | Digital input polling with software debouncing to switch between multi-mode LED patterns (running, alternating, and flashing). | `AT89S52`, Push-Button Switches, LED Array, `main.c`, `.hex` |
| **CAT4** | Matrix Keypad & 7-Segment Display Interfacing | Row-column scanning of a 4×4 matrix keypad to decode keystrokes and drive a 7-segment display alongside status LEDs. | `AT89S52`, 4×4 Keypad, 7-Segment Display, `main.c`, `.hex` |
| **CAT5** | Hardware Timer Waveforms & PWM Generation | Timer 0 Mode 1 polling for variable-frequency square waves (`100 Hz`–`5 kHz`) and Timer 1 interrupts for pulse trains, burst signals, and variable duty-cycle PWM fading. | `AT89S52`, Timer 0/1, Oscilloscope, LED (`P1.0`, `P1.1`), `main.c` / `main1.c`–`main3.c` |
| **CAT6** | UART Serial Transmission & Character Echo | UART Mode 1 (`9600 baud` via Timer 1 auto-reload at `11.0592 MHz`) for continuous character transmission (`SBUF`/`TI`) and full-duplex PC echo (`RI`/`TI`). | `AT89S52`, `P3.0`/`P3.1`, USB-to-TTL, PuTTY, `main.c` |
| **CAT7** | 16×2 LCD Driver & Keypad Character Navigation | HD44780 4-bit LCD driver supporting custom string/integer formatting (`lcd_goto`, `lcd_print_number`) and 4×4 keypad (`2`, `4`, `6`, `8`) directional `*` cursor navigation. | `AT89S52`, 16×2 LCD (`P3.2`–`P3.7`), 4×4 Keypad (`P2.0`–`P2.7`), `main.c` |

---

### 2. STM32 Microcontrollers (`Blue Pill` & `Nucleo` Series)

All STM32 projects are configured via **STM32CubeMX** and built in **Keil MDK-ARM** using **STM32 HAL** and **CMSIS** drivers.

| CAT | Experiment / Focus Area | Target Hardware | Technical Summary & Deliverables |
| :--- | :--- | :--- | :--- |
| **CAT8** | GPIO Polling, Debouncing & Press-Duration Logic | `STM32F103C8T6` (Blue Pill, 72 MHz) | Push-button input (`PA9`) controlling LED (`PC13`) via polling, `30 ms` software debounce toggling, and `HAL_GetTick()` short-press (`< 1 s`) vs. long-press (`≥ 1 s`) `100 ms` blinking (`main.c`). |
| **CAT9** | UART Echo & String Command Parser | `STM32F103C8T6` + FT232RL | `USART2` (`PA2`/`PA3` @ `115200 baud`) full-duplex character echo and line-buffered `strcmp()` parser executing `LED ON`, `LED OFF`, and `LED TOGGLE` commands on `PC13` (`main.c`). |
| **CAT10** | STM32–ESP8266 Wi-Fi AT Command Interface | `STM32F103C8T6` + Wemos D1 Mini | Dual-UART bridge (`USART2` to ESP8266, `USART1` to PC @ `115200 baud`) executing `AT`, `AT+CWMODE=1`, `AT+CWJAP`, and `AT+CIFSR` for station connection and IP retrieval (`main.c`). |
| **CAT11** | ESP8266 TCP Server & Dynamic HTTP Web Server | `STM32F103C8T6` + Wemos D1 Mini | Configures ESP8266 multi-connection TCP server on port `80` (`AT+CIPMUX=1`, `AT+CIPSERVER=1,80`), parses `+IPD` requests, and serves dynamic HTML telemetry via `AT+CIPSEND` (`main.c`). |
| **CAT12** | Nucleo-F401RE GPIO LED & Button State Control | `STM32F401RET6` (Nucleo-F401RE, 84 MHz) | On-board LED (`PA5`) `500 ms` blinking, `10 ms` debounced User Button (`PC13`) state toggle, and non-blocking `HAL_GetTick()` short/long-press blinking controller (`main.c`). |
| **CAT13** | Bosch BME280 Environmental Sensor via I²C | `STM32F103C8T6` + GY-BME280 | Integrates Bosch Sensortec BME280 API over `I2C1` (`PB6`/`PB7` @ `100 kHz`, address `0x76`) with custom HAL read/write/delay callbacks to acquire temperature (`°C`), pressure (`hPa`), and humidity (`%RH`) (`main.c`). |
| **CAT14** | MQTT Cloud Publishing via Custom ESP8266 API | `STM32F410RBT6` (Nucleo-F410RB) + Wemos D1 Mini | Uses custom `ESPLib` driver over `USART1` (`PA9`/`PA10`) to connect to Wi-Fi, open a TCP socket to `broker.emqx.io:1883`, and publish `QoS0` MQTT payloads (`main.c`, `ESPLib.c`/`.h`). |
| **CAT15** | Smart Fisherman Advisory System (Mini Project) | `STM32F103C8T6` + BME280 + ESP8266 + Node-RED | End-to-end IoT marine telemetry pipeline streaming JSON BME280 readings over MQTT (`stm32/trivee/data`) and fusing OpenWeather API coastal forecasts in Node-RED to compute Sea Safety & Fish Feeding indices (`main.c`, `project.png`, Node-RED flow & dashboard). |

---

## Build & Flash Workflow

### 8051 (`AT89S52`)
1. Open the Keil µVision project (`.uvproj` / `.uvprojx`) inside the target `CAT` folder.
2. Compile the C source code (**Build Target / F7**) to generate the `.hex` binary.
3. Flash the `.hex` file onto the `AT89S52` microcontroller using an ISP programmer (e.g., USBasp / ProgISP) and reset the board.

### STM32 (`STM32F103C8T6` / `STM32F401RE` / `STM32F410RB`)
1. Open the `.ioc` configuration in **STM32CubeMX** if pin or clock adjustments are needed, or open the Keil MDK-ARM project directly.
2. Build the target firmware (**F7**) in Keil µVision.
3. Connect the **ST-Link V2** (or on-board ST-Link on Nucleo boards), download the firmware (**F8**), and verify output via serial terminal (`115200 baud`, `8-N-1`), oscilloscope, or Node-RED dashboard.
