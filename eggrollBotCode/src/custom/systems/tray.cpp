#include "main.h"
#include "custom/systems/tray.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/lift.hpp"

namespace tray{
  // bool trayMove = false;
  const double traySpeed = 25.0;
  const double position =  585.0;
  Contollers controller = Contollers::NONE;
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
      controller = Contollers::FORWARD;
    }
    else{
      controller = Contollers::DEINT;
    }
  }


  void back(){
    if(BtnB.isPressed()){
      controller = Contollers::BACKWARD;
    }
    else if(!BtnB.isPressed() && !BtnF.isPressed()){
      controller = Contollers::DEINT;
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
if(lift::getPosition()<25 && motor.getPosition()<150) controller= Contollers::LIFT;


    if(!motorCanTravel() && controller== Contollers::FORWARD) controller= Contollers::DEINT;
    switch (controller) {
      case Contollers::FORWARD:
      motor.moveVelocity(traySpeed);
      break;
      case Contollers::BACKWARD:
      motor.moveVelocity(-traySpeed);
      break;
      case Contollers::DEINT:
      motor.moveVelocity(0);
      controller = Contollers::NONE;
      break;
      case Contollers::NONE:
      break;
      case Contollers::LIFT:
      motor.moveAbsolute(150+25, traySpeed);
      if(motor.isStopped()) controller = Contollers::DEINT;
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
