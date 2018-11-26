#include "Neopixel.h"
#include "Debug.h"

// Initialize fixed list of light gestures.
constexpr void (*Neopixel::LIGHTS[])(uint32_t);

uint8_t Neopixel::_currentIdx = 0;
uint32_t Neopixel::_lastLoop = 0;
Adafruit_NeoPixel_ZeroDMA Neopixel::_strip = Adafruit_NeoPixel_ZeroDMA(NEOPIXEL_COUNT, NEOPIXEL_PIN, NEO_GRBW);

void Neopixel::setup() {
  _strip.begin();
  _strip.setBrightness(5);
  _strip.show();
}

void Neopixel::loop() {
  uint32_t thisLoop = millis();
  uint32_t dt;
  if (_lastLoop) {
    dt = thisLoop - _lastLoop;
  } else {
    dt = 0;
  }
  _lastLoop = thisLoop;

  if (LIGHTS[_currentIdx] != nullptr) {
    LIGHTS[_currentIdx](dt);
  }
}

void Neopixel::setLight(uint8_t lightIdx) {
  // lightIdx soundIdx. Anything outside of the bounds of the array is 0.
  if (lightIdx >= sizeof(LIGHTS) / sizeof(void*)) {
    lightIdx = 0;
  }

  if (_currentIdx != lightIdx) {
    _strip.clear();
    _strip.show();

    _currentIdx = lightIdx;
    _lastLoop = 0;
  }
}

uint8_t Neopixel::getLight() {
  return _currentIdx;
}

void Neopixel::rainbow(uint32_t dt) {
  static uint8_t offset = 0;
  static uint32_t rainbowColors[NEOPIXEL_COUNT] = {16711680, 13578240, 10444800, 7311360, 4177920, 1044480, 56865, 44625,
                                                   32385, 20145, 7905, 1179885, 4325565, 7471245, 10616925, 13762605};

  if (dt > 50) {
    for (uint8_t pix = 0; pix < NEOPIXEL_COUNT; pix++) {
      _strip.setPixelColor((pix + offset) % NEOPIXEL_COUNT, rainbowColors[pix]);
    }
    _strip.show();
    offset++;
  }
}

void Neopixel::strobe(uint32_t dt) {
    static bool on = false;
    if (dt > 50) {
        if (on) {
            for (uint16_t i = 0; i < NEOPIXEL_COUNT; i++) { _strip.setPixelColor(255,255,255,255); }
        } else {
            for (uint16_t i = 0; i < NEOPIXEL_COUNT; i++) { _strip.setPixelColor(0,0,0,0); }
        }
        on = !on;
    }
}

void Neopixel::twinkle_lights(uint32_t dt) {
  //Set brightness to 15?
  _strip.setBrightness(15);
  //Delay between changes?
  if(dt > 100) {
    // First turn off all lights
    for (uint16_t i = 0; i < NEOPIXEL_COUNT; i++) { _strip.setPixelColor(0,0,0,0); }
    // Choose random number of pixels to be on at the same time between 1-4
    int numLightsOn = rand() % 4 + 1;

    for (int i = 0; i<numLightsOn; i++) {
      //For each pixel that's on, choose which pixel it is from 0-15
      uint16_t pixelNum = rand() % NEOPIXEL_COUNT;
      //Set the color of the pixel to blue
      _strip.setPixelColor(pixelNum, 0, 0, 255, 0);
    }
    _strip.show();
  }
}
