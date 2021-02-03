#ifndef MOTORS_HPP
#define MOTORS_HPP
#include "custom/setup/ramping.hpp"
#include "main.h"
namespace drive {
extern okapi::Motor leftBack;
extern okapi::Motor leftFront;
extern okapi::Motor rightBack;
extern okapi::Motor rightFront;
extern okapi::MotorGroup left_drive;
extern okapi::MotorGroup right_drive;
extern okapi::MotorGroup left_strafe;
extern okapi::MotorGroup right_strafe;
extern okapi::MotorGroup driveGroup;
extern ramping accelDrive;
extern ramping deAccelDrive;
} // namespace drive
namespace intake {
extern okapi::Motor left_motor;
extern okapi::Motor right_motor;
extern okapi::MotorGroup intakeGroup;
} // namespace intake
namespace elevator {
extern okapi::Motor elevMotor;
extern okapi::Motor ratchetMotor;
extern okapi::MotorGroup elevGroup;
} // namespace elevator
extern pros::Optical opt;
#endif /* end of include guard: MOTORS_HPP */
