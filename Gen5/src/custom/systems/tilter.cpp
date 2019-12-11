#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/tilter.hpp"
#include "custom/systems/lift.hpp"
#include "custom/auton.hpp"

namespace tilter{
  Controllers controller = Controllers::NONE;
  void tilterUp(){
    if(BtnForward.isPressed()){
      controller = Controllers::FORWARD;
    }
    else if(controller == Controllers::FORWARD){
      controller = Controllers::DEINIT;
    }
  }

  void tilterDown(){
    if(BtnBackward.isPressed()){
      controller = Controllers::BACKWARD;
    }
    else if(controller == Controllers::BACKWARD){
      controller = Controllers::DEINIT;
    }
  }

  void returnDown(){
    if(BtnBackward.isPressed()){
      controller = Controllers::RETURN;
    }
    else if(controller == Controllers::RETURN && motor.getActualVelocity() > -5){
      controller = Controllers::DEINIT;
    }
  }


  void execute()
  {
    // if (controller == Controllers::FORWARD && motor.getPosition() > 400)
    // {
    //   controller = Controllers::DEINIT;
    // }
    // if (controller == Controllers::BACKWARD && motor.getPosition() < 5)
    // {
    //   controller = Controllers::DEINIT;
    // }
    if(motor.getPosition() > 1684 && controller == Controllers::FORWARD){
      controller = Controllers::DEINIT;
    }
    if(motor.getPosition() < 50 && controller == Controllers::BACKWARD){
      controller = Controllers::DEINIT;
    }
    switch (controller)
    {
      case Controllers::FORWARD:
      motor.moveVelocity(50);
      // trayLock = false;
      break;

      case Controllers::BACKWARD:
      motor.moveVelocity(-100);
      // intake::intakegroup.moveVelocity(-28);
      // trayLock = false;
      break;

      case Controllers::TOUP:
      // trayLock = true;
      if(motor.getPosition() < 250){
        motor.moveVelocity(50);
      }
      // if (sensor() < upPlace)
      // {
      //   motor.moveVelocity(100);
      // }
      // else if (sensor() >= upPlace)
      // {
      //   motor.moveVelocity(0);
      //   controller = Controllers::DEINIT;
      // }
      break;

      case Controllers::RETURN:
      if(motor.getPosition() > 5){
        motor.moveVelocity(-100);
      }


      break;

      case Controllers::DEINIT:
      motor.moveVelocity(0);
      controller = Controllers::NONE;
      break;

      case Controllers::NONE:
      break;
    }
  }

  void init(){
    tilterUp();
    tilterDown();
    returnDown();
    execute();
  }

  namespace auton{

    void tilter(int pos, int velocity){
      if(motor.getPosition() > pos && velocity > 1){
        velocity = -velocity;
        while(motor.getPosition() >= pos){
          motor.moveAbsolute(pos,velocity);
        }
      }
      else{
        while(motor.getPosition() <= pos){
          motor.moveAbsolute(pos,velocity);
        }

      }
    }
  }
}
