#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/tilter.hpp"
#include "custom/systems/lift.hpp"

namespace tilter{
  void tilterUp(){
    if(BtnForward.isPressed()){
      motor.moveVelocity(25);
    }
    else if(abs(motor.get_actual_velocity()) > 0 && !BtnBackward.isPressed()){
      motor.moveVelocity(0);
    }
  }

  void tilterDown(){
    if(BtnBackward.isPressed()){
      motor.moveVelocity(-100);
    }
    else if(abs(motor.get_actual_velocity()) > 0 && !BtnForward.isPressed()){
      motor.moveVelocity(0);
    }
  }

  void init(){
    tilterUp();
    tilterDown();
  }
}
