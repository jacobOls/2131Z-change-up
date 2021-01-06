#include "custom/setup/odom.hpp"
#include "custom/setup/motors.hpp"
#include "main.h"
#include <cmath>
namespace odom {
// vars
volatile double wheelCirc = M_PI * 2;
const double robotDiameter{hypot(9, 15)};
const double robotCircumference{M_PI * robotDiameter};
pros::Rotation right(5);
pros::Rotation left(7);
pros::Rotation back(6);
// encoder variables
double curX, curY, curR, reqX, reqY, reqR;

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
void calcTurn() {
  reqR = atan2(reqY - curY, reqX - curX);
  deltaR = reqR - curR;
}

double finalTurn() { return deltaR * (180 / M_PI); }
void posCalc() {
  double curLeftEnc, curRightEnc, curBackEnc, deltaLeft, deltaRight, deltaBack,
      prevLeft, prevRight, prevBack, avgDelta;
  // pos variables
  curLeftEnc = (left.get_position());
  curRightEnc = (right.get_position());
  curBackEnc = (back.get_position());
  setCurR(back.get_position());
  deltaLeft = (curLeftEnc - prevLeft);
  deltaRight = (curRightEnc - prevRight);
  deltaBack = (curBackEnc - prevBack);

  avgDelta = (deltaLeft + deltaRight) / 2;

  prevLeft = curLeftEnc;
  prevRight = curRightEnc;
  prevBack = curBackEnc;
}
} // namespace odom
