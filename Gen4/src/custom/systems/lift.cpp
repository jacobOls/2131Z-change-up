#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/tilter.hpp"

namespace lift{
  Controllers controller = Controllers::NONE;
  double sensor(){
    return liftSensor.get_value();
  }
  double tilter(){
    return tilter::tilterSensor.get_value();
  }
  int upPlace;
  int sensorPlace;
  int fastSpeedSpot;

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

  void lowT(){
    if(BtnL.isPressed()){
      controller = Controllers::LOWT;

    }
    else if(controller == Controllers::LOWT){
      controller = Controllers::DEINIT;
    }

  }

  void midT(){
    if(BtnM.isPressed()){
      controller = Controllers::MIDT;

    }
    else if(controller == Controllers::MIDT){
      controller = Controllers::DEINIT;
    }
  }


  void execute(){
    switch(controller){

      case Controllers::UP:
      motor.moveVelocity(75);
      if(tilter() < upPlace){
        tilter::motor.moveVelocity(75);
      }

      break;

      case Controllers::DOWN:
      if(sensor() > fastSpeedSpot){
      motor.moveVelocity(-75);
    }
    else{
      motor.moveVelocity(-25);
    }
      if(sensor() < sensorPlace){
        if(tilter() >= upPlace){
          tilter::motor.moveVelocity(-75);
        }
      }
      break;

      case Controllers::LOWT:
      break;

      case Controllers::MIDT:
      break;

      case Controllers::DEINIT:
      motor.moveVelocity(0);
      tilter::motor.moveVelocity(0);
      controller = Controllers::NONE;
      break;

      case Controllers::NONE:
      break;
    }

  }

  void init(){
    up();
    down();
    lowT();
    midT();
    execute();
  }


}
