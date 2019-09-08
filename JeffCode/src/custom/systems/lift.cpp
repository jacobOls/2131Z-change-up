#include "main.h"
#include "custom/systems/lift.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
//extends the bot up and down

namespace lift{

  void lift(){


    if (BtnUp.isPressed()) {
      group2.moveVelocity(100);
    }
    else if (BtnDown.isPressed()) {
      group2.moveVelocity(-100);

    }
    else{
      group2.moveVelocity(0);
      group2.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    }

  }


}
