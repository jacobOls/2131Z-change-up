#include "custom/auton/routines.hpp"
#include "custom/settup/motors.hpp"
#include "custom/systems/drive.hpp"
#include "custom/systems/intake.hpp"
#include "custom/systems/wheel.hpp"
#include "main.h"
namespace auton {
void wait(int time) { pros::delay(time); }

void redAuton() { // start between middle and right tower
  strafe(100, 50, "left");
  runIntake(200);
  drive(100, 50);
  turn(80, 90, "right");
  drive(100, 50);
  runIntake(0);
  runWheel(200);
  wait(700);
  runWheel(0);
  drive(130, -100);
  turn(765, 100, "right");
  runWheel(25);
  drive(675, 200);
  runWheel(200);
  wait(700);
  runWheel(0);
  drive(50, -100);
  strafe(900, 150, "right");
  turn(20, 25, "left");
  runIntake(200);
  drive(1700, 170);
  runWheel(200);
  wait(1000);
  runIntake(0);
  runWheel(0);
  drive(200, -200);

  // runIntake(200);
  // drive(100, 50);
  // turn(80, 90, "right");
  // drive(100, 50);
  // runIntake(0);
  // runWheel(200);
  // wait(700);
  // runWheel(0);
  // drive(150, -175);
  // turn(240, 100, "right");
  // timeStrafe(9000, 1500, "left"); // reckoning
  // strafe(1800, 200, "right");
  // runIntake(200);
  // drive(180, 200);
  // runIntake(0);
  // runWheel(200);
  // wait(1200);
  // runWheel(0);
  // runIntake(-100);
  // drive(-100, -175);
  // runIntake(0);
  // strafe(1060, 200, "right");
  // turn(180, 100, "right");
  // runIntake(200);
  // drive(650, 200);
  // runIntake(0);
  // runWheel(200);
  // wait(1000);
  // runWheel(0);
  // drive(-200, -200);
}

void blueHome() {
  strafe(475, 200, "right");
  runIntake(200);
  turn(180, 90, "left");
  runWheel(25);
  drive(600, 140);
  runIntake(0);
  runWheel(200);
  wait(700);
  runWheel(0);
  drive(150, -150);
  turn(240, 100, "left");
  strafe(850, 120, "right"); // reckoning
  strafe(1800, 200, "left");
  runIntake(200);
  drive(275, 150);
  runIntake(0);
  runWheel(200);
  wait(800);
  runWheel(0);
  runIntake(-100);
  drive(-100, -150);
  runIntake(0);
  strafe(1060, 200, "left");
  turn(210, 100, "left");
  runIntake(200);
  drive(800, 100);
  runIntake(0);
  runWheel(200);
  wait(1000);
  runWheel(0);
  drive(-200, -200);
}
void skills() {
  runIntake(200);
  runWheel(60);
  drive(700, 100);
  runWheel(0);
  turn(450, 100, "right");
  drive(540, 100);
  drive(250, -100);
  turn(270, 90, "right");
  runIntake(140);
  runWheel(20);
  drive(700, 100);
  runWheel(200);
  wait(500);
  runWheel(-25);
  runIntake(-25);
  drive(275, -100);
  runWheel(0);
  runIntake(0);
  turn(240, 100, "right");
  strafe(625, 120, "left"); // reckoning
  strafe(1800, 200, "right");
  runIntake(200);
  drive(250, 150);
  runIntake(0);
  runWheel(200);
  wait(800);
  runWheel(0);
  runIntake(-100);
  drive(-100, -150);
  runIntake(0);
  strafe(1060, 200, "right");
  turn(210, 100, "right");
  runIntake(200);
  drive(800, 100);
  runIntake(0);
  runWheel(200);
  wait(1000);
  runWheel(0);
  drive(-200, -200);
  /*
  turn(710, 100, "left");
  strafe(1700, 100, "left");
  runIntake(200);
  runWheel(50);
  drive(400, 100);
  runIntake(0);
  runWheel(0);
  drive(500, 200);
  runWheel(200);
  wait(700);
  runWheel(0);
  */
}
void testFunctions() {
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
  drive(500, -100);
  // strafe(800, 200, "left");
  // strafe(800, 200, "right");
}
} // namespace auton

/*front left strafe 360
forward 310
turn 600
spit in
back 200
turn 40
reckon left voltage
strafe right 1750
forward 330
ball 2 in
backup 330
strafe right 1060
turn 480
forward 275
spit in
backup 200
*/
