#include "main.h"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/drive.hpp"
#include "custom/systems/elevator.hpp"
#include "custom/systems/intake.hpp"
void initialize() { master.setText(1, 1, "200"); }
// pros::Task position(posCalc);
// pros::Task elevatorRatchet(elevator::init); // run elevator independetly of
// other systems

void disabled() {
  drive::driveGroup.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  // pros::c::taskSuspend(elevatorRatchet);
}

void competition_initialize() {}

void autonomous() {}
void opcontrol() {
  while (true) {
    drive::userDrive();
    intake::init();
    elevator::init();
    pros::delay(20);
  }
}
