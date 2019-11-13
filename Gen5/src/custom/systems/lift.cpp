#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/tilter.hpp"
namespace lift{
  void up(){
    if(BtnUp.isPressed()){
      motor.moveVelocity(100);
    }
    else if(abs(motor.get_actual_velocity()) > 0 && !BtnDown.isPressed()){
      motor.moveVelocity(0);
    }
  }

  void down(){
    if(BtnDown.isPressed()){
      motor.moveVelocity(-100);
    }
    else if(abs(motor.get_actual_velocity()) > 0 && !BtnUp.isPressed()){
      motor.moveVelocity(0);
    }
  }


  void init(){
    up();
    down();
  }
}
