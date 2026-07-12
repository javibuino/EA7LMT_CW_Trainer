// ============================================================
// PRO MICRO - HID MIRROR FOR MORSE APP / EA7LMT WEB APP
// ATmega32U4 - 16MHz - USB-C
//
// Turns a streight key or an iambic paddle (3.5mm stereo jack) into a USB HID
// keyboard, sending X (dit) and Z (dah) for EA7LMT's CW Trainer
// web app.
//
// Paddle wired in parallel with a K3NG Nano, if used at the
// same time.
//
// WIRING (3.5mm stereo jack):
//   Tip    (TIP)    -> DIT (left paddle)  -> Pin 7
//   Ring   (RING)   -> DAH (right paddle) -> Pin 8
//   Sleeve (SLEEVE) -> GND
//   (no external resistors: internal PULLUPs are used)
//
// DIT -> X key  |  DAH -> Z key
//
// REQUIRED LIBRARIES:
//   - Keyboard.h   (included in the Arduino AVR core)
//   - Bounce2      (Thomas O. Fredericks — install from the
//                   Arduino IDE library manager)
// ============================================================

#include <Keyboard.h>
#include <Bounce2.h>

// --- PINS ---
#define DIT_PIN   7
#define DAH_PIN   8

// --- KEYS ---
// CW Trainer EA7LMT / Morse App Android: X / Z
// Change these if your app needs different keys
#define KEY_DIT  'x'
#define KEY_DAH  'z'

// --- DEBOUNCE ---
// Settling time in ms. 5ms is enough for most paddles.
// Raise to 10ms if you notice bouncing.
#define DEBOUNCE_MS  5

Bounce dit = Bounce();
Bounce dah = Bounce();

// ============================================================
void setup() {
  pinMode(DIT_PIN, INPUT_PULLUP);
  pinMode(DAH_PIN, INPUT_PULLUP);

  dit.attach(DIT_PIN);
  dit.interval(DEBOUNCE_MS);

  dah.attach(DAH_PIN);
  dah.interval(DEBOUNCE_MS);

  Keyboard.begin();
}

// ============================================================
void loop() {
  dit.update();
  dah.update();

  // --- DIT ---
  if (dit.fell())  Keyboard.press(KEY_DIT);
  if (dit.rose())  Keyboard.release(KEY_DIT);

  // --- DAH ---
  if (dah.fell())  Keyboard.press(KEY_DAH);
  if (dah.rose())  Keyboard.release(KEY_DAH);
}
