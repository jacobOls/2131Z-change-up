#include "custom/systems/drive.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "main.h"

namespace drive {

double lVel, rVel;

void userDrive() {
  if (!intake::BtnBackUp.isPressed()) {
    lVel = master.getAnalog(ControllerAnalog::leftY) * 200;
    rVel = master.getAnalog(ControllerAnalog::rightY) * 200;
  } else if (intake::BtnBackUp.isPressed()) {
    lVel = -40;
    rVel = -40;
  }
  left_drive.moveVelocity(lVel);
  right_drive.moveVelocity(rVel);
}
} // namespace drive
