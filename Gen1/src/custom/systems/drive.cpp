#include "custom/systems/drive.hpp"
#include "custom/settup/controller.hpp"
#include "custom/settup/motors.hpp"
#include "main.h"
namespace drive {
Left left = Left::NONE;
Right right = Right::NONE;
Brake brake = Brake::NONE;
void leftStraight() {
  if (abs(master.getAnalog(ControllerAnalog::leftY)) >
          abs(master.getAnalog(ControllerAnalog::leftX)) + 0.01 &&
      abs(master.getAnalog(ControllerAnalog::leftY)) > 0.05) {
    left = Left::STRAIGHT;
  } else if (left == Left::STRAIGHT) {
    left_drive.moveVelocity(0);
    left = Left::DEINIT;
  }
}

void rightStraight() {
  if (abs(master.getAnalog(ControllerAnalog::rightY)) >
          abs(master.getAnalog(ControllerAnalog::rightX)) + 0.01 &&
      abs(master.getAnalog(ControllerAnalog::rightY)) > 0.05) {
    right = Right::STRAIGHT;
  } else if (right == Right::STRAIGHT) {
    right_drive.moveVelocity(0);
    right = Right::DEINIT;
  }
}

void leftStrafe() {
  if (abs(master.getAnalog(ControllerAnalog::leftX)) >
          abs(master.getAnalog(ControllerAnalog::leftY)) + 0.01 &&
      abs(master.getAnalog(ControllerAnalog::leftX)) > 0.05) {
    left = Left::STRAFE;
  } else if (left == Left::STRAFE) {
    left_strafe.moveVelocity(0);
    left = Left::DEINIT;
  }
}

void rightStrafe() {
  if (abs(master.getAnalog(ControllerAnalog::rightX)) >
          abs(master.getAnalog(ControllerAnalog::rightY)) + 0.01 &&
      abs(master.getAnalog(ControllerAnalog::rightX)) > 0.05) {
    right = Right::STRAFE;
  } else if (right == Right::STRAFE) {
    right_strafe.moveVelocity(0);
    right = Right::DEINIT;
  }
}
void driveBrake() {
  if (BtnBrake.isPressed()) {
    drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  } else {
    drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  }
}
void execute() {

  switch (left) {

  case Left::STRAIGHT:
    left_drive.moveVelocity(master.getAnalog(ControllerAnalog::leftY) * 200);
    break;

  case Left::STRAFE:
    left_strafe.moveVelocity(master.getAnalog(ControllerAnalog::leftX) * 200);
    break;

  case Left::DEINIT:
    left = Left::NONE;
    break;

  case Left::NONE:
    break;
  }
  switch (right) {

  case Right::STRAIGHT:
    right_drive.moveVelocity(master.getAnalog(ControllerAnalog::rightY) * 200);
    break;

  case Right::STRAFE:
    right_strafe.moveVelocity(master.getAnalog(ControllerAnalog::rightX) *
                              -200);

    break;

  case Right::DEINIT:
    right = Right::NONE;
    break;

  case Right::NONE:
    break;
  }
}
void userDrive() {
  // std::cout << "init" << std::endl;
  leftStraight();
  rightStraight();
  leftStrafe();
  rightStrafe();
  driveBrake();
  execute();
}
} // namespace drive

namespace auton {

void drive(int distance, int velocity) {
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
  while (abs(drive::left_front.getPosition()) <= abs(distance)) {
    drive::leftDrive.accelMath(accel, &drive::left_drive, velocity);
    drive::rightDrive.accelMath(accel, &drive::right_drive, velocity);
    pros::delay(drive::leftDrive.rateOfChange);
    // std::cout << "ramping" << std::endl;
    // std::cout << "looping" << std::endl;
  }
  // std::cout << "stopping" << std::endl;
  while (abs(drive::left_front.getActualVelocity()) > 0) {
    drive::leftDrive.deAccelMath(accel, &drive::left_drive, 0);
    drive::rightDrive.deAccelMath(accel, &drive::right_drive, 0);
    // drive::left_drive.moveVelocity(0);
    // drive::right_drive.moveVelocity(0);
    pros::delay(drive::leftDrive.rateOfChange);
  }
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
}
void strafe(int distance, int velocity, std::string direction) {
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
  while (abs(drive::left_front.getPosition()) <= abs(distance)) {

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
  while (abs(drive::left_front.getActualVelocity()) > 0) {
    drive::leftDrive.deAccelMath(accel, &drive::left_strafe, 0);
    drive::rightDrive.deAccelMath(accel, &drive::right_strafe, 0);
    pros::delay(drive::leftDrive.rateOfChange);
  }
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

  while (abs(drive::left_front.getPosition()) <= abs(turnAmount)) {
    if (direction == "left") {
      drive::left_drive.moveVelocity(-velocity);
      drive::right_drive.moveVelocity(velocity);
    }

    else if (direction == "right") {
      drive::right_drive.moveVelocity(-velocity);
      drive::left_drive.moveVelocity(velocity);
    }
  }
  while (drive::left_front.getActualVelocity() > 0) {
    drive::right_strafe.moveVelocity(0);
    drive::left_strafe.moveVelocity(0);
  }
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
}

} // namespace auton
