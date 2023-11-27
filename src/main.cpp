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
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "robot-config.h"
#include <string>
#include <sstream>
using namespace vex;
competition Competition;
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
}

int video(){

           while(true) {
        for (int i=0; i < 200; i++){
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
       DigitalOutD.set(true);
   // Initializing Robot Configuration. DO NOT REMOVE!
   vexcodeInit();
   Drivetrain.setDriveVelocity(100,percent);
   task videoTask(video);
   puncherMotorGroup.setVelocity(70, percent);
   puncherMotorGroup.setMaxTorque(100,percent);
   Controller1.ButtonR1.pressed(pneum);
   Controller1.ButtonR2.pressed(pneumF);
   Controller1.ButtonY.pressed(puncherOff);
   Controller1.ButtonX.pressed(puncherOn);
    Competition.autonomous(autonomous);
   Competition.drivercontrol(usercontrol);
  //  Controller1.ButtonY.pressed(puncherOff);

  return 0;
  
}
