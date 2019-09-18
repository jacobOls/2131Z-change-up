#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/systems/drive.hpp"
#include "custom/setup/controller.hpp"
namespace config{
  bool calabrated = false;
  void tareMotors(){
    drive::right_drive.tarePosition();
    drive::left_drive.tarePosition();
    tray::motor.tarePosition();
    lift::motor.tarePosition();
  }

  void calabrate(){
    if(BtnCalabrate.isPressed()){
      if(!calabrated){
        tray::motor.moveVelocity(-5);
        lift::motor.moveVelocity(-5);
        calabrated = true;
      }

    }
    if(calabrated){
      tareMotors();
      calabrated = false;
    }
  }
}
