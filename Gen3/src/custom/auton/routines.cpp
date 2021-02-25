#include "custom/auton/routines.hpp"
#include "custom/auton/pid.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/drive.hpp"
#include "custom/systems/elevator.hpp"
#include "custom/systems/intake.hpp"
#include "main.h"
namespace auton {
#define RED true
#define BLUE false
const int max = 12000;
void wait(int time) { pros::delay(time); }
bool fail = true;
void dont() { fail = false; }
void deploy() {
  runElevator(max);
  wait(100);
  runElevator(0);
}

void rThree() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  unityStraight(35, true);
  unityTurn(87, true);
  open();
  unityStraight(38, false);
  wait(1150);
  runIntake(max);
  scoreUntil(RED);
  open();
  unityBack(30, true);
  unityTurn(220, true);
  unityStraight(78, false);
  ratchetUntil(RED);
  wait(2200);
  unityTurn(172, true);
  runIntake(max);
  unityStraight(26, false);
  wait(1150);
  scoreUntil(RED);
  runIntake(0);
  open();
  unityBack(15, true);
}

void brThree() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  unityStraight(35, true);
  unityTurn(87, true);
  open();
  unityStraight(38, false);
  wait(1150);
  runIntake(max);
  scoreUntil(BLUE);
  open();
  unityBack(30, true);
  unityTurn(220, true);
  unityStraight(78, false);
  ratchetUntil(BLUE);
  wait(2200);
  unityTurn(172, true);
  runIntake(max);
  unityStraight(26, false);
  wait(1150);
  scoreUntil(BLUE);
  runIntake(0);
  open();
  unityBack(15, true);
}

void rTwo() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  unityStraight(22, true);
  unityTurn(127, true);
  open();
  unityStraight(28, false);
  wait(1000);
  runIntake(12000);
  scoreUntil(RED);
  wait(50);
  runIntake(0);
  unityBack(20, true);
  unityTurn(270, true);
  eject();
  unityStraight(40, true);
  runElevator(0);
  unityTurn(180, true);
  runIntake(max);
  unityStraight(12, false);
  wait(1000);
  scoreUntil(RED);
  open();
  runElevator(0);
  unityBack(15, true);
  release();
}

void brTwo() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  unityStraight(22, true);
  unityTurn(127, true);
  open();
  unityStraight(28, false);
  wait(1000);
  runIntake(12000);
  scoreUntil(BLUE);
  wait(50);
  runIntake(0);
  unityBack(20, true);
  unityTurn(270, true);
  eject();
  unityStraight(40, true);
  runElevator(0);
  unityTurn(180, true);
  runIntake(max);
  unityStraight(12, false);
  wait(1000);
  scoreUntil(BLUE);
  open();
  runElevator(0);
  unityBack(15, true);
  release();
}

void rOne() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  unityStraight(22, true);
  unityTurn(127, true);
  open();
  unityStraight(28, false);
  wait(1000);
  runIntake(12000);
  scoreUntil(RED);
  runIntake(0);
  open();
  unityBack(10, true);
}

void brOne() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  unityStraight(22, true);
  unityTurn(127, true);
  open();
  unityStraight(28, false);
  wait(1000);
  runIntake(12000);
  scoreUntil(BLUE);
  runIntake(0);
  open();
  unityBack(10, true);
}

void lThree() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  unityStraight(35, true);
  unityTurn(270, true);
  open();
  unityStraight(38, false);
  wait(1150);
  runIntake(max);
  scoreUntil(RED);
  open();
  unityBack(30, true);
  // release();
  unityTurn(140, true);
  unityStraight(78, false);
  ratchetUntil(RED);
  wait(2200);
  unityTurn(180, true);
  runIntake(max);
  unityStraight(23, false);
  wait(1150);
  scoreUntil(RED);
  runIntake(0);
  open();
  unityBack(15, true);
}

void blThree() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  unityStraight(35, true);
  unityTurn(270, true);
  open();
  unityStraight(38, false);
  wait(1150);
  runIntake(max);
  scoreUntil(BLUE);
  open();
  unityBack(30, true);
  // release();
  unityTurn(140, true);
  unityStraight(78, false);
  ratchetUntil(BLUE);
  wait(2200);
  unityTurn(180, true);
  runIntake(max);
  unityStraight(23, false);
  wait(1150);
  scoreUntil(BLUE);
  runIntake(0);
  open();
  unityBack(15, true);
}

