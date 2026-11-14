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
- **Firmware Approach:** Bare-metal Embedded C using direct GPIO control (`<reg51.h>`).
- **Peripherals:** 16×2 HD44780-compatible LCD.
- **Pin Mapping:**
  - `P3.2` — LCD Register Select (RS).
  - `P3.3` — LCD Enable (E).
  - `P3.4–P3.7` — LCD data lines (D4–D7).
  - `GND` — LCD ground and RW connection.
  - `VCC` — LCD power supply.

## Core Logic / Pseudocode / Code Base

### Working Principle
- The LCD operates in **4-bit mode**, transferring data through pins D4–D7.
- The `lcd_init()` function configures the LCD for 2-line operation, display ON and cursor settings.
- Separate functions handle command transmission, character transmission and string display.
- The main program displays `ABC` on the first row and `DEF` on the second row.

### Pseudocode
- Initialize LCD in 4-bit, 2-line mode.
- Set the cursor to the first row and display `ABC`.
- Move the cursor to the second row and display `DEF`.
- Keep the display running.

### Code Base

- `main.c` — Implements LCD initialization, command and data transmission, cursor positioning, and character/string display using `lcd_cmd()`, `lcd_putc()` and `lcd_puts()`.

## INFERENCE

- Successfully interfaced a 16×2 LCD with the AT89S52 microcontroller.
- Demonstrated 4-bit data communication and LCD initialization.
- Displayed character strings on both LCD rows using Embedded C functions.