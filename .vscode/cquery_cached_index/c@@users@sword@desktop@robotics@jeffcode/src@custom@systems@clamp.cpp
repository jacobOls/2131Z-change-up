#include "main.h"
#include "custom/systems/clamp.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/tilter.hpp"
bool clampOpen = false; //is the clamp open or closed
namespace clamp{
  void clampdump(){
    if(clampMotor.getPosition() >= 250){
      if(!clampOpen)//if its closed run this next code
      {
        if(BtnToggle.isPressed())
        {
          clampOpen = true;
          clampMotor.moveAbsolute(50,100);
        }
      }
      else//if open do this
      {
        if(BtnToggle.isPressed())
        {
          clampOpen = false;
          clampMotor.moveAbsolute(0,-100);
        }
      }
    }
    else
    {
      if(!clampOpen)//if its closed run this next code
      {
        if(BtnToggle.isPressed())
        {
          clampOpen = true;
          clampMotor.moveAbsolute(100,100);
        }
      }
      else//if open do this
      {
        if(BtnToggle.isPressed())
        {
          clampOpen = false;
          clampMotor.moveAbsolute(0,-100);
        }
      }
    }
  }
}
