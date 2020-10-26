#include "custom/systems/drive.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "main.h"
namespace drive {

void userDrive() {
  leftFront.moveVelocity(
      (okapi::deadband(master.getAnalog(okapi::ControllerAnalog::leftY), -0.05,
                       0.05) +
       okapi::deadband(master.getAnalog(okapi::ControllerAnalog::leftX), -0.05,
                       0.05)) *
      200);
  leftBack.moveVelocity(
      (okapi::deadband(master.getAnalog(okapi::ControllerAnalog::leftY), -0.05,
                       0.05) -
       okapi::deadband(master.getAnalog(okapi::ControllerAnalog::leftX), -0.05,
                       0.05)) *
      200);

  rightFront.moveVelocity(
      (okapi::deadband(master.getAnalog(okapi::ControllerAnalog::rightY), -0.05,
                       0.05) -
       okapi::deadband(master.getAnalog(okapi::ControllerAnalog::rightX), -0.05,
                       0.05)) *
      200);
  rightBack.moveVelocity(
      (okapi::deadband(master.getAnalog(okapi::ControllerAnalog::rightY), -0.05,
                       0.05) +
       okapi::deadband(master.getAnalog(okapi::ControllerAnalog::rightX), -0.05,
                       0.05)) *
      200);
}
void brake() {
  if (BtnBrake.isPressed()) {
    drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  } else {
    drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  }
}
} // namespace drive

namespace auton {
int remDist;
void drive(int distance, int velocity) {
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
  while (abs(drive::leftFront.getPosition()) <= abs((distance)*7 / 10)) {
    drive::leftDrive.accelMath(accel, &drive::left_drive, velocity);
    drive::rightDrive.accelMath(accel, &drive::right_drive, velocity);
    pros::delay(drive::leftDrive.rateOfChange);
    // std::cout << "ramping" << std::endl;
    // std::cout << "looping" << std::endl;
  }
  // std::cout << "stopping" << std::endl;
  while (abs(drive::leftFront.getPosition()) <= abs(distance)) {
    remDist = distance - abs(drive::leftFront.getPosition());
    if (abs(remDist) > abs(velocity))
      remDist = velocity;
    if (velocity < 0 && remDist > 0)
      remDist *= -1;

    drive::leftDrive.deAccelMath(accel, &drive::left_drive, remDist);
    drive::rightDrive.deAccelMath(accel, &drive::right_drive, remDist);
    pros::delay(drive::leftDrive.rateOfChange);
  }
  std::cout << drive::left_drive.getPosition() << std::endl;
  drive::left_drive.moveVelocity(0);
  drive::right_drive.moveVelocity(0);
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
}

void driveNE(int distance, int velocity) {
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
  while (abs(drive::leftFront.getPosition()) <= abs(distance)) {
    drive::leftDrive.accelMath(accel, &drive::left_drive, velocity);
    drive::rightDrive.accelMath(accel, &drive::right_drive, velocity);
    pros::delay(drive::leftDrive.rateOfChange);
    // std::cout << "ramping" << std::endl;
    // std::cout << "looping" << std::endl;
  }
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
}
void strafe(int distance, int velocity, std::string direction) {
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();

  while (abs(drive::leftFront.getPosition()) <= abs(distance) * (7 / 10)) {

    if (direction == "right") {
      drive::leftDrive.accelMath(accel, &drive::left_strafe, velocity);
      drive::rightDrive.accelMath(accel, &drive::right_strafe, -velocity);
      pros::delay(drive::leftDrive.rateOfChange);
    }

    else if (direction == "left") {
      drive::leftDrive.accelMath(accel, &drive::left_strafe, -velocity);
      drive::rightDrive.accelMath(accel, &drive::right_strafe, velocity);
      pros::delay(drive::leftDrive.rateOfChange);
    }
  }
  while (abs(drive::leftFront.getPosition()) <= abs(distance)) {
    remDist = distance - abs(drive::leftFront.getPosition());
    if (abs(remDist) > abs(velocity))
      remDist = velocity;
    if (velocity < 0 && remDist > 0)
      remDist *= -1;
    if (direction == "right") {
      drive::leftDrive.deAccelMath(accel, &drive::left_strafe, remDist);
      drive::rightDrive.deAccelMath(accel, &drive::right_strafe, -remDist);
    } else if (direction == "left") {
      drive::leftDrive.deAccelMath(accel, &drive::left_strafe, -remDist);
      drive::rightDrive.deAccelMath(accel, &drive::right_strafe, remDist);
    }
    pros::delay(drive::leftDrive.rateOfChange);
  }
  std::cout << drive::leftFront.getPosition() << std::endl;
  drive::left_strafe.moveVelocity(0);
  drive::right_strafe.moveVelocity(0);
  drive::left_strafe.tarePosition();
  drive::right_strafe.tarePosition();
}

void timeStrafe(int voltage, int time, std::string direction) {
  if (direction == "right") {
    drive::left_strafe.moveVoltage(voltage);
    drive::right_strafe.moveVoltage(-voltage);
  } else if (direction == "left") {
    drive::left_strafe.moveVoltage(-voltage);
    drive::right_strafe.moveVoltage(voltage);
  }
  pros::delay(time);
  drive::right_strafe.moveVelocity(0);
  drive::left_strafe.moveVelocity(0);
  drive::left_strafe.tarePosition();
  drive::right_strafe.tarePosition();
}

void turn(int turnAmount, int velocity, std::string direction) {
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
  while (abs(drive::leftFront.getPosition()) <= abs(turnAmount) * (7 / 10)) {
    if (direction == "left") {
      drive::leftDrive.accelMath(accel, &drive::left_drive, -velocity);
      drive::rightDrive.accelMath(accel, &drive::right_drive, velocity);
      pros::delay(drive::leftDrive.rateOfChange);
    }

    else if (direction == "right") {
      drive::leftDrive.accelMath(accel, &drive::left_drive, velocity);
      drive::rightDrive.accelMath(accel, &drive::right_drive, -velocity);
      pros::delay(drive::leftDrive.rateOfChange);
    }
  }
  while (abs(drive::leftFront.getPosition()) <= abs(turnAmount) - 2) {
    remDist = turnAmount - abs(drive::leftFront.getPosition());
    if (abs(remDist) > abs(velocity))
      remDist = velocity;
    if (direction == "left") {
      drive::leftDrive.deAccelMath(accel, &drive::left_drive, -remDist);
      drive::rightDrive.deAccelMath(accel, &drive::right_drive, remDist);
    } else if (direction == "right") {
      drive::leftDrive.deAccelMath(accel, &drive::left_drive, remDist);
      drive::rightDrive.deAccelMath(accel, &drive::right_drive, -remDist);
    }
    pros::delay(drive::leftDrive.rateOfChange);
  }
  std::cout << drive::left_drive.getPosition() << std::endl;
  drive::left_drive.moveVelocity(0);
  drive::right_drive.moveVelocity(0);
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
}

} // namespace auton
