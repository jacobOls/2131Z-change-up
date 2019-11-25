#include "main.h"
#include "custom/systems/drive.hpp"
#include "custom/systems/intake.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/tilter.hpp"
#include "custom/setup/motors.hpp"
#include "custom/auton/selection.hpp"
#include "custom/auton.hpp"
/**
* A callback function for LLEMU's center button.
*
* When this callback is fired, it will toggle line 2 of the LCD text between
* "I was pressed!" and nothing.
*/

/**
* Runs initialization code. This occurs as soon as the program is started.
*
* All other competition modes are blocked by initialize; it is recommended
* to keep execution time for this mode under a few seconds.
*/
void initialize() {
	tilter::motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	intake::right_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	intake::left_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	intake::intakegroup.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	lift::motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	lift::motor.tarePosition();
	tilter::motor.tarePosition();
	std::cout << "initialize " << std::endl;
	auton::screenInit();
}

/**
* Runs while the robot is in the disabled state of Field Management System or
* the VEX Competition Switch, following either autonomous or opcontrol. When
* the robot is enabled, this task will exit.
*/
void disabled() {
	auton::autonTask.suspend();
	auton::set_auton(false);
}

/**
* Runs after initialize(), and before autonomous when connected to the Field
* Management System or the VEX Competition Switch. This is intended for
* competition-specific initialization routines, such as an autonomous selector
* on the LCD.
*
* This task will exit when the robot is enabled and autonomous or opcontrol
* starts.
*/
void competition_initialize() {

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
namespace auton{
	pros::Task autonTask(::auton::Task, (void *)"test", TASK_PRIORITY_DEFAULT,
	TASK_STACK_DEPTH_DEFAULT, "AutonTask");
}

void autonomous() {
	auton::screenInit();
	auton::set_auton(true);
	auton::autonTask.resume();
	auton::execute();
}

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

	while (2131 == 2131){
		drive::drive();
		intake::init();
		lift::init();
		tilter::init();
		pros::delay(20);
	}
}
