#include "main.h"
#include "custom/auton/selection.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/drive.hpp"
#include "custom/systems/elevator.hpp"
#include "custom/systems/intake.hpp"

void initialize() {
  selection::init();
  elevator::initVision();
  intake::intakeGroup.tarePosition();
}

void disabled() {
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
}

void competition_initialize() {}

void autonomous() { selection::execute(); }
okapi::ControllerButton autosdf = master[okapi::ControllerDigital::X];

void opcontrol() {
  // selection::execute();
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  while (true) {
    if (autosdf.isPressed()) {
      selection::execute();
      std::cout << "sadlfj" << std::endl;
    }
    // drive::userDrive();
    drive::brake();
    intake::init();
    elevator::init();
    selection::colorSwap();
    pros::delay(20);
  }
}
