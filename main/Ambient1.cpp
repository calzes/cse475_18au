#include "Ambient1.h"
#include "Neopixel.h"
#include "Debug.h"

constexpr uint8_t Ambient1::_localWeights[];

uint8_t Ambient1::getNumRepeats() {
 return 20;	//random number of repeats, as requested
}

void Ambient1::loop(uint32_t dt) {
//  dprintln(F("Ambient1"));
}

const uint8_t* Ambient1::getLocalWeights() {
  return this->_localWeights;
}

float Ambient1::getStartleFactor() {
  return 9999999999;
}

bool Ambient1::rxStartle(int8_t rssi, uint8_t len, uint8_t* payload) {}

void Ambient1::PIR() {
  dprintln("PIR triggered!");
}

void Ambient1::startled(uint8_t strength, uint8_t id) {}
