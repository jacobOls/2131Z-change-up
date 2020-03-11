#include "custom/systems/drive.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "custom/setup/ramping.hpp"
#include "main.h"

namespace drive {

ramping drive = ramping(12, 1.2, -200, 200);
double lVel, rVel;

void userDrive() {
  if (!intake::BtnBackUp.isPressed()) {
    lVel = master.getAnalog(ControllerAnalog::leftY) * 200;
    rVel = master.getAnalog(ControllerAnalog::rightY) * 200;
  } else if (intake::BtnBackUp.isPressed()) {
    lVel = -40;
    rVel = -40;
  }
  left_drive.moveVelocity(lVel);
  right_drive.moveVelocity(rVel);
}

// autons

void exDrive(int distance, int vel) { // eponential ramping drive
  driveAll.tarePosition();
  while (abs(driveAll.getPosition()) < abs(distance)) {
    drive.accelMath(accel, &driveAll, 200);
    timesLooped++;
    pros::delay(drive.rateOfChange);
  }
  timesLooped = 0;
  while (driveAll.getActualVelocity() != 0) {
    drive.deAccelMath(accel, &driveAll, 0);
  }
}

void noRampEnd(int distance, int vel) { // eponential ramping drive
  driveAll.tarePosition();
  while (abs(driveAll.getPosition()) < abs(distance)) {
    drive.accelMath(accel, &driveAll, 200);
    timesLooped++;
    pros::delay(drive.rateOfChange);
  }
  timesLooped = 0;
}

void linDrive(int distance, int vel) { // linear ramping drive
  driveAll.tarePosition();
  int velocity = driveAll.getActualVelocity();
  driveAll.moveVelocity(velocity);
  while (abs(driveAll.getPosition()) < abs(distance)) {
    velocity += drive.changeVal;
    driveAll.moveVelocity(velocity);
    pros::delay(drive.rateOfChange);
  }
  while (driveAll.getActualVelocity() != 0) {
    drive.deAccelMath(accel, &driveAll, 0);
  }
}

void swingTurnLeft(int distance, int velocity, int rVel) {
  driveAll.tarePosition();
  while (abs(right_front.getPosition()) < distance) {
    right_drive.moveVelocity(velocity);
    left_drive.moveVelocity(rVel);
  }
  left_drive.moveVelocity(0);
  right_drive.moveVelocity(0);
}

void swingTurnRight(int distance, int velocity, int lVel) {
  driveAll.tarePosition();
  while (abs(left_front.getPosition()) < distance) {
    left_drive.moveVelocity(velocity);
    right_drive.moveVelocity(lVel);
  }
  left_drive.moveVelocity(0);
  right_drive.moveVelocity(0);
}

void leftTurn(int deg, int velocity) {
  driveAll.tarePosition();
  while (abs(left_front.getPosition()) < deg) {
    left_drive.moveVelocity(velocity);
    right_drive.moveVelocity(-velocity);
  }
  left_drive.moveVelocity(0);
  right_drive.moveVelocity(0);
}

void rightTurn(int deg, int velocity) {
  driveAll.tarePosition();
  while (abs(right_front.getPosition()) < deg) {
    left_drive.moveVelocity(-velocity);
    right_drive.moveVelocity(velocity);
  }
  left_drive.moveVelocity(0);
  right_drive.moveVelocity(0);
}
} // namespace drive
