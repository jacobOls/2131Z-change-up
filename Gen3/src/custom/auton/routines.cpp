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
void jankTurn(int turnAngle) {
  sTracker.set_position(0);
  sTracker.set_position(0);
  turnAngle = turnAngle * 100;
  wait(15);
  if (turnAngle < 0) {
    turnAngle += 30;
    while (abs(sTracker.get_position()) < abs(turnAngle * 2.925)) {
      drive::left_drive.moveVelocity(-60);
      drive::right_drive.moveVelocity(60);
    }
  } else if (turnAngle > 0) {
    while (abs(sTracker.get_position()) < abs(turnAngle * 2.925)) {
      drive::left_drive.moveVelocity(60);
      drive::right_drive.moveVelocity(-60);
    }
  }
  drive::driveGroup.moveVelocity(0);
}
void rightAuton() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  strafe(520, 140, "left");
  runIntake(12000);
  // drive(100, 50);
  turn(220, 160, "right");
  drive(500, 160);
  // runIntake(-8000);
  runElevator(12000);
  wait(500);
  runElevator(-5000);
  runIntake(4000);
  // runElevator(80);
  drive(200, -75);
  // runIntake(100);
  // runElevator(8000);
  turn(310, 90, "right");
  runElevator(0);
  strafe(1425, 200, "right");
  runIntake(0);
  drive(220, 80);
  // wait(450);
  // strafe(100, 50, "left");
  runElevator(12000);
  wait(700);
  // turn(100, 25, "left");
  runElevator(0);
  drive(150, -40);
  // drive(50, -100);
  // drive(150, -70);
  strafe(1500, 200, "right");
  turn(235, 150, "right");
  runIntake(12000);
  runElevator(12000);
  drive(820, 150);
  runIntake(0);
  wait(700);
  // drive(50, 20);
  // runIntake(-6000);
  // wait(1100);
  runElevator(0);
  runIntake(0);
  drive(200, -50);
}
void RtwoTowers() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  strafe(520, 140, "left");
  runIntake(12000);
  // drive(100, 50);
  turn(235, 160, "right");
  drive(500, 160);
  // runIntake(-8000);
  runElevator(12000);
  wait(500);
  runElevator(-5000);
  runIntake(4000);
  // runElevator(80);
  drive(200, -75);
  // runIntake(100);
  // runElevator(8000);
  turn(310, 90, "right");
  runElevator(0);
  strafe(1425, 200, "right");
  runIntake(0);
  drive(350, 80);
  // wait(450);
  // strafe(100, 50, "left");
  runElevator(12000);
  wait(700);
  // turn(100, 25, "left");
  runElevator(0);
  drive(150, -40);
}

void RoneTower() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  strafe(520, 140, "left");
  runIntake(12000);
  // drive(100, 50);
  turn(220, 160, "right");
  drive(540, 160);
  // runIntake(-8000);
  runElevator(12000);
  wait(3000);
  runElevator(-5000);
  runIntake(4000);
  // runElevator(80);
  drive(200, -75);
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
  drive(30, 155);
  jankTurn(-110);
  runIntake(200);
  drive(30, 150);
  runIntake(0);
  score();
  drive(10, -150);
}
void lTwoTowers() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  strafe(520, 140, "right");
  runIntake(12000);
  // drive(100, 50);
  turn(240, 160, "left");
  drive(510, 160);
  // runIntake(-8000);
  runElevator(12000);
  wait(500);
  runElevator(0);
  runIntake(4000);
  // runElevator(80);
  drive(200, -75);
  // runIntake(100);
  // runElevator(8000);
  turn(310, 90, "left");
  runElevator(0);
  strafe(1475, 200, "left");
  runIntake(0);
  // turn(55, 30, "right");
  drive(220, 80);
  // wait(450);
  // strafe(100, 50, "left");
  runElevator(12000);
  wait(700);
  // turn(100, 25, "left");
  runElevator(0);
  drive(300, -140);
}
void lOneTower() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  strafe(520, 140, "right");
  runIntake(12000);
  // drive(100, 50);
  turn(240, 160, "left");
  drive(510, 160);
  // runIntake(-8000);
  runElevator(12000);
  wait(500);
  runElevator(0);
  runIntake(4000);
  // runElevator(80);
  drive(200, -75);
}
void skills() {
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  if (fail) {
    dont();
  }
  clampDrive(465, 300, 100);
  runIntake(12000);
  // runElevator(4000);
  turn(780, 200, "right");
  // runElevator(0);
  // runIntake(12000);
  drive(650, 150);
  runElevator(10000);
  runIntake(0);
  wait(625);
  runElevator(-3000);
  drive(200, -80);
  runElevator(0);
  runIntake(0);
  drive(80, -25);
  turn(1100, 160, "right");
  // autoBack(600);
  // tower 1
  clampDrive(1200, 1100, 200);
  runIntake(max);
  runElevator(max / 4);
  turn(670, 160, "left");
  runElevator(0);
  runIntake(0);
  // wait(450);
  // strafe(100, 50, "left");
  drive(800, 200);
  runElevator(12000);
  wait(500);
  runElevator(-5000);
  drive(150, -60);
  runElevator(0);
  // runIntake(12000);
  turn(500, 200, "right");
  clampDrive(1400, 900, 180);
  runElevator(max / 4);
  runIntake(max);
  turn(180, 100, "left");
  runIntake(0);
  runElevator(0);
  runIntake(0);
  drive(400, 150);
  runElevator(12000);
  wait(450);
  runElevator(0);
  drive(200, -100);
  // end home row
  turn(780, 100, "right");
  // runIntake(12000);
  runElevator(-max / 4);
  clampDrive(1500, 1350, 200);
  runElevator(max / 4);
  runIntake(max);
  turn(640, 200, "left");
  drive(290, 80);
  runElevator(12000);
  runIntake(0);
  wait(500);
  runElevator(0);
  turn(760, 200, "right");
  clampDrive(1400, 1200, 200);
  runIntake(max);
  runElevator(max / 4);
  turn(400, 150, "left");
  drive(600, 150);
  runElevator(12000);
}
void rightThree() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive(465, 100);
  turn(780, 200, "right");
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

void testFunctions() { score(); }

} // namespace auton
