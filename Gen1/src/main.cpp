#include "main.h"
#include "custom/auton/selection.hpp"
#include "custom/settup/motors.hpp"
#include "custom/settup/record.hpp"
#include "custom/systems/drive.hpp"
#include "custom/systems/intake.hpp"
#include "custom/systems/wheel.hpp"

void initialize() { selection::init(); }

void disabled() {}

void competition_initialize() {}

void autonomous() { selection::execute(); }

void opcontrol() {

  while (true) {
    intake::init();
    wheel::init();
    drive::userDrive();
    record::record();
    pros::delay(20);
  }
}
