#include "custom/systems/drive.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "custom/setup/ramping.hpp"
#include "custom/systems/lift.hpp"
#include "main.h"

namespace drive {
int rightVel;
int leftVel;
Controllers controller = Controllers::NONE;
void userDrive() {
  if (intake::BtnBackUp.isPressed()) {
    right_drive.moveVelocity(-25);
    left_drive.moveVelocity(-25);
  } else {
    if (master.getAnalog(ControllerAnalog::rightY) < 0.05 &&
        master.getAnalog(ControllerAnalog::rightY) > 0 &&
        master.getAnalog(ControllerAnalog::leftY) >= 0) {
      leftVel = 0;
    } else {
      leftVel = (master.getAnalog(ControllerAnalog::leftY) * 200);
    }
    //  if(abs(master.getAnalog(ControllerAnalog::leftX)) < 0.05){
    //   // rightVel = 0;
    // }
    // else{
    rightVel = (master.getAnalog(ControllerAnalog::rightY) * 200);
    // }

    right_drive.moveVelocity(rightVel);
    left_drive.moveVelocity(leftVel);
  }
}

void execute() {
  switch (controller) {
  case Controllers::DRIVE:
    leftVel = (master.getAnalog(ControllerAnalog::leftY) * abs(200));
    rightVel = (master.getAnalog(ControllerAnalog::rightY) * abs(200));

    right_drive.moveVelocity(rightVel);
    left_drive.moveVelocity(leftVel);
    break;

  case Controllers::NONE:
    break;

  case Controllers::DEINIT:
    right_drive.moveVelocity(0);
    left_drive.moveVelocity(0);
    Controllers controller = Controllers::NONE;
    break;
  }
}

// void userDrive(){
//   execute();
//   driveU();

namespace auton {

int gyV() { return gyro.get_value(); }

void resetPos() {
  left_drive.tarePosition();
  right_drive.tarePosition();
}

void drive(int distance, int velocity) {
  resetPos();
  distance = abs(distance);
  while (abs(left_front.getPosition()) < distance ||
         abs(right_front.getPosition()) < distance) {
    left_drive.moveVelocity(LEFT_DRIVE.calculate(velocity));
    right_drive.moveVelocity(RIGHT_DRIVE.calculate(velocity));
    // LEFT_DRIVE.calculate(targetVelocity);
    // RIGHT_DRIVE.calculate(targetVelocity);
    pros::delay(LEFT_DRIVE.get_changeMsec());
  }
  while (LEFT_DRIVE.output() != 0) {
    left_drive.moveVelocity(LEFT_DRIVE.calculate(0));
    right_drive.moveVelocity(RIGHT_DRIVE.calculate(0));
    pros::delay(LEFT_DRIVE.get_changeMsec());
  }
}

void driveVolt(int startTime, int time, int velocity) {
  resetPos();
  while (startTime - pros::millis() > time) {
    left_drive.moveVoltage(velocity);
    right_drive.moveVoltage(velocity);
    // LEFT_DRIVE.calculate(targetVelocity);
    // RIGHT_DRIVE.calculate(targetVelocity);
    pros::delay(20);
    ;
  }

  left_drive.moveVelocity(0);
  right_drive.moveVelocity(0);
}

void driveNR(int distance, int velocity) {
  resetPos();
  distance = abs(distance);
  while (abs(left_front.getPosition()) < distance ||
         abs(right_front.getPosition()) < distance) {
    left_drive.moveVelocity(velocity);
    right_drive.moveVelocity(velocity);
    // LEFT_DRIVE.calculate(targetVelocity);
    // RIGHT_DRIVE.calculate(targetVelocity);
    pros::delay(20);
  }
  // while(LEFT_DRIVE.output() != 0){
  left_drive.moveVelocity(0);
  right_drive.moveVelocity(0);
  pros::delay(20);
  // }
}

void swingTurnLeft(int distance, int velocity, int rVel) {
  resetPos();
  while (abs(right_front.getPosition()) < distance) {
    right_drive.moveVelocity(velocity);
    left_drive.moveVelocity(rVel);
  }
  left_drive.moveVelocity(0);
  right_drive.moveVelocity(0);
}

void swingTurnRight(int distance, int velocity, int lVel) {
  resetPos();
  while (abs(left_front.getPosition()) < distance) {
    left_drive.moveVelocity(velocity);
    right_drive.moveVelocity(lVel);
  }
  left_drive.moveVelocity(0);
  right_drive.moveVelocity(0);
}

void driveNRE(int distance, int velocity) {
  resetPos();
  distance = abs(distance);
  while (abs(left_front.getPosition()) < distance ||
         abs(right_front.getPosition()) < distance) {
    left_drive.moveVelocity(LEFT_DRIVE.calculate(velocity));
    right_drive.moveVelocity(RIGHT_DRIVE.calculate(velocity));
    // LEFT_DRIVE.calculate(targetVelocity);
    // RIGHT_DRIVE.calculate(targetVelocity);
    pros::delay(LEFT_DRIVE.get_changeMsec());
  }
}

void driveNRB(int distance, int velocity) {
  resetPos();
  distance = abs(distance);
  while (abs(left_front.getPosition()) < distance ||
         abs(right_front.getPosition()) < distance) {
    left_drive.moveVelocity(velocity);
    right_drive.moveVelocity(velocity);
    // LEFT_DRIVE.calculate(targetVelocity);
    // RIGHT_DRIVE.calculate(targetVelocity);
    pros::delay(20);
  }
  while (LEFT_DRIVE.output() != 0) {
    left_drive.moveVelocity(LEFT_DRIVE.calculate(0));
    right_drive.moveVelocity(RIGHT_DRIVE.calculate(0));
    pros::delay(LEFT_DRIVE.get_changeMsec());
  }
}

void turn(int deg, int velocity) {
  resetPos();
  while (abs(left_front.getPosition()) < deg) {
    left_drive.moveVelocity(velocity);
    right_drive.moveVelocity(-velocity);
  }
  left_drive.moveVelocity(0);
  right_drive.moveVelocity(0);
}
} // namespace auton
} // namespace drive
