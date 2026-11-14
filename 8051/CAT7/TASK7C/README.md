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
- **Peripherals:** 16×2 HD44780-compatible LCD, 4×4 Matrix Keypad.
- **Pin Mapping:**
  - `P3.2` — LCD Register Select (RS).
  - `P3.3` — LCD Enable (E).
  - `P3.4–P3.7` — LCD data lines (D4–D7).
  - `P2.4–P2.7` — Keypad rows.
  - `P2.0–P2.3` — Keypad columns.

## Core Logic / Pseudocode / Code Base

### Working Principle
- LCD operates in 4-bit, 2-line mode.
- The keypad is scanned to detect directional inputs using keys `2`, `4`, `6` and `8`.
- Software debouncing prevents repeated detection of a single key press.
- The `move_character()` function updates the character position:
  - `2` — Move up.
  - `8` — Move down.
  - `4` — Move left.
  - `6` — Move right.
- The previous position is cleared and the `*` character is displayed at the updated position. Boundary conditions allow movement between rows and across columns.

### Pseudocode
- Initialize LCD and keypad GPIO pins.
- Display `*` at the initial LCD position.
- Continuously scan the keypad.
- On detecting a valid directional key:
  - Clear the previous character.
  - Update row or column position.
  - Display `*` at the new position.
- Repeat indefinitely.

### Code Base

- `main.c` — Implements keypad scanning, software debouncing, LCD initialization, cursor positioning and directional character movement.

## INFERENCE

- Implemented keypad-controlled character movement on a 16×2 LCD.
- Demonstrated matrix keypad scanning and software debouncing.
- Implemented directional navigation with row and column boundary handling using Embedded C.