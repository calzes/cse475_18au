#include "Active2.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

//BELLS
constexpr uint8_t Active2::_localWeights[];

uint8_t Active2::getNumRepeats() {
 return rand() % 5 + 4; // 4 - 8 repeats
}

//Bell lights: &bell(0x04), bell2(0x13)
void Active2::loop(uint32_t dt) {
  rand() % 2 ? Neopixel::setLight(0x04) : Neopixel::setLight(0x13);
  Midi::setSound(rand() % 4 + 0x21); // Random bell sound between 0x20 and 0x24
}

const uint8_t* Active2::getLocalWeights() {
  return this->_localWeights;
}

float Active2::getStartleFactor() {
  return 0.001f;
}
