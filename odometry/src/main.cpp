#include "main.h"
#include "custom/auton/newAuton.hpp"
#include "custom/auton/selection.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "custom/setup/odom.hpp"
#include "custom/systems/drive.hpp"
#include "custom/systems/elevator.hpp"
#include "custom/systems/intake.hpp"
void initialize() {
  selection::init();
  elevator::initVision();
  intake::intakeGroup.tarePosition();
  left.set_position(0);
  right.set_position(0);
  back.set_position(0);
  left.set_reversed(true);
  back.set_reversed(true);
  pros::Task trackPosition(posCalc);
}
pros::Task pid(auton::unity2);

void disabled() {
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
}

void competition_initialize() {}

void autonomous() { selection::execute(); }
okapi::ControllerButton autosdf = master[okapi::ControllerDigital::X];
void foo2() {
  if (autosdf.changedToPressed())
    selection::execute();
}

void opcontrol() {
  // pros::Task taskSuspend(pid);
  // auton::unityStop();
  while (true) {
    foo2();
    // drive::userDrive();
    // drive::brake();

    intake::init();
    elevator::init();
    selection::colorSwap();
    pros::delay(20);
  }
}
