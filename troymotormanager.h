#ifndef TroyMotorManager_h
#define TroyMotorManager_h
#include "Arduino.h"
#include "troymotor.h"
class TroyMotorManager{
  public:
     TroyMotorManager(int);
     void add(TroyMotor*);
     void goToStep(int,int);
     void loopForever(); // for testing
     void run();  // main loop
  private:
    TroyMotor** _motors;
    int _motorCount;
    int _motorPtr;
    int* _motorStatus;
     unsigned long prevMillis;
     int _interval;

};
#endif
