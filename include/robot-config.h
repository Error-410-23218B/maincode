using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern drivetrain Drivetrain;
extern digital_out DigitalOutD;
extern digital_out DigitalOutH;
extern digital_out DigitalOutG; 
extern motor_group puncherMotorGroup;
extern motor rightMotorC;
extern motor leftMotorC;
extern motor leftMotorA;
extern motor rightMotorB;
extern motor leftMotorB;
extern motor rightMotorB;
extern motor rightMotorA;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
void autonomous();