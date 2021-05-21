#ifndef MOTORS_HPP
#define MOTORS_HPP
#include "main.h"
namespace drive {
extern okapi::MotorGroup leftBack;
extern okapi::MotorGroup leftFront;
extern okapi::MotorGroup rightBack;
extern okapi::MotorGroup rightFront;
extern okapi::MotorGroup driveGroup;
} // namespace drive
namespace intake {
extern okapi::Motor left_motor;
extern okapi::Motor right_motor;
extern okapi::MotorGroup intakeGroup;
} // namespace intake
namespace elevator {
extern okapi::Motor elevMotor;
extern okapi::MotorGroup elevGroup;

extern okapi::Motor elevMotor2;
} // namespace elevator

#endif /* end of include guard: MOTORS_HPP */
