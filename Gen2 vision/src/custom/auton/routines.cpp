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
  drive(80, -25);
  // runIntake(100);
  // runElevator(8000);
  turn(310, 90, "right");
  runElevator(0);
  strafe(1600, 200, "right");
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
  drive(790, 100);
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
  drive(80, -25);
  // runIntake(100);
  // runElevator(8000);
  turn(310, 90, "right");
  runElevator(0);
  strafe(1600, 200, "right");
  runIntake(0);
  drive(100, 50);
  // wait(450);
  // strafe(100, 50, "left");
  runElevator(12000);
  wait(900);
  // turn(100, 25, "left");
  runElevator(0);
  drive(-100, 40);
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
  drive(520, 160);
  // runIntake(-8000);
  runElevator(12000);
  wait(500);
  runElevator(-5000);
  runIntake(4000);
  // runElevator(80);
  drive(80, -25);
  // runIntake(100);
  // runElevator(8000);
  turn(310, 90, "right");
  runElevator(0);
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
  runElevator(0);
  drive(200, -80);
  runElevator(0);
  runIntake(0);
  drive(80, -25);
  turn(330, 90, "right");
  // autoBack(600);
  // tower 1
  strafe(1200, 200, "right");
  drive(125, 60);
  // wait(450);
  // strafe(100, 50, "left");
  runElevator(12000);
  wait(300);
  runElevator(0);
  drive(80, -30);
  runIntake(12000);
  turn(550, 200, "right");
  drive(1200, 140);
  runIntake(0);
  turn(220, 100, "left");
  drive(500, 150);
  runElevator(12000);
  wait(750);
  runElevator(0);
  drive(200, -100);
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
  lineUp();
  // turn(50, 10, "right");
  // strafe(800, 200, "left");
  // strafe(800, 200, "right");
}

} // namespace auton
