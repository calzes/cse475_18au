#ifndef _ACTIVE3_H_
#define _ACTIVE3_H_

#include "Creature.h"
#include "State.h"

class Active3 : public State {
 public:
  Active3(Creature& creature) : State(creature, "Active 3", 6) {}
  uint8_t getNumRepeats();
  void loop(uint32_t dt);
  const uint8_t* getLocalWeights();
  float getStartleFactor();
private:
  //from melodics, we go to: weather, winds, insects, birds, bells
  //states: ambient1, active 1, ambient2, active 2, ambient 3, active 3
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = {10, 4, 6, 2, 8, -1};
};

#endif  // _ACTIVE3_H_
