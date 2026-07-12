# CW Trainer — Iambic B / Straight Key

Morse code (CW) trainer with a keyboard-driven Iambic B keyer and a straight-key mode.

**Author:** EA7LMT

Inspired by [EA4JAH's (Morffe) CW Trainer](https://hz.morffe.dev/cw-trainer/), adapted to work with an external keyboard instead of a touchscreen.

## Usage

### Iambic B mode (default)

- **X** = dit
- **Z** = dah

Hold down each key to send repeated elements. If you press both at once (squeeze), the keyer alternates dit/dah automatically, just like a real electronic keyer in **Iambic B** mode.

### Vertical mode (straight key)

- **X** or **space** = the key

No electronic keyer here: you control each element's duration by holding the key down. A short tap is decoded as a dot and a long one as a dash, using the dit duration at the configured WPM as the reference. This mode trains your own hand timing, just like a real straight key.

Switch between the two modes with the mode button in the controls bar.

### Speed and timing

Speed is measured in **WPM** (words per minute, PARIS standard) and follows the international timing standard (ITU-R M.1677-1):

| Element | Duration |
|---|---|
| Dot (dit) | 1 unit |
| Dash (dah) | 3 units |
| Space between elements of a letter | 1 unit |
| Space between letters | 3 units |
| Space between words | 7 units |

## Features

- Real-time decoding with the standard Morse table
- Iambic B keyer and straight-key mode, switchable on the fly
- Decoded text shown on screen, grouped into words, with a three-color scheme: the letter being built (purple), confirmed letters (yellow), and the most recently typed letter (green)
- Unrecognized patterns are shown as `*`
- Built-in Morse reference table (code, mnemonic, and phonetic alphabet) for every programmed character, available from the REF button — for lookup only, never shown during practice
- Adjustable tone between 500 and 900 Hz, using the Web Audio API with click-free gain ramps
- Adjustable speed (WPM)
- Screen Wake Lock, so the display doesn't turn off mid-session
- CLR button to clear the decoded text

## Technology

Static single-file HTML web app (HTML + CSS + JavaScript, no external dependencies, no backend). Runs directly in any modern browser. Hardened with a Content Security Policy and a no-referrer policy.

## License

This project is licensed under the GNU General Public License v3.0. See the [LICENSE](LICENSE) file for details.
