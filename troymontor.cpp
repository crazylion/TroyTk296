
#include "troymotor.h"

TroyMotor::TroyMotor(int pin){
  pinMode(pin,OUTPUT);
  _pin=pin;
  isRunning=false;
  _currentStep=0;
}

void TroyMotor::goToStep(int stepCount){
    _goToSTep=stepCount;
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
