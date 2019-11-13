#ifndef MOTORS_HPP
#define MOTORS_HPP
#include "main.h"
namespace drive{
  extern okapi::Motor left_back;
extern okapi::Motor left_front;
extern okapi::Motor right_back;
extern okapi::Motor right_front;
extern okapi::MotorGroup left_drive;
extern okapi::MotorGroup right_drive;
extern okapi::MotorGroup left_strafe;
extern okapi::MotorGroup right_strafe;
}

#endif /* end of include guard: MOTORS_HPP */
