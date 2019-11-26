#include "main.h"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/drive.hpp"
#include "custom/systems/intake.hpp"


namespace intake
{

  Controllers controller = Controllers::NONE;
  int liftUp = 1300;
  bool bothButtonsPressed(){
    return BtnLeft.isPressed() && BtnRight.isPressed();
  }

  bool slowOut = false;
  void intake(){

    if (BtnIn.isPressed()){
      controller = Controllers::IN;
    }
    else if (controller == Controllers::IN){
      controller = Controllers::DEINIT;
    }
  }

  void stackReverse(){
    if (BtnBackUp.isPressed()){
      drive::left_drive.moveVelocity(-25);
      drive::right_drive.moveVelocity(-25);
      controller = Controllers::MACRO;
    }
    else if (controller == Controllers::MACRO){
      controller = Controllers::DEINIT;
    }
  }

  void outake(){
    if (BtnOut.isPressed() || bothButtonsPressed())
    {
      controller = Controllers::OUT;
    }
    else if (controller == Controllers::OUT)
    {
      controller = Controllers::DEINIT;
    }
  }

  void spinR(){
    if (BtnRight.isPressed()){
      controller = Controllers::SPINR;
    }
    else if (controller == Controllers::SPINR){
      controller = Controllers::DEINIT;
    }
  }

  void spinL(){
    if (BtnLeft.isPressed()){
      controller = Controllers::SPINL;
    }
    else if (controller == Controllers::SPINL){
      controller = Controllers::DEINIT;
    }
  }

  void execute(){
    switch (controller){

      case Controllers::IN:
      // if (lift::liftSensor.get_value() > liftUp)
      // {
      // intakegroup.moveVelocity(0);
      // }
      // else
      // {
      intakegroup.moveVelocity(200);
      // }
      break;

      case Controllers::OUT:
      // if (lift::liftSensor.get_value() > liftUp && cubeSensor.get_value() < 2700)
      // {
      //   slowOut = true;
      // }
      // if (slowOut)
      // {
      //   intakegroup.moveVelocity(-47);
      // }
      // else
      // {
      intakegroup.moveVelocity(-200);
      // }
      break;

      case Controllers::SPINL:
      left_motor.moveVelocity(50);
      right_motor.moveVelocity(-50);
      break;

      case Controllers::SPINR:
      left_motor.moveVelocity(-50);
      right_motor.moveVelocity(50);
      break;

      case Controllers::MACRO:
      intakegroup.moveVelocity(-35);
      break;

      case Controllers::DEINIT:
      intakegroup.moveVelocity(0);
      slowOut = false;
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
    stackReverse();
  }
  namespace auton{

    void stackReverseAuton(double distance, double driveSpeed, double intakeSpeed){
      while (drive::left_front.getPosition() > distance || drive::right_front.getPosition() > distance){
        /* code */
        drive::left_drive.moveVelocity(-driveSpeed);
        drive::right_drive.moveVelocity(-driveSpeed);
        intakegroup.moveVelocity(-intakeSpeed);
      }
      drive::left_drive.moveVelocity(0);
      drive::right_drive.moveVelocity(0);
      intakegroup.moveVelocity(0);
      // drive::auton::resetPositions();
    }

    bool intakeRunning = false;
    void intakeOn(double targetVelocity){
      intakegroup.moveVelocity(targetVelocity);
    }

    void intakeOff(){
      intakegroup.moveVelocity(0);
    }
  } // namespace auton
}
