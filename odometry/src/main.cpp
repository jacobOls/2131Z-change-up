#include "main.h"
#include "custom/auton/newAuton.hpp"
#include "custom/auton/selection.hpp"
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
// pros::Task pid(auton::unity2);

void disabled() {
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
}

void competition_initialize() {}

void autonomous() {
  // pros::Task taskResume(pid);
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  // auton::unityStraight(23,true);
  // auton::unityTurn(-1360,true);
  // auton::unityStraight(25,true);

  // pros::delay(10000);
  // selection::execute();
}

void opcontrol() {
  // pros::Task taskSuspend(pid);
  // auton::unityStop();
  while (true) {
    drive::userDrive();
    drive::brake();
    intake::init();
    elevator::init();
    selection::colorSwap();
    pros::delay(20);
  }
}
