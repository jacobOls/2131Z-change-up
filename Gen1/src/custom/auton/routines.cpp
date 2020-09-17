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
  turn(600, 120, "right");
  runWheel(200);
  wait(100);
  runWheel(0);
  drive(-200, -150);
  turn(40, 30, "right");
  strafe(400, 150, "left");
  strafe(1750, 200, "right");
  drive(330, 150);
  runWheel(200);
  wait(100);
  runWheel(0);
  drive(-330, -150);
  strafe(1060, 200, "right");
  turn(480, 100, "left");
  drive(275, 100);
  runWheel(200);
  wait(100);
  runWheel(0);
  drive(-200, -200);
}
} // namespace auton

/*front left strafe 360
reset motors
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
