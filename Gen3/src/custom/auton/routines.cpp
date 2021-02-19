#include "custom/auton/routines.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/drive.hpp"
#include "custom/systems/elevator.hpp"
#include "custom/systems/intake.hpp"
#include "custom/auton/pid.hpp"
#include "main.h"
namespace auton {
  #define RED true
  #define BLUE false
const int max = 12000;
void wait(int time) { pros::delay(time); }
bool fail = true;
void dont() { fail = false; }
void deploy(){
  runElevator(max);
  wait(100);
  runElevator(0);
}

void redCyclePID(){
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
unityStraight(23,true);
unityTurn(-1370,true);
runIntake(10000);
unityStraight(26,true);
scoreUntil(RED);
runIntake(0);
open();
unityBack(10,true);
}

void rThree() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  drive(17,130);
  turn(225,60,"right");
  runIntake(10000);
  drive(19,140);
  scoreUntil(RED);
  runIntake(0);
  drive(15, -110);
  turn(325, 110, "right");
  eject();
  drive(34, 150);
  runElevator(0);
  turn(195,50,"left");
  runIntake(max);
  drive(13,85);
  scoreUntil(RED);
  runIntake(0);
  drive(8,-60);
}

void brThree() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  drive(17,130);
  turn(225,60,"right");
  runIntake(10000);
  drive(19,140);
  scoreUntil(BLUE);
  runIntake(0);
  drive(15, -110);
  turn(325, 110, "right");
  eject();
  drive(34, 150);
  runElevator(0);
  turn(195,50,"left");
  runIntake(max);
  drive(13,85);
  scoreUntil(BLUE);
  runIntake(0);
  drive(8,-60);
}

void rTwo() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
unityStraight(22,true);
unityTurn(127,true);
open();
unityStraight(28,false);
wait(1000);
runIntake(12000);
scoreUntil(RED);
wait(50);
runIntake(0);
unityBack(20,true);
unityTurn(270,true);
eject();
unityStraight(40,true);
runElevator(0);
unityTurn(180,true);
runIntake(max);
unityStraight(11,false);
wait(1000);
scoreUntil(RED);
open();
runElevator(0);
unityBack(15,true);
release();
}

void brTwo(){
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
unityStraight(22,true);
unityTurn(127,true);
open();
unityStraight(28,false);
wait(1000);
runIntake(12000);
scoreUntil(BLUE);
wait(50);
runIntake(0);
unityBack(20,true);
unityTurn(270,true);
eject();
unityStraight(40,true);
runElevator(0);
unityTurn(180,true);
runIntake(max);
unityStraight(11,false);
wait(1000);
scoreUntil(BLUE);
open();
runElevator(0);
unityBack(15,true);
release();
}


void rOne() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
unityStraight(22,true);
unityTurn(127,true);
open();
unityStraight(28,false);
wait(1000);
runIntake(12000);
scoreUntil(RED);
runIntake(0);
open();
unityBack(10,true);
}

void brOne() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
unityStraight(22,true);
unityTurn(127,true);
open();
unityStraight(28,false);
wait(1000);
runIntake(12000);
scoreUntil(BLUE);
runIntake(0);
open();
unityBack(10,true);
}

void lThree() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
  unityStraight(35,true);
  unityTurn(1250,true);
  open();
  unityStraight(35,false);
  wait(1150);
  runIntake(max);
  scoreUntil(RED);
  open();
  unityBack(30,true);
  release();
  unityTurn(1875,true);
  eject();
  unityStraight(72,true);
  runElevator(0);
  unityTurn(-375,true);
  runIntake(max);
  unityStraight(25,false);
  wait(1150);
  scoreUntil(RED);
  runIntake(0);
  open();
  unityBack(15,true);
}

void lTwo() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
unityStraight(22,true);
unityTurn(234,true);
open();
unityStraight(26,false);
wait(1000);
runIntake(12000);
scoreUntil(RED);
wait(50);
runIntake(0);
unityBack(20,true);
unityTurn(90,true);
eject();
unityStraight(40,true);
runElevator(0);
unityTurn(180,true);
runIntake(max);
unityStraight(8,false);
wait(1300);
scoreUntil(RED);
open();
runElevator(0);
unityBack(15,true);
release();
}

void blTwo(){
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
unityStraight(22,true);
unityTurn(233,true);
open();
unityStraight(26,false);
wait(1000);
runIntake(12000);
scoreUntil(BLUE);
wait(50);
runIntake(0);
unityBack(20,true);
unityTurn(90,true);
eject();
unityStraight(40,true);
runElevator(0);
unityTurn(180,true);
runIntake(max);
unityStraight(11,false);
wait(1000);
scoreUntil(BLUE);
open();
runElevator(0);
unityBack(15,true);
release();
}
void lOne() {
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
unityStraight(22,true);
unityTurn(233,true);
open();
unityStraight(26,false);
wait(1000);
runIntake(12000);
scoreUntil(RED);
  runIntake(0);
  open();
  unityBack(10,true);
}
void blOne(){
  if (fail) {
    dont();
  }
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  deploy();
unityStraight(22,true);
unityTurn(233,true);
open();
unityStraight(26,false);
wait(1000);
runIntake(12000);
scoreUntil(BLUE);
 runIntake(0);
 open();
 unityBack(10,true);
}
void skills() {
//   if (fail) {
//     dont();
//   }
//   drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
//   drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
//   deploy();
//   open();
// unityStraight(22,false);
// wait(400);
// release();
// wait(300);
// unityTurn(-1690,true);
// runIntake(12000);
// unityStraight(28,true);
// // scoreUntil(RED);
// score();
// wait(50);
// runIntake(0);
// unityBack(20,true);
// unityTurn(-1930,true);
// eject();
// wait(200);
// runElevator(0);
// unityStraight(43,true);
// runElevator(0);
// unityTurn(1100,true);
// runIntake(max);
// unityStraight(10,false);
// wait(1000);
// score();
// // runElevator(0);
// open();
// unityBack(15,true);
// unityTurn(-1000,true);
// unityStraight(37,false);
// wait(300);
// release();
// wait(900);
// unityTurn(13000,true);
// unityStraight(20,true);
// score();
  drive::left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  drive::right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  if (fail) {
    dont();
  }
  runIntake(max);
  drive(24, 150);
  turn(260, 80, "right");
  drive(29, 150);
  score();

  runIntake(0);
  open();
  runElevator(-max/3);
  drive(10, -80);
  runElevator(0);
  release();
  turn(330, 100, "right");
  open();
  clampDrive(50, 41, 130);
  release();
  // runElevator(max / 4);
  turn(230, 80, "left");
  runElevator(0);
  drive(30, 100);
  score();

  drive(5, -40);
  turn(175, 50, "right");
  // runIntake(max);
  open();
  clampDrive(42,30,110);
  turn(70, 60, "left");
  drive(11, 90);
  runIntake(max);
  score();
eject();
runIntake(0);

  drive(6, -50);
  runElevator(0);
  turn(260, 50, "right");
  open();
  clampDrive(56, 42, 200);
  turn(190, 70, "left");
  drive(14, 50);
  score();

  drive(10, -50);
  turn(170, 60, "right");
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
  // unityStraight(35,true);
  unityTurn(195,true);
  // unityStraight(20,true);
}

} // namespace auton
