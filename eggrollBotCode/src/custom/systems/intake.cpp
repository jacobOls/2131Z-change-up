#include "main.h"
#include "custom/systems/intake.hpp"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"

namespace intake
{
  Controllers controller = Controllers::NONE;
  #define spinSpeed 25
  bool BothLeftAndRightButtonsPressed() {
    return BtnLeft.isPressed() && BtnRight.isPressed();
  }
  void spinRight() {
    if(BtnRight.isPressed()){
      controller = Controllers::SPINNINGRIGHT;
    }
    else if(controller == Controllers::SPINNINGRIGHT){
      controller = Controllers::DEINIT;
    }
  }

  void spinLeft(){
    if(BtnLeft.isPressed()){
      controller = Controllers::SPINNINGLEFT;
    }
    else if(controller == Controllers::SPINNINGLEFT){
      controller = Controllers::DEINIT;
    }
  }
  void intaking(){
    if(BtnOn.isPressed()){
      controller = Controllers::INTAKING;
    }
    else if(controller == Controllers::INTAKING){
      controller = Controllers::DEINIT;
    }
  }

  void outaking(){
    if(BtnOut.isPressed()){
      controller = Controllers::OUTTAKING;
    }
    else if(BothLeftAndRightButtonsPressed()){
      controller = Controllers::OUTTAKING;
    }
    else if(controller == Controllers::SPINNINGRIGHT){
      controller = Controllers::DEINIT;
    }
  }

  void execute(){
    switch(controller){
      case Controllers::INTAKING:
      intakegroup.moveVelocity(200);
      break;

      case Controllers::OUTTAKING:
      intakegroup.moveVelocity(-200);
      break;

      case Controllers::SPINNINGRIGHT:
      left_motor.moveVelocity(-spinSpeed);
      right_motor.moveVelocity(spinSpeed);
      break;

      case Controllers::SPINNINGLEFT:
      left_motor.moveVelocity(spinSpeed);
      right_motor.moveVelocity(-spinSpeed);
      break;

      case Controllers::DEINIT:
      intakegroup.moveVelocity(0);
      controller = Controllers::NONE;
      break;

      case Controllers::NONE:
      break;
    }
  }

  void intake(){
    intaking();
    outaking();
    spinLeft();
    spinRight();
    execute();
  }

  namespace auton{
    bool intakeRunning = false;
    void intakeOn(double targetVelocity)
    {
      intakeRunning = true;
      if(intakeRunning){
        intakegroup.moveVelocity(targetVelocity);
      }
    }
    void intakeOff(){
      intakeRunning = false;
      intakegroup.moveVelocity(0);

    }
  }
}
