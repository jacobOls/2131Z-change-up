#ifndef RAMPING_HPP
#define RAMPING_HPP
#include "main.h"
class ramping {

  typedef void (*rampMotor)(okapi::Motor *, int);

public:
  int roc; // rate of change
  int cv;  // change value
  int min, max;

  ramping(double changeRate, double changeVal, int minimum, int maximum);

  void accelMath(rampMotor handler, okapi::Motor *motor, int requested);
};
void accel(okapi::Motor *motor, int requested);

#endif /* end of include guard: RAMPING_HPP */
