#include "custom/settup/ramping.hpp"
#include "custom/settup/motors.hpp"
#include "main.h"
#include <math.h>

double timesLooped = 0;
ramping::ramping(double changeRate, double changeVal, int minimum,
                 int maximum) {

  rateOfChange = changeRate;
  changeValue = changeVal;
  min = minimum;
  max = maximum;
}

double vel;
void ramping::accelMath(rampMotor handler, okapi::MotorGroup *MotorGroup,
                        int requested) {

  vel = pow(changeValue, timesLooped);

  if (abs(vel) > abs(requested)) {
    vel = requested;
  }

  if (requested < 0) {
    vel = -abs(vel);
  }

  (*handler)(MotorGroup, vel);
  timesLooped++;
}

void ramping::deAccelMath(rampMotor handler, okapi::MotorGroup *MotorGroup,
                          int requested) {
  double vel = MotorGroup->getVoltage();
  if (abs(requested) > 0) {
    if (requested > 0) {
      vel -= changeValue * 90;
    } else {
      vel += changeValue * 90;
    }
  }
  if (abs(vel) < abs(requested)) {
    vel = requested;
  }

  (*handler)(MotorGroup, vel);
  timesLooped++;
}

void accel(okapi::MotorGroup *MotorGroup, int vel) {
  MotorGroup->moveVoltage(vel);
}

// ramping ramper = ramping(5, 5, -200, 200);
// example
// void pie() { ramper.accelMath(accel, &intake::intakeGroup, 200); }