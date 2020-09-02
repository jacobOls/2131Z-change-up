#include "custom/settup/record.hpp"
#include "custom/settup/motors.hpp"
#include "main.h"
namespace record {

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
  pros::delay(20);
}

} // namespace record
