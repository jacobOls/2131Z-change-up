#include "main.h"
#include "custom/systems/tray.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/lift.hpp"

namespace tray{
  // bool trayMove = false;
  const double traySpeed = 25.0;
  const double position =  585.0;
  Controllers controller = Controllers::NONE;
  bool motorCanTravel() {
    return motor.getPosition() < position;
  }
  bool liftUp(){
    return lift::motor.getPosition() >= 10;
  }
  bool liftButtons(){
    return lift::BtnUp.isPressed() || lift::BtnDown.isPressed();
  }
  void forward(){
    if( BtnF.isPressed()){
      controller = Controllers::FORWARD;
    }
    else{
      controller = Controllers::DEINT;
    }
  }


  void back(){
    if(BtnB.isPressed()){
      controller = Controllers::BACKWARD;
    }
    else if(!BtnB.isPressed() && !BtnF.isPressed()){
      controller = Controllers::DEINT;
    }
  }
  // void nothing(){
  //   if (!motorCanTravel()) {
  //     if (!BtnB.isPressed()) {
  //       if(!liftButtons()){
  //         motor.moveVelocity(0);
  //       }
  //     }
  //   }
  //   if(!BtnB.isPressed() && !BtnF.isPressed()){
  //     motor.moveVelocity(0);
  //   }
  // }
  void tilter(){
    // if(motorCanTravel()){
      forward();
      back();
      execute();
      // nothing();

    // }
    // else {
      // back();
      // nothing();
    }
  void execute(){
if(lift::getPosition()<25 && motor.getPosition()<150) controller= Controllers::LIFT;
    if(!motorCanTravel() && controller== Controllers::FORWARD) controller= Controllers::DEINT;
    switch (controller) {
      case Controllers::FORWARD:
      motor.moveVelocity(traySpeed);
      break;
      case Controllers::BACKWARD:
      motor.moveVelocity(-traySpeed);
      break;
      case Controllers::DEINT:
      motor.moveVelocity(0);
      controller = Controllers::NONE;
      break;
      case Controllers::NONE:
      break;
      case Controllers::LIFT:
      motor.moveAbsolute(150+25, traySpeed);
      if(motor.isStopped()) controller = Controllers::DEINT;
      break;
    }
  }
  namespace auton{
    const double absolutePosition = 25;
    const double epsilon = 5;
    bool isMotorWithinRange() {
      double currentPosition = motor.getPosition();
      if (currentPosition > absolutePosition - epsilon) {
        return true;
      }
      if (currentPosition < absolutePosition + epsilon) {
        return true;
      }
      return false;
    }
    void stack(double currentPosition, double targetVelocity){

      while(!isMotorWithinRange())
      {
        motor.moveVelocity(targetVelocity);
        pros::delay(20);
      }
      if(isMotorWithinRange())
      motor.moveVelocity(0);
    }
  }
}
