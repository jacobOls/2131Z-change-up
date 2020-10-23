#include "custom/settup/record.hpp"
#include "custom/settup/controller.hpp"
#include "custom/settup/motors.hpp"
#include "custom/systems/drive.hpp"
#include "main.h"
namespace record {
okapi::ControllerButton checkpoint = master[okapi::ControllerDigital::up];
void record() {
  FILE *txtWrite = fopen("/usd/info.txt", "a");
  if (txtWrite != NULL) {
    if (checkpoint.changedToPressed()) {
      fprintf(txtWrite, "while(left_front.getPosition < %f){\n ",
              drive::left_front.getPosition());
      fprintf(txtWrite,
              "drive::leftBack.accelMath(accel, &drive::rightFront, %f);\n",
              drive::left_back.getActualVelocity());
      fprintf(txtWrite,
              "drive::leftFront.accelMath(accel, &drive::rightFront, %f)\n",
              drive::left_front.getActualVelocity());
      fprintf(txtWrite,
              "drive::rightDrive.accelMath(accel, &drive::rightBack, %f)\n",
              drive::right_back.getActualVelocity());
      fprintf(txtWrite,
              "drive::rightDrive.accelMath(accel, &drive::rightFront, %f) }\n",
              drive::right_front.getActualVelocity());
      fprintf(txtWrite, "left_drive.moveVelocity(0);");
      fprintf(txtWrite, "right_drive.moveVelocity(0);");
    }
  }
}

} // namespace record
