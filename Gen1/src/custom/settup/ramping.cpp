#include "custom/settup/ramping.hpp"
#include "custom/settup/motors.hpp"
#include "main.h"
#include <math.h>

double timesLooped = 0;
ramping::ramping(double changeRate, double changeVal, int minimum,
                 int maximum) {

  rateOfChange = changeRate;
  changeVal = changeVal;
  min = minimum;
  max = maximum;
}

double vel;
void ramping::accelMath(rampMotor handler, okapi::MotorGroup *MotorGroup,
                        int requested) {

  vel = pow(3, timesLooped);

  if (vel > abs(requested)) {
    vel = requested;
  }

  if (requested < 0) {
    vel = -vel;
  }

  (*handler)(MotorGroup, vel);
  timesLooped++;
}

void ramping::deAccelMath(rampMotor handler, okapi::MotorGroup *MotorGroup,
                          int requested) {
  double vel = MotorGroup->getActualVelocity();
  vel -= 3 * 15;
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
// void pie() { ramper.accelMath(accel, &intake::intakeGroup, 200); }
