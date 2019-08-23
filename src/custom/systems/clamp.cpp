#include "main.h"
#include "custom/systems/clamp.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/tilter.hpp"
bool clampOpen = false; //is the clamp open or closed
namespace clamp{
  void clampdump(){
    if(tilter::tiltmotor.getPosition() >= 700){ //checks position of tilter to run first block
      if(!clampOpen)//if its closed run this next code
      {
        if(BtnToggle.isPressed())
        {
          clampOpen = true;
          clampMotor.moveAbsolute(70,100);
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
    else //if the tilter is in a different position do this
    {
      if(!clampOpen)//if its closed run this next code
      {
        if(BtnToggle.isPressed())
        {
          clampOpen = true;
          clampMotor.moveAbsolute(15,100);
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





  void clampAgain()
  {
    if(tilter::tiltmotor.getPosition() >= 700){ //checks position of tilter to run first block
      if(!clampOpen){
        if(BtnToggle.isPressed())
        {
          clampOpen = true;
          clampMotor.moveAbsolute(70,100);
        }
        else
        {
          if(BtnToggle.isPressed())
          {
            clampOpen = false;
            clampMotor.moveAbsolute(0,-100);
          }
        }
      }
    }
    else if(tilter::tiltmotor.getPosition() < 700)
    {
      if(!clampOpen){
        if(BtnToggle.isPressed())
        {
          clampOpen = true;
          clampMotor.moveAbsolute(70,100);
        }
      }
      else
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
