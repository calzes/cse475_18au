#include "Active1.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

//BIRDS
constexpr uint8_t Active1::_localWeights[];

uint8_t Active1::getNumRepeats() {
 return 10; // shorter than ambient, but still kind of high, not random because birds have brains
}


//active 1 lights: &smoothRainbow (0x02), &quadRand (0x10)
void Active1::loop(uint32_t dt) {
  //Random number: if it's odd, play smoothRainbow, if even, play quadRand
  rand() % 2 ? Neopixel::setLight(0x02) : Neopixel::setLight(0x10);
  //Midi::setSound(15);
  Midi::setSound(rand() % 10 + 1); // Random bird sound from 1-11
}

const uint8_t* Active1::getLocalWeights() {
  return this->_localWeights;
}

float Active1::getStartleFactor() {
  return 0.001f;
}
