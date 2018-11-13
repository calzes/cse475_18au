#ifndef _AMBIENT1_H_
#define _AMBIENT1_H_

#include "Creature.h"
#include "State.h"

class Ambient1 : public State {
 public:
  Ambient1(Creature& creature) : State(creature, "Ambient1", 0x01) {}	//Name = Ambient1, State ID = 0x01
  uint8_t getNumRepeats();
  void loop(uint32_t dt);
  const uint8_t* getLocalWeights();
  float getStartleFactor();
protected:
  bool rxStartle(int8_t rssi, uint8_t len, uint8_t* payload);
  void PIR();
  void startled(uint8_t strength, uint8_t id);
private:
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 60, 40, 70, 30, 65, 30 };
};

#endif  // _AMBIENT1_H_