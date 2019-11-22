#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/drive.hpp"
#include "custom/setup/ramping.hpp"
int leftVel;
int rightVel;
int lJoystickSpeed = 200;
int rJoystickSpeed = 200;
namespace drive{
  void drive(){
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
    namespace auton{

void resetPositions(){
  left_drive.tarePosition();
  right_drive.tarePosition();

}

void driving(int distance, int velocity)
    {
        resetPositions();
        while(abs(left_front.getPosition()) < distance || abs(right_front.getPosition()) < distance){
            left_drive.moveVelocity(LEFT_DRIVE.calculate(velocity));
            right_drive.moveVelocity(RIGHT_DRIVE.calculate(velocity));
            // LEFT_DRIVE.calculate(targetVelocity);
            // RIGHT_DRIVE.calculate(targetVelocity);
            pros::delay(LEFT_DRIVE.get_changeMsec());

        }
        while(LEFT_DRIVE.output() != 0){
            left_drive.moveVelocity(LEFT_DRIVE.calculate(0));
            right_drive.moveVelocity(RIGHT_DRIVE.calculate(0));
            pros::delay(LEFT_DRIVE.get_changeMsec());
        }
    }



    }
  }
