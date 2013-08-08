
#include "troymotor.h"
const int emptyQueue =-32767;
#define __DEBUG__
TroyMotor::TroyMotor(int pin1,int pin2){
  init(pin1,pin2);
}

void TroyMotor::init(int pin1,int pin2){

  _status=0;
  _currentStep=0;
  _goToStep=0;
  _position=false;
  _counter=0;
  _isReset=true;
  _direction=1;
  _pin=pin1;
  pinMode(pin1,OUTPUT);
  _pin2=pin2;
  pinMode(pin2,OUTPUT);
  
  //init queue
  _queueSize=3;
  _gotoArray= new int[_queueSize];//max assigned step
  for(int i=0;i<_queueSize;i++){
    _gotoArray[i]=0;
  }
  _queueTail=-1;
}

void TroyMotor::pushToStepQueue(int stepCount){
  if(_queueTail>=_queueSize){
    Serial.println("queue is full");
  }else{
   _gotoArray[++_queueTail]=stepCount;
  }
}

int TroyMotor::popToStepQueue(){

  if(_queueTail==-1){
    return emptyQueue;
  }
  int ret = _gotoArray[0];
  for(int i=0;i<_queueTail;i++){
    _gotoArray[i]=_gotoArray[i+1];
  }
  _queueTail--;
  return ret;
}

void TroyMotor::goToStep(int stepCount  ){
  _goToStep=stepCount;
  if(stepCount>0){
    _direction=1;
  }
  else{
    _direction=-1;
  }
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

void TroyMotor::step(){
  if(_counter==3){
    _currentStep+=_direction;
    _counter=0;
  }
#ifdef __DEBUG__  
  Serial.print("currentStep=");
  Serial.println(_currentStep);
  Serial.print("goToStep=");
  Serial.println(_goToStep);
#endif  
  if(_currentStep==_goToStep){
    _status=0;
    _counter=0;
    //check next run
    
    int nextStep = popToStepQueue();
    if(nextStep != emptyQueue ){
      goToStep(nextStep);
      _status=1;
    }
    return;
  }
  char ret[100];
#ifdef __DEBUG__
  sprintf(ret,"currentStep:%d,gotostep:%d",_currentStep,_goToStep);
  Serial.println(ret);
#endif

  if(_position){
    low();
    _position=false;
    _counter++;
  }
  else{
    high();
    _position=true;
    _counter++;
  }
}

void TroyMotor::run(){
  if(_isReset){
    step();
  }
  else{

    reseting();
  }


}

void TroyMotor::high(){
  if(_direction>0){
    digitalWrite(_pin,HIGH);
  }
  else{
    digitalWrite(_pin2,HIGH);
  }

}
void TroyMotor::low(){
  if(_direction>0){
    digitalWrite(_pin,LOW);
  }
  else{
    digitalWrite(_pin2,LOW);
  }
}
void TroyMotor::reseting(){
  int val = analogRead(5);
  if(val==0){
    Serial.print("reset step");
    Serial.println(_currentStep);

    _isReset=true;
    _currentStep=0;
    _goToStep=0;
    _position=false;
    _counter=0;
    _status=0;

  }
  else{
    step();
  }
}

void TroyMotor::reset(){
  _isReset=false;
  _status=1;
  _goToStep=3000; // give   hung steps
}






