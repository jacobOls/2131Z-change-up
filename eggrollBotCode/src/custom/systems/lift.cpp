#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/tray.hpp"
namespace lift{
  const double position = 30;
  const double velocity = 50;
  const double trayVelocity = 35;
  Controllers controller = Controllers::NONE;
  double getPosition(){
    return lift::motor.getPosition();
  }
double encoder(){
return liftSensor.get_value();
}
  bool liftUp(){
    return motor.getPosition() > position;
  }

  bool buttonsPressed(){
    return  BtnUp.isPressed() && BtnDown.isPressed();
  }

  void liftMovingUp(){
    if(BtnUp.isPressed()){
      controller = Controllers::UP;
    }
    else if(controller == Controllers::UP){
      controller = Controllers::DEINIT;
    }
  }

  void liftMovingDown(){
    if(BtnDown.isPressed()){
      controller = Controllers::DOWN;
    }
    else if(controller == Controllers::DOWN){
      controller = Controllers::DEINIT;
    }
  }

  void MidTower(){
    if(BtnMidTower.isPressed()){
      controller = Controllers::MIDTOWER;
    }
  }

  void lowTower(){
    if(BtnLowTower.isPressed()){
      controller = Controllers::LOWTOWER;
    }
  }

/* pot positions
down  2380
tray pop 2300
up  1000
MidTower 1200
lowTower 1630
the lower the number the higher it is
*/


  void execute(){
    if(encoder() > 2380 && controller== Controllers::DOWN) controller= Controllers::DEINIT;
    if(encoder() < 800 && controller== Controllers::UP) controller= Controllers::DEINIT;
    switch (controller){
      case Controllers::UP:
      motor.moveVelocity(100);
      break;

      case Controllers::DOWN:
      if(encoder() <= 2300){
      motor.moveVelocity(-100);
    }
    else if(encoder() > 2300){
      motor.moveVelocity(-25);
    }
      break;

      case Controllers::NONE:

      break;

      case Controllers::DEINIT:
      motor.moveVelocity(0);
      if(encoder() > 2360){
        motor.moveVelocity(-5);
      }
      controller = Controllers::NONE;
      break;

      case Controllers::MIDTOWER:
      motor.moveAbsolute(350,25);
      if (encoder() < 1835 && encoder() > 1825){
        if(motor.isStopped())
        {
          controller = Controllers::DEINIT;
        }
      }
      break;

      case Controllers::LOWTOWER:
      motor.moveAbsolute(250,25);
      if (encoder() < 1405 && encoder() > 1395){
        if(motor.isStopped())
        {
          controller = Controllers::DEINIT;
        }
      }
      break;
    }
  }

  void lift(){
    liftMovingUp();
    liftMovingDown();
    MidTower();
    lowTower();
    execute();
  }

  namespace auton{
    const double targetPosition = 25;
    const double epsilon = 5;
    bool isMotorWithinRange() {
      double position = motor.getPosition();
      if (position > targetPosition - epsilon) {
        return true;
      }
      if (position < targetPosition + epsilon) {
        return true;
      }
      return false;
    }
    void autonLift(double targetPosition, double targetVelocity){
      while(!isMotorWithinRange()){
        motor.moveVelocity(targetVelocity);
      }
      if(isMotorWithinRange()){
        motor.moveVelocity(0);
      }
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
