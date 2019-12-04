#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/ramping.hpp"
namespace drive{
  okapi::Motor left_back(6, false, okapi::AbstractMotor::gearset::green,
    okapi::AbstractMotor::encoderUnits::degrees);
    okapi::Motor left_front(8, true, okapi::AbstractMotor::gearset::green,
      okapi::AbstractMotor::encoderUnits::degrees);
      okapi::Motor right_back(7, true, okapi::AbstractMotor::gearset::green,
        okapi::AbstractMotor::encoderUnits::degrees);
        okapi::Motor right_front(4, false, okapi::AbstractMotor::gearset::green,
          okapi::AbstractMotor::encoderUnits::degrees);
          okapi::MotorGroup left_drive({left_back, left_front});
          okapi::MotorGroup right_drive({right_back, right_front});
          okapi::MotorGroup right_strafe({left_back, right_front});
          okapi::MotorGroup left_strafe({right_back, left_front});
          Ramping LEFT_DRIVE(1, 10, 200, -200);
          Ramping RIGHT_DRIVE(1, 10, 200, -200);

        }

        namespace intake{
          okapi::Motor left_motor(20, false, okapi::AbstractMotor::gearset::green, //left
            okapi::AbstractMotor::encoderUnits::degrees);
            okapi::Motor right_motor(1, true, okapi::AbstractMotor::gearset::green, //right
              okapi::AbstractMotor::encoderUnits::degrees);

              okapi::MotorGroup intakegroup({left_motor, right_motor});
              // pros::ADIAnalogIn cubeSensor(2);

            } // namespace intake

            namespace tilter{
              okapi::Motor motor(3, false, okapi::AbstractMotor::gearset::red,
                okapi::AbstractMotor::encoderUnits::degrees);
                // pros::ADIAnalogIn tilterSensor(3);

              } // namespace tilter

              namespace lift{
                okapi::Motor motor(2, false, okapi::AbstractMotor::gearset::red,
                  okapi::AbstractMotor::encoderUnits::degrees);
                  // pros::ADIAnalogIn liftSensor(1);

                } // namespace lift
