#include "main.h"
#include "custom/systems/clamp.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/tilter.hpp"
bool clampOpen = false; //is the clamp open or closed
namespace clamp{
  //
  // void clampthings()
  // {
  //
  //     if(!clampOpen){
  //       if(BtnToggle.isPressed())
  //       {
  //         clampOpen = true;
  //         clampMotor.moveAbsolute(60,100);
  //       }
  //     }
  //     else
  //       if(BtnToggle.isPressed())
  //       {
  //         clampOpen = false;
  //         clampMotor.moveAbsolute(0,-100);
  //     }
  //   }
  //
  double targetPos;
  void changer(){
    if(targetPos==60){targetPos=0;}
    else if(targetPos==0){targetPos=60;}
    clampMotor.moveAbsolute(targetPos,200);
  }
  void control(){
    static bool btnwas;
    if(BtnToggle.isPressed() && !btnwas)
    {//init
      btnwas=true;

      changer();

    }
    if(!BtnToggle.isPressed() && btnwas)
    {//deinit
      btnwas=false;
    }
  }
  // void clampclose()
  // {
  //   static bool btnwas;
  //
  //   if(BtnToggle.isPressed() && btnwas)
  //   {
  //     clampMotor.moveAbsolute(0,100);
  //
  //   }
  //   if(BtnToggle.isPressed() && !btnwas)
  //   {
  //   }
  //   btnwas = BtnToggle.isPressed();
  // }
  void clamptoggle()
  {
    control();
  }
}
