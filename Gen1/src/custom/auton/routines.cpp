#include "custom/auton/routines.hpp"
#include "custom/systems/drive.hpp"
#include "custom/systems/intake.hpp"
#include "custom/systems/wheel.hpp"
#include "main.h"
namespace auton {
void wait(int time) { pros::delay(time); }

void redAuton() { // start between middle and right tower
  strafe(360, 200, "left");
  drive(310, 200);
  runIntake(200);
  turn(600, 120, "right");
  runIntake(0);
  runWheel(200);
  wait(100);
  runWheel(0);
  drive(-200, -150);
  turn(40, 30, "right");
  strafe(400, 150, "left"); // reckoning
  strafe(1750, 200, "right");
  runIntake(200);
  drive(330, 150);
  runIntake(0);
  runWheel(200);
  wait(100);
  runWheel(0);
  drive(-330, -150);
  strafe(1060, 200, "right");
  turn(480, 100, "left");
  runIntake(200);
  drive(275, 100);
  runIntake(0);
  runWheel(200);
  wait(100);
  runWheel(0);
  drive(-200, -200);
}

void testFunctions() {
  drive(500, 200);
  strafe(400, 100, "left");
  turn(400, 100, "right");
  runWheel(200);
  runIntake(200);
  wait(500);
  runWheel(0);
  runIntake(0);
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
