#include "troymotormanager.h"

TroyMotorManager::TroyMotorManager(int motorCount){
  _motors = new TroyMotor*[motorCount];
  _motorCount=motorCount;
  _motorPtr=-1;
  _interval=20;
  _motorStatus = new int[motorCount];
  prevMillis=0;
  _isReset=false;
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

  unsigned long currentMillis = millis();
  if(currentMillis - prevMillis > _interval) {
    prevMillis = currentMillis;
    for(int i=0;i<=_motorPtr;i++){
      if( _motors[i]->getStatus()==1){
        _motors[i]->run();
      }
    }
  }

}
void TroyMotorManager::interval(int interval){
  _interval=interval;
}


void TroyMotorManager::goToStep(int index,int step){
  _motors[index]->goToStep(step);
  _motors[index]->setStatus(1);
}

int TroyMotorManager::getInterval(){
  return _interval;
}

void TroyMotorManager::loopForever(){
  for(int i=0;i<=_motorPtr;i++){
    _motors[i]->setStatus(1);
     _motors[i]->run();
  }


}




