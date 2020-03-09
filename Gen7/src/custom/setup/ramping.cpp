#include "custom/setup/ramping.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/lift.hpp"
#include "main.h"

ramping::ramping(double changeRate, double changeVal, int minimum,
                 int maximum) {

  roc = changeRate;
  cv = changeVal;
  min = minimum;
  max = maximum;
}

void ramping::accelMath(rampMotor handler, okapi::Motor *motor, int requested) {
  int i = 1; // initial velocity
  int t = 0; // times looped
  double vel = 1;
  for (vel = i; vel < requested; vel = i + cv ^ t) {
    if (vel > requested) {
      vel = requested;
      break;
    }
    t++;
    (*handler)(motor, requested);
    pros::delay(roc);
  }
}

void accel(okapi::Motor *motor, int requested) {
  motor->moveVelocity(requested);
}

// ramping ramper = ramping(5, 5, -200, 200);
//
// void pie() { ramper.accelMath(accel, &lift::motor, 200); }
