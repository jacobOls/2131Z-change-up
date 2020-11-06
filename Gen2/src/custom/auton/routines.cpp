#include "custom/auton/routines.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/drive.hpp"
#include "custom/systems/elevator.hpp"
#include "custom/systems/intake.hpp"
#include "main.h"
namespace auton {
void wait(int time) { pros::delay(time); }
bool fail = true;
void dont() { fail = false; }
void rightAuton() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  strafe(500, 140, "left");
  runIntake(12000);
  // drive(100, 50);
  turn(290, 160, "right");
  drive(520, 200);
  runIntake(-8000);
  runElevator(12000);
  wait(400);
  runElevator(0);
  runIntake(4000);
  // runElevator(80);
  drive(125, -100);
  // runIntake(100);
  // runElevator(8000);
  turn(275, 125, "right");
  runElevator(0);
  strafe(1350, 200, "right");
  runIntake(0);
  drive(260, 100);
  // wait(450);
  // strafe(100, 50, "left");
  runElevator(12000);
  wait(400);
  runElevator(0);
  // drive(50, -100);
  drive(150, -70);
  strafe(1250, 200, "right");
  turn(300, 200, "right");
  runIntake(12000);
  runElevator(5000);
  runElevator(12000);
  drive(900, 200);
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
  strafe(500, 140, "left");
  runIntake(12000);
  // drive(100, 50);
  turn(290, 160, "right");
  drive(520, 200);
  runIntake(-8000);
  runElevator(12000);
  wait(400);
  runElevator(0);
  runIntake(4000);
  // runElevator(80);
  drive(125, -100);
  // runIntake(100);
  // runElevator(8000);
  turn(275, 125, "right");
  runElevator(0);
  strafe(1350, 200, "right");
  runIntake(0);
  drive(260, 100);
  // wait(450);
  // strafe(100, 50, "left");
  runElevator(12000);
  wait(400);
  runElevator(0);
}

void RoneTower() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  strafe(500, 140, "left");
  runIntake(12000);
  // drive(100, 50);
  turn(290, 160, "right");
  drive(520, 200);
  runIntake(-8000);
  runElevator(12000);
  wait(400);
  runElevator(0);
  runIntake(0);
  // runElevator(80);
  drive(125, -100);
}
void leftAuton() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  strafe(500, 140, "right");
  runIntake(12000);
  // drive(100, 50);
  turn(170, 160, "left");
  drive(520, 200);
  runIntake(-8000);
  runElevator(12000);
  wait(400);
  runElevator(0);
  runIntake(4000);
  // runElevator(80);
  drive(125, -100);
  // runIntake(100);
  // runElevator(8000);
  turn(350, 125, "left");
  runElevator(0);
  strafe(1350, 200, "left");
  runIntake(0);
  drive(230, 100);
  // wait(450);
  // strafe(100, 50, "left");
  runElevator(12000);
  wait(500);
  runElevator(0);
  // drive(50, -100);
  drive(150, -70);
  strafe(1250, 200, "left");
  turn(100, 130, "left");
  runIntake(12000);
  runElevator(5000);
  runElevator(12000);
  drive(1000, 200);
  // drive(50, 20);
  // runIntake(-6000);
  // wait(1100);
  runElevator(0);
  runIntake(0);
  drive(200, -50);
}
void skills() {
  if (fail) {
    dont();
  }
  runIntake(200);
  runElevator(60);
  drive(700, 100);
  runElevator(0);
  turn(450, 100, "right");
  drive(540, 100);
  drive(250, -100);
  turn(270, 90, "right");
  runIntake(140);
  runElevator(20);
  drive(700, 100);
  runElevator(12000);
  wait(500);
  runElevator(-25);
  runIntake(-25);
  drive(275, -100);
  runElevator(0);
  runIntake(0);
  turn(240, 100, "right");
  strafe(625, 120, "left"); // reckoning
  strafe(1800, 200, "right");
  runIntake(200);
  drive(250, 150);
  runIntake(0);
  runElevator(12000);
  wait(800);
  runElevator(0);
  runIntake(-100);
  drive(-100, -150);
  runIntake(0);
  strafe(1060, 200, "right");
  turn(210, 100, "right");
  runIntake(200);
  drive(800, 100);
  runIntake(0);
  runElevator(12000);
  wait(1000);
  runElevator(0);
  drive(-200, -200);
  /*
  turn(710, 100, "left");
  strafe(1700, 100, "left");
  runIntake(200);
  runElevator(50);
  drive(400, 100);
  runIntake(0);
  runElevator(0);
  drive(500, 200);
  runElevator(12000);
  wait(700);
  runElevator(0);
  */
}
void testFunctions() {
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  turn(50, 10, "right");
  // strafe(800, 200, "left");
  // strafe(800, 200, "right");
}

} // namespace auton
