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
  strafe(1400, 200, "right");
  runIntake(0);
  drive(100, 50);
  // wait(450);
  // strafe(100, 50, "left");
  runElevator(12000);
  wait(700);
  // turn(100, 25, "left");
  runElevator(0);
  drive(150, -40);
  // drive(50, -100);
  // drive(150, -70);
  strafe(1350, 200, "right");
  turn(235, 150, "right");
  runIntake(12000);
  runElevator(12000);
  drive(720, 100);
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
  strafe(1400, 200, "right");
  runIntake(0);
  drive(100, 50);
  // wait(450);
  // strafe(100, 50, "left");
  runElevator(12000);
  wait(1500);
  // turn(100, 25, "left");
  runElevator(0);
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
  drive(500, 160);
  // runIntake(-8000);
  runElevator(12000);
  wait(500);
  runElevator(-5000);
  runIntake(4000);
  // runElevator(80);
  drive(200, -75);
  runIntake(0);
  runElevator(0);
}
void leftAuton() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  strafe(520, 140, "right");
  runIntake(12000);
  // drive(100, 50);
  turn(240, 160, "left");
  drive(520, 160);
  // runIntake(-8000);
  runElevator(12000);
  wait(500);
  runElevator(-5000);
  runIntake(4000);
  // runElevator(80);
  drive(200, -75);
  // runIntake(100);
  // runElevator(8000);
  leftTurn(280, 90);
  runElevator(0);
  strafe(1500, 200, "left");
  runIntake(0);
  turn(55, 30, "right");
  drive(400, 100);
  // wait(450);
  // strafe(100, 50, "left");
  runElevator(12000);
  wait(700);
  // turn(100, 25, "left");
  runElevator(0);
  drive(150, -40);
  // drive(50, -100);
  // drive(150, -70);
  strafe(1350, 200, "left");
  turn(235, 150, "left");
  runIntake(12000);
  runElevator(12000);
  drive(850, 100);
  runIntake(0);
  wait(700);
  // drive(50, 20);
  // runIntake(-6000);
  // wait(1100);
  runElevator(0);
  runIntake(0);
  drive(200, -50);
}
void skills() {
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  if (fail) {
    dont();
  }
  runIntake(12000);
  drive(500, 100);
  runIntake(0);
  // runElevator(4000);
  turn(770, 200, "right");
  // runElevator(0);
  // runIntake(12000);
  drive(650, 150);
  runElevator(12000);
  wait(400);
  runElevator(-3000);
  drive(200, -80);
  runElevator(0);
  runIntake(0);
  drive(80, -25);
  turn(600, 90, "right");
  // autoBack(600);
  // tower 1
  open();
  drive(1200, 200);
  release();
  runIntake(max);
  runElevator(max / 4);
  turn(350, 60, "left");
  // wait(450);
  // strafe(100, 50, "left");
  drive(200, 80);
  runElevator(12000);
  wait(300);
  runElevator(0);
  drive(80, -30);
  // runIntake(12000);
  open();
  turn(550, 200, "right");
  drive(1200, 140);
  release();
  runElevator(max / 4);
  runIntake(max);
  turn(220, 100, "left");
  runElevator(0);
  runIntake(0);
  drive(500, 150);
  runElevator(12000);
  wait(750);
  runElevator(0);
  drive(200, -100);
  // end home row
  turn(700, 100, "right");
  runIntake(12000);
  drive(1300, 200);
  runIntake(0);
  turn(520, 200, "left");
  runElevator(12000);
  wait(500);
  runElevator(0);
  turn(550, 200, "right");
}
void testFunctions() {
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  open();
  wait(2000);
  release();
  // strafe(800, 200, "left");
  // strafe(800, 200, "right");
}

} // namespace auton
