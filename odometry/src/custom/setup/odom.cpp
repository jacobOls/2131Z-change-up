#include "custom/setup/odom.hpp"
#include "custom/setup/motors.hpp"
#include "custom/vec2.hpp"
#include "main.h"
#include <cmath>
#include <iostream>
#define MUT_DELAY 666;
volatile const double wheelCirc = M_PI * 2.75;
const double sL = 6.5;
const double sR = 6.5;
const double sS = 4;
volatile const double robotDiameter{hypot(9, 15)};
pros::Rotation right(8);
pros::Rotation left(17);
pros::Rotation back(19);
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
    curLeft = left.get_position();
    curRight = right.get_position();
    curBack = back.get_position();

    const double deltaR = (curRight - prevRight) / 36000 * (M_PI * 2.75);
    const double deltaL = (curLeft - prevLeft) / 36000 * (M_PI * 2.75);

    double deltaTheta = (deltaL - deltaR) / 13;
    double localOffX, localOffY;
    curTheta += deltaTheta;
    const double deltaM = (curBack - prevBack) / (36000 * (M_PI * 2.75)) -
                          ((deltaTheta / (2 * M_PI)) * M_PI * 4 * 2);

    prevLeft = curLeft;
    prevRight = curRight;
    prevBack = curBack;

    if (deltaL == deltaR) {
      localOffX = deltaM;
      localOffY = deltaR;
    } else {
      localOffX = 2 * std::sin(deltaTheta / 2) * (deltaM / deltaTheta + 4 * 2);
      localOffY = 2 * std::sin(deltaTheta / 2) * (deltaR / deltaTheta + 13 / 2);
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
    std::cout << "x " << xPos << "\t"
              << "y " << yPos << "\t"
              << "theta " << curTheta << "\tdelta left " << deltaL
              << "\tdelta right " << deltaR << "\tdeltaX " << dX << "\tdeltaY "
              << dY << std::endl;
    // }
    pros::delay(3);
  }
}
// void pointTurn() {}
