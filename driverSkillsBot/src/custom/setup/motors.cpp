#include "main.h"
namespace drive {
okapi::Motor lb1(1, false, okapi::AbstractMotor::gearset::blue,
                 okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor lb2(2, true, okapi::AbstractMotor::gearset::blue,
                 okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor lf1(4, false, okapi::AbstractMotor::gearset::blue,
                 okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor lf2(3, true, okapi::AbstractMotor::gearset::blue,
                 okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor rb1(13, false, okapi::AbstractMotor::gearset::blue,
                 okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor rb2(12, true, okapi::AbstractMotor::gearset::blue,
                 okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor rf1(15, true, okapi::AbstractMotor::gearset::blue,
                 okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor rf2(14, false, okapi::AbstractMotor::gearset::blue,
                 okapi::AbstractMotor::encoderUnits::degrees);

okapi::MotorGroup leftBack({lb1, lb2});
okapi::MotorGroup leftFront({lf1, lf2});
okapi::MotorGroup rightBack({rb1, rb2});
okapi::MotorGroup rightFront({rf1, rf2});

okapi::MotorGroup driveGroup({rf1, rf2, lf1, lf2, rb1, rb2, lb1, lb2});
} // end namespace drive
namespace intake {
okapi::Motor left_motor(10, false, okapi::AbstractMotor::gearset::green, // left
                        okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor right_motor(20, true,
                         okapi::AbstractMotor::gearset::green, // right
                         okapi::AbstractMotor::encoderUnits::degrees);

okapi::MotorGroup intakeGroup({left_motor, right_motor});
} // end namespace intake

namespace elevator {
okapi::Motor elevMotor(6, true, okapi::AbstractMotor::gearset::blue, // left
                       okapi::AbstractMotor::encoderUnits::degrees);

okapi::Motor elevMotor2(7, true,
                        okapi::AbstractMotor::gearset::blue, // right
                        okapi::AbstractMotor::encoderUnits::degrees);

okapi::MotorGroup elevGroup({elevMotor, elevMotor2});

} // namespace elevator
