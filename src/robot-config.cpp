#include "vex.h"
#include <iostream>

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor puncherMotorA = motor(PORT1,ratio36_1,false);
motor puncherMotorB = motor(PORT10,ratio36_1,true);
motor_group puncherMotorGroup = motor_group(puncherMotorA,puncherMotorB);

motor leftMotorA = motor(PORT3, ratio6_1, false);
motor leftMotorB = motor(PORT4, ratio6_1, true);
motor leftMotorC = motor(PORT5, ratio6_1, false);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB,leftMotorC);
motor rightMotorA = motor(PORT6, ratio6_1, true);
motor rightMotorB = motor(PORT7, ratio6_1, false);
motor rightMotorC = motor(PORT8, ratio6_1, true);

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
    
// if(Controller1.ButtonRight.pressing()){
     
//       bool DriveTrainNeedsToBeStopped = false;
//       bool HangNeedsToBeStopped = false;
//       int drivetrainLeftSideSpeed = Controller1.Axis2.position() + Controller1.Axis1.position();
//       int drivetrainRightSideSpeed = Controller1.Axis2.position() - Controller1.Axis1.position();
//       int hangUpSpeed = Controller1.Axis4.position() + Controller1.Axis1.position();
//       int hangDownSpeed = Controller1.Axis4.position() - Controller1.Axis1.position();

//       if (abs(hangUpSpeed) < 5 && abs(hangDownSpeed) < 5) {
//         // check if the left motor has already been stopped
//         if (DrivetrainLNeedsToBeStopped_Controller1) {
//           // stop the left drive motor
//             leftMotorA.stop();
//             rightMotorC.stop();

//           // tell the code that the left motor has been stopped
//           DrivetrainLNeedsToBeStopped_Controller1 = false;
//         }
//         else {
//           DrivetrainLNeedsToBeStopped_Controller1 = true;
//         }

//       if (abs(drivetrainLeftSideSpeed) < 5 && abs(drivetrainRightSideSpeed) < 5) {
//         // check if the right motor has already been stopped
//         if (DriveTrainNeedsToBeStopped) {
//           // stop the right drive motor
//             leftMotorB.stop();
//             leftMotorC.stop();
//             rightMotorA.stop();
//             rightMotorB.stop();
//           // tell the code that the right motor has been stopped
//           DriveTrainNeedsToBeStopped = false;
                                    
//         }
//       } else {
//         // reset the toggle so that the deadband code knows to stop the right motor next time the input is in the deadband range
//         DriveTrainNeedsToBeStopped = true;


//       }
//   }

// if(HangNeedsToBeStopped){
//   // leftMotorA.setVelocity(drivetrainLeftSideSpeed,percent);
//   // rightMotorC.setVelocity(drivetrainLeftSideSpeed,percent);
//   // leftMotorA.spin(forward);
//   // rightMotorC.spin(forward);

//   leftMotorB.setVelocity(drivetrainRightSideSpeed,percent);
//   leftMotorC.setVelocity(drivetrainRightSideSpeed,percent);
//   rightMotorA.setVelocity(drivetrainRightSideSpeed,percent);
//   rightMotorB.setVelocity(drivetrainRightSideSpeed,percent);

//   leftMotorB.spin(forward);
//   leftMotorC.spin(reverse);
//   rightMotorA.spin(forward);
//   rightMotorB.spin(reverse);
// }
// if (DriveTrainNeedsToBeStopped){
//   // leftMotorB.setVelocity(drivetrainRightSideSpeed,percent);
//   // leftMotorC.setVelocity(drivetrainRightSideSpeed,percent);
//   // rightMotorA.setVelocity(drivetrainRightSideSpeed,percent);
//   // rightMotorB.setVelocity(drivetrainRightSideSpeed,percent);

//   // leftMotorB.spin(forward);
//   // leftMotorC.spin(forward);
//   // rightMotorA.spin(forward);
//   // rightMotorB.spin(forward);

//   leftMotorA.setVelocity(drivetrainLeftSideSpeed,percent);
//   rightMotorC.setVelocity(drivetrainLeftSideSpeed,percent);
//   leftMotorA.spin(forward);
//   rightMotorC.spin(forward);
// }



// }




// else{

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
      } else {
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
    // }

    }

    // wait before repeating the process
    wait(20,msec);
  } 


  return 0;
}

