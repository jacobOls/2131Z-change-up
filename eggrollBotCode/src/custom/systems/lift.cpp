#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/tray.hpp"
namespace lift{
  const double position = 25;
  const double velocity = 50;
  const double trayVelocity = 35;

  bool liftUp(){
    return motor.getPosition() > position;
  }
  bool buttonsPressed(){
    return  BtnUp.isPressed() && BtnDown.isPressed();
  }
  // void up(){
  //   if(BtnUp.isPressed()){
  //     motor.moveVelocity(velocity);
  //   }
  //
  // }
  // void moveTray(){
  //   if(liftUp()){
  //     tray::motor.moveAbsolute(50,trayVelocity);
  //   }
  // }
  // void down(){
  //   if(BtnDown.isPressed()){
  //     motor.moveVelocity(-velocity);
  //   }
  // }
  // void nothing(){
  //   if (!buttonsPressed()) {
  //     motor.moveVelocity(0);
  //   }
  // }
  // void lift(){
  //   up();
  //   moveTray();
  //   down();
  //   nothing();
  // }
  void lift(){
    if(BtnUp.isPressed()){
      motor.moveVelocity(100);
    }
    if(motor.getPosition() >= position){
      tray::motor.moveAbsolute(150, trayVelocity);
    }
    else if(BtnDown.isPressed()){
      motor.moveVelocity(-100);
    }
    else{
      motor.moveVelocity(0);
      motor.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
    }
  }
  namespace auton{
    const double absolutePosition = 25;
    const double epsilon = 5;
    bool isMotorWithinRange() {
      double position = motor.getPosition();
      if (position > absolutePosition - epsilon) {
        return true;
      }
      if (position < absolutePosition + epsilon) {
        return true;
      }
      return false;
    }
    void autonLift(double position, double targetVelocity)
    {
      while(!isMotorWithinRange()){
        motor.moveVelocity(targetVelocity);
      }
      if(isMotorWithinRange()){
        motor.moveVelocity(0);
      }
    }
    void popOpen(){
      motor.moveAbsolute(100,20);
      tray::motor.moveAbsolute(100,20);
      pros::delay(100);
      motor.moveAbsolute(0,20);
      tray::motor.moveAbsolute(0,20);
    }
  }
}
