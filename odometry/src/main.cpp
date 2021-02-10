#include "main.h"
#include "custom/auton/selection.hpp"
#include "custom/setup/motors.hpp"
#include "custom/setup/odom.hpp"
#include "custom/systems/drive.hpp"
#include "custom/systems/elevator.hpp"
#include "custom/systems/intake.hpp"
#include "custom/auton/newAuton.hpp"
void initialize() {
  selection::init();
  elevator::initVision();
  intake::intakeGroup.tarePosition();
  pros::Task trackPosition(posCalc);
}

void disabled() {
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
}

void competition_initialize() {}

void autonomous() {
  // pros::Task pid(auton::unity2);
  // drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  // drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  // auton::unityStraight(25,true,true);
  // selection::execute();
}

void opcontrol() {
  // selection::execute();
  // pros::Task taskSuspend(pid);
  // trackPosition.
  pros::Task pid(auton::unity2);
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  auton::unityStraight(25,false,false);
  while (true) {
    // drive::userDrive();
    // drive::brake();
    intake::init();
    elevator::init();
    selection::colorSwap();
    pros::delay(20);
  }
}
