#include "main.h"
#include "custom/setup/controller.hpp"
okapi::Controller master;
namespace drive{

}

namespace tilter{
okapi::ControllerButton BtnUp = master[okapi::ControllerDigital::Y];
okapi::ControllerButton BtnDown = master[okapi::ControllerDigital::right];
}

namespace config{
}

namespace intake{
  okapi::ControllerButton BtnIn = master[okapi::ControllerDigital::R1];
  okapi::ControllerButton BtnOut = master[okapi::ControllerDigital::R2];
  okapi::ControllerButton BtnLeft = master[okapi::ControllerDigital::down];
  okapi::ControllerButton BtnRight = master[okapi::ControllerDigital::B];
}

namespace lift{

}
