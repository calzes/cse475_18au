#ifndef _AMBIENT2_H_
#define _AMBIENT2_H_

#include "Creature.h"
#include "State.h"

class Ambient2 : public State {
 public:
  Ambient2(Creature& creature) : State(creature, "Ambient 2", 3) {}
  uint8_t getNumRepeats();
  void loop(uint32_t dt);
  const uint8_t* getLocalWeights();
  float getStartleFactor();
private:
  //from insects we go to weather, winds, insects, melodics, bells, birds
  //states: ambient1, active 1, ambient2, active 2, ambient 3, active 3
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = {10, 1, 6, 2, 8, 4};
};

#endif  // _AMBIENT2_H_
