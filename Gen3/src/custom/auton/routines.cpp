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
  unityStraight(16, false);
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
  unityTurn(125, true);
  open();
  unityStraight(26, false);
  wait(800);
  runIntake(12000);
  wait(200);
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
  unityTurn(125, true);
  open();
  unityStraight(26, false);
  wait(800);
  runIntake(12000);
  wait(200);
  scoreUntil(BLUE);
  runIntake(0);
  open();
  unityBack(10, true);
}
void hoodTwo() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  unityStraight(35, true);
  unityTurn(92, true);
  open();
  unityStraight(37, false);
  wait(1150);
  runIntake(max);
  wait(500);
  scoreControlled(400);
  wait(200);
  runElevator(max / 2);
  scoreUntil(RED);
  runIntake(0);
  runElevator(-max / 4);
  unityBack(6, true);
}
void bhoodTwo() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  unityStraight(35, true);
  unityTurn(92, true);
  open();
  unityStraight(37, false);
  wait(1150);
  runIntake(max);
  wait(500);
  scoreControlled(400);
  wait(200);
  runElevator(max / 2);
  scoreUntil(BLUE);
  runIntake(0);
  runElevator(-max / 4);
  unityBack(6, true);
}

void lhoodTwo() {
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
  scoreUntil(RED);
  open();
  unityBack(30, true);
}
void blhoodTwo() {
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
}
void lThree() {
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
  scoreUntil(RED);
  open();
  unityBack(30, true);
  // release();
  unityTurn(128, true);
  unityStraight(80, false);
  ratchetUntil(RED, max);
  wait(2500);
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
  unityTurn(128, true);
  unityStraight(80, false);
  ratchetUntil(BLUE, max);
  wait(2500);
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
  unityTurn(128, true);
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
  unityTurn(180, true);
  // runIntake(max);
  unityStraight(8, true);
  score();
  // third tower
  unityBack(7, true);
  unityTurn(265, true);
  openSkills();
  unityStraight(44, false);
  wait(850);
  release();
  wait(1250);
  unityTurn(234, true);
  unityStraight(14, true);
  score();
  // fourth tower
  unityBack(14, true);
  unityTurn(352, true);
  unityStraight(49, false);
  openSkills();
  wait(900);
  release();
  wait(1600);
  unityTurn(272, true);
  unityStraight(7, false);
  wait(700);
  score();
  // fifth tower
  unityBack(8, true);
  unityTurn(88, true);
  openSkills();
  unityStraight(18, false);
  wait(500);
  release();
  wait(450);
  runIntake(max);
  runElevator(8000);
  wait(300);
  runIntake(0);
  runElevator(0);
  unityBack(7, true);
  unityTurn(352, true);
  unityStraight(44, false);
  openSkills();
  wait(750);
  release();
  wait(850);
  unityBack(8, true);
  unityTurn(305, true);
  unityStraight(30, true);
  // runIntake(max / 2);
  score();
  // sixth tower
  // runIntake(0);
  unityBack(51, true);
  runElevator(-max / 4);
  unityTurn(82, true);
  runElevator(0);
  unityStraight(17, false);
  openSkills();
  wait(300);
  release();
  wait(800);
  runElevator(0);
  unityTurn(345, true);
  unityBack(13, false);
  wait(1200);
  // unityTurn(330, true);
  unityStraight(43, false);
  wait(1500);
  // unityTurn(352, true);
  // unityStraight(31, true);
  score();
  //  seventh tower
  unityBack(10, true);
  unityTurn(80, true);
  openSkills();
  unityStraight(48, false);
  wait(900);
  release();
  wait(1100);
  unityTurn(29, true);
  unityStraight(16, true);
  score();
  // eigth tower
  unityBack(25, true);
  unityTurn(190, true);
  unityStraight(40, false);
  openSkills();
  wait(900);
  release();
  runIntake(max);
  runElevator(max / 4);
  wait(1500);
  runIntake(0);
  unityTurn(255, true);
  openSkills();
  unityStraight(14, true);
  runElevator(7500);
  wait(900);
  runElevator(0);
  // ninth tower
  unityBack(10, true);
  release();
  unityTurn(70, true);
  unityStraight(35, false);
  openSkills();
  wait(600);
  release();
  wait(800);
  score();
  unityBack(8, true);
}

void specialty() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  unityStraight(35, true);
  unityTurn(92, true);
  open();
  unityStraight(37, false);
  wait(1150);
  runIntake(max);
  wait(500);
  scoreControlled(400);
  wait(200);
  runElevator(max / 2);
  int foo = pros::millis();
  while (opt.get_hue() < 95) {
    if (pros::millis() - foo > 1500) {
      break;
    }
    if (disSense.get() < 175) {
      runElevator(0);
    }
    runIntake(max * .8);
  }
  runIntake(0);
  runElevator(-max / 4);
  unityBack(6, true);
  runElevator(0);
  // runElevator(0);
  unityTurn(0, true);
  unityTurn(320, true);
  // open();
  unityStraight(36, true);
  unityTurn(325, true);
  open();
  wait(250);
  open();
  unityStraight(9, false);
  wait(1200);
  runIntake(max);
  wait(100);
  runIntake(0);
  unityBack(6, true);
  unityTurn(359, true);
  unityStraight(3, true);
  score();
  score();
  wait(200);
  unityBack(5, true);
}

void bSpecialty() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  unityStraight(35, true);
  unityTurn(92, true);
  open();
  unityStraight(37, false);
  wait(1150);
  runIntake(max);
  wait(500);
  scoreControlled(400);
  wait(200);
  runElevator(max / 2);
  int foo = pros::millis();
  while (opt.get_hue() > 45) {
    if (pros::millis() - foo > 1500) {
      break;
    }
    if (disSense.get() < 175) {
      runElevator(0);
    }
    runIntake(max * .8);
  }
  runIntake(0);
  runElevator(-max / 4);
  unityBack(6, true);
  runElevator(0);
  // runElevator(0);
  unityTurn(0, true);
  unityTurn(320, true);
  // open();
  unityStraight(36, true);
  unityTurn(325, true);
  open();
  wait(250);
  open();
  unityStraight(9, false);
  wait(1200);
  runIntake(max);
  wait(100);
  runIntake(0);
  unityBack(6, true);
  unityTurn(359, true);
  unityStraight(3, true);
  score();
  score();
  wait(200);
  unityBack(5, true);
}

void testFunctions() {
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  unityTurn(90, true);
  unityStraight(70, true);
  unityBack(30, true);
  unityStraight(30, true);
}
} // namespace auton
