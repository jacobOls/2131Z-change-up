#include "main.h"
#include "custom/setup/motors.hpp"

namespace drive{
  okapi::Motor left_back(11, false, okapi::AbstractMotor::gearset::green,
    okapi::AbstractMotor::encoderUnits::degrees);
    okapi::Motor left_front(13, true, okapi::AbstractMotor::gearset::green,
      okapi::AbstractMotor::encoderUnits::degrees);
      okapi::Motor right_back(19, true, okapi::AbstractMotor::gearset::green,
        okapi::AbstractMotor::encoderUnits::degrees);
        okapi::Motor right_front(18, false, okapi::AbstractMotor::gearset::green,
          okapi::AbstractMotor::encoderUnits::degrees);
          okapi::MotorGroup left_drive({left_back, left_front});
          okapi::MotorGroup right_drive({right_back, right_front});
          okapi::MotorGroup left_strafe({left_back, right_front});
          okapi::MotorGroup right_strafe({right_back, left_front});
        }
