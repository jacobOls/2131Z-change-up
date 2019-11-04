#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/tilter.hpp"

namespace lift
{
Controllers controller = Controllers::NONE;
double sensor()
{
  return liftSensor.get_value();
}
double tilter()
{
  return tilter::tilterSensor.get_value();
}
int upPlace;
int sensorPlace;
int fastSpeedSpot;
int startUp;

void up()
{
  if (BtnUp.isPressed())
  {
    controller = Controllers::UP;
  }
  else if (controller == Controllers::UP)
  {
    controller = Controllers::DEINIT;
  }
}

void down()
{
  if (BtnDown.isPressed())
  {
    controller = Controllers::DOWN;
  }
  else if (controller == Controllers::DOWN)
  {
    controller = Controllers::DEINIT;
  }
}

void lowT()
{
  if (BtnL.isPressed())
  {
    controller = Controllers::LOWT;
  }
  else if (controller == Controllers::LOWT)
  {
    controller = Controllers::DEINIT;
  }
}

void midT()
{
  if (BtnM.isPressed())
  {
    controller = Controllers::MIDT;
  }
  else if (controller == Controllers::MIDT)
  {
    controller = Controllers::DEINIT;
  }
}

void execute()
{
  if (controller == Controllers::UP)
  {
    if (sensor() > 2200)
    {
      controller = Controllers::DEINIT;
    }
  }
  if (controller == Controllers::DOWN)
  {
    if (sensor() < 1000)
    {
      controller = Controllers::DEINIT;
    }
  }
  switch (controller)
  {

  case Controllers::UP:
    if (tilter() < startUp)
    {
      tilter::motor.moveVelocity(75);
    }
    else
    {
      motor.moveVelocity(75);
      if (tilter() < upPlace)
      {
        tilter::motor.moveVelocity(75);
      }
    }
    break;

  case Controllers::DOWN:
    if (sensor() > fastSpeedSpot)
    {
      motor.moveVelocity(-75);
    }
    else
    {
      motor.moveVelocity(-25);
    }
    if (sensor() < sensorPlace)
    {
      if (tilter() >= upPlace)
      {
        tilter::motor.moveVelocity(-75);
      }
    }
    break;

  case Controllers::LOWT:
    if (sensor() < 1800)
    {
      motor.moveVelocity(100);
    }
    break;

  case Controllers::MIDT:
    if (sensor() < 2500)
    {
      motor.moveVelocity(100);
    }
    break;

  case Controllers::DEINIT:
    motor.moveVelocity(0);
    tilter::motor.moveVelocity(0);
    controller = Controllers::NONE;
    break;

  case Controllers::NONE:
    break;
  }
}

void init()
{
  up();
  down();
  lowT();
  midT();
  execute();
}
namespace auton{
  bool unpopped = true;
  bool popped = false;
  const double targetPosition = 25;
  const double epsilon = 5;

  void autonLiftUp(double targetPosition, double targetVelocity){
    while(sensor() <= targetPosition){
      motor.moveVelocity(targetVelocity);
    }
    if(sensor() >= targetPosition){
      motor.moveVelocity(0);
    }
  }

  void autonLiftDown(double wantedPosition, double targetVelocity){
    if(sensor() <= wantedPosition){
      motor.moveVelocity(targetVelocity);
    }
    if(sensor() >= wantedPosition){
      motor.moveVelocity(0);
    }
  }





  void popOpen(){
    if(sensor() > 2000){
      motor.moveVelocity(90);
      tilter::motor.moveVelocity(60);
    }
    if(sensor() <= 2000){
      motor.moveVelocity(0);
      tilter::motor.moveVelocity(0);
    }
  }
}
} // namespace lift
