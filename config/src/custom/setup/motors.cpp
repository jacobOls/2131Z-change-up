#include "main.h"
#include "custom/setup/motors.hpp"

namespace drive{
  okapi::Motor right_drive(20,false,okapi::AbstractMotor::gearset::green,
    okapi::AbstractMotor::encoderUnits::degrees);
    okapi::Motor left_drive(18,true,okapi::AbstractMotor::gearset::green,
      okapi::AbstractMotor::encoderUnits::degrees);


    }
    namespace claw{
      okapi::Motor motor(2,false,okapi::AbstractMotor::gearset::green,
        okapi::AbstractMotor::encoderUnits::degrees);

    }

    namespace arma{
      okapi::Motor motor(1,false,okapi::AbstractMotor::gearset::green,
        okapi::AbstractMotor::encoderUnits::degrees);

    }
