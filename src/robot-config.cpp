#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor puncherMotorA = motor(PORT12,ratio36_1,false);
motor puncherMotorB = motor(PORT13,ratio36_1,true);
motor_group puncherMotorGroup = motor_group(puncherMotorA,puncherMotorB);

motor leftMotorA = motor(PORT3, ratio6_1, true);
motor leftMotorB = motor(PORT4, ratio6_1, false);
motor leftMotorC = motor(PORT5, ratio6_1, true);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB,leftMotorC);
motor rightMotorA = motor(PORT6, ratio6_1, true);
motor rightMotorB = motor(PORT7, ratio6_1, false);
motor rightMotorC = motor(PORT8, ratio6_1, false);

digital_out DigitalOutC = digital_out(Brain.ThreeWirePort.C);
digital_out DigitalOutD = digital_out(Brain.ThreeWirePort.D);
digital_out DigitalOutH = digital_out(Brain.ThreeWirePort.H);
digital_out DigitalOutG = digital_out(Brain.ThreeWirePort.G);

motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB,rightMotorC);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);
limit LimitSwitchE = limit(Brain.ThreeWirePort.E);


// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool DrivetrainLNeedsToBeStopped_Controller1 = true;
bool DrivetrainRNeedsToBeStopped_Controller1 = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values

  while(true) {
    if(RemoteControlCodeEnabled) {

      // calculate the drivetrain motor velocities from the controller joystick axies
      // left = Axis3 + Axis1
      // right = Axis3 - Axis1
      
      int drivetrainLeftSideSpeed = Controller1.Axis3.position() + Controller1.Axis1.position();
      int drivetrainRightSideSpeed = Controller1.Axis3.position() - Controller1.Axis1.position();
    
if(Controller1.ButtonB.pressing()){
  
      bool DriveTrainNeedsToBeStopped = false;
      bool HangNeedsToBeStopped = false;
      int drivetrainLeftSideSpeed = Controller1.Axis2.position() + Controller1.Axis1.position();
      int drivetrainRightSideSpeed = Controller1.Axis2.position() - Controller1.Axis1.position();
      int hangUpSpeed = Controller1.Axis4.position() + Controller1.Axis1.position();
      int hangDownSpeed = Controller1.Axis4.position() - Controller1.Axis1.position();

      if (abs(hangUpSpeed) < 5 && abs(hangDownSpeed) < 5) {
        // check if the left motor has already been stopped
        if (DrivetrainLNeedsToBeStopped_Controller1) {
          // stop the left drive motor
            leftMotorA.stop();
            rightMotorC.stop();

          // tell the code that the left motor has been stopped
          DrivetrainLNeedsToBeStopped_Controller1 = false;
        }
        else {
          DrivetrainLNeedsToBeStopped_Controller1 = true;
        }

      if (abs(drivetrainLeftSideSpeed) < 5 && abs(drivetrainRightSideSpeed) < 5) {
        // check if the right motor has already been stopped
        if (DriveTrainNeedsToBeStopped) {
          // stop the right drive motor
            leftMotorB.stop();
            leftMotorC.stop();
            rightMotorA.stop();
            rightMotorB.stop();
          // tell the code that the right motor has been stopped
          DriveTrainNeedsToBeStopped = false;
                                    
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the right motor next time the input is in the deadband range
        DriveTrainNeedsToBeStopped = true;


      }
  }

if(HangNeedsToBeStopped){
  leftMotorA.setVelocity(drivetrainLeftSideSpeed,percent);
  rightMotorC.setVelocity(drivetrainLeftSideSpeed,percent);
  leftMotorA.spin(forward);
  rightMotorC.spin(forward);
}
if (DriveTrainNeedsToBeStopped){
  leftMotorB.setVelocity(drivetrainRightSideSpeed,percent);
  leftMotorC.setVelocity(drivetrainRightSideSpeed,percent);
  rightMotorA.setVelocity(drivetrainRightSideSpeed,percent);
  rightMotorB.setVelocity(drivetrainRightSideSpeed,percent);

  leftMotorB.spin(forward);
  leftMotorC.spin(forward);
  rightMotorA.spin(forward);
  rightMotorB.spin(forward);
}



}




else{

      // check if the value is inside of the deadband range
      if (drivetrainLeftSideSpeed < 5 && drivetrainLeftSideSpeed > -5) {
        // check if the left motor has already been stopped
        if (DrivetrainLNeedsToBeStopped_Controller1) {
          // stop the left drive motor
          LeftDriveSmart.stop();
          // tell the code that the left motor has been stopped
          DrivetrainLNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the left motor nexttime the input is in the deadband range
        DrivetrainLNeedsToBeStopped_Controller1 = true;
      }
      // check if the value is inside of the deadband range
      if (drivetrainRightSideSpeed < 5 && drivetrainRightSideSpeed > -5) {
        // check if the right motor has already been stopped
        if (DrivetrainRNeedsToBeStopped_Controller1) {
          // stop the right drive motor
          RightDriveSmart.stop();
          // tell the code that the right motor has been stopped
          DrivetrainRNeedsToBeStopped_Controller1 = false;
        }
      } else if(Controller1.ButtonB.pressing()) {
        // reset the toggle so that the deadband code knows to stop the right motor next time the input is in the deadband range
        DrivetrainRNeedsToBeStopped_Controller1 = true;
      }
      
      // only tell the left drive motor to spin if the values are not in the deadband range
      if (DrivetrainLNeedsToBeStopped_Controller1) {
        LeftDriveSmart.setVelocity(drivetrainLeftSideSpeed, percent);
        LeftDriveSmart.spin(forward);
      }
      // only tell the right drive motor to spin if the values are not in the deadband range
      if (DrivetrainRNeedsToBeStopped_Controller1) {
        RightDriveSmart.setVelocity(drivetrainRightSideSpeed, percent);
        RightDriveSmart.spin(forward);
      }
    }

    }

    // wait before repeating the process
    wait(20, msec);
  } 


  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}