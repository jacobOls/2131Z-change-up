#ifndef RAMPING_HPP
#define RAMPING_HPP
#include "main.h"
extern double timesLooped; // times looped

class ramping {

  typedef void (*rampMotor)(okapi::MotorGroup *, int);

public:
  double rateOfChange; // rate of change
  double changeVal;    // change value
  int min, max;

  ramping(double changeRate, double changeVal, int minimum, int maximum);

  void accelMath(rampMotor handler, okapi::MotorGroup *MotorGroup,
                 int requested);

  void deAccelMath(rampMotor handler, okapi::MotorGroup *MotorGroup,
                   int requested);
};
void accel(okapi::MotorGroup *MotorGroup, int requested);

#endif /* end of include guard: RAMPING_HPP */
