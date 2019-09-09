#include "main.h"
#include "custom/systems/tray.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
bool trayMove = false;
#define traySpeed 35
//#define position 100
const double position =  350.0;
namespace tray
{
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
  // void tray(){
  //   if(motor.getPosition() > position)
  //   {
  //     if(BtnF.isPressed())
  //     {
  //       controller=Contollers::FORWARD;
  //       motor.moveVelocity(traySpeed);
  //     }
  //     else if(BtnB.isPressed())
  //     {
  //       controller=Contollers::BACKWARD;
  //
  //       motor.moveVelocity(-traySpeed);
  //     }
  //     else
  //     {
  //       controller=Contollers::DEINT;
  //
  //
  //     }
  //   }
  //   else{//zone 2
  //     if(BtnB.isPressed())
  //     {
  //       controller=Contollers::BACKWARD;
  //       motor.moveVelocity(-traySpeed);
  //     }
  //     else{
  //       controller=Contollers::DEINT;
  //
  //     }
  //   }
  // }
  // void execute(){
  //   switch (controller) {
  //     case Contollers::FORWARD:
  //     motor.moveVelocity(traySpeed);
  //     break;
  //     case Contollers::BACKWARD:
  //     motor.moveVelocity(-traySpeed);
  //     break;
  //     case Contollers::DEINT:
  //     motor.moveVelocity(0);
  //     controller = Contollers::NONE;
  //     break;
  //     case Contollers::NONE:
  //     break;
  //   }
  // }
  namespace auton{
    void stack(double tiltPosition, double targetVelocity)
    {
      motor.moveAbsolute(tiltPosition, targetVelocity);
      pros::delay(3);
      motor.moveAbsolute(0, targetVelocity);
    }
  }
}
