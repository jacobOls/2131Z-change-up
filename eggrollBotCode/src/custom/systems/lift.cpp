#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/tray.hpp"
namespace lift{
  const double position = 30;
  const double velocity = 50;
  const double trayVelocity = 35;
  Controllers controller = Controllers::NONE;
  double getPosition(){
    return lift::motor.getPosition();
  }

  bool liftUp(){
    return motor.getPosition() > position;
  }
  bool buttonsPressed(){
    return  BtnUp.isPressed() && BtnDown.isPressed();
  }
  // void getOutOfTheWay(){
  //   if(liftUp()){
  //     tray::motor.moveAbsolute(100,100);
  //     pros::lcd::set_text(1,"lift is up");
  //   }
  // }
  void liftMovingUp(){
    if(BtnUp.isPressed()){
      controller = Controllers::UP;
    }
    else if(controller == Controllers::UP){
      controller = Controllers::DEINIT;
    }
  }

  void liftMovingDown(){
    if(BtnDown.isPressed()){
      controller = Controllers::DOWN;
    }
    else if(controller == Controllers::DOWN){
      controller = Controllers::DEINIT;
    }
  }

  void MidTower(){
    if(BtnMidTower.isPressed()){
      controller = Controllers::MIDTOWER;
    }
  }

  void lowTower(){
    if(BtnLowTower.isPressed()){
      controller = Controllers::LOWTOWER;
    }
  }



  void execute(){
    if(motor.getPosition() < 3 && controller== Controllers::DOWN) controller= Controllers::DEINIT;
    if(motor.getPosition() > 500 && controller== Controllers::UP) controller= Controllers::DEINIT;
    switch (controller){
      case Controllers::UP:
      motor.moveVelocity(100);
      break;

      case Controllers::DOWN:
      if(motor.getPosition() > 25){
      motor.moveVelocity(-100);
    }
    else if(motor.getPosition() <25){
      motor.moveVelocity(-25);
    }
      break;

      case Controllers::NONE:
      if(motor.getPosition() < 25){
        motor.moveVelocity(-10);
      }
      break;

      case Controllers::DEINIT:
      motor.moveVelocity(0);
      controller = Controllers::NONE;
      break;

      case Controllers::MIDTOWER:
      motor.moveAbsolute(350,25);
      if (motor.getPosition() < 355 && motor.getPosition() > 345){
        if(motor.isStopped())
        {
          controller = Controllers::DEINIT;
        }
      }
      break;

      case Controllers::LOWTOWER:
      motor.moveAbsolute(250,25);
      if (motor.getPosition() < 255 && motor.getPosition() > 245){
        if(motor.isStopped())
        {
          controller = Controllers::DEINIT;
        }
      }
      break;
    }
  }

  void lift(){
    liftMovingUp();
    liftMovingDown();
    MidTower();
    lowTower();
    execute();
  }

  namespace auton{
    const double targetPosition = 25;
    const double epsilon = 5;
    bool isMotorWithinRange() {
      double position = motor.getPosition();
      if (position > targetPosition - epsilon) {
        return true;
      }
      if (position < targetPosition + epsilon) {
        return true;
      }
      return false;
    }
    void autonLift(double targetPosition, double targetVelocity){
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
