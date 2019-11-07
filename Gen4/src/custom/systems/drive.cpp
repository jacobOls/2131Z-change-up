#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/drive.hpp"
#include "custom/setup/ramping.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/intake.hpp"

namespace drive
{
  int lSensor(){
    return lift::liftSensor.get_value();
  }

  bool holdDrive = false;
  bool toggled = false;
  int rightVel;
  int leftVel;
  int lJoystickSpeed = 200;
  int rJoystickSpeed = 200;
  void drive()
  {
    //drive code
    // if(abs(master.getAnalog(okapi::ControllerAnalog::leftY)) >0.5 || abs(master.getAnalog(okapi::ControllerAnalog::rightY)) > 0){
    // lJoystickSpeed = LEFT_MANUAL.calculate(master.getAnalog(okapi::ControllerAnalog::leftY) * 200);
    // rJoystickSpeed = RIGHT_MANUAL.calculate(master.getAnalog(okapi::ControllerAnalog::rightY) * 200);
    if (std::abs(master.getAnalog(okapi::ControllerAnalog::leftY)) < 0.05)
    leftVel = 0;
    else
    leftVel = (master.getAnalog(ControllerAnalog::leftY) * abs(lJoystickSpeed));

    if (std::abs(master.getAnalog(okapi::ControllerAnalog::rightY)) < 0.05)
    rightVel = 0;
    else
    rightVel = (master.getAnalog(ControllerAnalog::rightY) * abs(rJoystickSpeed));

    right_drive.moveVelocity(rightVel);
    left_drive.moveVelocity(leftVel);


  }

  void hold(){
    if(holdDrive){
      right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
      left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    }

    else if(!holdDrive){
      right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
      left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    }
  }


  void toggle(){

    if(lSensor() >= 2400 && abs(intake::intakegroup.getActualVelocity()) > 0){
      holdDrive = true;
    }
    else if(BtnHold.isPressed() && toggled == false){
      holdDrive = true;
      toggled = true;
    }
    else if(BtnHold.isPressed() && toggled == true){
      toggled = false;
    }
    else if(!toggled && lSensor() < 2400){
      holdDrive = false;
    }


  }

  void init(){
    drive();
    hold();
    toggle();
  }

  // else {
  //   rightVel = 0;
  //   leftVel = 0;
  // }

  namespace auton
  {

    int lVel;
    int rVel;
    int lPos;
    int rPos;
    int moving()
    {
      return left_front.getActualVelocity() && left_back.getActualVelocity() && right_front.getActualVelocity() && right_back.getActualVelocity();
    }
    void resetPositions()
    {
      left_drive.tarePosition();
      right_drive.tarePosition();
    }

    void driving(int distance, int velocity)
    {
      resetPositions();
      lVel = LEFT_DRIVE.calculate(velocity);
      rVel = RIGHT_DRIVE.calculate(velocity);
      lPos = left_back.getPosition();
      rPos = right_back.getPosition();

      while (lPos != distance || rPos != distance)
      {
        left_drive.moveVelocity(lVel);
        right_drive.moveVelocity(rVel);
        pros::delay(20);
      }

      while (moving() > 0)
      {
        velocity = 0;
        left_drive.moveVelocity(lVel);
        right_drive.moveVelocity(rVel);
        pros::delay(20);
      }
    }

    void rightTurn(double distance, double velocity)
    {
      resetPositions();
      while (left_front.getPosition() < distance)
      {
        left_drive.moveVelocity(velocity);
        right_drive.moveVelocity(-velocity);
      }
      if (left_front.getPosition() > distance)
      {
        left_drive.moveVelocity(0);
        right_drive.moveVelocity(0);
        resetPositions();
      }
    }

    void leftTurn(double distance, double velocity)
    {
      resetPositions();
      while (right_front.getPosition() < distance)
      {
        left_drive.moveVelocity(-velocity);
        right_drive.moveVelocity(velocity);
      }
      if (right_front.getPosition() > distance)
      {
        left_drive.moveVelocity(0);
        right_drive.moveVelocity(0);
        resetPositions();
      }
    }

  } // namespace auton

} // namespace drive
