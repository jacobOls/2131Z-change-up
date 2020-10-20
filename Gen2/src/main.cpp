#include "main.h"
#include "custom/auton/selection.hpp"
#include "custom/systems/drive.hpp"

void initialize() { selection::init(); }

void disabled() {}

void competition_initialize() {}

void autonomous() { selection::execute(); }

void opcontrol() {

  while (true) {
    drive::userDrive();
    drive::brake();
    pros::delay(20);
  }
}
