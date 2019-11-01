#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/tilter.hpp"
#include "custom/systems/lift.hpp"

namespace tilter{
  Controllers controller = Controllers::NONE;
  double sensor(){
    return  tilterSensor.get_value();
  }
  double lSensor(){
    return lift::liftSensor.get_value();
  }

int halfDown;
int allDown;

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

  void returnDown(){
    if(BtnDown.isPressed()){
      controller = Controllers::RETURN;
    }
    else if(controller == Controllers::RETURN){
      controller = Controllers::DEINIT;
    }
  }



  void execute(){
    if(controller == Controllers::UP){
      if(sensor() > 2200){
        controller = Controllers::DEINIT;
      }
    }
    if(controller == Controllers::DOWN){
      if(sensor() < 1000){
        controller = Controllers::DEINIT;
      }
    }
    switch(controller){

      case Controllers::UP:
      motor.moveVelocity(25);
      break;

      case Controllers::DOWN:
      motor.moveVelocity(75);
      break;

      case Controllers::RETURN:
      if(lSensor() > 1200){
        if(sensor() >= halfDown){
          motor.moveVelocity(-100);
        }
      }
      else if(sensor() >= allDown){
        motor.moveVelocity(-100);
      }
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
