#include "main.h"
#include "custom/systems/drive.hpp"
#include "custom/systems/lift.hpp"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/ramping.hpp"

namespace drive{
int rightVel;
int leftVel;

  void userDrive(){
    // if (std::abs(master.getAnalog(okapi::ControllerAnalog::leftY)) < 0.05)
       // leftVel = 0;
       // else
       leftVel = (master.getAnalog(ControllerAnalog::leftY) * abs(200));

       // if (std::abs(master.getAnalog(okapi::ControllerAnalog::rightY)) < 0.05)
       // rightVel = 0;
       // else
       rightVel = (master.getAnalog(ControllerAnalog::rightY) * abs(200));

       right_drive.moveVelocity(rightVel);
       left_drive.moveVelocity(leftVel);
  }

  namespace auton{

    void resetPos(){
      left_drive.tarePosition();
      right_drive.tarePosition();
    }

    void drive(int distance, int velocity){
      resetPos();
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

    void turn(int deg, int velocity){
      resetPos();
      while(abs(left_front.getPosition()) < deg){
        left_drive.moveVelocity(velocity);
        right_drive.moveVelocity(-velocity);

      }
    }
  }
}
