#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/ramping.hpp"
//sets motors
namespace drive
{
  okapi::Motor right_motor(1,true,okapi::AbstractMotor::gearset::red,
    okapi::AbstractMotor::encoderUnits::degrees);
    okapi::Motor left_motor(10,false, okapi::AbstractMotor::gearset::red,
      okapi::AbstractMotor::encoderUnits::degrees);



    }
    namespace lift
    {
      okapi::Motor motor(3,true,okapi::AbstractMotor::gearset::red, //right
        okapi::AbstractMotor::encoderUnits::degrees);
        okapi::Motor motor2(8,false,okapi::AbstractMotor::gearset::red, //left
          okapi::AbstractMotor::encoderUnits::degrees);

          okapi::MotorGroup group2({motor, motor2});
        }

        namespace intake
        {
          okapi::Motor motor(12,true,okapi::AbstractMotor::gearset::green, //left
            okapi::AbstractMotor::encoderUnits::degrees);
            okapi::Motor motor2(9,false,okapi::AbstractMotor::gearset::green, //right
              okapi::AbstractMotor::encoderUnits::degrees);

              okapi::MotorGroup intakegroup({motor, motor2});
            }

            namespace tilter
            {
              okapi::Motor tiltmotor(6,false,okapi::AbstractMotor::gearset::red,
                okapi::AbstractMotor::encoderUnits::degrees);
                Ramping tilt(1, 5, 50, -50); //need to keep change msec the same; for now ... tasks

              }
              namespace clamp
              {
                okapi::Motor clampMotor(2,false,okapi::AbstractMotor::gearset::red,
                  okapi::AbstractMotor::encoderUnits::degrees);


              }
