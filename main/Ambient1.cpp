#include "Ambient1.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

//WEATHER
constexpr uint8_t Ambient1::_localWeights[];

uint8_t Ambient1::getNumRepeats() {
 return rand() % 5 + 4; // 4 - 8 repeats
}

//weather lights: rainbow(0x01), wavez(0x07), rainCycle(0x0F), fire(0x11)
void Ambient1::loop(uint32_t dt) {
  int randNum = rand() % 4;
  switch(randNum) {
    case 0: Neopixel::setLight(0x01); break;
    case 1: Neopixel::setLight(0x07); break;
    case 2: Neopixel::setLight(0x0F); break;
    case 3: Neopixel::setLight(0x11); break;
  }
  Midi::setSound(4);
}

const uint8_t* Ambient1::getLocalWeights() {
  return this->_localWeights;
}

float Ambient1::getStartleFactor() {
  return 0.001f;
}
