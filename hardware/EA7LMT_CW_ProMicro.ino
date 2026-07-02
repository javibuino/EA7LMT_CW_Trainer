// ============================================================
// PRO MICRO - ESPEJO HID PARA MORSE APP / VBAND
// ATmega32U4 - 16MHz - USB-C
//
// Convierte un manipulador iambic (jack estéreo 3.5mm) en
// teclado USB HID, emitiendo X (dit) y Z (dah) para la
// web app CW Trainer de EA7LMT.
//
// Palas en paralelo con Nano K3NG si se usa simultáneamente.
//
// CONEXIONES (jack estéreo 3.5mm):
//   Punta  (TIP)    → DIT (pala izquierda) → Pin 7
//   Anillo (RING)   → DAH (pala derecha)   → Pin 8
//   Manga  (SLEEVE) → GND
//   (sin resistencias externas: se usan los PULLUP internos)
//
// DIT → tecla X  |  DAH → tecla Z
//
// LIBRERÍAS NECESARIAS:
//   - Keyboard.h   (incluida en el core de Arduino AVR)
//   - Bounce2      (Thomas O. Fredericks — instalar desde
//                   el gestor de librerías del IDE de Arduino)
// ============================================================

#include <Keyboard.h>
#include <Bounce2.h>

// --- PINES ---
#define DIT_PIN   7
#define DAH_PIN   8

// --- TECLAS ---
// CW Trainer EA7LMT / vBand / Morse App Android: X / Z
// Cambia aquí si tu app necesita otras teclas
#define TECLA_DIT  'x'
#define TECLA_DAH  'z'

// --- DEBOUNCE ---
// Tiempo de estabilización en ms. 5ms es suficiente para la
// mayoría de manipuladores. Sube a 10ms si notas rebotes.
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
  if (dit.fell())  Keyboard.press(TECLA_DIT);
  if (dit.rose())  Keyboard.release(TECLA_DIT);

  // --- DAH ---
  if (dah.fell())  Keyboard.press(TECLA_DAH);
  if (dah.rose())  Keyboard.release(TECLA_DAH);
}
