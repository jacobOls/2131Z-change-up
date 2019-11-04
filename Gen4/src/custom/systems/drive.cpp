#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/drive.hpp"
#include "custom/setup/ramping.hpp"

namespace drive
{

int rightVel;
int leftVel;

void drive()
{
  //drive code
  if (std::abs(master.getAnalog(okapi::ControllerAnalog::leftY)) < 0.05)
    leftVel = 0;
  else
    leftVel = (master.getAnalog(ControllerAnalog::leftY) * 200);
  if (std::abs(master.getAnalog(okapi::ControllerAnalog::rightY)) < 0.05)
    rightVel = 0;
  else
    rightVel = (master.getAnalog(ControllerAnalog::rightY) * 200);

  right_drive.moveVelocity(rightVel);
  left_drive.moveVelocity(leftVel);
}

namespace auton
{

int lVel;
int rVel;
int lPos;
int rPos;
int moving()
{
  return left_front.getActualVelocity() && left_back.getActualVelocity() && right_front.getActualVelocity() && right_back.getActualVelocity();
}
void resetPositions()
{
  left_drive.tarePosition();
  right_drive.tarePosition();
}

void checkPos()
{
  if (lPos == rPos)
  {
  }
  else if (lPos != rPos)
  {
  }
}

void driving(int distance, int velocity)
{
  lVel = LEFT_DRIVE.calculate(velocity);
  rVel = RIGHT_DRIVE.calculate(velocity);
  lPos = left_back.getPosition();
  rPos = right_back.getPosition();

  while (lPos != distance || rPos != distance)
  {
    left_drive.moveVelocity(lVel);
    right_drive.moveVelocity(rVel);
    pros::delay(20);
  }

  while (moving() > 0)
  {
    velocity = 0;
    left_drive.moveVelocity(lVel);
    right_drive.moveVelocity(rVel);
    pros::delay(20);
  }
}

void rightTurn(double distance, double velocity)
{
  while (left_front.getPosition() < distance)
  {
    left_drive.moveVelocity(velocity);
    right_drive.moveVelocity(-velocity);
  }
  if (left_front.getPosition() > distance)
  {
    left_drive.moveVelocity(0);
    right_drive.moveVelocity(0);
    resetPositions();
  }
}

void leftTurn(double distance, double velocity)
{
  while (right_front.getPosition() < distance)
  {
    left_drive.moveVelocity(-velocity);
    right_drive.moveVelocity(velocity);
  }
  if (right_front.getPosition() > distance)
  {
    left_drive.moveVelocity(0);
    right_drive.moveVelocity(0);
    resetPositions();
  }
}

} // namespace auton

} // namespace drive
