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
  int getStatus();
  void setStatus(int);
private:
  int _pin,_currentStep,_goToSTep;
  int _status; // 0-> stop // 1->running



};
#endif



