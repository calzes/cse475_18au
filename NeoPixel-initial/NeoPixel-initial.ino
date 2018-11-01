// Also requires LATEST Adafruit_NeoPixel and Adafruit_ZeroDMA libraries.

#include <Adafruit_NeoPixel_ZeroDMA.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_FeatherOLED.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

Adafruit_SSD1306 oled = Adafruit_SSD1306();

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
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(20);
  strip.show();

  oled.begin();
  oled.setTextSize(1);
  oled.setTextColor(WHITE, BLACK);
  oled.setCursor(0,0);

}

//uint16_t lightOrder[16] = {0, 8, 12, 4, 10, 2, 13, 5, 11, 3, 15, 7, 1, 9, 14, 6};
int fadeColors[16] = {0,0,255,0,       //Dark Blue
                      0,161,228,0,     //Light Blue
                      220,164,0,0,     //Dark Yellow
                      4,231,98,0};     //Green-ish Blue

void loop() {
  oled.clearDisplay();
  oled.print("\rLight 1"); oled.display();
  oled.display();
  colorFade(fadeColors, 4);
  delay(5000);

  oled.clearDisplay(); oled.setCursor(0,0);
  oled.print("\rLight 2"); oled.display();
  twinkle_lights(100);
  delay(5000);
  oled.clearDisplay(); oled.setCursor(0,0);

  oled.clearDisplay();
  oled.print("\rLight 3"); oled.display();
  oled.display();
  sweep(8);
  delay(5000);

  oled.clearDisplay();
  oled.print("\rLight 4"); oled.display();
  oled.display();
  colorChange(8);
  delay(5000);

}

void colorFade(int colors[], int numColors) {
  //Set first color
  setEveryColor(colors[0], colors[1], colors[2], colors[3]);

  //Initial Fade-In
  for (int i = 1; i < 20; i++) {
      strip.setBrightness(i + 1);
      strip.show();
      delay(100);
    }

  //Loop through each color
  for(int  j = 1; j < numColors; j++) {

    //Dim the color
    for (int i = 20; i > 1; i--) {
      strip.setBrightness(i - 1);
      strip.show();
      delay(100);
    }

    //Change to next color
    setEveryColor(colors[j * numColors], colors[(j* numColors)+1], colors[(j* numColors)+2], colors[(j* numColors)+3]);
    delay(200);

    //Brighten the color
    for (int i = 1; i < 20; i++) {
      strip.setBrightness(i + 1);
      strip.show();
      delay(100);
    }
  }

  //Final Dim-out
  for (int i = 20; i > 1; i--) {
      strip.setBrightness(i - 1);
      strip.show();
      delay(100);
   }

  delay(200);
  setEveryColor(0,0,0,0);
  strip.show();
}

void setEveryColor(int r, int g, int b, int w) {
 for (uint16_t i = 0; i < 16; i++) {
   strip.setPixelColor(i, (uint8_t)r, (uint8_t)g, (uint8_t)b, (uint8_t)w);
  }
}

void twinkle_lights(int diff) {

  strip.setBrightness(15);

  //Loop through the sequence 50 times (random number)
  for (int j = 0; j < 50; j++) {

    //Choose a random number of pixels to be on at the same time between 1-4
    int numLightsOn = randomNumber(1,4);

    for (int i = 0; i<numLightsOn; i++) {

      //For each pixel that's on, choose which pixel it is from 0-15
      uint16_t pixelNum = randomNumber(0,15);
      //Set the color of the pixel to blue
      strip.setPixelColor(pixelNum, 0, 0, 255, 0);
    }

    strip.show();
    //Increase delay between twinkling over time
    delay(diff + j*2);

    //Turn each light off
    setEveryColor(0,0,0,0);
    strip.show();
  }
}

uint16_t randomNumber(int lower, int upper) {
  return (rand() % (upper - lower + 1)) + lower;
}

void colorChange(int cycles) {
  for (int i = 0; i < cycles; i++) {
    mapColor(50, 128, 0, 128, 255, 255, 0);
    delay(1000);
    mapColor(50, 255, 255, 0, 128, 0, 128);
    delay(1000);
  }
}

void sunrise() {
  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(i, (uint8_t) 204, (uint8_t) 102, (uint8_t) 0);
    strip.setPixelColor(15 - i, (uint8_t) 204, (uint8_t) 102, (uint8_t) 0);
    strip.show();
    delay(100);

  }
  delay(500);
  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(7 - i, (uint8_t) 0, (uint8_t) 0, (uint8_t) 255);
    strip.setPixelColor(8 + i, (uint8_t) 0, (uint8_t) 0, (uint8_t) 255);
    strip.show();
    delay(100);
  }
  delay(500);
}
void sweep(int cycles) {
  for (int j = 1; j <= cycles; j++) {
    for (uint16_t i = 0; i < 8; i++) {

        blendColor(0, 8 + i, 255, 255, 0, 128, 0, 128);
        blendColor(0, i, 128, 0, 128, 255, 255, 0);
        strip.show();
        delay(100);
    }
    for (uint16_t i = 0; i < 8; i++) {
        blendColor(0, 8 + i, 128, 0, 128, 255, 255, 0);
        blendColor(0, i, 255, 255, 0, 128, 0, 128);
        strip.show();
        delay(100);
    }
  }
}

void setAll(int r, int g, int b) {
  for (int i = 0; i < 16; i++) {
    strip.setPixelColor(i, (uint8_t) r, (uint8_t) g, (uint8_t) b);
  }
}

void mapColor( int time_, int redA, int greenA, int blueA, int redB, int greenB, int blueB) {
  int stepR = (redB - redA) * 100 / time_;
  int stepB = (blueB - blueA) * 100/ time_;
  int stepG = (greenB - greenA) * 100 / time_;
  for (int i = 1; i <= time_; i++) {
  for (int j = 0; j <16 ; j++) {
    strip.setPixelColor(j, (uint8_t) ((redA * 100 + stepR * i) / 100), (uint8_t) ((greenA * 100 + stepG * i) / 100), (uint8_t) ((100 * blueA + stepB * i) / 100));
  }
  strip.show();
  delay(10);
  }
}
// for a < b
void blendColor(int locationA, int locationB, int redA, int greenA, int blueA, int redB, int greenB, int blueB) {
  // calculate distance between a and b:
  int distance = locationB - locationA;
  int stepR = (redB - redA) * 100 / distance;
  int stepB = (blueB - blueA) * 100/ distance;
  int stepG = (greenB - greenA) * 100 / distance;

  for (int i = 0; i <= distance; i++) {
    strip.setPixelColor(locationA + i, (uint8_t) ((redA * 100 + stepR * i) / 100), (uint8_t) ((greenA * 100 + stepG * i) / 100), (uint8_t) ((100 * blueA + stepB * i) / 100));
  }
}
