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

void rThree() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive(17,130);
  turn(225,60,"right");
  runIntake(10000);
  drive(19,140);
  scoreUntil('r');
  runIntake(0);
  drive(15, -110);
  turn(325, 110, "right");
  eject();
  drive(34, 150);
  runElevator(0);
  turn(195,50,"left");
  runIntake(max);
  drive(12,75);
  scoreUntil('r');
  runIntake(0);
  drive(8,-60);
}

void brThree() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive(17,130);
  turn(225,60,"right");
  runIntake(10000);
  drive(19,140);
  scoreUntil('b');
  runIntake(0);
  drive(15, -110);
  turn(325, 110, "right");
  eject();
  drive(34, 150);
  runElevator(0);
  turn(195,50,"left");
  runIntake(max);
  drive(12,75);
  scoreUntil('b');
  runIntake(0);
  drive(8,-60);
}

void rTwo() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive(17,130);
  turn(225,60,"right");
  runIntake(10000);
  drive(19,140);
  scoreUntil('r');
  runIntake(0);
  drive(15, -110);
  turn(325, 110, "right");
  eject();
  drive(34, 150);
  runElevator(0);
  turn(190,50,"left");
  runIntake(max);
  drive(10,75);
  scoreUntil('r');
  runIntake(0);
  drive(8,-60);
}

void rOne() {
    if (fail) {
      dont();
    }
    drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
    drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
    drive(17,130);
    turn(225,60,"right");
    runIntake(10000);
    drive(19,140);
    scoreUntil('r');
    runIntake(0);
    drive(15, -110);
}

void brOne() {
    if (fail) {
      dont();
    }
    drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
    drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
    drive(17,130);
    turn(225,60,"right");
    runIntake(10000);
    drive(19,140);
    scoreUntil('b');
    runIntake(0);
    drive(15, -110);
}

void lThree() {

}

void lTwo() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  runElevator(max);
  wait(100);
  runElevator(0);
  drive(47, 150);
  turn(190, 50, "left");
  runIntake(max);
  drive(55, 120);
  score();
  wait(100);
  runIntake(0);
  score();
  drive(5, -50);
}
void lOne() {
  if (fail) {
    dont();
  }
  rightTracker.set_position(0);
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive(35, 100);
  turn(260, 50, "left");
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

int foo = 36000 * 3;
void testFunctions() {
  rightTracker.set_position(0);
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive(20, 100);
  drive(10, -100);
}

} // namespace auton
