#include "main.h"
#include "custom/systems/tray.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/lift.hpp"

namespace tray{
  const double epsilon = 5;
  const double upPosition = 150;
  const double liftPosition = 25;
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
    else if (controller==Controllers::FORWARD){
      controller = Controllers::DEINT;
    }
  }


  void back(){
    if(BtnB.isPressed()){
      controller = Controllers::BACKWARD;
    }
    else if(controller == Controllers::BACKWARD){
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
    if(lift::getPosition()>liftPosition && motor.getPosition()<upPosition) controller= Controllers::LIFT;
    if(!motorCanTravel() && controller== Controllers::FORWARD) controller= Controllers::DEINT;
    switch (controller) {
      // pros::lcd::set_text(3,std::to_string(static_cast<int>(controller));
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
      case Controllers::RETURN:
      pros::lcd::set_text(1,"RETURN" );
      motor.moveAbsolute(0,75);
      if(motor.isStopped()) controller = Controllers::DEINT;
      case Controllers::LIFT:
      static int i;
      i++;
      pros::lcd::set_text(2,std::to_string(i));
      motor.moveAbsolute(upPosition +25, 75);
      if(lift::getPosition()<25) controller = Controllers::RETURN;
      break;
    }
  }
  namespace auton{
    const double absolutePosition = 25;
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
