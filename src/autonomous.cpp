#include "vex.h"
#include "robot-config.h"
#include "pid.h"

eftl::PIDController voltagePIDController = eftl::PIDController(1.0,1.0,1.0,1.0);



double PConstant = 3.3; 
double PTurnConstant = 2.0;
int PWaitConstant = 50;
int voltControl(){
  while (1) 
    voltagePIDController.step(11500,Drivetrain.voltage(vex::voltageUnits::mV));
}

const double proportion = 1.0;
void pneumA(){
       DigitalOutH.set(true);
       DigitalOutG.set(true);
}

void pneumFA(){
       DigitalOutH.set(false);
       DigitalOutG.set(false);
}

void skillAuton(){
  puncherMotorGroup.setVelocity(70, percent);
  puncherMotorGroup.setMaxTorque(100,percent);  
  puncherMotorGroup.spin(forward);
  wait(5,sec);
  puncherMotorGroup.stop();
  Drivetrain.driveFor(forward,5,inches);
  Drivetrain.turnFor(left,125,deg);  
  Drivetrain.driveFor(forward,100,inches);
  Drivetrain.turnFor(right,60,degrees);
  Drivetrain.driveFor(forward,10,inches);
  Drivetrain.turnFor(left,90,degrees);
  pneumA();
  Drivetrain.driveFor(forward,70,inches);
  Drivetrain.turnFor(left,90,degrees);
  Drivetrain.driveFor(70,inches);
  Drivetrain.driveFor(reverse,30,inches);


  



  // Drivetrain.turnFor(right,135,deg);
  // Drivetrain.driveFor(forward,36,inches);
  // pneumA();
  // Drivetrain.driveFor(forward,30,inches);
  
}

void basicAuton(){
   wait(PWaitConstant,msec);
   Drivetrain.setDriveVelocity(40,percent);
   Drivetrain.setTurnVelocity(40,percent);
   Drivetrain.setTimeout(5,sec);
  //  puncherMotorGroup.setVelocity(80, percent);
  //  puncherMotorGroup.setMaxTorque(100,percent);
  //  puncherMotorGroup.spin(forward);
  //  wait(5,sec);


// Drivetrain.driveFor(forward,12*PConstant,inches);
  Drivetrain.driveFor(5*PConstant,inches);
  wait(PWaitConstant,msec);
  Drivetrain.turnFor(right,60*PTurnConstant,degrees);
  wait(PWaitConstant,msec);
  Drivetrain.driveFor(14.5*PConstant,inches);
  wait(PWaitConstant,msec);
  Drivetrain.turnFor(left,45*PTurnConstant,degrees);
  wait(PWaitConstant,msec);
  Drivetrain.driveFor(forward,5*PConstant,inches);
  wait(3*PWaitConstant,msec);
  Drivetrain.driveFor(reverse,10*PConstant,inches);
  wait(PWaitConstant,msec);
  Drivetrain.turnFor(left,65*PTurnConstant,degrees);
  wait(PWaitConstant,msec);
  Drivetrain.driveFor(28*PConstant,inches);
  pneumA();
  wait(PWaitConstant,msec);
  Drivetrain.turnFor(right,55*PTurnConstant,degrees);
  wait(PWaitConstant,msec);
  Drivetrain.setDriveVelocity(30,percent);
  Drivetrain.driveFor(10*PConstant,inches);
  wait(PWaitConstant,msec);
  Drivetrain.setTurnVelocity(20,percent);
  Drivetrain.turnFor(right,130*PTurnConstant,degrees);
  wait(PWaitConstant,msec);
  Drivetrain.driveFor(18*PConstant,inches);
  Drivetrain.driveFor(reverse,5*PConstant,inches);
  

//  Drivetrain.turnFor(right,90*PTurnConstant,degrees);
//   wait(PWaitConstant,msec);

//  Drivetrain.driveFor(18*PConstant,inches);
//   wait(PWaitConstant,msec);
//  Drivetrain.driveFor(reverse,18*PConstant,inches);
//   wait(PWaitConstant,msec);
 pneumFA();

  // Drivetrain.driveFor(100,mm);
  // Drivetrain.turnFor(right,90,degrees);
  // Drivetrain.driveFor(forward,30,mm);
  // Drivetrain.driveFor(reverse,30,mm);
  // Drivetrain.turnFor(right,180,degrees);   
}

void secondBasicAuton(){
  Drivetrain.setDriveVelocity(95, percent);
  Drivetrain.driveFor(forward,75,inches);
  Drivetrain.turnFor(90,degrees);
  pneumA();
  Drivetrain.setDriveVelocity(45, percent);
  wait(6000, msec);
  Drivetrain.driveFor(forward,50,inches);
  Drivetrain.turnFor(right,180,degrees);
  Drivetrain.driveFor(forward,65,inches);

}

// void skillAuton(){
//   Drivetrain.setDriveVelocity(95,percent);
//   Drivetrain.driveFor(forward,20,inches);
//   Drivetrain.turnFor(left,130,deg);
//   Drivetrain.driveFor(reverse,16,inches);
//   puncherMotorGroup.setVelocity(60, percent);
//   puncherMotorGroup.setMaxTorque(100,percent);  
//   puncherMotorGroup.spin(forward);
//   wait(30,sec);
//   puncherMotorGroup.stop();
//   Drivetrain.turnFor(right,95,degrees);
//   // Drivetrain.setStopping(hold);
//   Drivetrain.driveFor(forward,114,inches);
//   Drivetrain.turnFor(left,140,degrees);
//   Drivetrain.driveFor(reverse,50,inches);
//     Drivetrain.setDriveVelocity(200,percent);
//   Drivetrain.driveFor(forward,210,inches);
//     Drivetrain.setDriveVelocity(95,percent);
//     Drivetrain.turnFor(right,40,degrees);
// pneumA();
// // Drivetrain.driveFor(forward,90,inches);

//   // Drivetrain.driveFor(forward,25,inches);
//   // Drivetrain.turnFor(right,90,deg);
//   // Drivetrain.driveFor(forward,36,inches);
//   // pneumA();
//   // Drivetrain.driveFor(forward,30,inches);
//   // Drivetrain.driveFor(reverse,60,inches);
//   // Drivetrain.turnFor(right,225,degrees);
//   // Drivetrain.driveFor(forward,40,inches);
//   // pneumA();
//   // Drivetrain.driveFor(forward,90,inches);
// }

void autonomous(){
  // task pidControlTask(voltControl);
  basicAuton();
}