#include "main.h"
#include "custom/auton/selection.hpp"
#include "custom/settup/controller.hpp"
#include "custom/settup/motors.hpp"
#include "custom/settup/record.hpp"
#include "custom/systems/drive.hpp"
#include "custom/systems/intake.hpp"
#include "custom/systems/vision.hpp"
#include "custom/systems/wheel.hpp"

void initialize() {
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
  // set motor break type
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  intake::intakeGroup.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  wheel::wheelGroup.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  selection::init(); // selection screen init
  vision::init();
}

void disabled() {}

void competition_initialize() {}

void autonomous() { selection::execute(); }
bool running;
void win() { bool winner = true; }
void opcontrol() {
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  while (2131 == 2131) {
    if (running) {
      win();
    }
    // int temp = wheel::left_motor.getTemperature();
    // std::string temperature = std::to_string(temp);
    // master.setText(0, 0, temperature);
    intake::init();
    // wheel::init();
    // vision::execute();
    selection::colorSwap();
    drive::userDrive();
    record::record();
    pros::delay(20);
  }
}
