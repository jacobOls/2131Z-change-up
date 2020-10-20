#include "custom/setup/ramping.hpp"
#include "main.h"
namespace drive {
okapi::Motor leftBack(2, false, okapi::AbstractMotor::gearset::green,
                      okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor leftFront(3, false, okapi::AbstractMotor::gearset::green,
                       okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor rightBack(1, true, okapi::AbstractMotor::gearset::green,
                       okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor rightFront(8, true, okapi::AbstractMotor::gearset::green,
                        okapi::AbstractMotor::encoderUnits::degrees);
okapi::MotorGroup left_drive({leftFront, leftBack});
okapi::MotorGroup right_drive({rightFront, rightBack});
okapi::MotorGroup left_strafe({leftFront, rightBack});
okapi::MotorGroup right_strafe({rightFront, leftBack});

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

namespace elevator {
okapi::Motor upperMotor(20, true, okapi::AbstractMotor::gearset::green, // left
                        okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor lowerMotor(19, false,
                        okapi::AbstractMotor::gearset::green, // right
                        okapi::AbstractMotor::encoderUnits::degrees);

okapi::MotorGroup elevGroup({upperMotor, lowerMotor});

} // namespace elevator
