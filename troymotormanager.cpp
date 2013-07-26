#include "troymotormanager.h"

TroyMotorManager::TroyMotorManager(int motorCount){
  _motors = new TroyMotor*[motorCount];
  _motorCount=motorCount;
  _motorPtr=-1;
}
void TroyMotorManager::add(TroyMotor* motor){
  _motorPtr++;
  if(_motorPtr<_motorCount){
    _motors[_motorPtr]=motor;
  }else{
    Serial.println("out of motor array");
  }
}

void TroyMotorManager::run(int motorIndex,int step){

}

void TroyMotorManager::loopForever(){
//  _motors[0]->high();
//  delay(50);
//  _motors[0]->low();
//  delay(50);
//  Serial.println("loopForever");
  for(int i=0;i<=_motorPtr;i++){
    Serial.println("high");
    _motors[i]->high();
    
  }
  delay(40);
    for(int i=0;i<=_motorPtr;i++){
    _motors[i]->low();
  }
  delay(40);
}
