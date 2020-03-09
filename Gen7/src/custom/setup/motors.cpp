#include "custom/setup/motors.hpp"
#include "custom/setup/ramping.hpp"
#include "main.h"
namespace drive {
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
okapi::MotorGroup driveAll({right_front, right_back, left_front, left_back});

} // namespace drive
namespace intake {
okapi::Motor left_motor(2, false, okapi::AbstractMotor::gearset::green, // left
                        okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor right_motor(1, true, okapi::AbstractMotor::gearset::green, // right
                         okapi::AbstractMotor::encoderUnits::degrees);

okapi::MotorGroup intakegroup({left_motor, right_motor});

} // namespace intake

namespace tilter {
okapi::Motor motor(4, false, okapi::AbstractMotor::gearset::red,
                   okapi::AbstractMotor::encoderUnits::degrees);

} // namespace tilter

namespace lift {
okapi::Motor motor(5, true, okapi::AbstractMotor::gearset::red,
                   okapi::AbstractMotor::encoderUnits::degrees);

} // namespace lift
