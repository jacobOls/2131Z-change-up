#include "custom/systems/drive.hpp"
#include "custom/settup/controller.hpp"
#include "custom/settup/motors.hpp"
#include "main.h"
namespace drive {
Left left = Left::NONE;
Right right = Right::NONE;
bool inBrake = false;

void brake() {
  if (BtnBrake.isPressed() && inBrake == false) {
    left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
    right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
    inBrake = true;
  } else if (BtnBrake.isPressed()) {
    left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  }
}

void leftStraight() {
  if (abs(master.getAnalog(ControllerAnalog::leftY)) >
          abs(master.getAnalog(ControllerAnalog::leftX)) &&
      abs(master.getAnalog(ControllerAnalog::leftY)) > 0.05) {
    left = Left::STRAIGHT;
  } else if (left == Left::STRAIGHT) {
    left_drive.moveVelocity(0);
    left = Left::NONE;
  }
}

void rightStraight() {
  if (abs(master.getAnalog(ControllerAnalog::rightY)) >
          abs(master.getAnalog(ControllerAnalog::rightX)) &&
      abs(master.getAnalog(ControllerAnalog::rightY)) > 0.05) {
    right = Right::STRAIGHT;
  } else if (right == Right::STRAIGHT) {
    right_drive.moveVelocity(0);
    right = Right::NONE;
  }
}

void leftStrafe() {
  if (abs(master.getAnalog(ControllerAnalog::leftX)) >
          abs(master.getAnalog(ControllerAnalog::leftY)) &&
      abs(master.getAnalog(ControllerAnalog::leftX)) > 0.05) {
    left = Left::STRAFE;
  } else if (left == Left::STRAFE) {
    left_strafe.moveVelocity(0);
    left = Left::NONE;
  }
}

void rightStrafe() {
  if (abs(master.getAnalog(ControllerAnalog::rightX)) >
          abs(master.getAnalog(ControllerAnalog::rightY)) &&
      abs(master.getAnalog(ControllerAnalog::rightX)) > 0.05) {
    right = Right::STRAFE;
  } else if (right == Right::STRAFE) {
    right_strafe.moveVelocity(0);
    right = Right::NONE;
  }
}

void execute() {
  switch (right) {

  case Right::STRAIGHT:
    right_drive.moveVelocity(master.getAnalog(ControllerAnalog::rightY) * 200);
    break;

  case Right::STRAFE:
    right_strafe.moveVelocity(master.getAnalog(ControllerAnalog::rightX) *
                              -200);

    break;

  case Right::NONE:
    break;
  }

  switch (left) {

  case Left::STRAIGHT:
    left_drive.moveVelocity(master.getAnalog(ControllerAnalog::leftY) * 200);
    break;

  case Left::STRAFE:
    left_strafe.moveVelocity(master.getAnalog(ControllerAnalog::leftX) * 200);
    break;

  case Left::NONE:
    break;
  }
}
void userDrive() {
  // std::cout << "init" << std::endl;
  leftStraight();
  rightStraight();
  leftStrafe();
  rightStrafe();
  brake();
  execute();
}
} // namespace drive
