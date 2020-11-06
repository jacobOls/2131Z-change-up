#include "main.h"
#include "custom/auton/selection.hpp"
#include "custom/systems/drive.hpp"
#include "custom/systems/elevator.hpp"
#include "custom/systems/intake.hpp"

void initialize() {
  selection::init();
  intake::initVision();
}

void disabled() {}

void competition_initialize() {}

void autonomous() { selection::execute(); }

void opcontrol() {
  selection::execute();
  while (true) {
    drive::userDrive();
    drive::brake();
    intake::init();
    elevator::init();
    selection::colorSwap();
    pros::delay(20);
  }
}
