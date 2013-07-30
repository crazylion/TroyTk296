
#include "troymotor.h"

TroyMotor::TroyMotor(int pin){
  pinMode(pin,OUTPUT);
  _pin=pin;
  _status=0;
  _currentStep=0;
}

void TroyMotor::goToStep(int stepCount){
    _goToSTep=stepCount;
}

void TroyMotor::setStatus(int status){
  _status=status;  
}
int TroyMotor::getStatus(){
  return _status;
}

void TroyMotor::singleRun(){
  high();
  delay(50);
  low();
  Serial.println("singleRun");
}

void TroyMotor::high(){
  digitalWrite(_pin,HIGH);
}
void TroyMotor::low(){
  digitalWrite(_pin,LOW);
}
