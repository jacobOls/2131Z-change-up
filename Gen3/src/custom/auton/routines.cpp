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
  unityTurn(125, true);
  open();
  unityStraight(26, false);
  wait(800);
  runIntake(12000);
  wait(200);
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
  unityStraight(15, false);
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
  unityTurn(125, true);
  open();
  unityStraight(26, false);
  wait(800);
  runIntake(12000);
  wait(200);
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
  unityStraight(15, false);
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
  unityTurn(269, true);
  open();
  unityStraight(39, false);
  wait(1150);
  runIntake(max);
  scoreUntil(BLUE);
  open();
  unityBack(30, true);
  // release();
  unityTurn(140, true);
  unityStraight(80, false);
  ratchetUntil(BLUE);
  wait(2500);
  unityTurn(180, true);
  runIntake(max);
  unityStraight(22, false);
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
  unityTurn(233, true);
  open();
  unityStraight(26, false);
  wait(1000);
  runIntake(12000);
  scoreUntil(RED);
  wait(50);
  runIntake(0);
  unityBack(20, true);
  unityTurn(90, true);
  unityStraight(40, false);
  ratchetUntil(RED);
  wait(1200);
  unityTurn(173, true);
  runIntake(max);
  unityStraight(15, false);
  wait(900);
  scoreUntil(BLUE);
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
  unityTurn(173, true);
  runIntake(max);
  unityStraight(15, false);
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
  wait(600);
  unityTurn(123, true);
  unityStraight(27, false);
  // runElevator(max);
  // wait(10);
  wait(1000);
  score();
  // second tower
  wait(400);
  runElevator(-4000);
  wait(200);
  runElevator(0);
  // open();
  unityBack(20, true);
  // intake::intakeGroup.setBrakeMode(AbstractMotor::brakeMode::coast);
  // runIntake(max);
  // wait(200);
  // runIntake(0);
  unityTurn(260, true);
  unityStraight(41, true);
  runElevator(0);
  unityTurn(180, true);
  unityStraight(10, false);
  wait(1100);
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
  wait(1200);
  unityTurn(234, true);
  unityStraight(21, false);
  wait(800);
  score();
  wait(500);
  // fourth tower
  unityBack(12, true);
  unityTurn(357, true);
  unityBack(16, false);
  wait(1200);
  unityStraight(62, false);
  open();
  wait(1500);
  release();
  wait(1900);
  unityTurn(272, true);
  unityStraight(10, false);
  wait(700);
  score();
  // fifth tower
  unityBack(10, true);
  unityTurn(95, true);
  open();
  open();
  unityStraight(15, false);
  wait(800);
  release();
  wait(250);
  runIntake(max);
  runElevator(8000);
  unityTurn(3, true);
  runIntake(0);
  runElevator(0);
  unityStraight(50, false);
  open();
  wait(1250);
  release();
  wait(1250);
  unityBack(10, true);
  unityTurn(320, true);
  unityStraight(32, false);
  wait(750);
  runElevator(max);
  wait(20);
  score();
  wait(250);
  // sixth tower
  unityBack(25, true);
  unityTurn(100, true);
  unityStraight(38, true);
  runElevator(0);
  unityTurn(8, true);
  unityStraight(12, false);
  wait(1000);
  score();
  // seventh tower
  unityBack(13, true);
  unityTurn(95, true);
  open();
  unityStraight(47, false);
  wait(900);
  release();
  wait(1100);
  unityTurn(53, true);
  unityStraight(18, false);
  wait(800);
  score();
  // eigth tower
  unityBack(16, true);
  unityTurn(190, true);
  unityBack(17, false);
  wait(1400);
  unityStraight(64, false);
  open();
  wait(1450);
  release();
  wait(600);
  unityTurn(95, true);
  unityStraight(13, false);
  wait(600);
  score();
  // ninth tower (center)
  unityBack(10, true);
  unityTurn(277, true);
  open();
  open();
  unityStraight(15, true);
  release();
  runIntake(max);
  runElevator(max);
  wait(700);
  runIntake(0);
  runElevator(0);
  unityStraight(15, true);
  unityStraight(7, true);
  unityTurn(250, true);
  // unityStraight(6, true);
  unityBack(8, true);
  unityTurn(277, true);
  wait(250);
  unityStraight(8, false);
  wait(150);
  runElevator(9500);
  wait(5000);
}

void speciality() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  open();
  unityStraight(60, true);
  release();
  // wait(150);
  // unityBack(15, true);
}

void testFunctions() {
  rightTracker.set_position(0);
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  // unityLeft(2, true);
}
} // namespace auton
