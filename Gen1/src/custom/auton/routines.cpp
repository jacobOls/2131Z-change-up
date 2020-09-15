#include "custom/auton/routines.hpp"
#include "custom/systems/drive.hpp"
#include "custom/systems/intake.hpp"
#include "custom/systems/wheel.hpp"
#include "main.h"
namespace auton {

void redAuton() {
  strafe(360, 200, "left");
  drive(310, 200);
  turn(600, 120, "right");
  runWheel(200);
  pros::delay(100);
  runWheel(0);
  drive(-200, -150);
  turn(40, 30, "right");
  strafe(400, 150, "left");
  strafe(1750, 200, "right");
  drive(330, 150);
  runWheel(200);
  pros::delay(100);
  runWheel(0);
  drive(-330, -150);
  strafe(1060, 200, "right");
  turn(480, 100, "left");
  drive(275, 100);
  runWheel(200);
  pros::delay(100);
  runWheel(0);
  drive(-200, -200);
}
} // namespace auton

/*front left strafe 360
reset motors
forward 310
reset
turn 600
reset
spit in
back 200
reset
turn 40
reckon left voltage
reset
strafe right 1750
reset
forward 330
reset
ball 2 in
backup 330
reset
strafe right 1060
reset
turn 480
reset
forward 275
spit in
backup 200
*/
