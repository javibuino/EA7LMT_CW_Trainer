# Hardware — Arduino Pro Micro HID Mirror

USB HID firmware that lets you use a real **straight key** or **iambic paddle** as input for [EA7LMT's CW Trainer](../README.md), instead of (or alongside) a keyboard.

**Author:** EA7LMT

## What it does

The Arduino Pro Micro (ATmega32U4) enumerates as a standard USB keyboard. It reads the paddle's two contacts and mirrors them as key presses/releases:

- **DIT** contact → **X** key down/up
- **DAH** contact → **Z** key down/up

Since the web app already listens for X (dit) and Z (dah), no drivers, browser extensions, or app-side changes are needed — the browser just sees a keyboard.

## Hardware

- Arduino Pro Micro (ATmega32U4, 16 MHz, USB-C or micro-USB)
- Iambic paddle or straight key with a 3.5mm stereo jack
- No external resistors: the sketch uses the ATmega32U4's internal pull-ups

### Wiring (3.5mm stereo jack)

| Jack contact | Signal | Pro Micro pin |
|---|---|---|
| Tip (TIP) | DIT (left paddle) | Pin 7 |
| Ring (RING) | DAH (right paddle) | Pin 8 |
| Sleeve (SLEEVE) | GND | GND |

For a straight key (single contact, no separate dit/dah), wire it across Pin 7 and GND — it will act as the DIT/left-paddle contact, matching the web app's vertical (straight-key) mode.

## Firmware

File: [`EA7LMT_CW_ProMicro.ino`](EA7LMT_CW_ProMicro.ino)

### Required libraries

- `Keyboard.h` — included in the Arduino AVR core
- `Bounce2` (Thomas O. Fredericks) — install from the Arduino IDE Library Manager

### Configuration

- `KEY_DIT` / `KEY_DAH` — the keys sent for each contact (default `x` / `z`, matching the web app)
- `DEBOUNCE_MS` — contact debounce time in milliseconds (default 5ms; raise to 10ms if you notice bouncing on a mechanical paddle)

## Notes

This firmware only mirrors paddle contacts to keystrokes — it has no keyer logic of its own (no Iambic B state machine, no timing). All keying logic (Iambic B alternation, WPM timing, straight-key duration decoding) lives in the web app itself. This board can be wired in parallel with a separate keyer such as a K3NG Nano build, since it just taps the same paddle lines without any inter-board communication.

## License

This project is licensed under the GNU General Public License v3.0. See the [LICENSE](../LICENSE) file for details.
