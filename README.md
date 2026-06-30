# CW Trainer — Iambic B

Entrenador de código Morse (CW) con manipulador iambic B controlado por teclado.

**Autor:** EA7LMT

Inspirado en el [CW Trainer de EA4JAH (Morffe)](https://hz.morffe.dev/cw-trainer/), adaptado para funcionar con un teclado externo en vez de pantalla táctil.

## Uso

- **X** = dit (punto)
- **Z** = dah (raya)

Mantén pulsada cada tecla para emitir elementos repetidos. Si pulsas ambas a la vez (squeeze), el manipulador alterna dit/dah automáticamente, como un manipulador electrónico real en modo **Iambic B**.

La velocidad se mide en **WPM** (palabras por minuto, estándar PARIS) y sigue la regla internacional de temporización (ITU-R M.1677-1):

| Elemento | Duración |
|---|---|
| Punto (dit) | 1 unidad |
| Raya (dah) | 3 unidades |
| Espacio entre elementos de una letra | 1 unidad |
| Espacio entre letras | 3 unidades |
| Espacio entre palabras | 7 unidades |

## Funcionalidades

- Decodificación en tiempo real con tabla Morse estándar
- Frase decodificada visible en pantalla, agrupada en palabras
- Tono audible ajustable entre 500 y 900 Hz
- Velocidad ajustable (WPM)
- Botón CLR para limpiar el texto

## Tecnología

Aplicación web estática de un único archivo HTML (HTML + CSS + JavaScript, sin dependencias externas, sin backend). Funciona directamente en cualquier navegador moderno.

## Licencia

Este proyecto está bajo licencia GNU General Public License v3.0. Consulta el archivo [LICENSE](LICENSE) para más detalles.
