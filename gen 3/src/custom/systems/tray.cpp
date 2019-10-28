#include "main.h"
#include "custom/systems/tray.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/lift.hpp"
namespace tray{
  const double epsilon = 10;
  const double upPosition = 2200;
  const double liftPosition = 100;
  // bool trayMove = false;
  const double traySpeed = 75.0;
  const double position =  1500.0;
  Controllers controller = Controllers::NONE;
  double encoder(){
    return lift::liftSensor.get_value();
  }
  double tilterPos(){
    return tilterP.get_value();
  }
  bool motorCanTravel() {
    return tilterPos() >= position;
  }
  bool trayDown(){
    return tilterPos() >= 2795 ;
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

  void travel(){
    if(travelBack.isPressed()){
      controller = Controllers::TRAVELBACK;
    }
    else if(controller == Controllers::TRAVELBACK && motor.getActualVelocity() > -10){
      controller = Controllers::DEINIT;
    }

  }


  void tilter(){
    forward();
    back();
    travel();
    execute();
    if(encoder() < 1500 && tilterPos() < 2350 ){
      intake::intakegroup.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    }
    else {
      intake::intakegroup.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    }
  }
  void execute(){
    if(encoder() > 1350 && tilterPos() > upPosition) controller= Controllers::LIFT;
    if(!motorCanTravel() && controller== Controllers::FORWARD) controller= Controllers::DEINIT;
    if(trayDown() && controller== Controllers::BACKWARD) controller= Controllers::DEINIT;
    switch (controller) {
      // pros::lcd::set_text(3,std::to_string(static_cast<int>(controller));
      case Controllers::FORWARD:
      motor.moveVelocity(75);
      // intake::intakegroup.moveVelocity(-25);
      break;

      case Controllers::BACKWARD:
      motor.moveVelocity(-100);
      break;

      case Controllers::DEINIT:
      motor.moveVelocity(0);
      controller = Controllers::NONE;
      break;

      case Controllers::NONE:
      break;

      case Controllers::RETURN:
      if(tilterPos() < 2790)
      motor.moveVelocity(-100);
      // if(motor.getActualVelocity() >= 60){
      // }
      // pros::delay(motor.isStopped());
      if (tilterPos() > 2790){
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
      if (tilterPos() > upPosition){
        motor.moveVelocity(100);
      }
      else if (tilterPos() < upPosition){
        motor.moveVelocity(0);
      }
      if(encoder() < 1250 ) controller = Controllers::RETURN;
      // (upPosition +25, 100);
      break;

      case Controllers::TRAVELBACK:
      if(encoder()  > 1450 && tilterPos() > upPosition){
        motor.moveAbsolute(upPosition, -100);
        if(tilterPos() < upPosition){
          motor.moveVelocity(-100);
        }
      }
      else{
        motor.moveAbsolute(0,-100);
      }
      break;

    }
  }

  void ramping(void*)
  {
    static uint32_t start;
    tilt.calculate();
    pros::Task::delay_until(&start, tilt.get_changeMsec());
  }
  void taskInit(){
    pros::Task rampingTask(ramping, (void*) "test", TASK_PRIORITY_DEFAULT,
    TASK_STACK_DEPTH_DEFAULT,"tilt");
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

    void trayDown(double wantedPosition, double targetVelocity){
      while(motor.getPosition() > wantedPosition){
        motor.moveVelocity(targetVelocity);
      }
      if(motor.getPosition() <= wantedPosition){
        motor.moveVelocity(0);
      }
    }


    void stack(double wantedPosition, double targetVelocity){
      while(motor.getPosition() < wantedPosition){
        motor.moveVelocity(targetVelocity);
        // pros::lcd::set_text(2,std::to_string(motor.getPosition()));
      }
      if(motor.getPosition() >= wantedPosition){
        // pros::lcd::set_text(4,"stopping motor" );
        motor.moveVelocity(0);
      }
    }
  }
}
