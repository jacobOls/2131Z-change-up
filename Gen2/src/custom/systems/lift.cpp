#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/tray.hpp"
namespace lift{
  double position = 30;
  double velocity = 50;
  double trayVelocity = 35;
  int startUp = 2150;
  int upPlace = 2000;
  int forwardPos;
  int fastSpeedSpot = 2200;
  int sensorPlace = 2020;
  Controllers controller = Controllers::NONE;
  double getPosition(){
    return lift::motor.getPosition();
  }
  double sensor(){
    return liftSensor.get_value();
  }
  double tilter(){
    return tray::traySensor.get_value();
  }
  bool liftUp(){
    return motor.getPosition() > position;
  }

  bool buttonsPressed(){
    return  BtnUp.isPressed() && BtnDown.isPressed();
  }

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



  /* pot positions
  down  2380
  tray pop 2300
  up  1000
  MidTower 1200
  lowTower 1630
  the lower the number the higher it is
  */


  void execute(){
    if(sensor() > 2380 && controller== Controllers::DOWN) controller= Controllers::DEINIT;
    if(sensor() < 800 && controller== Controllers::UP) controller= Controllers::DEINIT;
    switch (controller){
      case Controllers::UP:
      // motor.moveVelocity(100);
      // if(sensor() > forwardPos ){
      //   tray::motor.moveVelocity(75);
      // }
      if (tilter() > startUp)
  {
    tray::motor.moveVelocity(40);
  }
  else if(tilter() <= startUp)
  {
    if (tilter() > upPlace)
    {
    motor.moveVelocity(100);
      tray::motor.moveVelocity(40);
    }
    else{
      motor.moveVelocity(100);
      tray::motor.moveVelocity(0);
    }
  }
      break;

      case Controllers::DOWN:
      // if(encoder() <= 2300){
      //   motor.moveVelocity(-100);
      //   if(tilter() <= forwardPos){
      //     motor.moveVelocity(-100);
      //   }
      // }
      // else if(encoder() > 2300){
      //   motor.moveVelocity(-25);
      //   if(tilter() <= forwardPos){
      //     motor.moveVelocity(-25);
      //   }
      // }
      if (sensor() < fastSpeedSpot)
        {
          motor.moveVelocity(-75);
        }
        else
        {
          motor.moveVelocity(-25);
        }
        if (sensor() > sensorPlace)
        {
          if (tilter() <= upPlace)
          {
            tray::motor.moveVelocity(-75);
          }
        }
      break;

      case Controllers::NONE:
      // pros::lcd::set_text(4,"NONE" );
      break;

      case Controllers::DEINIT:
      motor.moveVelocity(0);
      tray::motor.moveVelocity(0);
      controller = Controllers::BOTTOM;
      break;

      case Controllers::BOTTOM:
      // if(!buttonsPressed()){
      //   if(encoder() > 2200 && encoder() < 2350){
      //     motor.moveVelocity(-25);
      //   }
      //   else{
      //     motor.moveVelocity(0);
      //     controller = Controllers::NONE;
      //   }
      // }
      break;


}
}

  void lift(){
    liftMovingUp();
    liftMovingDown();
    execute();
  }
  namespace auton{
    bool unpopped = true;
    bool popped = false;
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
    void autonLiftUp(double targetPosition, double targetVelocity){
      while(sensor() <= targetPosition){
        motor.moveVelocity(targetVelocity);
      }
      if(sensor() >= targetPosition){
        motor.moveVelocity(0);
      }
    }

    void autonLiftDown(double wantedPosition, double targetVelocity){
      if(sensor() <= wantedPosition){
        motor.moveVelocity(targetVelocity);
      }
      if(sensor() >= wantedPosition){
        motor.moveVelocity(0);
      }
    }





    void popOpen(){
      if(sensor() > 1600){
        motor.moveVelocity(90);
        tray::motor.moveVelocity(60);
      }
      if(sensor() <= 1600){
        motor.moveVelocity(0);
        tray::motor.moveVelocity(0);
      }
    }
  }
}
