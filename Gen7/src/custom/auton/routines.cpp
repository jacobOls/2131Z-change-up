#include "custom/auton/routines.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/drive.hpp"
#include "custom/systems/intake.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/tilter.hpp"
#include "main.h"

void wait(int time) { pros::delay(time); }

void startup() {
  lift::motor.tarePosition();
  tilter::motor.tarePosition();
  drive::driveAll.tarePosition();
  intake::runIntake(200);
}

void redSmallFive() {
  startup();
  drive::exDrive(800, 100);
  drive::exDrive(-800, -200);
  drive::rightTurn(600, 80);
  intake::runIntake(-10);
  drive::exDrive(300, 150);
  intake::runIntake(0);
  tilter::stack(1050, 100);
  // back off stack
  intake::runIntake(-35);
  drive::exDrive(-200, -50);
}

void blueSmallFive() {
  startup();
  drive::exDrive(800, 100);
  drive::exDrive(-800, -200);
  drive::leftTurn(600, 80);
  intake::runIntake(-10);
  drive::exDrive(300, 150);
  intake::runIntake(0);
  tilter::stack(1050, 100);
  // back off stack
  intake::runIntake(-35);
  drive::exDrive(-200, -50);
}

void blueLargeSeven() {
  startup();
  drive::noRampEnd(300, 100);
  lift::motor.moveAbsolute(900, 100);
  drive::linDrive(300, 100);
  lift::lift(0, -65);
  drive::rightTurn(500, 60);
  drive::noRampEnd(400, 125);
  intake::runIntake(-10);
  drive::linDrive(400, 100);
  intake::runIntake(0);
  tilter::stack(1050, 100);
  // back off stack
  intake::runIntake(-35);
  drive::exDrive(-200, -50);
}

void redLargeSeven() {
  startup();
  drive::noRampEnd(300, 100);
  lift::motor.moveAbsolute(900, 100);
  drive::linDrive(300, 100);
  lift::lift(0, -65);
  drive::leftTurn(500, 60);
  drive::noRampEnd(400, 125);
  intake::runIntake(-10);
  drive::linDrive(400, 100);
  intake::runIntake(0);
  tilter::stack(1050, 100);
  // back off stack
  intake::runIntake(-35);
  drive::exDrive(-200, -50);
}
