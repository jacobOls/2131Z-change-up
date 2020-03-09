#include "custom/setup/ramping.hpp"
#include "custom/setup/motors.hpp"
#include "main.h"
#include <math.h>

ramping::ramping(double changeRate, double changeVal, int minimum,
                 int maximum) {

  rateOfChange = changeRate;
  changeVal = changeVal;
  min = minimum;
  max = maximum;
}

void ramping::accelMath(rampMotor handler, okapi::MotorGroup *MotorGroup,
                        int requested) {
  int i = 1; // initial velocity
  double vel = 1;
  if (vel > abs(requested)) {
    vel = requested;
  }

  vel = pow(changeVal, timesLooped);

  if (requested < 0) {
    vel = -vel;
  }

  (*handler)(MotorGroup, vel);
  pros::delay(rateOfChange);
}

void ramping::deAccelMath(rampMotor handler, okapi::MotorGroup *MotorGroup,
                          int requested) {
  double vel = MotorGroup->getActualVelocity();
  vel -= changeVal * 2;
  if (vel < abs(requested)) {
    vel = requested;
  }
  (*handler)(MotorGroup, vel);
}

void accel(okapi::MotorGroup *MotorGroup, int vel) {
  MotorGroup->moveVelocity(vel);
}

// ramping ramper = ramping(5, 5, -200, 200);
// example
// void pie() { ramper.accelMath(accel, &lift::motor, 200); }
