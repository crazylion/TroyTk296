#include <SerialCommand.h>



#include "troymotor.h"
#include "troymotormanager.h"
SerialCommand sCmd;  
TroyMotorManager  motorManager(3);
TroyMotor motor(13);
void setup(){
  Serial.begin(9600);
  sCmd.addCommand("h",help);
  sCmd.addCommand("run",runMotor);
  sCmd.addCommand("interval",setInterval);
  sCmd.setDefaultHandler(unrecognized); 
  motorManager.add(new TroyMotor(13));
  //motorManager.add(new TroyMotor(12));
  //motorManager.add(new TroyMotor(11));
  //motorManager.add(new TroyMotor(13));
  Serial.println("Welcome to the TroyTk296 commander !!");
}

void loop(){
  sCmd.readSerial();  
  //motor.singleRun();
  motorManager.run();
}

void help(){
  Serial.println("help");
}


void runMotor(){
  char *indexChar;
  char *stepChar;
  indexChar = sCmd.next();
  int motorIndex=-1;
  int motorStep=0;
  motorIndex =atol(indexChar);
  stepChar = sCmd.next();
  if (stepChar == NULL) {
    Serial.println("miss step value");
    return;
  }
  motorStep =atol(stepChar);
  motorManager.goToStep(motorIndex,motorStep);
  char str[100];
  //  sprintf(ret,"motor %s go to Step %s",indexChar,stepChar);
  sprintf(str,"motor %d go to Step %d",motorIndex,motorStep);
  Serial.println(str);

}

void setInterval(){
  char *intervalChar;
  intervalChar= sCmd.next();
 
  char str[100];
  sprintf(str,"change interval from %d to %d",motorManager.getInterval(),atol(intervalChar));
   motorManager.interval(atol(intervalChar));
  Serial.println(str);
}

// This gets set as the default handler, and gets called when no other command matches.
void unrecognized(const char *command) {
  Serial.println("What?");
}



