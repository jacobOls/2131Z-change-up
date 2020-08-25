#include "custom/systems/drive.hpp"
#include "custom/settup/controller.hpp"
#include "custom/settup/motors.hpp"
#include "main.h"
namespace drive {
State state = State::NONE;

void leftDriveStraight() {
  if (master.getAnalog(ControllerAnalog::leftY) >
          master.getAnalog(ControllerAnalog::leftX) &&
      master.getAnalog(ControllerAnalog::leftY) > 0.05) {
    State state = State::LEFTSTRAIGHT;
  } else if (state == State::LEFTSTRAIGHT) {
    State state = State::DEINIT;
  }
}

void rightDriveStraight() {
  if (master.getAnalog(ControllerAnalog::rightY) >
          master.getAnalog(ControllerAnalog::rightX) &&
      master.getAnalog(ControllerAnalog::rightY) > 0.05) {
    State state = State::RIGHTSTRAIGHT;
  } else if (state == State::RIGHTSTRAIGHT) {
    State state = State::DEINIT;
  }
}

void execute() {
  switch (state) {

  case State::NONE:
    break;

  case State::LEFTSTRAIGHT:
    left_drive.moveVelocity(master.getAnalog(ControllerAnalog::leftY) * 200);
    break;

  case State::LEFTSTRAFE:

    break;

  case State::RIGHTSTRAIGHT:
    right_drive.moveVelocity(master.getAnalog(ControllerAnalog::rightY) * 200);
    break;

  case State::RIGHTSTRAFE:

    break;

  case State::DEINIT:
    left_drive.moveVelocity(0);
    right_drive.moveVelocity(0);
    State state = State::NONE;
    break;
  }
}
void userDrive() {
  leftDriveStraight();
  rightDriveStraight();
}
} // namespace drive
