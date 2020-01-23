#ifndef MOTORS_HPP
#define MOTORS_HPP
#include "main.h"
#include "custom/setup/ramping.hpp"
namespace drive{
  extern okapi::Motor left_back;
extern okapi::Motor left_front;
extern okapi::Motor right_back;
extern okapi::Motor right_front;
extern okapi::MotorGroup left_drive;
extern okapi::MotorGroup right_drive;
extern okapi::MotorGroup left_strafe;
extern okapi::MotorGroup right_strafe;
extern Ramping LEFT_DRIVE;
extern Ramping RIGHT_DRIVE;

}

namespace intake{
extern okapi::Motor left_motor;
extern okapi::Motor right_motor;
extern okapi::MotorGroup intakegroup;
// extern pros::ADIAnalogIn cubeSensor;
} // namespace intake

namespace tilter{
extern okapi::Motor motor;
// extern pros::ADIAnalogIn tilterSensor;
} // namespace tilter

namespace lift{
extern okapi::Motor motor;
// extern pros::ADIAnalogIn liftSensor;
} // namespace lift
#endif /* end of include guard: MOTORS_HPP */
