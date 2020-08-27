#include "main.h"
#include "custom/auton/selection.hpp"
#include "custom/settup/motors.hpp"
#include "custom/systems/drive.hpp"
#include "custom/systems/intake.hpp"
#include "custom/systems/wheel.hpp"

void initialize() { selection::init(); }

void disabled() {}

void competition_initialize() {}

void autonomous() { selection::execute(); }

void record() {
  FILE *txtWrite = fopen("/usd/info.txt", "a");
  if (txtWrite != NULL) {
    fprintf(txtWrite, "drive::left_back.moveVelocity( %f );\n",
            drive::left_back.getActualVelocity());
    fprintf(txtWrite, "drive::left_front.moveVelocity( %f );\n",
            drive::left_front.getActualVelocity());
    fprintf(txtWrite, "drive::right_back.moveVelocity( %f );\n",
            drive::right_back.getActualVelocity());
    fprintf(txtWrite, "drive::right_front.moveVelocity( %f );\n",
            drive::right_front.getActualVelocity());
    fprintf(txtWrite, "intake::intakeGroup.moveVelocity( %f );\n",
            intake::intakeGroup.getActualVelocity());
    fprintf(txtWrite, "wheel::wheelGroup.moveVelocity( %f ); \n",
            wheel::wheelGroup.getActualVelocity());
    fprintf(txtWrite, "pros::delay(20);");
    fclose(txtWrite);
  }
  // pros::delay(20);\n
}
void opcontrol() {

  while (true) {
    intake::init();
    wheel::init();
    drive::userDrive();
    record();
    pros::delay(20);
  }
}
