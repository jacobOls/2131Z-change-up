#include "main.h"
#include "custom/systems/tray.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/lift.hpp"
namespace tray{
  const double epsilon = 10;
  const double upPosition = 250;
  const double liftPosition = 25;
  // bool trayMove = false;
  const double traySpeed = 25.0;
  const double position =  600.0;
  Controllers controller = Controllers::NONE;
  double encoder(){
  return lift::liftSensor.get_value();
  }
  bool motorCanTravel() {
    return motor.getPosition() < position;
  }
  bool trayDown(){
    return motor.getPosition() < 25;
  }
  const double finalPosition = 0;

  bool isLiftDown() {
    double liftPosition = lift::motor.getPosition();
    if (liftPosition > finalPosition - epsilon) {
      return true;
    }
    if (liftPosition < finalPosition + epsilon) {
      return true;
    }
    return false;
  }
  bool liftUp(){
    return lift::motor.getPosition() >= 10;
  }
  bool liftButtons(){
    return lift::BtnUp.isPressed() || lift::BtnDown.isPressed();
  }
  void forward(){
    if( BtnF.isPressed()){
      controller = Controllers::FORWARD;
    }
    else if (controller==Controllers::FORWARD){
      controller = Controllers::DEINIT;
    }
  }


  void back(){
    if(BtnB.isPressed()){
      controller = Controllers::BACKWARD;
    }
    else if(controller == Controllers::BACKWARD){
      controller = Controllers::DEINIT;
    }
  }


  void tilter(){
    forward();
    back();
    execute();

  }
  void execute(){
    if(encoder() < 2370 && motor.getPosition()<upPosition) controller= Controllers::LIFT;
    if(!motorCanTravel() && controller== Controllers::FORWARD) controller= Controllers::DEINIT;
    if(trayDown() && controller== Controllers::BACKWARD) controller= Controllers::DEINIT;
    switch (controller) {
      // pros::lcd::set_text(3,std::to_string(static_cast<int>(controller));
      case Controllers::FORWARD:
      motor.moveVelocity(traySpeed);
      break;

      case Controllers::BACKWARD:
      motor.moveVelocity(-100);
      break;

      case Controllers::DEINIT:
      motor.moveVelocity(0);
      controller = Controllers::NONE;
      break;

      case Controllers::NONE:
      pros::lcd::set_text(5,"NONE" );
      break;

      case Controllers::RETURN:
      motor.moveAbsolute(0,-75);
      // if(motor.getActualVelocity() >= 60){
      // }
      // pros::delay(motor.isStopped());
      if (motor.getPosition()<25){
        if(motor.isStopped())
        {
          controller = Controllers::DEINIT;
        }
      }
      break;

      case Controllers::LIFT:
      static int i;
      i++;
      pros::lcd::set_text(2,std::to_string(i));
      motor.moveAbsolute(upPosition +25, 75);
      if(encoder() > 2290) controller = Controllers::RETURN;
      break;

    }
  }
  namespace auton{
    double targetPosition = 25;
    bool isMotorWithinRange() {
      double currentPosition = motor.getPosition();
      if (currentPosition > targetPosition - epsilon) {
        return true;
      }
      if (currentPosition < targetPosition + epsilon) {
        return true;
      }
      return false;
    }
    void stack(double targetPosition, double targetVelocity){

      while(!isMotorWithinRange())
      {
        motor.moveVelocity(targetVelocity);
        pros::delay(20);
      }
      if(isMotorWithinRange())
      motor.moveVelocity(0);
    }
  }
}
