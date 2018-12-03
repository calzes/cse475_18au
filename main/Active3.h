#ifndef _ACTIVE3_H_
#define _ACTIVE3_H_

#include "Creature.h"
#include "State.h"

class Active3 : public State {
 public:
<<<<<<< HEAD
  Active3(Creature& creature) : State(creature, "Active3", 0x06) {}	//Name = Active3, State ID = 0x06
=======
  Active3(Creature& creature) : State(creature, "Active 3", 6) {}
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
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 50, 50, 50, 50, 50, 50 };
=======
private:
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = {1, 1, 1, 1, 1, 1};
>>>>>>> eac846eb4e444b2215aff2a30a0eb0324ced55c3
};

#endif  // _ACTIVE3_H_
