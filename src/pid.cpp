// pid.cpp
#include "pid.h"

eftl::PIDController::PIDController(double ikP, double ikI, double ikD, double ikF):
kP(ikP),kI(ikI),kD(ikD),kF(ikF)//member initialisation list.
{}

double eftl::PIDController::step(double isetpoint, double process_variable)
{
  // error is difference between setpoint and the actual sensor value
  double error = isetpoint - process_variable;
  // integral is accumulation of error
  integral += error;
  // Integral capped if it is higher than setpoint
  if (integral > isetpoint)
  {
    integral = 0;
  }
  // derivative is error - error from previous cycle
  derivative = error - prevError;
  // update error and store in prevError
  prevError = error;
  // calculate power via multiplying all values together
  Power = isetpoint * kF + error * kP + integral * kI + derivative * kD;
  // return
  return Power;
}