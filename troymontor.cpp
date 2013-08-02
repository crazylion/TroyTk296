
#include "troymotor.h"

TroyMotor::TroyMotor(int pin){
  pinMode(pin,OUTPUT);
  _pin=pin;
  _status=0;
  _currentStep=0;
  _position=false;
  _counter=0;
}

void TroyMotor::goToStep(int stepCount){
    _goToStep=stepCount;
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
void TroyMotor::run(){
  if(_counter==3){
    _currentStep++;
    _counter=0;
  }
  if(_currentStep>=_goToStep){
    _currentStep=0;
    _status=0;
    _counter=0;
    return;
  }
  char ret[100];
  sprintf(ret,"currentStep:%d,gotostep:%d",_currentStep,_goToStep);
  Serial.println(ret);
  if(_position){
    digitalWrite(_pin,LOW);
    _position=false;
    _counter++;
  }else{
    digitalWrite(_pin,HIGH);
    _position=true;
    _counter++;
  }
}

void TroyMotor::high(){
  digitalWrite(_pin,HIGH);
}
void TroyMotor::low(){
  digitalWrite(_pin,LOW);
}
