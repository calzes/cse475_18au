#ifndef _ACTIVE1_H_
#define _ACTIVE1_H_

#include "Creature.h"
#include "State.h"

class Active1 : public State {
 public:
  Active1(Creature& creature) : State(creature, "Active1", 0x02) {}	//Name = Active1, State ID = 0x02
  uint8_t getNumRepeats();
  void loop(uint32_t dt);
  const uint8_t* getLocalWeights();
  float getStartleFactor();
protected:
  bool rxStartle(int8_t rssi, uint8_t len, uint8_t* payload);
  void PIR();
  void startled(uint8_t strength, uint8_t id);
private:
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 50, 50, 50, 50, 50, 50};
};

#endif  // _ACTIVE1_H_