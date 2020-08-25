#include "custom/systems/drive.hpp"
#include "custom/settup/controller.hpp"
#include "custom/settup/motors.hpp"
#include "main.h"
namespace drive {
State state = State::NONE;

void leftDriveStraight() {
  if (abs(master.getAnalog(ControllerAnalog::leftY)) >
          abs(master.getAnalog(ControllerAnalog::leftX)) &&
      abs(master.getAnalog(ControllerAnalog::leftY)) > 0.05) {
    state = State::LEFTSTRAIGHT;
  } else if (state == State::LEFTSTRAIGHT) {
    state = State::DEINIT;
  }
}

void rightDriveStraight() {
  if (abs(master.getAnalog(ControllerAnalog::rightY)) >
          abs(master.getAnalog(ControllerAnalog::rightX)) &&
      abs(master.getAnalog(ControllerAnalog::rightY)) > 0.05) {
    state = State::RIGHTSTRAIGHT;
  } else if (state == State::RIGHTSTRAIGHT) {
    state = State::DEINIT;
  }
}

void leftStrafeDrive() {
  if (abs(master.getAnalog(ControllerAnalog::leftX)) >
          abs(master.getAnalog(ControllerAnalog::leftY)) &&
      abs(master.getAnalog(ControllerAnalog::leftX)) > 0.05) {
    state = State::LEFTSTRAFE;
  } else if (state == State::LEFTSTRAFE) {
    state = State::DEINIT;
  }
}

void rightStrafeDrive() {
  if (abs(master.getAnalog(ControllerAnalog::rightX)) >
          abs(master.getAnalog(ControllerAnalog::rightY)) &&
      abs(master.getAnalog(ControllerAnalog::rightX)) > 0.05) {
    state = State::RIGHTSTRAFE;
  } else if (state == State::RIGHTSTRAFE) {
    state = State::DEINIT;
  }
}

void execute() {
  switch (state) {

  case State::LEFTSTRAIGHT: {
    // std::cout << "left" << std::endl;
    left_drive.moveVelocity(master.getAnalog(ControllerAnalog::leftY) * 200);
    break;
  }

  case State::LEFTSTRAFE: {
    left_strafe.moveVelocity(master.getAnalog(ControllerAnalog::leftX) * 200);
    break;
  }

  case State::RIGHTSTRAIGHT: {
    // std::cout << "right" << std::endl;
    right_drive.moveVelocity(master.getAnalog(ControllerAnalog::rightY) * 200);
    break;
  }

  case State::RIGHTSTRAFE: {
    right_strafe.moveVelocity(master.getAnalog(ControllerAnalog::rightX) *
                              -200);
    break;
  }

  case State::DEINIT: {
    // std::cout << "deinit" << std::endl;
    left_drive.moveVelocity(0);
    right_drive.moveVelocity(0);
    State state = State::NONE;
    break;
  }

  case State::NONE: {
    std::cout << "none" << std::endl;
    break;
  }
  }
}
void userDrive() {
  // std::cout << "init" << std::endl;
  leftDriveStraight();
  rightDriveStraight();
  leftStrafeDrive();
  rightStrafeDrive();
  execute();
}
} // namespace drive
