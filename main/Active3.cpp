#include "Active3.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

//MELODICS
constexpr uint8_t Active3::_localWeights[];

uint8_t Active3::getNumRepeats() {
 return rand() % 5 + 4; // 4 - 8 repeats because less than ambient and sort of random
}

//melodic lights: melodic(0x05), rotating(0x08)
void Active3::loop(uint32_t dt) {
  rand() % 2 ? Neopixel::setLight(0x05) : Neopixel::setLight(0x08);
  Midi::setSound(rand() % 8 + 0x19); // Random sound between 0x19 and 0x20
}

const uint8_t* Active3::getLocalWeights() {
  return this->_localWeights;
}

float Active3::getStartleFactor() {
  return 0.001f;
}
