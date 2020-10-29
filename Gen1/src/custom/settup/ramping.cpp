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
                          int requested, int startVel) {
  if (vel < 0) {
    vel *= -1;
  }
  if (vel > .4 * abs(startVel)) {
    vel -= changeValue * timesLooped;
    if (vel < .4 * abs(startVel))
      vel = .4 * abs(startVel);
  } else if (vel > .3 * startVel && vel <= .5 * abs(startVel)) {
    vel -= changeValue;
  } else if (vel >= requested) {
    vel *= 0.7;
  }
  if (startVel < 0) {
    vel *= -1;
  }
  // std::cout << vel << std::endl;
  // cout<<timesLooped<<endl;
  (*handler)(MotorGroup, vel);
  timesLooped++;
}

void accel(okapi::MotorGroup *MotorGroup, int vel) {
  MotorGroup->moveVelocity(vel);
}

// ramping ramper = ramping(5, 5, -200, 200);
// example
// void pie() { ramper.accelMath(accel, &intake::intakeGroup, 200); }
