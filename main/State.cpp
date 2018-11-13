#include "Creature.h"
#include "State.h"

State::State(Creature& creature, char* const name, const uint8_t id) : _creature(creature), _id(id) {
  strncpy(_name, name, MAX_NAME_LEN);
  _name[MAX_NAME_LEN] = 0;
};

uint8_t State::getId() {
  return _id;
}

char* State::getName() {
  return _name;
}

void State::playSound(uint8_t sound_idx) {
  // TODO: implement
}

void State::playEffect(uint8_t effect_idx) {
  // TODO: implement
}

bool State::rxPlaySound(uint8_t len, uint8_t* payload) {
  // TODO: implement
}

bool State::rxPlayEffect(uint8_t len, uint8_t* payload) {
  // TODO: implement
}

// Not sure if STARTLE_DECAY and STARTLE_FACTOR are defined to be used like this
bool State::rxStartle(int8_t rssi, uint8_t len, uint8_t* payload) {
  // TODO: implement
 uint8_t strength = payload[0];
 uintn8_t id = payload[1];
 double startleWeight = (double) (GLOBALS.STARTLE_DECAY - rssi) / GLOBALS.STARTLE_DECAY;
 double decay = sigmoid(startleWeight) * STARTLE_FACTOR; // what is startle factor
 if (decay * strength > GLOBALS.STARTLE_THRESHOLD) {
    Serial.println("Startled. I'm so scared wow");
 }
////Globals.STARTLE_DECAY?
}

double sigmoid(double x) {
    return 1 / (1 + exp(-1 * x));
}

void State::txStartle(uint8_t strength, uint8_t id) {
  uint8_t payload[2] = {strength, id};
  _creature.tx((uint8_t)PID_STARTLE, (uint8_t)BROADCAST_ADDR, (uint8_t)2, payload);
  return;
  }
  /**
   * Transmits a packet to dst_addr from this creature.
   *
   * @param pid Packet identifier.
   * @param dst_addr  Address of the intended recipient of this packet.
   * @param len Length of the payload, in bytes
   * @param payload An array of bytes to use as the payload.
   * @returns true iff the packet was successfully sent, false otherwise.

  bool tx(const uint8_t pid, const uint8_t dstAddr, const uint8_t len, uint8_t* const payload); */
  return;
}

State* State::transition() {
  uint8_t N = GLOBALS.NUM_CREATURES;
  uint8_t* P[N] = probabilities();
  uint8_t R = rand(0,P[N]);
  for(int i = 1; i<=N; i++{
    if(R < P[i]){
      setNextState(_creatureStates[i]);
    }
  } 
}

//Create a new function in h for the transition math
uint8_t* probabilities() {//???
  uint8_t N = GLOBALS.NUM_CREATURES;
  uint8_t numStates = ACTIVE_STATES + AMBIENT_STATES;
  uint8_t* D[N] = inverseDistances(_creatureDistances);
  float Ls[numStates];

  float P_i[N];
  for(int i = 1; i<=N; i++{
    float P_max = 0;
    float P_j[N];
    for(int j = 1; j <= numStates; j++) {
  
      //calculate first sum: how many creatures are in the j'th state
      uint8_t sum1;
      for(int k=0; k < N; k++) {
        sum1 += ((_creatureStates[k] == j) ? 1 : 0);
      }
      Ls[j] = _globalWeights[j] * (N - sum1)/N;
      
      if(P_max < _localWeights[j] + Ls[j]*D[j]*sum1) {
        P_max = _localWeights[j] + Ls[j]*D[j]*sum1;
      }
      P_j[j] = P_max;
      P_i[i] += P_j[j];
    }
  }

  //Complete this calculation d times
  /*Needs:C =  _creatureStates, N = number of creatures, L_j (scalar global weight for next state j)
          W = _localWeights of the current state, D = inverse _creatureDistances
  */

  return P_i;
}

int8_t* inverseDistances(int8_t *creatureDistances) {
  uint8_t* inverseDistances[GLOBALS.NUM_CREATURES]
  for (int i = 0; i < GLOBALS.NUM_CREATURES; i++) {
    if (creatureDistances[i] = 0) { inverseDistances[i] = 0; }
    else { inverseDistances[i] = 1/creatureDistances[i]; }
  }
}


void State::PIR() {
  // TODO: implement
}

void State::startled(uint8_t strength, uint8_t id) {
  // TODO: implement
}

int8_t* State::getGlobalWeights() {
  return _globalWeights;
}
