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
void redAuton() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  strafe(650, 140, "left");
  runIntake(12000);
  // drive(100, 50);
  turn(290, 160, "right");
  drive(680, 200);
  runIntake(-8000);
  runElevator(12000);
  wait(800);
  runElevator(0);
  runIntake(4000);
  // runElevator(80);
  drive(125, -100);
  // runIntake(100);
  runElevator(5000);
  turn(275, 125, "right");
  runElevator(0);
  strafe(1400, 200, "right");
  runIntake(0);
  runIntake(0);
  drive(150, 70);
  // wait(450);
  // strafe(100, 50, "left");
  runElevator(12000);
  wait(1000);
  runElevator(0);
  // drive(50, -100);
  drive(150, -70);
  strafe(1150, 200, "right");
  turn(440, 200, "right");
  runIntake(12000);
  runElevator(3000);
  drive(800, 200);
  // drive(50, 20);
  runIntake(-6000);
  runElevator(12000);
  wait(1100);
  runElevator(0);
  runIntake(0);
  drive(200, -50);
}
void twoTowers() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  strafe(650, 140, "left");
  runIntake(12000);
  // drive(100, 50);
  turn(290, 160, "right");
  drive(680, 200);
  runIntake(-8000);
  runElevator(12000);
  wait(800);
  runElevator(0);
  runIntake(4000);
  // runElevator(80);
  drive(125, -100);
  // runIntake(100);
  runElevator(5000);
  turn(275, 125, "right");
  runElevator(0);
  strafe(1400, 200, "right");
  runIntake(0);
  runIntake(0);
  drive(150, 70);
  // wait(450);
  // strafe(100, 50, "left");
  runElevator(12000);
  wait(1000);
  runElevator(0);
  // drive(50, -100);
  drive(150, -70);
}

void oneTower() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  strafe(650, 140, "left");
  runIntake(12000);
  // drive(100, 50);
  turn(290, 160, "right");
  drive(680, 200);
  runIntake(-8000);
  runElevator(12000);
  wait(800);
  runElevator(0);
  runIntake(0);
}
void blueHome() {
  if (fail) {
    dont();
  }
  strafe(475, 200, "right");
  runIntake(200);
  turn(180, 90, "left");
  runElevator(25);
  drive(600, 140);
  runIntake(0);
  runElevator(12000);
  wait(700);
  runElevator(0);
  drive(150, -150);
  turn(240, 100, "left");
  strafe(850, 120, "right"); // reckoning
  strafe(1800, 200, "left");
  runIntake(200);
  drive(275, 150);
  runIntake(0);
  runElevator(12000);
  wait(800);
  runElevator(0);
  runIntake(-100);
  drive(-100, -150);
  runIntake(0);
  strafe(1060, 200, "left");
  turn(210, 100, "left");
  runIntake(200);
  drive(800, 100);
  runIntake(0);
  runElevator(12000);
  wait(1000);
  runElevator(0);
  drive(-200, -200);
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
