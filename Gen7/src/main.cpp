#include "main.h"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/lift.hpp"

void initialize() {} // runs when program start and is not disabled

void disabled() {} // runs while in disabled state

void competition_initialize() {} // runs when competition switch is initizalized

void autonomous() {} // runs when in auton

void opcontrol() { // runs while in user control

  while (true) {
    lift::init();
    pros::delay(20);
  }
}
