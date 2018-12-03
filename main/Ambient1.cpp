#include "Ambient1.h"
<<<<<<< HEAD
#include "Neopixel.h"
#include "Debug.h"
=======
#include "Debug.h"
#include "Midi.h"
>>>>>>> eac846eb4e444b2215aff2a30a0eb0324ced55c3

constexpr uint8_t Ambient1::_localWeights[];

uint8_t Ambient1::getNumRepeats() {
<<<<<<< HEAD
 return 20;	//random number of repeats, as requested
}

void Ambient1::loop(uint32_t dt) {
//  dprintln(F("Ambient1"));
=======
 return rand() % 5 + 4; // 4 - 8 repeats
}

void Ambient1::loop(uint32_t dt) {
Midi::setSound(4);
>>>>>>> eac846eb4e444b2215aff2a30a0eb0324ced55c3
}

const uint8_t* Ambient1::getLocalWeights() {
  return this->_localWeights;
}

float Ambient1::getStartleFactor() {
<<<<<<< HEAD
  return 9999999999;
}

bool Ambient1::rxStartle(int8_t rssi, uint8_t len, uint8_t* payload) {}

void Ambient1::PIR() {
  dprintln("PIR triggered!");
}

void Ambient1::startled(uint8_t strength, uint8_t id) {}
=======
  return 0.001f;
}
>>>>>>> eac846eb4e444b2215aff2a30a0eb0324ced55c3
