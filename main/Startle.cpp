#include "Startle.h"
<<<<<<< HEAD
#include "Neopixel.h"
#include "Debug.h"
=======
>>>>>>> eac846eb4e444b2215aff2a30a0eb0324ced55c3

constexpr uint8_t Startle::_localWeights[];

uint8_t Startle::getNumRepeats() {
<<<<<<< HEAD
 return 5;
}

void Startle::loop(uint32_t dt) {
//  dprintln(F("Startled"));
=======
 return rand() % 4 + 1; // 1 - 4
}

void Startle::loop(uint32_t dt) {
>>>>>>> eac846eb4e444b2215aff2a30a0eb0324ced55c3
}

const uint8_t* Startle::getLocalWeights() {
  return this->_localWeights;
}

float Startle::getStartleFactor() {
  return 9999999999;
}

<<<<<<< HEAD
bool Startle::rxStartle(int8_t rssi, uint8_t len, uint8_t* payload) {}

void Startle::PIR() {
  dprintln("PIR triggered!");
}

void Startle::startled(uint8_t strength, uint8_t id) {}
=======
bool Startle::rxStartle(uint8_t len, uint8_t* payload) {}

void Startle::PIR() {}

void Startle::startled() {}
>>>>>>> eac846eb4e444b2215aff2a30a0eb0324ced55c3
