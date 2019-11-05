#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/tilter.hpp"
#include "custom/systems/lift.hpp"

namespace tilter
{
  Controllers controller = Controllers::NONE;
  double sensor()
  {
    return tilterSensor.get_value();
  }
  double lSensor()
  {
    return lift::liftSensor.get_value();
  }

  int halfDown =1850;
  int allDown = 1170;
  int upPlace = 1850;

  void up()
  {
    if (BtnForward.isPressed())
    {
      controller = Controllers::FORWARD;
    }
    else if (controller == Controllers::FORWARD)
    {
      controller = Controllers::DEINIT;
    }
  }

  void down()
  {
    if (BtnBackward.isPressed())
    {
      controller = Controllers::BACKWARD;
    }
    else if (controller == Controllers::BACKWARD)
    {
      controller = Controllers::DEINIT;
    }
  }

  void goUp(){
    if(BtnGoUp.isPressed()){
      controller = Controllers::TOUP;
    }
    // else if(controller == Controllers::TOUP && motor.getActualVelocity() < 50){
    //   controller = Controllers::DEINIT;
    // }
  }



  void returnDown()
  {
    if (BtnReturn.isPressed())
    {
      controller = Controllers::RETURN;
    }
    else if (controller == Controllers::RETURN)
    {
      controller = Controllers::DEINIT;
    }
  }

  void execute()
  {
    if (controller == Controllers::FORWARD && sensor() > 2300)
    {
      controller = Controllers::DEINIT;
    }
    if (controller == Controllers::BACKWARD && sensor() < 1450)
    {

      controller = Controllers::DEINIT;

    }
    switch (controller)
    {

      case Controllers::FORWARD:
      motor.moveVelocity(75);
      break;

      case Controllers::BACKWARD:
      motor.moveVelocity(-75);
      break;

      case Controllers::TOUP:
      if(sensor() < upPlace){
        motor.moveVelocity(100);
      }
      else if(sensor() >= upPlace)
      { motor.moveVelocity(0);
        controller = Controllers::DEINIT;
      }
      break;

      case Controllers::RETURN:
      if (lSensor() > 1200)
      {
        if (sensor() >= halfDown)
        {
          motor.moveVelocity(-100);
        }
        else if (sensor() >= allDown)
        {
          motor.moveVelocity(-100);
        }
      }
      break;

      case Controllers::DEINIT:
      motor.moveVelocity(0);
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
    goUp();
    execute();
    returnDown();
  }

  namespace auton
  {

    void trayDown(double wantedPosition, double targetVelocity)
    {
      while (sensor() > wantedPosition)
      {
        motor.moveVelocity(targetVelocity);
      }
      if (motor.getPosition() <= wantedPosition)
      {
        motor.moveVelocity(0);
      }
    }

    void stack(double wantedPosition, double targetVelocity)
    {
      while (sensor() < wantedPosition)
      {
        motor.moveVelocity(targetVelocity);
      }
      if (sensor() >= wantedPosition)
      {
        motor.moveVelocity(0);
      }
    }

  } // namespace auton

} // namespace tilter
