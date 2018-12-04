#include "Ambient2.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

//INSECTS
constexpr uint8_t Ambient2::_localWeights[];

uint8_t Ambient2::getNumRepeats() {
 return rand() % 5 + 4; // 4 - 8 repeats
}

//Insect lights: insects(0x06), rotatingSlowly(0x0E)
void Ambient2::loop(uint32_t dt) {
  rand() % 2 ? Neopixel::setLight(0x06) : Neopixel::setLight(0x0E);
  Midi::setSound(5);
}

const uint8_t* Ambient2::getLocalWeights() {
  return this->_localWeights;
}

float Ambient2::getStartleFactor() {
  return 0.001f;
}
