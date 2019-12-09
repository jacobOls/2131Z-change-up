#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/tilter.hpp"
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
    if(motor.getPosition() > 2131 && controller == Controllers::UP){
      controller = Controllers::DEINIT;
    }
    if(motor.getPosition() < 5 && controller == Controllers::DOWN){
      controller = Controllers::DEINIT;
    }
    switch (controller)
    {

      case Controllers::UP:
      motor.moveVelocity(100);
      // tilter::motor.moveVelocity(75);

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

  namespace auton{

    void lift(int pos, int velocity){
      while(motor.getPosition() < pos-5 && motor.getPosition() > pos+5){
        if(motor.getPosition() > pos && velocity > 1){
          velocity = -velocity;
        }
        motor.moveAbsolute(pos,velocity);
      }
    }

  }
}
