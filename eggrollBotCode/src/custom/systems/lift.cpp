#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/tray.hpp"
namespace lift
{
  void lift()
  {
    if(BtnUp.isPressed()){
      motor.moveVelocity(100);
    }
    else if(BtnDown.isPressed()){
      motor.moveVelocity(-100);
    }
    else
    {
      motor.moveVelocity(0);
      motor.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);

    }
  }
  namespace auton
  {
    void autonLift(double position, double targetVelocity)
    {
      motor.moveAbsolute(position, targetVelocity);
    }
    void popOpen()
    {
      motor.moveVelocity(50);
      tray::motor.moveVelocity(50);
    }
  }
}
