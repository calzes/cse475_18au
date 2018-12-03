#include "Ambient3.h"
<<<<<<< HEAD
#include "Neopixel.h"
#include "Debug.h"
=======
#include "Debug.h"
#include "Midi.h"
>>>>>>> eac846eb4e444b2215aff2a30a0eb0324ced55c3

constexpr uint8_t Ambient3::_localWeights[];

uint8_t Ambient3::getNumRepeats() {
<<<<<<< HEAD
 return 31;	//random number of repeats, as requested
}

void Ambient3::loop(uint32_t dt) {
//  dprintln(F("Ambient3"));
=======
 return rand() % 5 + 4; // 4 - 8 repeats
}

void Ambient3::loop(uint32_t dt) {
  Midi::setSound(6);
>>>>>>> eac846eb4e444b2215aff2a30a0eb0324ced55c3
}

const uint8_t* Ambient3::getLocalWeights() {
  return this->_localWeights;
}

float Ambient3::getStartleFactor() {
<<<<<<< HEAD
  return 9999999999;
}

bool Ambient3::rxStartle(int8_t rssi, uint8_t len, uint8_t* payload) {}

void Ambient3::PIR() {
  dprintln("PIR triggered!");
}

void Ambient3::startled(uint8_t strength, uint8_t id) {}
=======
  return 0.001f;
}
>>>>>>> eac846eb4e444b2215aff2a30a0eb0324ced55c3
