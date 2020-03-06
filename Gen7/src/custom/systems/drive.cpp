#include "custom/systems/drive.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "main.h"

namespace drive {

double lVel, rVel;

void userDrive() {
  lVel = master.getAnalog(ControllerAnalog::leftY) * 200;
  rVel = master.getAnalog(ControllerAnalog::rightY) * 200;

  left_drive.moveVelocity(lVel);
  right_drive.moveVelocity(rVel);
}
} // namespace drive
