#include "Active1.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

//BIRDS
constexpr uint8_t Active1::_localWeights[];

uint8_t Active1::getNumRepeats() {
 return rand() % 5 + 4; // 4 - 8 repeats
}


//active 1 lights: &smoothRainbow (0x02), &quadRand (0x10)
void Active1::loop(uint32_t dt) {
  //Random number: if it's odd, play smoothRainbow, if even, play quadRand
  rand() % 2 ? Neopixel::setLight(0x02) : Neopixel::setLight(0x10);
  Midi::setSound(15);
}

const uint8_t* Active1::getLocalWeights() {
  return this->_localWeights;
}

float Active1::getStartleFactor() {
  return 0.001f;
}