bool Controller1UpDownButtonsControlMotorsStopped = true;
int rc_auto_loop_function_Controller1_backup() {
  bool hanging = false;

  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    std::cout << hanging;
    if(RemoteControlCodeEnabled) {
      // calculate the drivetrain motor velocities from the controller joystick axies
      // left = Axis3 + Axis1
      // right = Axis3 - Axis1
      int drivetrainLeftSideSpeed = Controller1.Axis3.position() + Controller1.Axis1.position();
      int drivetrainRightSideSpeed = Controller1.Axis3.position() - Controller1.Axis1.position();


    if(Controller1.ButtonA.pressing()){
      hanging = false;
    }

    
    if(Controller1.ButtonB.pressing()){
      hanging = true;
    }

    

if (hanging){
  bool DrivetrainNeedsToBeStopped_Controller1 = true;
  bool HangingNeedsToBeStopped = true;
     int HangingSpeed = Controller1.Axis3.position();
      drivetrainLeftSideSpeed = Controller1.Axis2.position() + Controller1.Axis1.position();
      drivetrainRightSideSpeed = Controller1.Axis2.position() - Controller1.Axis1.position();

          if (HangingSpeed < 5 && HangingSpeed > -5) {
        // check if the left motor has already been stopped
        if (HangingNeedsToBeStopped) {
          // stop the left drive motor
        leftMotorB.stop();
        leftMotorC.stop();
        rightMotorA.stop();
        rightMotorB.stop();
          // tell the code that the left motor has been stopped
          HangingNeedsToBeStopped = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the left motor nexttime the input is in the deadband range
        HangingNeedsToBeStopped = true;
      }

          if (HangingNeedsToBeStopped) {
        leftMotorB.setVelocity(HangingSpeed,percent);
        leftMotorC.setVelocity(HangingSpeed,percent);
        rightMotorA.setVelocity(HangingSpeed,percent);
        rightMotorB.setVelocity(HangingSpeed,percent);
        leftMotorB.spin(forward);
        leftMotorC.spin(forward);
        rightMotorA.spin(forward);
        rightMotorB.spin(forward);
     
      }




        if (abs(drivetrainLeftSideSpeed) < 5 && abs(drivetrainRightSideSpeed) < 5) {
        // check if the motors have already been stopped
        if (DrivetrainNeedsToBeStopped_Controller1) {
          // stop the drive motors
          leftMotorA.stop();
          rightMotorC.stop();
          // tell the code that the motors have been stopped
          DrivetrainNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the motors next time the input is in the deadband range
        DrivetrainNeedsToBeStopped_Controller1 = true;
      }
      
      // only tell the left drive motor to spin if the values are not in the deadband range
      if (DrivetrainNeedsToBeStopped_Controller1) {
        leftMotorA.setVelocity(drivetrainLeftSideSpeed, percent);
        leftMotorA.spin(forward);
      }
      // only tell the right drive motor to spin if the values are not in the deadband range
      if (DrivetrainNeedsToBeStopped_Controller1) {
        rightMotorC.setVelocity(drivetrainRightSideSpeed, percent);
        rightMotorC.spin(forward);
      }



      if (Controller1.ButtonUp.pressing()) {
        
        leftMotorB.setVelocity(100,percent);
        leftMotorC.setVelocity(100,percent);
        rightMotorA.setVelocity(100,percent);
        rightMotorB.setVelocity(100,percent);

        leftMotorB.spin(forward);
        leftMotorC.spin(forward);
        rightMotorA.spin(forward);
        rightMotorB.spin(forward);

        Controller1UpDownButtonsControlMotorsStopped = false;
      } else if (Controller1.ButtonDown.pressing()) {
        leftMotorB.spin(reverse);
        leftMotorC.spin(reverse);
        rightMotorA.spin(reverse);
        rightMotorB.spin(reverse);
        Controller1UpDownButtonsControlMotorsStopped = false;
      } else if (!Controller1UpDownButtonsControlMotorsStopped) {
        leftMotorB.stop();
        leftMotorC.stop();
        rightMotorA.stop();
        rightMotorB.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1UpDownButtonsControlMotorsStopped = true;
      }


}

    else{
      int drivetrainLeftSideSpeed = Controller1.Axis3.position() + Controller1.Axis1.position();
      int drivetrainRightSideSpeed = Controller1.Axis3.position() - Controller1.Axis1.position();
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
      } else {
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
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1_backup);
}