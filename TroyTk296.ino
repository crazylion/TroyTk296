#include "troymotor.h"
#include "troymotormanager.h"

TroyMotorManager  motorManager(3);
TroyMotor motor(13);
void setup(){
  Serial.begin(9600);
motorManager.add(new TroyMotor(13));
//motorManager.add(new TroyMotor(12));
//motorManager.add(new TroyMotor(11));
//motorManager.add(new TroyMotor(13));
}

void loop(){
  Serial.println("loop");
//motor.singleRun();
motorManager.run();
}
