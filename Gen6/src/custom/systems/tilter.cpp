#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/tilter.hpp"

namespace tilter{
Controllers controller = Controllers::NONE;
void tilterUp(){
  if (BtnForward.isPressed()){
    controller = Controllers::FORWARD;
  }
  else if (controller == Controllers::FORWARD){
    controller = Controllers::DEINIT;
  }
}

void returnDown(){
  if (BtnReturn.isPressed()){
    controller = Controllers::RETURN;
  }
  else if (controller == Controllers::RETURN && motor.getActualVelocity() == 0){
    controller = Controllers::DEINIT;
  }
}

void tilterDown(){
  if (BtnBackward.isPressed()){
    controller = Controllers::BACKWARD;
  }
  else if (controller == Controllers::BACKWARD){
    controller = Controllers::DEINIT;
  }
}

void execute(){
  // if (controller == Controllers::FORWARD && motor.getPosition() > 400)
  // {
  //   controller = Controllers::DEINIT;
  // }
  // if (controller == Controllers::BACKWARD && motor.getPosition() < 5)
  // {
  //   controller = Controllers::DEINIT;
  // }
  if (motor.getPosition() > 1750 && controller == Controllers::FORWARD){
    controller = Controllers::DEINIT;
  }
  if (motor.getPosition() < 5 && controller == Controllers::BACKWARD){
    controller = Controllers::DEINIT;
  }
  switch (controller){
  case Controllers::FORWARD:
    if (lift::motor.getPosition() < 100){
      motor.moveVelocity(75);
    }
    else if (lift::motor.getPosition() >= 100){
      motor.moveVelocity(45);
    }
    if (lift::motor.getPosition() < 50 && motor.getPosition() > 130){
      lift::motor.moveAbsolute(0, -200);
    }
    // trayLock = false;
    break;

  case Controllers::BACKWARD:
    motor.moveVelocity(-100);
    // intake::intakegroup.moveVelocity(-28);
    // trayLock = false;
    break;

  case Controllers::TOUP:
    // trayLock = true;
    if (motor.getPosition() < 250){
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
    motor.moveAbsolute(0, -200);

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

  while (motor.getPosition() <= pos){
    motor.moveAbsolute(pos, velocity);
    if (motor.getPosition() > pos){
      motor.moveVelocity(0);
      break;
    }
  }
}
void tilterDown(int pos, int velocity){
  while (motor.getPosition() >= pos){
    motor.moveAbsolute(pos, velocity);
    if (motor.getPosition() < pos){
      motor.moveVelocity(0);
      break;
    }
  }
}
} // namespace auton
} // namespace tilter
