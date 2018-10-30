// Also requires LATEST Adafruit_NeoPixel and Adafruit_ZeroDMA libraries.

#include <Adafruit_NeoPixel_ZeroDMA.h>

// DMA NeoPixels work ONLY on SPECIFIC PINS.
// On Circuit Playground Express: 8, A2 and A7 (TX) are valid.
// On Feather M0, Arduino Zero, etc.: 5, 11, A5 and 23 (SPI MOSI).
// On GEMMA M0: pin 0.
// On Trinket M0: pin 4.
// On Metro M4: 3, 6, 8, 11, A3 and MOSI
#define PIN         A5
#define NUM_PIXELS 16

Adafruit_NeoPixel_ZeroDMA strip(NUM_PIXELS, PIN, NEO_GRBW);

void setup() {
  strip.begin();
  strip.setBrightness(32);
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:

}
