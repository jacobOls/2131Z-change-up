#include "custom/auton/routines.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/drive.hpp"
#include "custom/systems/elevator.hpp"
#include "custom/systems/intake.hpp"
#include "main.h"
namespace auton {
const int max = 12000;
void wait(int time) { pros::delay(time); }
bool fail = true;
void dont() { fail = false; }
void jankTurn(int turnAngle, int velocity) {
  sTracker.set_position(0);
  sTracker.set_position(0);
  turnAngle = turnAngle * 100;
  wait(15);
  if (turnAngle < 0) {
    turnAngle += 30;
    while (abs(sTracker.get_position()) < abs(turnAngle * 2.925)) {
      drive::left_drive.moveVelocity(-velocity);
      drive::right_drive.moveVelocity(velocity);
    }
  } else if (turnAngle > 0) {
    while (abs(sTracker.get_position()) < abs(turnAngle * 2.925)) {
      drive::left_drive.moveVelocity(velocity);
      drive::right_drive.moveVelocity(-velocity);
    }
  }
  drive::driveGroup.moveVelocity(0);
}

void rightThree() {
  if (fail) {
    dont();
  }
  rightTracker.set_position(0);
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  runIntake(max);
  swingTurn(32, 150, "right");
  score();
  runElevator(-max / 4);
  drive(30, -200);
  runElevator(0);
  runIntake(0);
  turn(52, 100, "right");
  drive(36, 160);
  score();
  drive(10, -80);
  turn(60, 80, "right");
  drive(72, 200);
  runIntake(max);
  turn(39, 60, "left");
  drive(23, 175);
  score();
  runIntake(0);
  drive(10, -50);
}
/*
if (fail) {
  dont();
}
rightTracker.set_position(0);
drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
runIntake(max);
drive(1, 50);
swingTurn(32, 90, "right");
score();
runElevator(-max / 4);
drive(53, -200);
runElevator(0);
runIntake(0);
turn(55, 90, "right");
drive(22, 150);
score();
drive(15, -80);
turn(75, 95, "right");
drive(37, 200);
runIntake(max);
turn(38, 80, "left");
drive(21.5, 200);
score();
runIntake(0);
drive(10, -50);
*/
void RtwoTowers() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  runElevator(max);
  wait(100);
  runElevator(0);
  drive(45, 150);
  turn(155, 50, "right");
  runIntake(max);
  drive(50, 100);
  score();
  wait(100);
  runIntake(0);
  score();
  drive(5, -50);
}

