#include "troymotormanager.h"

TroyMotorManager::TroyMotorManager(int motorCount){
  _motors = new TroyMotor*[motorCount];
  _motorCount=motorCount;
  _motorPtr=-1;
  _delay=40;
  _motorStatus = new int[motorCount];
}
void TroyMotorManager::add(TroyMotor* motor){
  _motorPtr++;
  if(_motorPtr<_motorCount){
    _motors[_motorPtr]=motor;
  }
  else{
    Serial.println("out of motor array");
  }
}

void TroyMotorManager::run(){
  for(int i=0;i<=_motorPtr;i++){
    if( _motors[i]->getStatus()==1){
      _motors[i]->low();
    }
  }
  delay(_delay);
  for(int i=0;i<=_motorPtr;i++){
    if( _motors[i]->getStatus()==1){
      _motors[i]->high();
    }
  }
  delay(_delay);
  for(int i=0;i<=_motorPtr;i++){
    if( _motors[i]->getStatus()==1){
      _motors[i]->low();
    }
  }
}

void TroyMotorManager::goToStep(int index,int step){
  _motors[index]->goToStep(step);
  _motors[index]->setStatus(1);
}


void TroyMotorManager::loopForever(){
  for(int i=0;i<=_motorPtr;i++){
    Serial.println("high");
    _motors[i]->low();

  }
  delay(_delay);
  for(int i=0;i<=_motorPtr;i++){
    _motors[i]->high();
  }

  delay(_delay);
  for(int i=0;i<=_motorPtr;i++){
    Serial.println("high");
    _motors[i]->low();

  }

}

