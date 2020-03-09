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

void exDrive(int vel, int distance) { // eponential ramping drive
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

void linDrive(int vel, int distance) { // linear ramping drive
  int velocity = 1;
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

} // namespace drive
