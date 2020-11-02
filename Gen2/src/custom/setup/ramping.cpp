#include "custom/setup/ramping.hpp"
#include "custom/setup/motors.hpp"
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

  // if (vel == requested) {
  //   timesLooped = 0;
  // }
  (*handler)(MotorGroup, vel);
  timesLooped++;
  // if (vel == requested) {
  //   timesLooped = 0;
  // }
}
bool velTrue = false;
void ramping::deAccelMath(rampMotor handler, okapi::MotorGroup *MotorGroup,
                          int requested, int startVel) {
  if (!velTrue) {
    vel = startVel;
    velTrue = true;
  }
  if (startVel < 0) {
    vel *= -1;
  }
  if (vel > .6 * abs(startVel)) {
    vel -= changeValue * timesLooped;
    if (vel < .6 * abs(startVel))
      vel = .6 * abs(startVel);
  } else if (vel > .32 * startVel && vel <= .6 * abs(startVel)) {
    vel -= changeValue;
  } else if (vel >= requested) {
    vel *= 0.7;
  }
  if (startVel < 0) {
    vel *= -1;
  }
  if (abs(drive::driveGroup.getActualVelocity()) < abs(requested)) {
    vel = requested;
  }
  // std::cout << vel << std::endl;
  // cout<<timesLooped<<endl;
  (*handler)(MotorGroup, vel);
  pros::delay(changeValue);
  timesLooped++;
}
void reset() {
  timesLooped = 0;
  velTrue = false;
}
void accel(okapi::MotorGroup *MotorGroup, int vel) {
  MotorGroup->moveVelocity(vel);
}

// ramping ramper = ramping(5, 5, -200, 200);
// example
// void pie() { ramper.accelMath(accel, &intake::intakeGroup, 200); }
