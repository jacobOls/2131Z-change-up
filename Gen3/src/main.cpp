#include "main.h"
#include "custom/auton/selection.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/drive.hpp"
#include "custom/systems/elevator.hpp"
#include "custom/systems/intake.hpp"
pros::Rotation rTracker(7);
void initialize() {
  selection::init();
  elevator::initVision();
  intake::intakeGroup.tarePosition();
  rTracker.set_position(0);
}

void disabled() {
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  rTracker.set_position(0);
}

void competition_initialize() {}
okapi::ControllerButton autosdf = master[okapi::ControllerDigital::X];
bool asdf = false;
void foo() {
  if (autosdf.changedToPressed()) {
    if (asdf == true)
      asdf = false;
    else if (asdf == false)
      asdf = true;
    // selection::execute();
    // std::cout << "sadlfj" << std::endl;
    if (asdf == true) {
      elevator::elevGroup.moveVelocity(600);
      intake::intakeGroup.moveVelocity(600);
    } else if (asdf == false) {
      elevator::elevGroup.moveVelocity(0);
      intake::intakeGroup.moveVelocity(0);
    }
  }
}
void autonomous() { selection::execute(); }
void opcontrol() {
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  while (true) {
    // foo();
    drive::userDrive();
    drive::brake();
    intake::init();
    elevator::init();
    selection::colorSwap();
    pros::delay(20);
  }
}
