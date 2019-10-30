#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/intake.hpp"

namespace intake{
  Controllers controller = Controllers::NONE;

bool bothButtonsPressed(){
  return BtnLeft.isPressed() && BtnRight.isPressed();
}


void intake(){
  if(BtnIn.isPressed()){
    controller = Controllers::IN;
  }
  else if(controller == Controllers::IN){
    controller = Controllers::DEINIT;
  }
}

void outake(){
  if(BtnOut.isPressed() || bothButtonsPressed()){
    controller = Controllers::OUT;
  }
  else if(controller == Controllers::OUT){
    controller = Controllers::DEINIT;
  }
}

void spinR(){
  if(BtnRight.isPressed()){
    controller = Controllers::SPINR;
  }
  else if(controller == Controllers::SPINR){
    controller = Controllers::DEINIT;
  }
}

void spinL(){
  if(BtnRight.isPressed()){
    controller = Controllers::SPINL;
  }
  else if(controller == Controllers::SPINL){
    controller = Controllers::DEINIT;
  }
}


  void execute(){
    switch (controller){

      case Controllers::IN:
      intakegroup.moveVelocity(200);
      break;

      case Controllers::OUT:
      intakegroup.moveVelocity(-200);
      break;

      case Controllers::SPINL:
      left_motor.moveVelocity(50);
      right_motor.moveVelocity(-50);
      break;

      case Controllers::SPINR:
      left_motor.moveVelocity(-50);
      right_motor.moveVelocity(50);
      break;
      
      case Controllers::DEINIT:
      intakegroup.moveVelocity(0);
      controller = Controllers::NONE;
      break;

      case Controllers::NONE:
      break;

    }

  }

  void init(){
    intake();
    outake();
    spinR();
    spinL();
    execute();
  }

}
