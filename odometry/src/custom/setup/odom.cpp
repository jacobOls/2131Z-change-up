#include "custom/setup/odom.hpp"
#include "custom/setup/motors.hpp"
#include "main.h"
#include <cmath>
namespace odom {
// vars
volatile const double wheelCirc = M_PI * 2;
volatile const double robotDiameter{hypot(9, 15)};
volatile const double robotCircumference{M_PI * robotDiameter};
pros::Rotation right(5);
pros::Rotation left(7);
pros::Rotation back(6);
// encoder variables
double curX, curY, curR, reqR;

void setCurR(double foo) {
  while (foo > M_PI) {
    foo -= 2 * M_PI;
  }
  while (foo < -M_PI) {
    foo += 2 * M_PI;
  }
  curR = foo;
}
// calculates requred turn in radians
double deltaR;
void calcTurn(int reqX, int reqY) {
  reqR = atan2(reqY - curY, reqX - curX);
  deltaR = reqR - curR;
}
double reqDis;
void calcDist(int reqX, int reqY) { reqDis = hypot(reqX, reqY); }
double finalTurn() { return deltaR * (180 / M_PI); }
double remainingTurn() { return deltaR - curR; }
double velocity() { return remainingTurn() * 50; }
void travel() {
  while (abs(remainingTurn()) > abs(finalTurn())) {
    drive::accelDrive.accelMath(accel, &drive::left_drive, velocity());
    drive::accelDrive.accelMath(accel, &drive::right_drive, -velocity());
    pros::delay(drive::accelDrive.rateOfChange);
  }
  while (abs(remainingTurn()) < abs(finalTurn())) {
    drive::accelDrive.accelMath(accel, &drive::left_drive, -velocity());
    drive::accelDrive.accelMath(accel, &drive::right_drive, velocity());
    pros::delay(drive::accelDrive.rateOfChange);
  }
  drive::driveGroup.moveVelocity(0);
}
double absoluteX{0}, absoluteY{0};
double curLeftEnc, curRightEnc, curBackEnc, deltaLeft, deltaRight, deltaBack,
    prevLeft, prevRight, prevBack, avgDelta, deltaX, deltaY, changeR;
void posCalc() {
  // pos variables
  curLeftEnc = (left.get_position());
  curRightEnc = (right.get_position());
  curBackEnc = (back.get_position() * (M_PI / 180));
  setCurR(curBackEnc);
  deltaLeft = wheelCirc * (curLeftEnc - prevLeft) / 360;
  deltaRight = wheelCirc * (curRightEnc - prevRight) / 360;
  deltaBack = wheelCirc * (curBackEnc - prevBack) / 360;

  avgDelta = (deltaLeft + deltaRight) / 2;

  prevLeft = curLeftEnc;
  prevRight = curRightEnc;
  prevBack = curBackEnc;

  deltaX = avgDelta * cos(deltaR + (changeR / 2));
  deltaY = avgDelta * sin(deltaR + (changeR / 2));

  absoluteX += deltaX;
  absoluteY += deltaY;

  pros::delay(10);
}
} // namespace odom
