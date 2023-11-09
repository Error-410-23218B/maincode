#include "vex.h"
#include "robot-config.h"
#include "pid.h"

eftl::PIDController voltagePIDController = eftl::PIDController(1.0,1.0,1.0,1.0);

int voltControl(){
  while ((1)) 
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

void basicAuton(){
   puncherMotorGroup.setVelocity(80, percent);
   puncherMotorGroup.setMaxTorque(100,percent);
   puncherMotorGroup.spin(forward);
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

void skillAuton(){
  puncherMotorGroup.setVelocity(70, percent);
  puncherMotorGroup.setMaxTorque(100,percent);  
  puncherMotorGroup.spin(forward);
  wait(40,sec);
  puncherMotorGroup.stop();
  Drivetrain.driveFor(reverse,6,inches);
  Drivetrain.turnFor(right,180,deg);
  Drivetrain.driveFor(forward,25,inches);
  Drivetrain.turnFor(right,90,deg);
  Drivetrain.driveFor(forward,36,inches);
  pneumA();
  Drivetrain.driveFor(forward,30,inches);
  // Drivetrain.driveFor(reverse,60,inches);
  // Drivetrain.turnFor(right,225,degrees);
  // Drivetrain.driveFor(forward,40,inches);
  // pneumA();
  // Drivetrain.driveFor(forward,90,inches);
}

void autonomous(){
  task pidControlTask(voltControl);
  skillAuton();
}