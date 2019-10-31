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
}

namespace intake{
  extern okapi::Motor left_motor;
  extern okapi::Motor right_motor;
  extern okapi::MotorGroup intakegroup;
  extern pros::ADIAnalogIn cubeSensor;
}

namespace tilter{
  extern okapi::Motor motor;
  extern pros::ADIAnalogIn tilterSensor;
}

namespace lift{
  extern okapi::Motor motor;
  extern pros::ADIAnalogIn liftSensor;
}


#endif /* end of include guard: MOTORS_HPP */
