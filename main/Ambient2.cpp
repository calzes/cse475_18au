#include "Ambient2.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

//INSECTS
constexpr uint8_t Ambient2::_localWeights[];

uint8_t Ambient2::getNumRepeats() {
    return rand() % 6 + 10; // 10-15 repeats, random because nature is pretty random,
    //want it to be longer than active but shorter than other ambient 
}

//Insect lights: insects(0x06), rotatingSlowly(0x0E)
void Ambient2::loop(uint32_t dt) {
  rand() % 2 ? Neopixel::setLight(0x06) : Neopixel::setLight(0x0E);
  Midi::setSound(rand() % 2 + 0x29); //sounds 0x29 - 0x30
}

const uint8_t* Ambient2::getLocalWeights() {
  return this->_localWeights;
}

float Ambient2::getStartleFactor() {
  return 0.001f;
}
