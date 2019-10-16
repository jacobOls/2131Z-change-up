#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/ramping.hpp"

namespace drive{
  okapi::Motor left_back(15,false,okapi::AbstractMotor::gearset::green,
    okapi::AbstractMotor::encoderUnits::degrees);
    okapi::Motor left_front(14,true,okapi::AbstractMotor::gearset::green,
      okapi::AbstractMotor::encoderUnits::degrees);
      okapi::Motor right_back(11,true,okapi::AbstractMotor::gearset::green,
        okapi::AbstractMotor::encoderUnits::degrees);
        okapi::Motor right_front(13,false,okapi::AbstractMotor::gearset::green,
          okapi::AbstractMotor::encoderUnits::degrees);
          okapi::MotorGroup left_drive({left_back, left_front});
          okapi::MotorGroup right_drive({right_back, right_front});
          Ramping drive(1, -5,- 200, 200); //need to keep change msec the same; for now ... tasks

        }
        namespace tray{
          okapi::Motor motor(16,false,okapi::AbstractMotor::gearset::red,
            okapi::AbstractMotor::encoderUnits::degrees);
    Ramping tilt(1, 5, 50, -50);
          }

          namespace intake{
            okapi::Motor left_motor(17,false,okapi::AbstractMotor::gearset::green, //left
              okapi::AbstractMotor::encoderUnits::degrees);
              okapi::Motor right_motor(7,true,okapi::AbstractMotor::gearset::green, //right
                okapi::AbstractMotor::encoderUnits::degrees);

                okapi::MotorGroup intakegroup({left_motor, right_motor});
                pros::ADIAnalogIn cubeSensor(3);
              }
              namespace lift{
                okapi::Motor motor(1,false,okapi::AbstractMotor::gearset::red,
                  okapi::AbstractMotor::encoderUnits::degrees);
                  pros::ADIAnalogIn liftSensor(2);
                }
