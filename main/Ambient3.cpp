#include "Ambient3.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

//WINDS
constexpr uint8_t Ambient3::_localWeights[];

uint8_t Ambient3::getNumRepeats() {
 return rand() % 11 + 10; // 10-20 repeats random
}

//wind lights: wind(0x0A), blinkDot(0x0B), twinkleLights(0x0C)
void Ambient3::loop(uint32_t dt) {
  int randNum = rand() % 3;
  switch(randNum) {
    case 0: Neopixel::setLight(0x0A); break;
    case 1: Neopixel::setLight(0x0B); break;
    case 2: Neopixel::setLight(0x0C); break;
  }
  Midi::setSound(rand() % 2 ? 0x15 : 0x28); //sounds: 0x15 or 0x28
}

const uint8_t* Ambient3::getLocalWeights() {
  return this->_localWeights;
}

float Ambient3::getStartleFactor() {
  return 0.001f;
}
