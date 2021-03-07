#include "main.h"
#include "custom/auton/pid.hpp"
#include "custom/auton/posTracking.hpp"
#include "custom/auton/selection.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/drive.hpp"
#include "custom/systems/elevator.hpp"
#include "custom/systems/intake.hpp"
pros::Rotation rTracker(7);
void initialize() {
  selection::init();
  intake::intakeGroup.tarePosition();
  auton::rightTracker.set_position(0);
  auton::leftTracker.set_position(0);
  auton::sTracker.set_position(0);
  rTracker.set_position(0);

  opt.set_led_pwm(75);
  auton::leftTracker.set_reversed(true);
}
// pros::Task pid(auton::unity2);
pros::Task position(posCalc);
// pros::Task elevatorRatchet(elevator::init); // run elevator independetly of
// other systems

void disabled() {
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  rTracker.set_position(0);
  gyro.reset();
  while (gyro.is_calibrating()) {
    pros::delay(10);
  }
  // pros::c::taskSuspend(elevatorRatchet);
}

void competition_initialize() {}
okapi::ControllerButton autosdf = master[okapi::ControllerDigital::X];
bool asdf = false;
void foo() {
  if (autosdf.changedToPressed()) {
    if (asdf == true)
      asdf = false;
    else if (asdf == false)
      asdf = true;
    // selection::execute();
    // std::cout << "sadlfj" << std::endl;
    if (asdf == true) {
      elevator::elevGroup.moveVelocity(600);
      intake::intakeGroup.moveVelocity(600);
    } else if (asdf == false) {
      elevator::elevGroup.moveVelocity(0);
      intake::intakeGroup.moveVelocity(0);
    }
  }
}
void foo2() {
  if (autosdf.changedToPressed())
    selection::execute();
}
void autonomous() { selection::execute(); }
void opcontrol() {
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  auton::unityStop();
  while (true) {

    foo2();
    drive::userDrive();
    // drive::brake();
    intake::init();
    elevator::init();
    selection::colorSwap();
    pros::delay(20);
  }
}
