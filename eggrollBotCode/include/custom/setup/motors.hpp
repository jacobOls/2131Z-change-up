#ifndef MOTORS_HPP
#define MOTORS_HPP
#include "main.h"
#include "custom/setup/ramping.hpp"
namespace drive
{
  extern okapi::Motor left_back;
  extern okapi::Motor left_front;
  extern okapi::Motor right_back;
  extern okapi::Motor right_front;
  extern okapi::MotorGroup left_drive;
  extern okapi::MotorGroup right_drive;
  extern Ramping drive;

}
namespace tray
{
  extern okapi::Motor motor;

}
namespace intake
{

  extern okapi::Motor left_motor;
  extern okapi::Motor right_motor;
  extern okapi::MotorGroup intakegroup;

}
namespace lift
{
  extern okapi::Motor motor;

}
#endif /* end of include guard: MOTORS_HPP */
