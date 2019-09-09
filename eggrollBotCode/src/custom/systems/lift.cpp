#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/tray.hpp"
namespace lift{
  const double position = 10;
  const double velocity = 50;
  bool liftUp(){
    return motor.getPosition() > position;
  }
  bool buttonsPressed(){
    return  BtnUp.isPressed() && BtnDown.isPressed();
  }
  void up(){
    if(BtnUp.isPressed()){
      motor.moveVelocity(velocity);
    }
    if(liftUp()){
      tray::motor.moveAbsolute(50,velocity);
    }
  }
  void down(){
    if(BtnDown.isPressed()){
      motor.moveVelocity(-velocity);
    }
  }
  void nothing(){
    if (!buttonsPressed()) {
      motor.moveVelocity(0);
    }
  }
  void lift(){
    up();
    down();
    nothing();
  }

  namespace auton{
    void autonLift(double position, double targetVelocity)
    {
      motor.moveAbsolute(position, targetVelocity);
    }
    void popOpen(){
      motor.moveAbsolute(100,20);
      tray::motor.moveAbsolute(100,20);
      pros::delay(100);
      motor.moveAbsolute(0,20);
      tray::motor.moveAbsolute(0,20);
    }
  }
}
