#include "custom/auton/posTracking.hpp"
#include "custom/auton/pid.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/drive.hpp"
#include "main.h"
#include <iostream>
#include <math.h>
#define MUT_DELAY 666;
volatile const double wheelCirc = M_PI * 2.75;
const double sL = 7;
const double sR = 7;
const double sS = 4;
volatile const double robotDiameter{hypot(9, 15)};
double d2r(int degrees) { return degrees * (M_PI / 180); }
double r2d(int radians) { return radians * (180 / M_PI); }
double sgn(double foo) { return (foo > 0) ? 1 : ((foo < 0) ? -1 : 0); }
void printCords();
double clampAngle(double foo) {
  while (foo > M_PI) {
    foo -= 2 * M_PI;
  }
  while (foo < -M_PI) {
    foo += 2 * M_PI;
  }
  return foo;
}

double curLeft{0}, curRight{0}, curBack{0}, prevLeft{0}, prevRight{0},
    prevBack{0}, curTheta{0}, xPos{0}, yPos{0};

void posCalc() {
  while (true) {
    // if (fabs(left.get_velocity() + right.get_velocity() +
    // back.get_velocity()) > 15) {
    curLeft = auton::leftTracker.get_position();
    curRight = auton::rightTracker.get_position();
    curBack = auton::sTracker.get_position();

    double deltaR = (curRight - prevRight) / 36000 * (M_PI * 2.75);
    double deltaL = (curLeft - prevLeft) / 36000 * (M_PI * 2.75);

    double deltaTheta = (deltaL - deltaR) / 14;
    double localOffX, localOffY;

    double driftLeft = ((9.6 * deltaTheta * 2.5) / 2.75);
    double driftRight = ((9.6 * deltaTheta * 2.5) / 2.75);
    double unchangedR = deltaR;
    deltaR = (abs(deltaR) - driftRight) * sgn(deltaR);
    deltaL = (abs(deltaL) - driftLeft) * sgn(deltaL);

    auto deltaM = static_cast<const double>(
        ((curBack - prevBack) / 36000) * (M_PI * 2.75) -
        ((deltaTheta / (2_pi)) * M_PI * 3 * 2));

    double driftM = (11 * deltaTheta) / 2.75;
    double unchangedM = deltaM;

    deltaM = (abs(deltaM) - driftM) * sgn(deltaM);

    prevLeft = curLeft;
    prevRight = curRight;
    prevBack = curBack;

    deltaR = abs(deltaR) > 0.012 ? deltaR : 0;
    deltaL = abs(deltaL) > 0.012 ? deltaL : 0;
    deltaM = abs(deltaM) > 0.03 ? deltaM : 0;

    if (deltaL == deltaR) {
      localOffX = deltaM;
      localOffY = deltaR;
    } else {
      localOffX = 2 * std::sin(deltaTheta / 2) * (deltaM / deltaTheta + 3 * 2);
      localOffY = 2 * std::sin(deltaTheta / 2) * (deltaR / deltaTheta + 14 / 2);
    }

    double avgA = curTheta + (deltaTheta / 2);

    double polarR = sqrt((localOffX * localOffX) + (localOffY * localOffY));
    double polarA = atan2(localOffY, localOffX) - avgA;

    double dX = sin(polarA) * polarR;
    double dY = cos(polarA) * polarR;

    if (isnan(dX)) {
      dX = 0;
    }

    if (isnan(dY)) {
      dY = 0;
    }

    if (isnan(deltaTheta)) {
      deltaTheta = 0;
    }

    xPos += dX;
    yPos += dY;
    curTheta += deltaTheta;
    if (deltaM != 0)
      std::cout << deltaM << "\t" << driftM << "\t" << unchangedM << std::endl;
    // std::cout << "x " << xPos << "\t"
    // << "y " << yPos << "\t"
    // << "theta " << curTheta << "\tdelta left " << deltaL
    // << "\tdelta right " << deltaR << "\tdeltaM " << deltaM
    // << "\tdeltaX " << dX << "\tdeltaY " << dY << std::endl;
    // }
    pros::delay(3);
  }
}

void viewAngleTurn(double reqTheta,
                   double velocity) { // turns into pure pursuit range
  double threshold = .1;              // range of error
  int turnReq = 20;                   // final decelerated velocity
  bool direction;                     // true = left, false = right
  if (curTheta - reqTheta > 0) {
    direction = true;
  } else if (curTheta - reqTheta < 0) {
    direction = false;
  }
  if (direction == false) {
    velocity *= -1;
    turnReq *= -1;
  }
  // check if in threshold 1
  while (curTheta < reqTheta - (4 * threshold) &&
         curTheta > reqTheta + (4 * threshold)) {
    drive::accelDrive.accelMath(accel, &drive::left_drive, -velocity);
    drive::accelDrive.accelMath(accel, &drive::right_drive, velocity);
    pros::delay(3);
  }
  reset();

  // check if in threshold 2
  while (curTheta < reqTheta - threshold && curTheta > reqTheta + threshold) {

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
  return atan2(y - yPos, x - xPos) - (curTheta - d2r(90));
}
double distanceToTarget() { return hypot(x - xPos, y - yPos); }
double xToPoint() { return cos(angleToPoint()) * distanceToTarget(); }
double yToPoint() { return sin(angleToPoint()) * distanceToTarget(); }
double xPower() {
  return (xToPoint() / (abs(xToPoint()) + abs(yToPoint()))) * (200 / 2.2);
}
double yPower() {
  return (yToPoint() / (abs(xToPoint()) + abs(yToPoint()))) * (200 / 1.5);
}
double turnPower() {
  int foo = (angleToPoint() + prefAngle) / d2r(30);
  return std::clamp(foo, -1, 1) * (0);
}
} // namespace foo
double constrainVelocity(double foo) { return foo < 100 ? foo : 100; }

void toPoint(int reqX, int reqY) {
  viewAngleTurn(foo::angleToPoint(),
                constrainVelocity(foo::angleToPoint() * 63));
  while (xPos != reqX && yPos != reqY) {
    foo::x = reqX;
    foo::y = reqY;
    if (foo::distanceToTarget() > 3) {
      drive::leftFront.moveVelocity(foo::yPower() + foo::xPower() -
                                    foo::turnPower());
      drive::leftBack.moveVelocity(foo::yPower() - foo::xPower() -
                                   foo::turnPower());

      drive::rightFront.moveVelocity(foo::yPower() - foo::xPower() +
                                     foo::turnPower());
      drive::rightBack.moveVelocity(foo::yPower() + foo::xPower() +
                                    foo::turnPower());
    } else if (foo::distanceToTarget() <= 3 && foo::distanceToTarget() > 1) {
      drive::leftFront.moveVelocity((foo::yPower() + foo::xPower()) / 4);
      drive::leftBack.moveVelocity((foo::yPower() - foo::xPower()) / 4);

      drive::rightFront.moveVelocity((foo::yPower() - foo::xPower()) / 4);
      drive::rightBack.moveVelocity((foo::yPower() + foo::xPower()) / 4);
    } else {
      drive::driveGroup.moveVelocity(0);
      break;
    }
  }
}
