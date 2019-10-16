#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/systems/drive.hpp"
#include "custom/setup/controller.hpp"
namespace config{
  void tareMotors(){
    drive::right_drive.tarePosition();
    drive::left_drive.tarePosition();
    tray::motor.tarePosition();
    lift::motor.tarePosition();
  }

  void calibrate(){




  }

}
