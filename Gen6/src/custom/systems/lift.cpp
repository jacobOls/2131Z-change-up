#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/lift.hpp"

namespace lift{
Controllers controller = Controllers::NONE;
void up(){
  if (BtnUp.isPressed()){
    controller = Controllers::UP;
  }
  else if (controller == Controllers::UP){
    controller = Controllers::DEINIT;
  }
}

void down(){
  if (BtnDown.isPressed()){
    controller = Controllers::DOWN;
  }
  else if (controller == Controllers::DOWN){
    controller = Controllers::DEINIT;
  }
}

void pulse(){
  motor.moveVelocity(-125);
  pros::delay(300);
  motor.moveAbsolute(0, 125);
  pros::delay(300);
  motor.moveVelocity(0);
}

void execute(){
  if (motor.getPosition() < 1 && controller == Controllers::DOWN){
    controller = Controllers::DEINIT;
  }
  switch (controller){

  case Controllers::UP:
    motor.moveVelocity(100);
    break;

  case Controllers::DOWN:
    motor.moveVelocity(-100);

    break;
  case Controllers::DEINIT:
    motor.moveVelocity(0);
    if (motor.getPosition() < 40 && tilter::motor.getPosition() < 125){
      motor.moveAbsolute(40, 200);
    }
    controller = Controllers::NONE;
    break;

  case Controllers::NONE:
    break;
  }
}

void init(){
  up();
  down();
  execute();
}

namespace auton{

void lift(int pos, int velocity, int startTime, double stopTime){

  if (motor.getPosition() > pos && velocity > 1){
    velocity = -velocity;
    while (motor.getPosition() > pos && pros::millis() - startTime < stopTime){
      motor.moveAbsolute(pos, velocity);
    }
  }
  else{
    while (motor.getPosition() < pos && pros::millis() - startTime < stopTime){
      motor.moveAbsolute(pos, velocity);
    }
  }
}

void liftNoTime(int pos, int velocity){
  if (motor.getPosition() > pos && velocity > 1){
    velocity = -velocity;
    while (motor.getPosition() > pos){
      motor.moveAbsolute(pos, velocity);
    }
  }
  else{
    while (motor.getPosition() < pos){
      motor.moveAbsolute(pos, velocity);
    }
  }
}

} // namespace auton
} // namespace lift
