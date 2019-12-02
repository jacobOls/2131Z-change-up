#include "custom/systems/drive.hpp"
#include "custom/systems/lift.hpp"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"

namespace drive{
  int lStick(){
    return std::abs(master.getAnalog(okapi::ControllerAnalog::leftY));
  }

  int rStick(){
    return std::abs(master.getAnalog(okapi::ControllerAnalog::rightY));
  }
  int height(){
    return std::abs(lift::motor.getPosition()/500);
  }
  void userDrive(){
    if(lift::motor.getPosition() < 300){
      if(lStick() < 0.5){
        left_drive.moveVelocity(0);
      }
      else{
        left_drive.moveVelocity(lStick()*200);
      }


      if(rStick() < 0.5){
        right_drive.moveVelocity(0);
      }
      else{
        right_drive.moveVelocity(rStick()*200);
      }
    }
    else{
      if(lStick() < 0.5){
        left_drive.moveVelocity(0);
      }
      else{
        left_drive.moveVelocity(lStick()*200/height());
      }


      if(rStick() < 0.5){
        right_drive.moveVelocity(0);
      }
      else{
        right_drive.moveVelocity(rStick()*200/height());
      }
    }
  }
}
