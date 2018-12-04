#ifndef _AMBIENT3_H_
#define _AMBIENT3_H_

#include "Creature.h"
#include "State.h"

class Ambient3 : public State {
 public:
  Ambient3(Creature& creature) : State(creature, "Ambient 3", 5) {}
  uint8_t getNumRepeats();
  void loop(uint32_t dt);
  const uint8_t* getLocalWeights();
  float getStartleFactor();
private:
  //from winds we go to insects, weather, winds, bells, birds, melodics
  //states: ambient1, active 1, ambient2, active 2, ambient 3, active 3
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = {8, 2, 10, 4, 6, 1};
};

#endif  // _AMBIENT3_H_
