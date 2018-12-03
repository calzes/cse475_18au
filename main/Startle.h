<<<<<<< HEAD
#ifndef _STARTLESTATE_H_
#define _STARTLESTATE_H_
=======
#ifndef _STARTLE_H_
#define _STARTLE_H_
>>>>>>> eac846eb4e444b2215aff2a30a0eb0324ced55c3

#include "Creature.h"
#include "State.h"

class Startle : public State {
 public:
<<<<<<< HEAD
  Startle(Creature& creature) : State(creature, "Startle", 0xFF) {}
=======
  Startle(Creature& creature) : State(creature, "Startle", 255) {}
>>>>>>> eac846eb4e444b2215aff2a30a0eb0324ced55c3
  uint8_t getNumRepeats();
  void loop(uint32_t dt);
  const uint8_t* getLocalWeights();
  float getStartleFactor();
protected:
<<<<<<< HEAD
  bool rxStartle(int8_t rssi, uint8_t len, uint8_t* payload);
  void PIR();
  void startled(uint8_t strength, uint8_t id);
private:
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 0 };
};

#endif  // _STARTLESTATE_H_
=======
  bool rxStartle(uint8_t len, uint8_t* payload);
  void PIR();
  void startled();
private:
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 1, 1, 1, 1, 1, 1 };
};

#endif  // _STARTLE_H_
>>>>>>> eac846eb4e444b2215aff2a30a0eb0324ced55c3
