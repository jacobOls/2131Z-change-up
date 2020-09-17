#include "custom/settup/ramping.hpp"
#include "main.h"
namespace drive {
okapi::Motor left_back(2, false, okapi::AbstractMotor::gearset::green,
                       okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor left_front(3, false, okapi::AbstractMotor::gearset::green,
                        okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor right_back(1, true, okapi::AbstractMotor::gearset::green,
                        okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor right_front(4, true, okapi::AbstractMotor::gearset::green,
                         okapi::AbstractMotor::encoderUnits::degrees);
okapi::MotorGroup left_drive({left_front, left_back});
okapi::MotorGroup right_drive({right_front, right_back});
okapi::MotorGroup left_strafe({left_front, right_back});
okapi::MotorGroup right_strafe({right_front, left_back});

ramping leftDrive = ramping(20, 3, -200, 200);
ramping rightDrive = ramping(20, 3, -200, 200);

} // end namespace drive
namespace intake {
okapi::Motor left_motor(17, false, okapi::AbstractMotor::gearset::green, // left
                        okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor right_motor(15, true,
                         okapi::AbstractMotor::gearset::green, // right
                         okapi::AbstractMotor::encoderUnits::degrees);

okapi::MotorGroup intakeGroup({left_motor, right_motor});

} // end namespace intake

namespace wheel {
okapi::Motor left_motor(20, true, okapi::AbstractMotor::gearset::green, // left
                        okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor right_motor(19, false,
                         okapi::AbstractMotor::gearset::green, // right
                         okapi::AbstractMotor::encoderUnits::degrees);

okapi::MotorGroup wheelGroup({left_motor, right_motor});

} // end namespace wheel
