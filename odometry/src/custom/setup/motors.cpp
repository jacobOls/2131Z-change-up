#include "custom/setup/ramping.hpp"
#include "main.h"
namespace drive {
okapi::Motor leftBack(12, false, okapi::AbstractMotor::gearset::green,
                      okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor leftFront(15, false, okapi::AbstractMotor::gearset::green,
                       okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor rightBack(3, true, okapi::AbstractMotor::gearset::green,
                       okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor rightFront(11, true, okapi::AbstractMotor::gearset::green,
                        okapi::AbstractMotor::encoderUnits::degrees);
okapi::MotorGroup left_drive({leftFront, leftBack});
okapi::MotorGroup right_drive({rightFront, rightBack});
okapi::MotorGroup left_strafe({leftFront, rightBack});
okapi::MotorGroup right_strafe({rightFront, leftBack});

okapi::MotorGroup driveGroup({rightFront, rightBack, leftFront, leftBack});

ramping accelDrive = ramping(15, 2, -200, 200);
ramping deAccelDrive = ramping(6, 2, -200, 200);
} // end namespace drive
namespace intake {
okapi::Motor left_motor(14, false, okapi::AbstractMotor::gearset::green, // left
                        okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor right_motor(17, true,
                         okapi::AbstractMotor::gearset::green, // right
                         okapi::AbstractMotor::encoderUnits::degrees);

okapi::MotorGroup intakeGroup({left_motor, right_motor});
} // end namespace intake

namespace elevator {
okapi::Motor elevMotor(16, false, okapi::AbstractMotor::gearset::blue, // left
                       okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor ratchetMotor(21, true,
                          okapi::AbstractMotor::gearset::blue, // right
                          okapi::AbstractMotor::encoderUnits::degrees);

okapi::MotorGroup elevGroup({elevMotor, ratchetMotor});

} // namespace elevator
