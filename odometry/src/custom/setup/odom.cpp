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
static double curLeft = 0, curRight = 0, curBack = 0, deltaLeft = 0, deltaRight = 0, deltaBack = 0;
static double storedLeft = 0, storedRight = 0, storedBack = 0, globalLeft = 0, globalRight = 0, globalBack = 0;
static double startingLeft = 0, startingRight = 0, startingBack = 0;
static double xOffset = 0, yOffset = 0, thetaMe = 0;;
static double curTheta = 0, startingTheta = 0, prevTheta = 0, deltaTheta = 0, dlX = 0, dlY = 0;
static double polarOffsetX = 0, polarOffsetY = 0, globalXOffset = 0, globalYOffset = 0, yPos = 0, xPos = 0, prevX = 0, prevY = 0;
#define wheelCirc (M_PI * 2.75)
#define sL 6.5
#define sR 6.5
#define sS 4

 void printCoords() {
  std::cout << "x " << xPos << "\t"
            << "y " << yPos << "\t"
            << "theta " << curTheta << "\tdelta left " << deltaLeft << "\tdelta right " << deltaRight << std::endl;
}
void posCalc() {
  while(true){
    if(fabs(left.get_velocity() + right.get_velocity() + back.get_velocity()) > 2){
  curLeft = left.get_position()/100;
  curRight = right.get_position()/100;
  curBack = back.get_position()/100;

  deltaLeft = ((curLeft - storedLeft) / 360) * wheelCirc;
  deltaRight = ((curRight - storedRight) / 360) * wheelCirc;
  deltaBack = ((curBack - storedBack) / 360) * wheelCirc;

  storedLeft = curLeft;
  storedRight = curRight;
  storedBack = curBack;

  globalLeft = ((curLeft / 360)* wheelCirc) - startingLeft;
  globalRight = ((curRight / 360) * wheelCirc) - startingRight;
  globalBack = ((curBack / 360) * wheelCirc) - startingBack;

  curTheta = startingTheta + ((globalLeft - globalRight) / (sL + sR));

  deltaTheta = curTheta - prevTheta;

  if(deltaTheta == 0){
    xOffset = deltaBack;
    yOffset = deltaRight;
  } else{
    xOffset = (2 * sin(deltaTheta / 2)) * ((deltaBack / deltaTheta) + sS);
    yOffset = (2 * sin(deltaTheta / 2)) * ((deltaRight / deltaTheta) + sR);
  }

  thetaMe = prevTheta + (deltaTheta / 2);

  double polarTheta = atan2(yPos, xPos) - thetaMe;
  double polarR = hypot(xPos,yPos);
  xPos = polarR * cos(polarTheta);
  yPos = polarR * sin(polarTheta);

  xPos = xPos + xOffset;
  yPos = yPos + yOffset;

}
    printCoords();
    pros::delay(10);
  }
}
void printCords() {
  std::cout << "x " << pos.x << "\t"
            << "y " << pos.y << "\t"
            << "theta " << theta1 << "\tdelta left " << deltaLeft << "\tdelta right " << deltaRight << std::endl;
}
// void pointTurn() {}
