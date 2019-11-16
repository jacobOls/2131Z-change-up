#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/ramping.hpp"

namespace drive
{
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
Ramping LEFT_DRIVE(1, 12, 200, -200);
Ramping RIGHT_DRIVE(1, 12, 200, -200);
Ramping LEFT_MANUAL(1, 10, 200, -200);
Ramping RIGHT_MANUAL(1, 10, 200, -200);

} // namespace drive

namespace intake
{
okapi::Motor left_motor(9, false, okapi::AbstractMotor::gearset::green, //left
                        okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor right_motor(10, true, okapi::AbstractMotor::gearset::green, //right
                         okapi::AbstractMotor::encoderUnits::degrees);

okapi::MotorGroup intakegroup({left_motor, right_motor});
pros::ADIAnalogIn cubeSensor(2);

} // namespace intake

namespace tilter
{
okapi::Motor motor(15, true, okapi::AbstractMotor::gearset::red,
                   okapi::AbstractMotor::encoderUnits::degrees);
pros::ADIAnalogIn tilterSensor(3);

} // namespace tilter

namespace lift
{
okapi::Motor motor(1, false, okapi::AbstractMotor::gearset::red,
                   okapi::AbstractMotor::encoderUnits::degrees);
pros::ADIAnalogIn liftSensor(1);

} // namespace lift

namespace vision{
  pros::Vision vision (5);
}
