#include "custom/auton/motionProfile.hpp"
#include "custom/setup/motors.hpp"
#include "custom/setup/odom.hpp"
#include "main.h"
#include <cmath>
#include <iostream>
namespace auton {
// conver degrees into radians
double d2r(int degrees) { return degrees * (M_PI / 180); }
// constrains the max velocity for a turn
double constrainVelocity(double foo) { return foo < 100 ? foo : 100; }
double epsilon;

void precisionTurn(double reqTheta, double velocity) { // to be used seperatly
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
  // check for being in range of deceleration
  while (theta1 < reqTheta - (4 * epsilon) &&
         theta1 > reqTheta + (4 * epsilon)) {
    drive::accelDrive.accelMath(accel, &drive::left_drive, -velocity);
    drive::accelDrive.accelMath(accel, &drive::right_drive, velocity);
    pros::delay(3);
  }
  reset();

  // check if in acceptable range of error
  while (theta1 < reqTheta - epsilon && theta1 > reqTheta + epsilon) {

    drive::accelDrive.deAccelMath(accel, &drive::left_drive, -turnReq,
                                  drive::driveGroup.getActualVelocity());
    drive::accelDrive.deAccelMath(accel, &drive::right_drive, turnReq,
                                  drive::driveGroup.getActualVelocity());
  }
  drive::driveGroup.moveVelocity(0);
  reset();
} // end function manualTurn

double threshold;
void viewAngleTurn(double reqTheta,
              double velocity) { // turns into pure pursuit range
  threshold = .1;                // range of error
  int turnReq = 20;              // final decelerated velocity
  bool direction;                // true = left, false = right
  if (theta1 - reqTheta > 0) {
    direction = true;
  } else if (theta1 - reqTheta < 0) {
    direction = false;
  }
  if (direction == false) {
    velocity *= -1;
    turnReq *= -1;
  }
  // check if in threshold 1
  while (theta1 < reqTheta - (4 * threshold) &&
         theta1 > reqTheta + (4 * threshold)) {
    drive::accelDrive.accelMath(accel, &drive::left_drive, -velocity);
    drive::accelDrive.accelMath(accel, &drive::right_drive, velocity);
    pros::delay(3);
  }
  reset();

  // check if in threshold 2
  while (theta1 < reqTheta - threshold && theta1 > reqTheta + threshold) {

    drive::accelDrive.deAccelMath(accel, &drive::left_drive, -turnReq,
                                  drive::driveGroup.getActualVelocity());
    drive::accelDrive.deAccelMath(accel, &drive::right_drive, turnReq,
                                  drive::driveGroup.getActualVelocity());
  }
  drive::driveGroup.moveVelocity(0);
  reset();
} // end function odomTurn
namespace foo {
double x, y, prefAngle;
double angleToPoint() {
  return atan2(y - pos.y, x - pos.x) - (theta1 - d2r(90));
}
double distanceToTarget() { return hypot(x - pos.x, y - pos.y); }
double xToPoint() { return cos(angleToPoint()) * distanceToTarget(); }
double yToPoint() { return sin(angleToPoint()) * distanceToTarget(); }
double xPower() { return (xToPoint() / (abs(xToPoint()) + abs(yToPoint())))*(200/2.2); }
double yPower() { return (yToPoint() / (abs(xToPoint()) + abs(yToPoint())))*(200/2.2); }
double turnPower(){
  int foo = (angleToPoint() + prefAngle)/d2r(30);
  return std::clamp(foo,-1,1) * (20);
}
} // namespace foo
void goToPoint(Vec2 reqPos) {
  viewAngleTurn(foo::angleToPoint(), constrainVelocity(foo::angleToPoint() * 63));
  while(pos.x !=  reqPos.x && pos.y != reqPos.y){
    foo::x = reqPos.x;
    foo::y = reqPos.y;
    if(foo::distanceToTarget() > 3){
    drive::leftFront.moveVelocity(foo::yPower() + foo::xPower() - foo::turnPower());
    drive::leftBack.moveVelocity(foo::yPower() - foo::xPower() - foo::turnPower());

    drive::rightFront.moveVelocity(foo::yPower() - foo::xPower() + foo::turnPower());
    drive::rightBack.moveVelocity(foo::yPower() + foo::xPower() + foo::turnPower());
  } else if (foo::distanceToTarget() > 1){
    drive::leftFront.moveVelocity((foo::yPower() + foo::xPower())/2);
    drive::leftBack.moveVelocity((foo::yPower() - foo::xPower())/2);

    drive::rightFront.moveVelocity((foo::yPower() - foo::xPower())/2);
    drive::rightBack.moveVelocity((foo::yPower() + foo::xPower())/2);
  }
  else{
    break;
  }
  }
}
void pursue(Vec2 reqPos) { // give a point on the fied to travel to
  double angleToTarget = atan2(reqPos.y - pos.y, reqPos.x - pos.x) - (theta1 - d2r(90));
  viewAngleTurn(angleToTarget, constrainVelocity(angleToTarget * 63));
  // moves the robot to look ahead point

} // end function goToPoint

} // namespace auton
