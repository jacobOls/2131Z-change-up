#include "main.h"
#include "custom/systems/intake.hpp"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/drive.hpp"

namespace intake
{
  Controllers controller = Controllers::NONE;
  #define spinSpeed 25
  double intakeSpeed = 200;
  bool BothLeftAndRightButtonsPressed() {
    return BtnLeft.isPressed() && BtnRight.isPressed();
  }

  bool slowOutake = false;

  double cubeSense(){
    return cubeSensor.get_value();
  }
  double encoder(){
    return lift::liftSensor.get_value();
  }
  void spinRight() {
    if(BtnRight.isPressed()){
      controller = Controllers::SPINNINGRIGHT;
    }
    else if(controller == Controllers::SPINNINGRIGHT){
      controller = Controllers::DEINIT;
    }
  }

  //second sprocket beneath main one on intake.
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
    else if(controller == Controllers::OUTTAKING){
      controller = Controllers::DEINIT;
    }
  }

  void execute(){
    switch(controller){
      case Controllers::INTAKING:
      if(encoder() < 2370 && cubeSensor.get_value() <= 2700){
        intakegroup.moveVelocity(0);
      }
      else if(encoder() >= 2370) {
        intakegroup.moveVelocity(200);
      }
      break;

      case Controllers::OUTTAKING:
      // if(cubeSensor.get_value() <= 2700){
      //   intakegroup.moveVelocity(-100);
      // }
      // else{
      //   intakegroup.moveVelocity(-200);
      // }
      if(cubeSensor.get_value() < 2700 && encoder() < 2370){
        slowOutake = true;
        if(slowOutake){
          intakegroup.moveVelocity(-100);
        }
      }
      else if(!slowOutake){
        intakegroup.moveVelocity(-200);
      }
      break;

      case Controllers::MACRO:
      intakegroup.moveVelocity(-25);
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
      if(encoder() >= 2370 || cubeSensor.get_value() > 2600){
        if(slowOutake){
          slowOutake = false;
        }
      }
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

  void stackReverse(){
    if(drive::BtnBackUp.isPressed()){
      drive::left_drive.moveVelocity(-25);
      drive::right_drive.moveVelocity(-25);
      controller = Controllers::MACRO;
    }
    else if(controller == Controllers::MACRO){
      controller = Controllers::DEINIT;
    }
  }

  namespace auton{




    void stackReverseAuton(double distance, double driveSpeed, double intakeSpeed){
      while (drive::left_front.getPosition() > distance || drive::right_front.getPosition() > distance) {
        /* code */
        drive::left_drive.moveVelocity(-driveSpeed);
        drive::right_drive.moveVelocity(-driveSpeed);
        intakegroup.moveVelocity(-intakeSpeed);
      }
      drive::left_drive.moveVelocity(0);
      drive::right_drive.moveVelocity(0);
      intakegroup.moveVelocity(0);
      drive::auton::resetPositions();
    }

    bool intakeRunning = false;
    void intakeOn(double targetVelocity)
    {
      intakegroup.moveVelocity(targetVelocity);
    }
    void intakeOff(){
      intakegroup.moveVelocity(0);
    }
  }
}
