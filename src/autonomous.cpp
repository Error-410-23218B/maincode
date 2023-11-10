#include "vex.h"
#include "robot-config.h"
#include "pid.h"

eftl::PIDController voltagePIDController = eftl::PIDController(1.0,1.0,1.0,1.0);

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
  Drivetrain.setDriveVelocity(95,percent);
  puncherMotorGroup.stop();
  Drivetrain.driveFor(forward,20,inches);
  Drivetrain.turnFor(left,170,deg);
  Drivetrain.driveFor(reverse,16,inches);
  // puncherMotorGroup.setVelocity(60, percent);
  // puncherMotorGroup.setMaxTorque(100,percent);  
  // puncherMotorGroup.spin(forward);
  // wait(40,sec);
  Drivetrain.turnFor(right,150,degrees);
  // Drivetrain.setStopping(hold);
  Drivetrain.driveFor(forward,114,inches);
  Drivetrain.turnFor(left,135,degrees);
    Drivetrain.setDriveVelocity(200,percent);
  Drivetrain.driveFor(forward,100,inches);
    Drivetrain.setDriveVelocity(95,percent);
    Drivetrain.turnFor(right,40,degrees);
pneumA();
// Drivetrain.driveFor(forward,90,inches);

  // Drivetrain.driveFor(forward,25,inches);
  // Drivetrain.turnFor(right,90,deg);
  // Drivetrain.driveFor(forward,36,inches);
  // pneumA();
  // Drivetrain.driveFor(forward,30,inches);
  // Drivetrain.driveFor(reverse,60,inches);
  // Drivetrain.turnFor(right,225,degrees);
  // Drivetrain.driveFor(forward,40,inches);
  // pneumA();
  // Drivetrain.driveFor(forward,90,inches);
}

void autonomous(){
  // task pidControlTask(voltControl);
  skillAuton();
}