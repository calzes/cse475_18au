#ifndef _AMBIENT3_H_
#define _AMBIENT3_H_

#include "Creature.h"
#include "State.h"

class Ambient3 : public State {
 public:
<<<<<<< HEAD
  Ambient3(Creature& creature) : State(creature, "Ambient3", 0x05) {}	//Name = Ambient3, State ID = 0x05
=======
  Ambient3(Creature& creature) : State(creature, "Ambient 3", 5) {}
>>>>>>> eac846eb4e444b2215aff2a30a0eb0324ced55c3
  uint8_t getNumRepeats();
  void loop(uint32_t dt);
  const uint8_t* getLocalWeights();
  float getStartleFactor();
<<<<<<< HEAD
protected:
  bool rxStartle(int8_t rssi, uint8_t len, uint8_t* payload);
  void PIR();
  void startled(uint8_t strength, uint8_t id);
private:
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 2, 4, 6, 8, 10, 12 };
=======
private:
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = {1, 1, 1, 1, 1, 1};
>>>>>>> eac846eb4e444b2215aff2a30a0eb0324ced55c3
};

#endif  // _AMBIENT3_H_
