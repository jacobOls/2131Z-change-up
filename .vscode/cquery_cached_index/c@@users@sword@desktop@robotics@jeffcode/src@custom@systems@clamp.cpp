#include "main.h"
#include "custom/systems/clamp.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "custom/systems/tilter.hpp"
#include "custom/systems/intake.hpp"
bool clampOpen = false; //is the clamp open or closed
enum clampingState {any, open, close};//
clampingState overrideState = clampingState::any;
namespace clamp{

  void openClamp(bool override){
    if (override || overrideState == clampingState::any) {
      clampMotor.moveAbsolute(130,200);
    }

    if (override) {
      overrideState = clampingState::open;
    }
    else if (overrideState == clampingState::open){
      overrideState = clampingState::any;
    }
  }

  void closeClamp(bool override) {
    if (override || overrideState == clampingState::any) {
      clampMotor.moveAbsolute(0,200);
    }

    if (override) {
      overrideState = clampingState::close;
    }
    else if (overrideState == clampingState::close){
      overrideState = clampingState::any;
    }
  }
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
    if(targetPos==130){targetPos=0;}
    else if(targetPos==0){targetPos=130;}
    clampMotor.moveAbsolute(targetPos,200);
  }
  void control(){
    static bool btnwas;
    if(BtnToggle.isPressed())
    {//init
      if (!btnwas) {
        btnwas=true;

        changer();
      }
    } else if (btnwas) {
      btnwas = false;
    }
    // if(!BtnToggle.isPressed() && btnwas)
    // {//deinit
    //   btnwas=false;
    // }
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
