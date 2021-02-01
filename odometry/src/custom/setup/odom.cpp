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
volatile const double robotCircumference{M_PI * robotDiameter};
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
double d0, theta0, thetaR = 0, theta1, deltaTheta, curLeft, curRight, curBack,
                   storedLeft, storedRight, storedBack, deltaLeft, deltaRight,
                   deltaBack, globalDeltaLeft, globalDeltaRight,
                   globalDeltaBack, storedGlobalLeft = 0, storedGlobalRight = 0,
                   storedGlobalBack = 0, thetaM;
Vec2 offset = {0, 0};
Vec2 pos = {0, 0};
Vec2 prevPos = pos;
Vec2 offsetPolar = offset;
Vec2 globalOffset = offset;
double reconvert;
void posCalc() {
  left.set_reversed(true);
  back.set_reversed(false);
  right.set_reversed(false);
  right.set_position(0);
  left.set_position(0);
  back.set_position(0);
  while (true) {

    if (abs(right.get_velocity() + abs(back.get_velocity())) !=
        0) {
      // set current position of encoders
      curLeft = left.get_position();
      curRight = right.get_position();
      curBack = back.get_position();
      // find the change in distance of the encoders from last check
      deltaLeft = (curLeft - storedLeft) / 36000 * wheelCirc;
      deltaRight = (curRight - storedRight) / 36000 * wheelCirc;
      deltaBack = (curBack - storedBack) / 36000 * wheelCirc;
      // store previous values
      storedLeft = curLeft;
      storedRight = curRight;
      storedBack = curBack;
      // get global delta
      globalDeltaLeft = curLeft - storedGlobalLeft;
      globalDeltaRight = curRight - storedGlobalRight;
      globalDeltaBack = curBack - storedGlobalBack;
      // calculate absolute theta
      theta1 =
          thetaR + ((globalDeltaLeft + globalDeltaRight) / ((sL + sR) * 100));
      // change in angle
      deltaTheta = theta1 - theta0;
      // calculate offset (how off this equation is from accuracy)
      if (deltaTheta == 0) {
        offset = {deltaBack, deltaRight};
      } else if (deltaTheta != 0) {
        // offset = {(deltaBack / deltaTheta) + sS,
        //           (deltaRight / deltaTheta) + sR};
                  double yee = (deltaBack/deltaTheta) + sS;
                  double yee2 = (deltaRight/deltaTheta + sR);

        offset =  {yee,yee2};
        offset = offset * (2 * sin(theta1 / 2));
      }
      // calculate average orientation
      thetaM = theta0 + (deltaTheta / 2);
      // calculate global offset
      offsetPolar = {sqrt(pow(offset.x, 2) + pow(offset.y, 2)),
                     atan2(offset.y, offset.x)};
      reconvert = offsetPolar.y * sin(theta1 - thetaM);
      globalOffset = {offset.x, reconvert};
      pos = globalOffset + prevPos;
      prevPos = pos;
    } else{
      left.set_position(curLeft);
    }
    printCords();
    pros::delay(100);
    }
  }


void printCords() {
  std::cout << "x " << pos.x << "\t"
            << "y " << pos.y << "\t"
            << "theta " << theta1 << "\tdelta left " << deltaLeft << "\tdelta right " << deltaRight << std::endl;
}
// void pointTurn() {}
