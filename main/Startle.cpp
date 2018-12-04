#include "Startle.h"
#include "Neopixel.h"
constexpr uint8_t Startle::_localWeights[];

uint8_t Startle::getNumRepeats() {
 return rand() % 4 + 1; // 1 - 4
}

//startle lights: strobe(0x03), lightning(0x09), strobeRand(0x0D), flashing(0x12)
void Startle::loop(uint32_t dt) {
  int randNum = rand() % 4;
  switch(randNum) {
    case 0: Neopixel::setLight(0x03); break;
    case 1: Neopixel::setLight(0x09); break;
    case 2: Neopixel::setLight(0x0D); break;
    case 3: Neopixel::setLight(0x12); break;
  }
}

const uint8_t* Startle::getLocalWeights() {
  return this->_localWeights;
}

float Startle::getStartleFactor() {
  return 9999999999;
}

bool Startle::rxStartle(uint8_t len, uint8_t* payload) {}

void Startle::PIR() {}

void Startle::startled() {}
