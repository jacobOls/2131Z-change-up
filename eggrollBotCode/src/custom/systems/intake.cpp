#include "main.h"
#include "custom/systems/intake.hpp"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"

namespace intake
{
  #define spinSpeed 25
  bool BothLeftAndRightButtonsPressed() {
    return BtnLeft.isPressed() && BtnRight.isPressed();
  }
  void spinLeft() {
    left_motor.moveVelocity(spinSpeed);
    right_motor.moveVelocity(-spinSpeed);
  }
  void spinRight() {
    left_motor.moveVelocity(-spinSpeed);
    right_motor.moveVelocity(spinSpeed);
  }
  //
  void stopIntake() {
    intakegroup.moveVelocity(0);
  }

  void intake()
  {
    if (BothLeftAndRightButtonsPressed())
    {
      intakegroup.moveVelocity(-200);
    }
    else if(BtnOn.isPressed())
    {
      intakegroup.moveVelocity(200);
    }
    else if(BtnOut.isPressed())
    {
      intakegroup.moveVelocity(-50);
    }
    else if(BtnLeft.isPressed())
    {
      spinLeft();

    }
    else if(BtnRight.isPressed())
    {
      spinRight();

    }
    else
    {
      stopIntake();
    }
  }
  namespace auton
  {
    bool intakeRunning = false;
    void intakeOn(double targetVelocity)
    {
      intakeRunning = true;
      while(intakeRunning){
        intakegroup.moveVelocity(targetVelocity);
      }
    }
    void intakeOff()
    {
      intakeRunning = false;
    }
  }
}
