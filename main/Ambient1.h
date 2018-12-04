#ifndef _AMBIENT1_H_
#define _AMBIENT1_H_

#include "Creature.h"
#include "State.h"

class Ambient1 : public State {
 public:
  Ambient1(Creature& creature) : State(creature, "Ambient 1", 1) {}
  uint8_t getNumRepeats();
  void loop(uint32_t dt);
  const uint8_t* getLocalWeights();
  float getStartleFactor();
private:
  //from weather we go to: winds, insects, weather, birds, melodics, bells
  //states: ambient1, active 1, ambient2, active 2, ambient 3, active 3
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = {6, 4, 8, 1, 10, 2};
};

#endif  // _AMBIENT1_H_
