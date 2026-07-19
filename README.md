# CW Trainer — Iambic B / Straight Key

Morse code (CW) trainer with a keyboard-driven Iambic B keyer, a straight-key mode, and an accuracy practice mode.

**Author:** EA7LMT

Inspired by [EA4JAH's (Morffe) CW Trainer](https://hz.morffe.dev/cw-trainer/), adapted to work with an external keyboard instead of a touchscreen.

## Usage

### Iambic B mode (default)

- **X** or **Left Ctrl** = dit
- **Z** or **Right Ctrl** = dah

Both key mappings work at the same time, so this is compatible with vBand-style USB paddle devices (e.g. an Arduino Pro Micro sending `KEY_LEFT_CTRL`/`KEY_RIGHT_CTRL`) as well as a regular keyboard.

Hold down each key to send repeated elements. If you press both at once (squeeze), the keyer alternates dit/dah automatically, just like a real electronic keyer in **Iambic B** mode.

### Vertical mode (straight key)

- **X**, **Left Ctrl**, or **space** = the key

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

### Prosigns

Common procedural signs (`<BT>`, `<AR>`, `<KN>`, `<AS>`, `<SK>`, `<KA>`, `<VE>`, `<HH>`) decode automatically when their two letters are keyed without a pause between them, and are shown in a distinct cyan color. Some share a Morse code with a punctuation symbol (e.g. `<BT>` = `=`, `<AR>` = `+`) — the trainer favors the procedural-sign reading, since that's what's actually useful in CW practice.

### Accuracy practice (ACC)

Generates a sequence and scores your keying against ideal timing at the current WPM, in Vertical mode:

- **SEQ** — random letters/numbers/punctuation (configurable charset)
- **DOTS / DASHES / MIX** — raw rhythm drills with no real characters
- **QCODE / ABBR** — real ham vocabulary (QTH, QRM, QSL... / 73, CQ, DE, FB...)
- **CUSTOM** — type your own words to drill

Each character gets its own bar, built from its actual dot/dash/gap composition (so a short letter gets a short bar, a longer one a taller bar). Each block fills from the bottom; the top 10% is an overflow zone that turns red if you hold past the ideal stop point. A 0-9 cadence score appears below each bar. Session history is kept (persisted in `localStorage`) with a copy-to-clipboard export from the results screen.

## Features

- Real-time decoding with the standard Morse table, plus common prosigns
- Iambic B keyer and straight-key mode, switchable on the fly, both vBand/USB-paddle and keyboard compatible
- Decoded text shown on screen, grouped into words, with a color scheme: letter being built (purple), confirmed letters (yellow), most recently typed letter (green), prosigns (cyan)
- Unrecognized patterns are shown as `*`
- Built-in Morse reference table (code, mnemonic, and phonetic alphabet/meaning) for every character and prosign, available from the REF button — for lookup only, never shown during practice
- Accuracy practice mode (ACC) with seven drill types, per-element timing feedback, and session history/export
- Light and dark themes, toggled from the controls bar and remembered between sessions
- Adjustable tone between 500 and 900 Hz, using the Web Audio API with raised-cosine (click-free, soft-edged) gain ramps
- Adjustable speed (WPM)
- All settings (tone, WPM, ACC drill config, theme) persisted locally via `localStorage`
- Offline support via a Service Worker, so the trainer works with no signal at all (portable/SOTA/POTA use)
- Screen Wake Lock, so the display doesn't turn off mid-session
- CLR button to clear the decoded text

## Technology

Static single-file HTML web app (HTML + CSS + JavaScript, no external dependencies, no backend), plus a Service Worker for offline caching. Runs directly in any modern browser. Hardened with a Content Security Policy and a no-referrer policy.

## License

This project is licensed under the GNU General Public License v3.0. See the [LICENSE](LICENSE) file for details.
