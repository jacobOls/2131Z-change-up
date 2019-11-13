#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/drive.hpp"
int leftXVel;
int rightXVel;
int leftYVel;
int rightYVel;
namespace drive{
  void drive(){
    if (std::abs(master.getAnalog(okapi::ControllerAnalog::leftY)) < 0.05 && std::abs(master.getAnalog(okapi::ControllerAnalog::leftX)) < 0.05){
      left_drive.moveVelocity(0);
    }
    else if(std::abs(master.getAnalog(okapi::ControllerAnalog::leftY)) > std::abs(master.getAnalog(okapi::ControllerAnalog::leftX))){
      left_drive.moveVelocity(master.getAnalog(okapi::ControllerAnalog::leftY)*200);
    }
    else if(std::abs(master.getAnalog(okapi::ControllerAnalog::leftY)) < std::abs(master.getAnalog(okapi::ControllerAnalog::leftX))){
      if(master.getAnalog(okapi::ControllerAnalog::leftX) > 0.05 && master.getAnalog(okapi::ControllerAnalog::leftX) > master.getAnalog(okapi::ControllerAnalog::rightX)){
        left_strafe.moveVelocity(master.getAnalog(okapi::ControllerAnalog::leftX)*200);
        right_strafe.moveVelocity(master.getAnalog(okapi::ControllerAnalog::leftX)*-200);
      }
    }

    if (std::abs(master.getAnalog(okapi::ControllerAnalog::rightY)) < 0.05 && std::abs(master.getAnalog(okapi::ControllerAnalog::rightX)) < 0.05){
      right_drive.moveVelocity(0);

    }
    else if(std::abs(master.getAnalog(okapi::ControllerAnalog::rightY)) > std::abs(master.getAnalog(okapi::ControllerAnalog::rightX))){
      right_drive.moveVelocity(master.getAnalog(okapi::ControllerAnalog::rightY)*200);
    }
    else if(std::abs(master.getAnalog(okapi::ControllerAnalog::rightY)) < std::abs(master.getAnalog(okapi::ControllerAnalog::rightX))){
      if(master.getAnalog(okapi::ControllerAnalog::rightX) > 0.05 && master.getAnalog(okapi::ControllerAnalog::rightX) > master.getAnalog(okapi::ControllerAnalog::leftX)){
        left_strafe.moveVelocity(master.getAnalog(okapi::ControllerAnalog::rightX)*200);
        right_strafe.moveVelocity(master.getAnalog(okapi::ControllerAnalog::rightX)*-200);
      }
    }
  }

}
