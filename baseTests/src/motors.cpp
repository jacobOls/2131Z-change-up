#include "main.h"

namespace drive {
okapi::Motor left_back(1, false, okapi::AbstractMotor::gearset::green,
                       okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor left_front(2, true, okapi::AbstractMotor::gearset::green,
                        okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor right_back(3, true, okapi::AbstractMotor::gearset::green,
                        okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor right_front(4, false, okapi::AbstractMotor::gearset::green,
                         okapi::AbstractMotor::encoderUnits::degrees);
                         okapi::MotorGroup left_drive({left_front, left_back});
                         okapi::MotorGroup right_drive({right_front, right_back});

} // namespace drive
namespace intakeGroup1 {
okapi::Motor left_motor(5, false, okapi::AbstractMotor::gearset::green, // left
                        okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor right_motor(6, true, okapi::AbstractMotor::gearset::green, // right
                         okapi::AbstractMotor::encoderUnits::degrees);

okapi::MotorGroup intakegroup({left_motor, right_motor});

} // namespace intake


namespace intakeGroup2 {
okapi::Motor left_motor(9, false, okapi::AbstractMotor::gearset::green, // left
                        okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor right_motor(11, false, okapi::AbstractMotor::gearset::green, // right
                         okapi::AbstractMotor::encoderUnits::degrees);

okapi::MotorGroup intakegroup({left_motor, right_motor});

} // namespace intake2
