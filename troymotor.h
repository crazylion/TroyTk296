#ifndef TroyMotor_h
#define TroyMotor_h
#include "Arduino.h"



class TroyMotor{
public:
  TroyMotor(int,int);

  inline void high();
  inline void low();
  void singleRun();
  void run();
  void goToStep(int);
  void pushToStepQueue(int);
  int  popToStepQueue();
  int getStatus();
  void setStatus(int);
  void reset();
private:
  int _pin,_pin2,_currentStep,_goToStep,_direction;
  int _status; // 0-> stop // 1->running
  boolean _position; //false=>LOW  , false=>HIGH
  int _counter;
  boolean _isReset; // default is true. Don't need to reset
  void reseting();  //run reseting
  void step(); 
  void init(int,int);
  int* _gotoArray;
  int _queueTail;
  int _queueSize;

};
#endif



