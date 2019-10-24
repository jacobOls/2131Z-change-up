#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/drive.hpp"
namespace drive{
  int rightVel; //right side velocity
  int leftVel; //left side velocity

  void tankDrive(){
    //drive code
    if(std::abs(master.getAnalog(okapi::ControllerAnalog::leftY))<0.05) leftVel=0;
    //if input is not great enough, do not move motor so there is no accidetnal input
    else	leftVel=(master.getAnalog(ControllerAnalog::leftY)*200);
    if(std::abs(master.getAnalog(okapi::ControllerAnalog::rightY))<0.05) rightVel=0;
    //if input is not great enough, do not move motor so there is no accidetnal input
    else	rightVel=(master.getAnalog(ControllerAnalog::rightY)*200);

    right_drive.moveVelocity(leftVel);
    left_drive.moveVelocity(rightVel);
  }
}
