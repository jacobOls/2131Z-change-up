#include "main.h"
#include "custom/auton/selection.hpp"
#include "custom/systems/drive.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/intake.hpp"
#include "custom/systems/tilter.hpp"
#include "custom/setup/auton.hpp"



namespace auton {
  pros::Task autonTask(::auton::Task, (void *)"test", TASK_PRIORITY_DEFAULT,
  TASK_STACK_DEPTH_DEFAULT, "AutonTask");
}
/**
* Runs the user autonomous code. This function will be started in its own task
* with the default priority and stack size whenever the robot is enabled via
* the Field Management System or the VEX Competition Switch in the autonomous
* mode. Alternatively, this function may be called in initialize or opcontrol
* for non-competition testing purposes.
*
* If the robot is disabled or communications is lost, the autonomous task
* will be stopped. Re-enabling the robot will restart the task, not re-start it
* from where it left off.
*/
void autonomous() {

  // puncher::motor.tarePosition();
  auton::set_auton(true);
  auton::autonTask.resume();
  //
  auton::selection::execute();
  // auton::routines::red::front::win();
}
