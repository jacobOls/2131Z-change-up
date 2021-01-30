#include "custom/auton/motionProfile.hpp"
#include "custom/setup/motors.hpp"
#include "custom/setup/odom.hpp"
#include "main.h"
#include <cmath>
#include <iostream>
namespace auton {
double d2r(int degrees) { return degrees * (M_PI / 180); }
double epsilon;
void odomTurn(double reqTheta, double velocity) {
  reqTheta = d2r(reqTheta);
  epsilon = .05;   // range of error
  int turnReq = 5; // final decelerated velocity
  bool direction;  // true = left, false = right
  if (theta1 - reqTheta > 0) {
    direction = true;
  } else if (theta1 - reqTheta < 0) {
    direction = false;
  }
  if (direction == false) {
    velocity *= -1;
    turnReq *= -1;
  }
  while (theta1 < reqTheta - (4 * epsilon) &&
         theta1 >
             reqTheta +
                 (4 * epsilon)) { // check for being in range of deceleration
    drive::accelDrive.accelMath(accel, &drive::left_drive, -velocity);
    drive::accelDrive.accelMath(accel, &drive::right_drive, velocity);
    pros::delay(3);
  }
  reset();

  while (theta1 < reqTheta - epsilon &&
         theta1 > reqTheta + epsilon) { // check if in acceptable range of error

    drive::accelDrive.deAccelMath(accel, &drive::left_drive, -turnReq,
                                  drive::driveGroup.getActualVelocity());
    drive::accelDrive.deAccelMath(accel, &drive::right_drive, turnReq,
                                  drive::driveGroup.getActualVelocity());
  }
  drive::driveGroup.moveVelocity(0);
  reset();
} // end function odomTurn
} // namespace auton
