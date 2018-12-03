#include "Ambient2.h"
<<<<<<< HEAD
#include "Neopixel.h"
#include "Debug.h"
=======
#include "Debug.h"
#include "Midi.h"
>>>>>>> eac846eb4e444b2215aff2a30a0eb0324ced55c3

constexpr uint8_t Ambient2::_localWeights[];

uint8_t Ambient2::getNumRepeats() {
<<<<<<< HEAD
 return 25;	//random number of repeats, as requested
}

void Ambient2::loop(uint32_t dt) {
//  dprintln(F("Ambient2"));
=======
 return rand() % 5 + 4; // 4 - 8 repeats
}

void Ambient2::loop(uint32_t dt) {
  Midi::setSound(5);
>>>>>>> eac846eb4e444b2215aff2a30a0eb0324ced55c3
}

const uint8_t* Ambient2::getLocalWeights() {
  return this->_localWeights;
}

float Ambient2::getStartleFactor() {
<<<<<<< HEAD
  return 9999999999;
}

bool Ambient2::rxStartle(int8_t rssi, uint8_t len, uint8_t* payload) {}

void Ambient2::PIR() {
  dprintln("PIR triggered!");
}

void Ambient2::startled(uint8_t strength, uint8_t id) {}
=======
  return 0.001f;
}
>>>>>>> eac846eb4e444b2215aff2a30a0eb0324ced55c3
