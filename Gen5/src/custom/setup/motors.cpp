#include "main.h"
#include "custom/setup/motors.hpp"

namespace drive{
  okapi::Motor left_back(2, false, okapi::AbstractMotor::gearset::green,
    okapi::AbstractMotor::encoderUnits::degrees);
    okapi::Motor left_front(4, false, okapi::AbstractMotor::gearset::green,
      okapi::AbstractMotor::encoderUnits::degrees);
      okapi::Motor right_back(1, true, okapi::AbstractMotor::gearset::green,
        okapi::AbstractMotor::encoderUnits::degrees);
        okapi::Motor right_front(5, true, okapi::AbstractMotor::gearset::green,
          okapi::AbstractMotor::encoderUnits::degrees);
          okapi::MotorGroup left_drive({left_back, left_front});
          okapi::MotorGroup right_drive({right_back, right_front});
          okapi::MotorGroup left_strafe({left_back, right_front});
          okapi::MotorGroup right_strafe({right_back, left_front});
        }

        namespace intake
        {
          okapi::Motor left_motor(8, false, okapi::AbstractMotor::gearset::green, //left
            okapi::AbstractMotor::encoderUnits::degrees);
            okapi::Motor right_motor(7, true, okapi::AbstractMotor::gearset::green, //right
              okapi::AbstractMotor::encoderUnits::degrees);

              okapi::MotorGroup intakegroup({left_motor, right_motor});
              // pros::ADIAnalogIn cubeSensor(2);

            } // namespace intake

            namespace tilter
            {
              okapi::Motor motor(3, false, okapi::AbstractMotor::gearset::red,
                okapi::AbstractMotor::encoderUnits::degrees);
                // pros::ADIAnalogIn tilterSensor(3);

              } // namespace tilter

              namespace lift
              {
                okapi::Motor motor(6, false, okapi::AbstractMotor::gearset::red,
                  okapi::AbstractMotor::encoderUnits::degrees);
                  // pros::ADIAnalogIn liftSensor(1);

                } // namespace lift
