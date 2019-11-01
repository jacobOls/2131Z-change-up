#include "main.h"
#include "custom/setup/motors.hpp"

namespace drive
{
okapi::Motor left_back(19, true, okapi::AbstractMotor::gearset::green,
                       okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor left_front(17, false, okapi::AbstractMotor::gearset::green,
                        okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor right_back(16, true, okapi::AbstractMotor::gearset::green,
                        okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor right_front(18, false, okapi::AbstractMotor::gearset::green,
                         okapi::AbstractMotor::encoderUnits::degrees);
okapi::MotorGroup left_drive({left_back, left_front});
okapi::MotorGroup right_drive({right_back, right_front});
} // namespace drive

namespace intake
{
okapi::Motor left_motor(1, false, okapi::AbstractMotor::gearset::green, //left
                        okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor right_motor(3, true, okapi::AbstractMotor::gearset::green, //right
                         okapi::AbstractMotor::encoderUnits::degrees);

okapi::MotorGroup intakegroup({left_motor, right_motor});
pros::ADIAnalogIn cubeSensor(3);

} // namespace intake

namespace tilter
{
okapi::Motor motor(8, true, okapi::AbstractMotor::gearset::red,
                   okapi::AbstractMotor::encoderUnits::degrees);
pros::ADIAnalogIn tilterSensor(3);

} // namespace tilter

namespace lift
{
okapi::Motor motor(2, false, okapi::AbstractMotor::gearset::red,
                   okapi::AbstractMotor::encoderUnits::degrees);
pros::ADIAnalogIn liftSensor(3);

} // namespace lift
