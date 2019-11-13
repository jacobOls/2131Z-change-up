#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/tilter.hpp"
namespace lift{
  Controllers controller = Controllers::NONE;
  void up(){
    if(BtnUp.isPressed()){
      Controllers controller = Controllers::UP;
    }
    else if(controller == Controllers::UP){
      Controllers controller = Controllers::DEINIT;
    }
  }

  void down(){
    if(BtnDown.isPressed()){
    Controllers controller = Controllers::DOWN;
    }
    else if(controller == Controllers::DOWN){
      Controllers controller = Controllers::DEINIT;
    }
  }


  void execute()
  {
    // if (controller == Controllers::UP)
    // {
    //   if (motor.getPosition() > 800)
    //   {
    //     controller = Controllers::DEINIT;
    //   }
    // }
    // if (controller == Controllers::DOWN)
    // {
    //   if (motor.getPosition() < 1200)
    //   {
    //     controller = Controllers::DEINIT;
    //   }
    // }
    switch (controller)
    {

      case Controllers::UP:

        tilter::motor.moveVelocity(75);

      break;

      case Controllers::DOWN:

      motor.moveVelocity(-75);

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
}