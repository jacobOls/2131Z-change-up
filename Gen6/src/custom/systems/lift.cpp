#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/lift.hpp"

namespace lift{
  Controllers controller = Controllers::NONE;
  void up(){
    if(BtnUp.isPressed()){
      controller = Controllers::UP;
    }
    else if(controller == Controllers::UP){
      controller = Controllers::DEINIT;
    }
  }

  void down(){
    if(BtnDown.isPressed()){
      controller = Controllers::DOWN;
    }
    else if(controller == Controllers::DOWN){
      controller = Controllers::DEINIT;
    }
  }


  void execute(){

    switch (controller)
    {

      case Controllers::UP:

      break;

      case Controllers::DOWN:


      break;
      case Controllers::DEINIT:
      motor.moveVelocity(0);
      controller = Controllers::NONE;
      break;

      case Controllers::NONE:
      break;
    }
  }

  void init(){
    up();
    down();
    execute();
  }

  namespace auton{

    void lift(int pos, int velocity){
      if(motor.getPosition() > pos && velocity > 1){
        velocity = -velocity;
      }
      motor.moveAbsolute(pos,velocity);
    }


  }
}
