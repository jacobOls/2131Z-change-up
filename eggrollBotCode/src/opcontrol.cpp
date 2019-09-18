#include "main.h"
#include "custom/systems/drive.hpp"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/intake.hpp"
#include "custom/systems/tray.hpp"
#include "custom/systems/lift.hpp"
#include "custom/auton/routines.hpp"
/**
* Runs the operator control code. This function will be started in its own task
* with the default priority and stack size whenever the robot is enabled via
* the Field Management System or the VEX Competition Switch in the operator
* control mode.
*
* If no competition control is connected, this function will run immediately
* following initialize().
*
* If the robot is disabled or communications is lost, the
* operator control task will be stopped. Re-enabling the robot will restart the
* task, not resume it from where it left off.
*/
void opcontrol() {

	while (true) {
		pros::lcd::clear_line(3);
		drive::tankDrive();
		// drive::brakeMode();
		drive::auton::stackMacro(-250, 25);
		intake::intake();
		lift::lift();
		tray::tilter();
		pros::delay(20);
	}
}
