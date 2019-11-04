#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/drive.hpp"

namespace drive
{

int rightVel;
int leftVel;

void drive()
{
  //drive code
  if (std::abs(master.getAnalog(okapi::ControllerAnalog::leftY)) < 0.05)
    leftVel = 0;
  else
    leftVel = (master.getAnalog(ControllerAnalog::leftY) * 200);
  if (std::abs(master.getAnalog(okapi::ControllerAnalog::rightY)) < 0.05)
    rightVel = 0;
  else
    rightVel = (master.getAnalog(ControllerAnalog::rightY) * 200);

  right_drive.moveVelocity(rightVel);
  left_drive.moveVelocity(leftVel);
}

namespace auton{
  void resetPositions(){
  left_drive.tarePosition();
  right_drive.tarePosition();

}





}

} // namespace drive
