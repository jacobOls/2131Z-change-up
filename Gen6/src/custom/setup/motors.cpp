#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/ramping.hpp"
namespace drive{
  okapi::Motor left_back(11, false, okapi::AbstractMotor::gearset::green,
    okapi::AbstractMotor::encoderUnits::degrees);
    okapi::Motor left_front(14, true, okapi::AbstractMotor::gearset::green,
      okapi::AbstractMotor::encoderUnits::degrees);
      okapi::Motor right_back(12, true, okapi::AbstractMotor::gearset::green,
        okapi::AbstractMotor::encoderUnits::degrees);
        okapi::Motor right_front(13, false, okapi::AbstractMotor::gearset::green,
          okapi::AbstractMotor::encoderUnits::degrees);
          okapi::MotorGroup left_drive({left_front, left_back});
          okapi::MotorGroup right_drive({right_front, right_back});
          Ramping LEFT_DRIVE(1, 10, 200, -200);
          Ramping RIGHT_DRIVE(1, 10, 200, -200);

          pros::ADIGyro gyro(10);


        }
//16 and 18 burned and 3
        namespace intake{
          okapi::Motor left_motor(2, false, okapi::AbstractMotor::gearset::green, //left
            okapi::AbstractMotor::encoderUnits::degrees);
            okapi::Motor right_motor(1, true, okapi::AbstractMotor::gearset::green, //right
              okapi::AbstractMotor::encoderUnits::degrees);

              okapi::MotorGroup intakegroup({left_motor, right_motor});
              pros::ADIAnalogIn cubeSensor(1);

            } // namespace intake

            namespace tilter{
              okapi::Motor motor(4, false, okapi::AbstractMotor::gearset::red,
                okapi::AbstractMotor::encoderUnits::degrees);
                Ramping TILTER(1, 10, 100, -100);
                // pros::ADIAnalogIn tilterSensor(3);

              } // namespace tilter

              namespace lift{
                okapi::Motor motor(5, true, okapi::AbstractMotor::gearset::red,
                  okapi::AbstractMotor::encoderUnits::degrees);
                  // pros::ADIAnalogIn liftSensor(1);

                } // namespace lift
