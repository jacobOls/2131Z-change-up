#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/drive.hpp"
#include "custom/setup/ramping.hpp"
namespace drive{
  int rightVel; //right side velocity
  int leftVel; //left side velocity
  bool isBraked = false;//checks if the bot is braked
  void tankDrive()
  //drive code
  {
    if(std::abs(master.getAnalog(okapi::ControllerAnalog::leftY))<0.05) leftVel=0;
    //if input is not great enough, do not move motor so there is no accidetnal input
    else	leftVel=(master.getAnalog(ControllerAnalog::leftY)*200);
    if(std::abs(master.getAnalog(okapi::ControllerAnalog::rightY))<0.05) rightVel=0;
    //if input is not great enough, do not move motor so there is no accidetnal input
    else	rightVel=(master.getAnalog(ControllerAnalog::rightY)*200);

    right_drive.moveVelocity(rightVel);
    left_drive.moveVelocity(leftVel);

  }

  void brakeMode()
  //brakes the bot
  {
    if(BtnBrake.isPressed())
    {
      isBraked = true;
      while (isBraked)
      {
        right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
        left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
        if(BtnBrake.isPressed())
        {
          isBraked = false;
          right_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
          left_drive.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
        }
      }


    }
  }


  namespace auton
  {

    #define wheelCircumfrance 12.56;

    void resetPositions()
    {
      left_drive.tarePosition();
      right_drive.tarePosition();

    }
    void autonDrive(double distance, double targetVelocity)
    {

      double Deg = distance*365 /wheelCircumfrance;
      if(left_front.getPosition() < distance || right_front.getPosition() < distance)
      {
        left_drive.moveVelocity(targetVelocity);
        right_drive.moveVelocity(targetVelocity);
      }
      else if(left_front.getPosition() >= distance && right_front.getPosition() >= distance)

      {
        left_drive.moveVelocity(0);
        right_drive.moveVelocity(0);
        resetPositions();
      }

    }
    void turn(double amount, double targetVelocity)
    {
      if(left_front.getPosition() < amount)
      {
        left_drive.moveVelocity(targetVelocity);
        right_drive.moveVelocity(-targetVelocity);
        pros::delay(1);
      }
      else if(left_front.getPosition() > amount)

      {
        left_drive.moveVelocity(-targetVelocity/5);
        right_drive.moveVelocity(targetVelocity/5);
        pros::delay(1);
      }
      else
      {
        left_drive.moveVelocity(0);
        right_drive.moveVelocity(0);
        resetPositions();
      }
    }
    void ramping(void*)
{
  static uint32_t start;

  drive.calculate();
  pros::Task::delay_until(&start, drive.get_changeMsec());
}
//adds ramping to the tilter
void taskInit(){
  pros::Task rampingTask(ramping, (void*) "test", TASK_PRIORITY_DEFAULT,
  TASK_STACK_DEPTH_DEFAULT,"drive");
  }
}
}
