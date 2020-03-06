#include "main.h"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/drive.hpp"
#include "custom/systems/intake.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/tilter.hpp"

void initialize() {} // runs when program start and is not disabled

void disabled() {} // runs while in disabled state

void competition_initialize() {} // runs when competition switch is initizalized

void autonomous() {} // runs when in auton

void opcontrol() { // runs while in user control

  while (2131) {
    drive::userDrive();
    tilter::init();
    lift::init();
    intake::init();
    pros::delay(20);
  }
}