void lTwo() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  unityStraight(22, true);
  unityTurn(234, true);
  open();
  unityStraight(26, false);
  wait(1000);
  runIntake(12000);
  scoreUntil(RED);
  wait(50);
  runIntake(0);
  unityBack(20, true);
  unityTurn(90, true);
  eject();
  unityStraight(40, true);
  runElevator(0);
  unityTurn(180, true);
  runIntake(max);
  unityStraight(8, false);
  wait(1300);
  scoreUntil(RED);
  open();
  runElevator(0);
  unityBack(15, true);
  release();
}

void blTwo() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  unityStraight(22, true);
  unityTurn(233, true);
  open();
  unityStraight(26, false);
  wait(1000);
  runIntake(12000);
  scoreUntil(BLUE);
  wait(50);
  runIntake(0);
  unityBack(20, true);
  unityTurn(90, true);
  unityStraight(40, false);
  ratchetUntil(BLUE);
  wait(1200);
  unityTurn(180, true);
  runIntake(max);
  unityStraight(10, false);
  wait(900);
  scoreUntil(BLUE);
  open();
  runElevator(0);
  unityBack(15, true);
  release();
}

void lOne() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  unityStraight(22, true);
  unityTurn(233, true);
  open();
  unityStraight(26, false);
  wait(1000);
  runIntake(12000);
  scoreUntil(RED);
  runIntake(0);
  open();
  unityBack(10, true);
}

void blOne() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  unityStraight(22, true);
  unityTurn(233, true);
  open();
  unityStraight(26, false);
  wait(1000);
  runIntake(12000);
  scoreUntil(BLUE);
  runIntake(0);
  open();
  unityBack(10, true);
}

void skills() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  // first tower
  deploy();
  open();
  unityStraight(22, false);
  wait(400);
  release();
  wait(300);
  unityTurn(123, true);
  unityStraight(25, true);
  runElevator(max);
  wait(10);
  score();
  // second tower
  wait(1000);
  runElevator(-4000);
  wait(200);
  runElevator(0);
  open();
  unityBack(20, true);
  intake::intakeGroup.setBrakeMode(AbstractMotor::brakeMode::coast);
  runIntake(max);
  wait(200);
  runIntake(0);
  unityTurn(270, true);
  unityStraight(41, true);
  runElevator(0);
  unityTurn(180, true);
  unityStraight(11, false);
  wait(1000);
  score();
  // third tower
  open();
  unityBack(10, true);
  release();
  unityTurn(264, true);
  open();
  unityStraight(40, false);
  wait(900);
  release();
  wait(1000);
  unityTurn(234, true);
  unityStraight(21, true);
  score();
  // fourth tower
  unityBack(14, true);
  unityTurn(0, true);
  unityStraight(52, false);
  open();
  wait(1100);
  release();
  wait(1500);
  unityTurn(272, true);
  unityStraight(8, true);
  score();
  // fifth tower
  unityBack(10, true);
  unityTurn(95, true);
  open();
  unityStraight(14, true);
  release();
  runElevator(7000);
  unityTurn(3, true);
  runElevator(0);
  unityStraight(50, false);
  open();
  wait(1250);
  release();
  wait(1250);
  unityBack(5, true);
  unityTurn(310, true);
  unityStraight(25, true);
  score();
  // sixth tower
  unityBack(25, true);
  unityTurn(100, true);
  unityStraight(35, true);
  runElevator(0);
  unityTurn(15, true);
  unityStraight(11, false);
  wait(1000);
  score();
  // seventh tower
  unityBack(15, true);
  unityTurn(95, true);
  open();
  unityStraight(43, false);
  wait(900);
  release();
  wait(1000);
  unityTurn(60, true);
  unityStraight(20, true);
  score();
  // eigth tower
  unityBack(15, true);
  unityTurn(190, true);
  unityStraight(55, false);
  open();
  wait(1200);
  release();
  unityTurn(95, true);
  unityStraight(10, true);
  score();
  // ninth tower (center)
  unityBack(10, true);
  unityTurn(277, true);
  open();
  unityStraight(12, true);
  release();
}

void speciality() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  unityStraight(22, true);
  unityTurn(127, true);
  open();
  unityStraight(28, false);
  wait(1000);
  runIntake(7000);
  scoreUntil(RED);
  runIntake(0);
  open();
  open();
  wait(150);
  unityBack(10, true);
  release();
  unityTurn(180, true);
  runElevator(max);
  wait(400);
  runElevator(0);
  unityTurn(2, true);
  unityStraight(15, true);
}

void testFunctions() {
  rightTracker.set_position(0);
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  ratchetUntil(RED);
}
} // namespace auton
