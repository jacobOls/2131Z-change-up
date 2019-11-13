#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/tilter.hpp"
#include "custom/systems/lift.hpp"

namespace tilter{
  Controllers controller = Controllers::NONE;
  void tilterUp(){
    if(BtnForward.isPressed()){
      motor.moveVelocity(25);
    }
    else if(abs(motor.get_actual_velocity()) > 0 && !BtnBackward.isPressed()){
      motor.moveVelocity(0);
    }
  }

  void tilterDown(){
    if(BtnBackward.isPressed()){
      motor.moveVelocity(-100);
    }
    else if(abs(motor.get_actual_velocity()) > 0 && !BtnForward.isPressed()){
      motor.moveVelocity(0);
    }
  }

  void execute()
  {
    // if (controller == Controllers::FORWARD && sensor() > 2150)
    // {
    //   controller = Controllers::DEINIT;
    // }
    // if (controller == Controllers::BACKWARD && sensor() <= 1430)
    // {
    //   controller = Controllers::DEINIT;
    // }
    switch (controller)
    {

      case Controllers::FORWARD:
      motor.moveVelocity(25);
      // trayLock = false;
      break;

      case Controllers::BACKWARD:
      motor.moveVelocity(-75);
      // trayLock = false;
      break;

      case Controllers::TOUP:
      // trayLock = true;
      // if (sensor() < upPlace)
      // {
      //   motor.moveVelocity(100);
      // }
      // else if (sensor() >= upPlace)
      // {
      //   motor.moveVelocity(0);
      //   controller = Controllers::DEINIT;
      // }
      break;

      case Controllers::RETURN:
      // if (lSensor() < 1250 && sensor() > 1520)
      // {
      //   motor.moveVelocity(-100);
      // }
      // else if (sensor() > 1870)
      // {
      //   motor.moveVelocity(-100);
      // }

      break;

      case Controllers::DEINIT:
      motor.moveVelocity(0);
      controller = Controllers::NONE;
      break;

      case Controllers::NONE:
      break;
    }
  }

  void init(){
    tilterUp();
    tilterDown();
    execute();
  }
}
