#include "custom/auton/routines.hpp"
#include "custom/auton/pid.hpp"
#include "custom/auton/posTracking.hpp"
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
  ratchetUntil(RED, max);
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
  ratchetUntil(BLUE, max);
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
  unityStraight(42, true);
  runElevator(0);
  unityTurn(178, true);
  runIntake(max);
  unityStraight(14, false);
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
  unityStraight(42, true);
  runElevator(0);
  unityTurn(178, true);
  runIntake(max);
  unityStraight(14, false);
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
  ratchetUntil(RED, max);
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
  ratchetUntil(BLUE, max);
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
  ratchetUntil(RED, max);
  wait(1200);
  unityTurn(173, true);
  runIntake(max);
  unityStraight(10, false);
  wait(900);
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
  ratchetUntil(BLUE, max);
  wait(1200);
  unityTurn(173, true);
  runIntake(max);
  unityStraight(12, false);
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
  wait(800);
  unityTurn(123, true);
  unityStraight(25, false);
  // runElevator(max);
  // wait(10);
  wait(1000);
  score();
  // second tower
  wait(400);
  runElevator(-4000);
  wait(200);
  runElevator(0);
  unityBack(20, true);
  unityTurn(265, true);
  unityStraight(41, true);
  runElevator(0);
  unityTurn(180, true);
  runIntake(max);
  unityStraight(11, true);
  score();
  // third tower
  // open();
  unityBack(7, true);
  // release();
  unityTurn(264, true);
  eject();
  runIntake(0);
  open();
  unityStraight(40, false);
  wait(850);
  runElevator(0);
  release();
  wait(1250);
  unityTurn(230, true);
  unityStraight(17, true);
  score();
  // fourth tower
  unityBack(12, true);
  unityTurn(357, true);
  unityBack(20, false);
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
  unityTurn(88, true);
  open();
  unityStraight(15, false);
  wait(800);
  release();
  wait(250);
  runIntake(max);
  runElevator(8000);
  wait(500);
  runIntake(0);
  runElevator(0);
  unityBack(5, true);
  unityTurn(3, true);
  unityStraight(50, false);
  open();
  wait(1250);
  release();
  wait(1250);
  unityBack(10, true);
  unityTurn(310, true);
  unityStraight(32, true);
  score();
  //   // sixth tower
  //   unityBack(25, true);
  //   unityTurn(100, true);
  //   unityStraight(38, true);
  //   runElevator(0);
  //   unityTurn(8, true);
  //   unityStraight(12, false);
  //   wait(1000);
  //   score();
  //   // seventh tower
  //   unityBack(13, true);
  //   unityTurn(95, true);
  //   open();
  //   unityStraight(47, false);
  //   wait(900);
  //   release();
  //   wait(1100);
  //   unityTurn(53, true);
  //   unityStraight(18, false);
  //   wait(800);
  //   score();
  //   // eigth tower
  //   unityBack(16, true);
  //   unityTurn(190, true);
  //   unityBack(17, false);
  //   wait(1400);
  //   unityStraight(64, false);
  //   open();
  //   wait(1450);
  //   release();
  //   wait(600);
  //   unityTurn(95, true);
  //   unityStraight(13, false);
  //   wait(600);
  //   score();
  //   // ninth tower (center)
  //   unityBack(10, true);
  //   unityTurn(277, true);
  //   open();
  //   open();
  //   unityStraight(15, true);
  //   release();
  //   runIntake(max);
  //   runElevator(max);
  //   wait(700);
  //   runIntake(0);
  //   runElevator(0);
  //   unityStraight(15, true);
  //   unityStraight(7, true);
  //   unityTurn(250, true);
  //   // unityStraight(6, true);
  //   unityBack(8, true);
  //   unityTurn(277, true);
  //   wait(250);
  //   unityStraight(8, false);
  //   wait(150);
  //   runElevator(9500);
  //   wait(5000);
}

void specialty() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  unityStraight(35, true);
  unityTurn(88, true);
  open();
  unityStraight(36, false);
  wait(1150);
  runIntake(max);
  wait(500);
  scoreControlled(400);
  wait(200);
  runElevator(max / 2);
  while (opt.get_hue() < 95) {
    if (disSense.get() < 175) {
      runElevator(0);
    }
    runIntake(max * .8);
  }
  runIntake(0);
  runElevator(0);
  unityBack(7, true);
  // runElevator(0);
  unityTurn(0, true);
  unityTurn(320, true);
  // open();
  unityStraight(38, true);
  unityTurn(325, true);
  open();
  wait(250);
  open();
  unityStraight(9, false);
  wait(1200);
  runIntake(max);
  wait(100);
  runIntake(0);
  unityBack(5, true);
  unityTurn(358, true);
  unityStraight(3, true);
  score();
  score();
  wait(200);
  unityBack(5, true);
  // release();
}

void bSpecialty() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  unityStraight(35, true);
  unityTurn(88, true);
  open();
  unityStraight(36, false);
  wait(1150);
  runIntake(max);
  wait(500);
  scoreControlled(400);
  wait(200);
  runElevator(max / 2);
  while (opt.get_hue() > 45) {
    if (disSense.get() < 175) {
      runElevator(0);
    }
    runIntake(max * .8);
  }
  runIntake(0);
  runElevator(0);
  unityBack(7, true);
  // runElevator(0);
  unityTurn(0, true);
  unityTurn(320, true);
  // open();
  unityStraight(38, true);
  unityTurn(325, true);
  open();
  wait(250);
  open();
  unityStraight(9, false);
  wait(1200);
  runIntake(max);
  wait(100);
  runIntake(0);
  unityBack(5, true);
  unityTurn(358, true);
  unityStraight(3, true);
  score();
  score();
  wait(200);
  unityBack(5, true);
}

void testFunctions() {
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  toPoint(10, 0);
  wait(1000);
  toPoint(0, 0);
}
} // namespace auton
