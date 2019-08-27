#include "main.h"
#include "custom/systems/intake.hpp"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/clamp.hpp"
//intakes cubes
namespace intake
{
  void intake()
  {
    if(BtnLeft.isPressed() && BtnRight.isPressed())
    {
      intakegroup.moveVelocity(-200);
    }
    else if(BtnOn.isPressed())
    {
      // while (infeed)
      // infeed = true;
      // {
      intakegroup.moveVelocity(200);
      // if(BtnOn.isPressed()){
      // infeed = false;
      // }
      // }
    }
    else if(BtnOut.isPressed())
    {
      intakegroup.moveVelocity(-50);
    }


    else if(BtnLeft.isPressed())
    {
      motor.moveVelocity(200);
      motor2.moveVelocity(-200);
    }
    else if(BtnRight.isPressed())
    {
      motor.moveVelocity(-200);
      motor2.moveVelocity(200);
    }


    else
    {
      intakegroup.moveVelocity(0);
      intakegroup.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    }
  }
  void intakein()
  {
    if(BtnOn.isPressed())
    {

      intakegroup.moveVelocity(200);
      clamp::clampMotor.moveAbsolute(60,200);
    }
  }
  void outake()
  {
    if(BtnLeft.isPressed() && BtnRight.isPressed())
    {
      intakegroup.moveVelocity(-200);
    }
    else if(BtnOut.isPressed())
    {
      intakegroup.moveVelocity(-50);
    }
  }
  void spin()
  {
    if(BtnLeft.isPressed())
    {
      motor.moveVelocity(200);
      motor2.moveVelocity(-200);
    }
    else if(BtnRight.isPressed())
    {
      motor.moveVelocity(-200);
      motor2.moveVelocity(200);
    }
    else
    {
      intakegroup.moveVelocity(0);
      intakegroup.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    }
  }
  void intakecontrol()
  {
    intakein();
    outake();
    spin();
  }
}
