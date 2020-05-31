#include "main.h"
#include "motors.hpp"
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
 double lVel, rVel;

void initialize() {

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

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
void autonomous() {}

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
 // if(loops % 10 == 0){
 //   std::cout << "left_drive.moveVelocity(" << drive::left_front.getActualVelocity() << ")" << std::endl;
 // }

//     if(loops % 20 == 0){
// info = std::to_string(drive::left_front.getActualVelocity());
// FILE* txtWrite = fopen("/usd/info.txt","w+b");
//   fprintf(txtWrite, "foo");
//   fprintf(txtWrite,"left_drive.moveVelocity( %f )",drive::left_front.getActualVelocity());
//
// fclose(txtWrite);
//
//
//     }
double loops = 0;

void write(){

  FILE* txtWrite = fopen("/usd/info.txt","a");
  if(txtWrite != NULL){
  fprintf(txtWrite,"drive::left_drive.moveVelocity( %f );\n pros::delay(20);\n",drive::left_back.getActualVelocity());
  fclose(txtWrite);
  }
}

void opcontrol() {
	okapi::Controller master;

	while (true) {



write();

if(master[okapi::ControllerDigital::R1].isPressed()){
	intakeGroup1::intakegroup.moveVelocity(200);
}
else if(master[okapi::ControllerDigital::R2].isPressed()){
	intakeGroup1::intakegroup.moveVelocity(-200);
}
else {
  intakeGroup1::intakegroup.moveVelocity(0);

}

if(master[okapi::ControllerDigital::L1].isPressed()){
	intakeGroup2::intakegroup.moveVelocity(200);
}
else if(master[okapi::ControllerDigital::L2].isPressed()){
	intakeGroup2::intakegroup.moveVelocity(-200);
}

else {
  intakeGroup2::intakegroup.moveVelocity(0);

}

// 	lVel = master.getAnalog(ControllerAnalog::leftY) * 200;
// 	rVel = master.getAnalog(ControllerAnalog::rightY) * 200;
//
//
// drive::left_drive.moveVelocity(lVel);
// drive::right_drive.moveVelocity(rVel);
if(loops < 40){
drive::left_back.moveVelocity(loops*5);
loops++;
}
pros::delay(20);

	}
}
