#ifndef _ACTIVE1_H_
#define _ACTIVE1_H_

#include "Creature.h"
#include "State.h"

class Active1 : public State {
 public:
  Active1(Creature& creature) : State(creature, "Active 1", 2) {}
  uint8_t getNumRepeats();
  void loop(uint32_t dt);
  const uint8_t* getLocalWeights();
  float getStartleFactor();
private:
  //from birds, we go to: insects, winds, weather, melodics, bells
  //states: ambient1, active 1, ambient2, active 2, ambient 3, active 3
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = {6, -1, 10, 2, 8, 4};
};

#endif  // _ACTIVE1_H_
