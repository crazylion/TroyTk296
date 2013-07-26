#ifndef TroyMotorManager_h
#define TroyMotorManager_h
#include "Arduino.h"
#include "troymotor.h"
class TroyMotorManager{
  public:
     TroyMotorManager(int);
     void add(TroyMotor*);
     void run(int,int);
     void loopForever();
  private:
    TroyMotor** _motors;
    int _motorCount;
    int _motorPtr;

};
#endif
