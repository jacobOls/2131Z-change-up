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
  int upPlace = 1750;
  int sensorPlace = 1500;
  int fastSpeedSpot = 1400;
  int startUp = 1640;

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



  void execute()
  {
    if (controller == Controllers::UP)
    {
      if (sensor() > 2800)
      {
        controller = Controllers::DEINIT;
      }
    }
    if (controller == Controllers::DOWN)
    {
      if (sensor() < 1200)
      {
        controller = Controllers::DEINIT;
      }
    }
    switch (controller)
    {

      case Controllers::UP:
      if (tilter() < startUp)
      {
        tilter::motor.moveVelocity(-40);
      }
      else if(tilter() >= startUp)
      {
        if (tilter() < upPlace)
        {
          motor.moveVelocity(100);
          tilter::motor.moveVelocity(-40);
        }
        else{
          motor.moveVelocity(100);
          tilter::motor.moveVelocity(-0);
        }
      }
      break;

      case Controllers::DOWN:

        motor.moveVelocity(-75);
        if (sensor() < sensorPlace)
        {
          if (tilter() >= startUp)
          {
            tilter::motor.moveVelocity(75);
          }
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
    execute();
  }
  namespace auton
  {
    bool unpopped = true;
    bool popped = false;
    const double targetPosition = 25;
    const double epsilon = 5;

    void autonLiftUp(double targetPosition, double targetVelocity)
    {
      while (sensor() <= targetPosition)
      {
        motor.moveVelocity(targetVelocity);
      }
      if (sensor() >= targetPosition)
      {
        motor.moveVelocity(0);
      }
    }

    void autonLiftDown(double wantedPosition, double targetVelocity)
    {
      if (sensor() <= wantedPosition)
      {
        motor.moveVelocity(targetVelocity);
      }
      if (sensor() >= wantedPosition)
      {
        motor.moveVelocity(0);
      }
    }

    void popOpen()
    {
      if (sensor() > 2000)
      {
        motor.moveVelocity(90);
        tilter::motor.moveVelocity(60);
      }
      if (sensor() <= 2000)
      {
        motor.moveVelocity(0);
        tilter::motor.moveVelocity(0);
      }
    }
  } // namespace auton
} // namespace lift
