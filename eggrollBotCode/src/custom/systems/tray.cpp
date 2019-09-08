#include "main.h"
#include "custom/systems/tray.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
bool trayMove = false;
#define traySpeed 35
#define position -500
namespace tray
{
  Contollers controller = Contollers::NONE;
  void tray()
  {
    // if(BtnF.isPressed() && motor.getPosition() >= -500)
    // {
    //   motor.moveVelocity(traySpeed);
    // }
    // else if (BtnB.isPressed())
    // {
    //   motor.moveVelocity(-traySpeed);
    // }
    // else
    // {
    //   motor.moveVelocity(0);
    //   motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    // }

    if(motor.getPosition() > position)
    {
      if(BtnF.isPressed())
      {
        controller=Contollers::FORWARD;
        motor.moveVelocity(traySpeed);
      }
      else if(BtnB.isPressed())
      {
        controller=Contollers::BACKWARD;

        motor.moveVelocity(-traySpeed);
      }
      else
      {
        controller=Contollers::DEINT;


      }
    }
    else{//zone 2
      if(BtnB.isPressed())
      {
        controller=Contollers::BACKWARD;
        motor.moveVelocity(-traySpeed);
      }
      else
      {
        controller=Contollers::DEINT;

      }
    }
  }
  void execute(){
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
    }
  }
  namespace auton
  {
    void stack(double tiltPosition, double targetVelocity, double delay)
    {
      motor.moveAbsolute(tiltPosition, targetVelocity);
      pros::delay(delay);
      motor.moveAbsolute(0, targetVelocity);
    }
  }
}