void RoneTower() {
  if (fail) {
    dont();
  }
  rightTracker.set_position(0);
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive(35, 100);
  turn(240, 50, "right");
  runIntake(12000);
  drive(42, 120);
  score();
  wait(450);
  score();
  wait(200);
  runIntake(0);
  wait(250);
  score();
  drive(5, -50);
}
void rOneCycle() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive(465, 100);
  // runElevator(4000);
  turn(780, 200, "right");
  runIntake(12000);
  // runElevator(0);
  // runIntake(12000);
  drive(690, 150);
  runIntake(12000);
  runElevator(12000);
  wait(1500);
  runElevator(0);
  runIntake(0);
  // runElevator(80);
  open();
  drive(200, -75);
  wait(500);
  release();
}
void imadick() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  open();
  drive(1650, 170);
  release();
  runIntake(10000);
  drive(800, -170);
  // runElevator(-6000);
  // open();
  // wait(300);
  // runElevator(0);
  // release();
  // runIntake(4000);
  wait(600);
  turn(750, 200, "right");
  // eject();
  runIntake(12000);
  // wait(200);
  // runElevator(0);
  // runIntake(12000);
  drive(500, 150);
  runIntake(0);
  runElevator(12000);
  wait(900);
  runElevator(0);
  runIntake(0);
  // runElevator(80);
  open();
  drive(200, -75);
  wait(500);
  release();
}
void leftAuton() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  driveNoRamp(20, 150);
  jankTurn(-125, 12);
  runIntake(200);
  driveNoRamp(30, 150);
  runIntake(0);
  score();
  driveNoRamp(15, -150);
  // jankTurn(-160);
  // drive(50, 175);
  // score();
}
void fastOne() {
  runIntake(max);
  drive(6, 50);
  jankTurn(-15, 25);
  runIntake(0);
  // driveNoRamp(0.25, 10);
  score();
  driveNoRamp(5, -45);
}
void lTwoTowers() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  runElevator(max);
  wait(100);
  runElevator(0);
  drive(45, 150);
  turn(173, 50, "left");
  runIntake(max);
  drive(53.3, 120);
  score();
  wait(100);
  runIntake(0);
  score();
  drive(5, -50);
}
void lOneTower() {
  if (fail) {
    dont();
  }
  rightTracker.set_position(0);
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive(35, 100);
  turn(240, 50, "left");
  runIntake(12000);
  drive(42, 120);
  score();
  wait(450);
  score();
  wait(200);
  runIntake(0);
  wait(250);
  score();
  drive(5, -50);
}
void skills() {
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  if (fail) {
    dont();
  }
  runIntake(max);
  drive(32, 150);
  turn(125, 80, "right");
  drive(33, 150);
  score();

  runIntake(0);
  runElevator(-max / 5);
  drive(10, -80);
  runElevator(0);
  turn(160, 100, "right");
  clampDrive(57, 42, 160);
  // runElevator(max / 4);
  turn(115, 80, "left");
  runElevator(0);
  drive(40, 100);
  score();

  drive(5, -40);
  turn(80, 50, "right");
  clampDrive(70, 60, 110);
  turn(37, 60, "left");
  drive(11, 90);
  score();

  drive(6, -50);
  turn(130, 50, "right");
  clampDrive(56, 42, 200);
  turn(80, 70, "left");
  drive(14, 50);
  score();

  drive(10, -50);
  turn(85, 60, "right");
  clampDrive(73, 58, 200);
  turn(50, 80, "left");
  drive(32, 100);
  score();
}

volatile const double wheelCirc = M_PI * 2.75;
double driveInches() {
  return (abs(leftTracker.get_position() + rightTracker.get_position()) / 2) /
         360 * wheelCirc;
}
void toPoint(int reqY, int reqX) {
  double turnAngle = atan2(reqY, reqX);
  turnAngle = turnAngle * 180 / M_PI;
  turnAngle *= 100;
  double driveDistance = hypot(reqY, reqX) * 10;
  rightTracker.set_reversed(true);
  leftTracker.set_reversed(false);
  rightTracker.set_reversed(true);
  rightTracker.set_position(0);
  leftTracker.set_position(0);
  rightTracker.set_position(0);
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  // pi*36000 is 1 full turn, precise at 65 vel and lower
  // when generating turn, it must multiply by M_PI to be accurate
  while (abs(rightTracker.get_position()) < (3.14 * turnAngle)) {
    drive::left_drive.moveVelocity(-65);
    drive::right_drive.moveVelocity(65);
  }
  drive::driveGroup.moveVelocity(0);
  while (driveInches() < driveDistance) {
    drive::left_drive.moveVelocity(65);
    drive::right_drive.moveVelocity(65);
  }
  drive::driveGroup.moveVelocity(0);
}

void iHaveAYardStick() {
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  rightTracker.set_position(0);
  drive(23, 160);
  turn(112, 100, "right");
  runIntake(max);
  drive(24, 160);
  score();
  drive(32, -200);
  runIntake(0);
  turn(55, 90, "right");
  drive(27, 150);
  score();
  drive(15, -100);
  turn(30, 50, "right");
  drive(55, 200);
  turn(-15, 70, "left");
  runIntake(max);
  drive(5, 175);
  score();
  runIntake(0);
  drive(10, -50);
}
int foo = 36000 * 3;
void testFunctions() {
  rightTracker.set_position(0);
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive(20, 100);
  drive(10, -100);
}

} // namespace auton
