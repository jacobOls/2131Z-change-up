#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/drive.hpp"
int leftVel;
int rightVel;
int lJoystickSpeed = 200;
int rJoystickSpeed = 200;
namespace drive{
  void drive(){
    if (std::abs(master.getAnalog(okapi::ControllerAnalog::leftY)) < 0.05)
            leftVel = 0;
        else
            leftVel = (master.getAnalog(ControllerAnalog::leftY) * abs(lJoystickSpeed));

        if (std::abs(master.getAnalog(okapi::ControllerAnalog::rightY)) < 0.05)
            rightVel = 0;
        else
            rightVel = (master.getAnalog(ControllerAnalog::rightY) * abs(rJoystickSpeed));

        right_drive.moveVelocity(rightVel);
        left_drive.moveVelocity(leftVel);
    }
  }
