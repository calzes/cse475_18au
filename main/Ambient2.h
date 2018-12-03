#ifndef _AMBIENT2_H_
#define _AMBIENT2_H_

#include "Creature.h"
#include "State.h"

class Ambient2 : public State {
 public:
<<<<<<< HEAD
  Ambient2(Creature& creature) : State(creature, "Ambient2", 0x03) {}	//Name = Ambient2, State ID = 0x03
=======
  Ambient2(Creature& creature) : State(creature, "Ambient 2", 3) {}
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
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 0, 100, 0, 0, 0, 0 };
=======
private:
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = {1, 1, 1, 1, 1, 1};
>>>>>>> eac846eb4e444b2215aff2a30a0eb0324ced55c3
};

#endif  // _AMBIENT2_H_
