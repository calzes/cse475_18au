#ifndef _ACTIVE2_H_
#define _ACTIVE2_H_

#include "Creature.h"
#include "State.h"

class Active2 : public State {
 public:
  Active2(Creature& creature) : State(creature, "Active2", 0x04) {}	//Name = Active2, State ID = 0x04
  uint8_t getNumRepeats();
  void loop(uint32_t dt);
  const uint8_t* getLocalWeights();
  float getStartleFactor();
protected:
  bool rxStartle(int8_t rssi, uint8_t len, uint8_t* payload);
  void PIR();
  void startled(uint8_t strength, uint8_t id);
private:
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 50, 50, 50, 50, 50, 50 };
};

#endif  // _ACTIVE2_H_
