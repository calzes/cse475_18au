#ifndef _ACTIVE2_H_
#define _ACTIVE2_H_

#include "Creature.h"
#include "State.h"

class Active2 : public State {
 public:
  Active2(Creature& creature) : State(creature, "Active 2", 4) {}
  uint8_t getNumRepeats();
  void loop(uint32_t dt);
  const uint8_t* getLocalWeights();
  float getStartleFactor();
private:
  //from bells we go to: winds, weather, insects, melodics, birds
  //states: ambient1, active 1, ambient2, active 2, ambient 3, active 3
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = {8, 2, 6, -1, 10, 4};
};

#endif  // _ACTIVE2_H_
