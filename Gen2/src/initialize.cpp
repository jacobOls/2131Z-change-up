#include "main.h"
#include "custom/systems/tray.hpp"
#include "custom/setup/motors.hpp"
#include "custom/auton/routines.hpp"
#include "custom/systems/drive.hpp"
#include "custom/auton/selection.hpp"
#include "custom/setup/config.hpp"
#include "custom/auton/selection.hpp"
#include "custom/auton/auto.hpp"
/**
* Runs initialization code. This occurs as soon as the program is started.
*
* All other competition modes are blocked by initialize; it is recommended
* to keep execution time for this mode under a few seconds.
*/
void initialize() {
	config::tareMotors();
	tray::motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	intake::right_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	intake::left_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	intake::intakegroup.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	lift::motor.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
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
	config::tareMotors();
	tray::motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	intake::right_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	intake::left_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	intake::intakegroup.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	lift::motor.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
}