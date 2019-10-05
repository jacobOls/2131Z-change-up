#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/drive.hpp"
#include "custom/setup/ramping.hpp"
#include "custom/systems/intake.hpp"
namespace drive{
  int rightVel; //right side velocity
  int leftVel; //left side velocity

  void tankDrive(){
    //drive code
    if(std::abs(master.getAnalog(okapi::ControllerAnalog::leftY))<0.05) leftVel=0;
    //if input is not great enough, do not move motor so there is no accidetnal input
    else	leftVel=(master.getAnalog(ControllerAnalog::leftY)*200);
    if(std::abs(master.getAnalog(okapi::ControllerAnalog::rightY))<0.05) rightVel=0;
    //if input is not great enough, do not move motor so there is no accidetnal input
    else	rightVel=(master.getAnalog(ControllerAnalog::rightY)*200);

    right_drive.moveVelocity(rightVel);
    left_drive.moveVelocity(leftVel);

  }




  namespace auton{

    #define wheelCircumfrance 12.56;
    // double Deg = distance*365 /wheelCircumfrance;
    double distances = 25;
    const double epsilon = 5;
    bool isMotorWithinRange(){
      double currentPosition = left_drive.getPosition() || right_drive.getPosition();
      if (currentPosition > distances - epsilon) {
        return true;
      }
      if (currentPosition < distances + epsilon) {
        return true;
      }
      return false;
    }

    void resetPositions(){
      left_drive.tarePosition();
      right_drive.tarePosition();

    }

    bool motorsInPosition(){
      return left_front.getPosition() || right_front.getPosition();
    }

    void autonDrive(double distance, double targetVelocity){


      while(left_front.getPosition() < distance || right_front.getPosition() < distance){
        left_drive.moveVelocity(targetVelocity);
        right_drive.moveVelocity(targetVelocity);
      }
      if(left_front.getPosition() >= distance || right_front.getPosition() >= distance){
        left_drive.moveVelocity(0);
        right_drive.moveVelocity(0);
        resetPositions();
      }




    }

    void autonDriveBack(double distance, double targetVelocity){


      while(left_front.getPosition() > distance || right_front.getPosition() > distance){
        left_drive.moveVelocity(targetVelocity);
        right_drive.moveVelocity(targetVelocity);
      }
      if(left_front.getPosition() <= distance || right_front.getPosition() <= distance){
        left_drive.moveVelocity(0);
        right_drive.moveVelocity(0);
        resetPositions();
      }




    }



    void rightTurn(double amount, double targetVelocity){
      while(left_front.getPosition() < amount){
        left_drive.moveVelocity(targetVelocity);
        right_drive.moveVelocity(-targetVelocity);
      }
      if(left_front.getPosition() > amount){
        left_drive.moveVelocity(0);
        right_drive.moveVelocity(0);
        resetPositions();
      }
    }

    void leftTurn(double amount, double targetVelocity){
      while(right_front.getPosition() < amount){
        left_drive.moveVelocity(-targetVelocity);
        right_drive.moveVelocity(targetVelocity);
      }
      if(right_front.getPosition() > amount){
        left_drive.moveVelocity(0);
        right_drive.moveVelocity(0);
        resetPositions();
      }
    }



    void ramping(void*){
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
