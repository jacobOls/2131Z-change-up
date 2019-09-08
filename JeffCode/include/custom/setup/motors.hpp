#ifndef MOTORS_HPP
#define MOTORS_HPP
#include "okapi/api.hpp"
#include "custom/setup/ramping.hpp"
//port numbers
// RFPort = 18
// RBPort = 17
// LFPort = 16
// LBPort = 15

//controller
//drive motors
namespace drive
{
  extern okapi::Motor right_motor;
  extern okapi::Motor left_motor;


}
namespace lift
{
  extern okapi::Motor motor;
  extern okapi::Motor motor2;
  extern okapi::MotorGroup group2;
}
namespace intake
{

  extern okapi::Motor motor;
  extern okapi::Motor motor2;
  extern okapi::MotorGroup intakegroup;

}

namespace tilter
{
  extern okapi::Motor tiltmotor;
  extern Ramping tilt;

}
namespace clamp
{
extern okapi::Motor clampMotor;

}
#endif /* end of include guard: MOTORS_HPP */
