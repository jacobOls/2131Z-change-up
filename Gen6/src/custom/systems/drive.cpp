#include "custom/systems/drive.hpp"
#include "custom/systems/lift.hpp"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"

namespace drive{
  int lStick(){
    return std::abs(master.getAnalog(okapi::ControllerAnalog::leftY));
  }

  int rStick(){
    return std::abs(master.getAnalog(okapi::ControllerAnalog::rightY));
  }
void userDrive(){




}

}
