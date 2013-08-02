#ifndef TroyMotor_h
#define TroyMotor_h
#include "Arduino.h"
class TroyMotor{
public:
  TroyMotor(int);

  void high();
  void low();
  void singleRun();
  void run();
  void goToStep(int);
  int getStatus();
  void setStatus(int);
  void reset();
private:
  int _pin,_currentStep,_goToStep;
  int _status; // 0-> stop // 1->running
  boolean _position; //false=>LOW  , false=>HIGH
  int _counter;
  boolean _isReset; // default is true. Don't need to reset
  void reseting();  //run reseting
  void step(); 


};
#endif



