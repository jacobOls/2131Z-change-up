#ifndef MOTORS_HPP
#define MOTORS_HPP
#include "custom/settup/ramping.hpp"
#include "main.h"
namespace drive {
extern okapi::Motor left_back;
extern okapi::Motor left_front;
extern okapi::Motor right_back;
extern okapi::Motor right_front;
extern okapi::MotorGroup left_drive;
extern okapi::MotorGroup right_drive;
extern okapi::MotorGroup left_strafe;
extern okapi::MotorGroup right_strafe;

extern okapi::MotorGroup leftFront;
extern okapi::MotorGroup leftBack;
extern okapi::MotorGroup rightFront;
extern okapi::MotorGroup rightBack;

extern ramping accelDrive;
extern ramping deAccelDrive;
} // namespace drive
namespace intake {
extern okapi::Motor left_motor;
extern okapi::Motor right_motor;
extern okapi::MotorGroup intakeGroup;
} // namespace intake
namespace wheel {
extern okapi::Motor left_motor;
extern okapi::Motor right_motor;
extern okapi::MotorGroup wheelGroup;
} // namespace wheel
#endif /* end of include guard: MOTORS_HPP */
