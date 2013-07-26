#ifndef TroyMotor_h
#define TroyMotor_h
#include "Arduino.h"
class TroyMotor{
public:
  TroyMotor(int);

  void high();
  void low();
  void singleRun();
    void goToStep(int);
private:
  int _pin,_currentStep,_goToSTep;
  boolean isRunning;


};
#endif


