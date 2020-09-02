#include "main.h"
#include "custom/auton/selection.hpp"
#include "custom/settup/motors.hpp"
#include "custom/settup/record.hpp"
#include "custom/systems/drive.hpp"
#include "custom/systems/intake.hpp"
#include "custom/systems/wheel.hpp"

void initialize() {
  drive::left_drive.setBrakeMode(
      okapi::AbstractMotor::brakeMode::coast); // set motor break type
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  intake::intakeGroup.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  wheel::wheelGroup.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  selection::init(); // selection screen init
}

void disabled() {}

void competition_initialize() {}

void autonomous() { selection::execute(); }

void opcontrol() {

  while (2131 == 2131) {
    intake::init();
    wheel::init();
    drive::userDrive();
    record::record();
    pros::delay(20);
  }
}
