#include "main.h"
#include "custom/systems/tray.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
bool trayMove = false;
const double traySpeed = 35.0;
const double position =  450.0;
namespace tray{
  // Contollers controller = Contollers::NONE;
  bool motorCanTravel() {
    return motor.getPosition() < position;
  }
  void forward(){
    if (motorCanTravel()){
      if( BtnF.isPressed()){
        motor.moveVelocity(traySpeed);
      }
    }
  }
  void back(){
    if(BtnB.isPressed()){
      motor.moveVelocity(-traySpeed);
    }
  }
  void nothing(){
    if (!motorCanTravel()) {
      if (!BtnB.isPressed()) {
        motor.moveVelocity(0);
      }
    }
    if(!BtnB.isPressed() && !BtnF.isPressed()){
      motor.moveVelocity(0);
    }
  }
  void tilter(){
    if(motorCanTravel()){
      forward();
      back();
      nothing();
    }
    else {
      back();
      nothing();
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
