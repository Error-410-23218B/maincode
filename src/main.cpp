/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Administrator                                    */
/*    Created:      Mon Jul 17 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    3, 4, 6, 7      
// ---- END VEXCODE CONFIGURED DEVICES -- --


#include "vex.h"
#include "robot-config.h"
#include "pid.h"
#include <string>
#include <sstream>

using namespace vex;
competition Competition;

eftl::PIDController driveVoltage(1.0,1.0,1.0,1.0);
eftl::PIDController puncherVoltage(1.0,1.0,1.0,1.0);
eftl::PIDController turnVoltage(1.0,1.0,1.0,1.0);
eftl::PIDController hangingVoltage(1.0,1.0,1.0,1.0);




void hangingUp(){

    rightMotorB.spin(forward);
    rightMotorA.spin(forward);
    leftMotorB.spin(forward);
    leftMotorA.spin(forward);
}

void hangingDown(){
    rightMotorB.spin(reverse);
    rightMotorA.spin(reverse);
    leftMotorB.spin(reverse);
    leftMotorA.spin(reverse);
}

void hangingReverse(){
       rightMotorC.spin(reverse);
       leftMotorA.spin(reverse);
}

void limitSwitch(){
       puncherMotorGroup.spin(forward);
       wait(5,seconds);
}

void pneumShift(){
       DigitalOutG.set(false);
}

void pneumShiftF(){
       DigitalOutG.set(true);
}


void pOn(){
       DigitalOutC.set(true);
       DigitalOutD.set(true);
}

void pOff(){
       DigitalOutC.set(false);
       DigitalOutD.set(false);
}

void limitSwitchOff(){
       puncherMotorGroup.stop();
}

int limitLoop(){
       while (1)
       {
              LimitSwitchE.pressed(limitSwitch);
              LimitSwitchE.released(limitSwitchOff);
       }
   return 0;    
}

void switchPneumF(){
      leftMotorB.spin(forward);
      leftMotorC.spin(forward);
      rightMotorB.spin(forward);
      rightMotorA.spin(forward);
      rightMotorB.setBrake(coast);
      leftMotorB.setBrake(coast);
      leftMotorC.setBrake(coast);
      rightMotorA.setBrake(coast);
      rightMotorB.setBrake(coast);

}

int pidTask(){
       std::ostringstream s; 
       std::string str;
while (1)
{ 
       driveVoltage.step(11000,Drivetrain.voltage());
       s<<Drivetrain.voltage();
       str = s.str();
       Brain.Screen.printAt(0,0,str.c_str());
       wait(50,msec);
}
       return 0;
}

void pneum(){
       DigitalOutH.set(true);
       DigitalOutG.set(true);
}

void pneumF(){
       DigitalOutH.set(false);
       DigitalOutG.set(false);
}
void puncherOff(){
      puncherMotorGroup.stop();

}


void puncherOn(){
    puncherMotorGroup.spin(forward);
    wait(100,msec);
     if(Controller1.ButtonX.pressing()){puncherMotorGroup.stop(); }
  // puncherMotor.spin(forward);
  // if(Controller1.ButtonX.pressing()){
  //     puncherMotor.stop();
  //   }
  // while(!Controller1.ButtonX.pressing()){
  //   puncherMotor.spin(forward);
  //   if(Controller1.ButtonX.pressing()){
  //     puncherMotor.stop();
  //   }
  // }
}

void usercontrol(){
   DigitalOutG.set(true);
//    Controller1.ButtonY.pressed(puncherOff);
//    Controller1.ButtonL2.pressed(puncherOff);
//    Controller1.ButtonL1.pressed(puncherOn);

//    Controller1.ButtonB.pressed();


   


}

int video(){

   while(true) {
        for (int i=0; i < 200; i++) {
            std::stringstream temp_str;
            temp_str <<(i);
            std::string str = temp_str.str() + ".png";

    
             
            Brain.Screen.drawImageFromFile(str.c_str(),0,0);
            wait(15,msec);
        }
    }

       return 0;
}

int main() {

   DigitalOutG.set(true);
   Controller1.ButtonB.pressed(pneumShift);
//    Controller1.ButtonUp.pressed(hangingUp);
//    Controller1.ButtonDown.pressed(hangingDown);
      Controller1.ButtonR1.pressed(pneum);
   Controller1.ButtonR2.pressed(pneumF);
//       Controller1.ButtonLeft.pressed(pOn);
//    Controller1.ButtonRight.pressed(pOff);
   Controller1.ButtonA.pressed(pneumShiftF);

   Controller1.ButtonX.pressed(puncherOn);

   DigitalOutD.set(true);
   // Initializing Robot Configuration. DO NOT REMOVE!
   vexcodeInit();
   task videoTask(video);
   task limitSwitch(limitLoop);
// task pidTask(pidTask); 
   
   puncherMotorGroup.setVelocity(70, percent);
   puncherMotorGroup.setMaxTorque(100,percent);
   Competition.autonomous(autonomous);
   Competition.drivercontrol(usercontrol);
  //  Controller1.ButtonY.pressed(puncherOff);
  return 0;
}
