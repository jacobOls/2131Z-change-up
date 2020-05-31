#ifndef MOTORS_HPP
#define MOTORS_HPP
#include "main.h"
namespace drive {
extern okapi::Motor left_back;
extern okapi::Motor left_front;
extern okapi::Motor right_back;
extern okapi::Motor right_front;
extern okapi::MotorGroup left_drive;
extern okapi::MotorGroup right_drive;

} // namespace drive

namespace intakeGroup1 {
extern okapi::Motor left_motor;
extern okapi::Motor right_motor;
extern okapi::MotorGroup intakegroup;
} // namespace intake
namespace intakeGroup2 {
extern okapi::Motor left_motor;
extern okapi::Motor right_motor;
extern okapi::MotorGroup intakegroup;
} // namespace intake2
#endif /* end of include guard: MOTORS_HPP */
