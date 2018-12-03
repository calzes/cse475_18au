#include "Active3.h"
<<<<<<< HEAD
#include "Neopixel.h"
#include "Debug.h"
=======
#include "Debug.h"
#include "Midi.h"
>>>>>>> eac846eb4e444b2215aff2a30a0eb0324ced55c3

constexpr uint8_t Active3::_localWeights[];

uint8_t Active3::getNumRepeats() {
<<<<<<< HEAD
 return 22;	//random number of repeats, as requested
}

void Active3::loop(uint32_t dt) {
//  dprintln(F("Active3"));
=======
 return rand() % 5 + 4; // 4 - 8 repeats
}

void Active3::loop(uint32_t dt) {
  Midi::setSound(3);
>>>>>>> eac846eb4e444b2215aff2a30a0eb0324ced55c3
}

const uint8_t* Active3::getLocalWeights() {
  return this->_localWeights;
}

float Active3::getStartleFactor() {
<<<<<<< HEAD
  return 9999999999;
}

bool Active3::rxStartle(int8_t rssi, uint8_t len, uint8_t* payload) {}

void Active3::PIR() {
  dprintln("PIR triggered!");
}

void Active3::startled(uint8_t strength, uint8_t id) {}
=======
  return 0.001f;
}
>>>>>>> eac846eb4e444b2215aff2a30a0eb0324ced55c3
