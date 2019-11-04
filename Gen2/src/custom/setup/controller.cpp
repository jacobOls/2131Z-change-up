#include "main.h"
#include "controller.hpp"
okapi::Controller master;
namespace drive{
  // okapi::ControllerButton BtnBrake = master[okapi::ControllerDigital::X];
  //toggles the brake
  okapi::ControllerButton BtnBackUp = master[okapi::ControllerDigital::X];
}
namespace tray{
  okapi::ControllerButton BtnF = master[okapi::ControllerDigital::Y];
  okapi::ControllerButton BtnB = master[okapi::ControllerDigital::right];
  okapi::ControllerButton travelBack =master[okapi::ControllerDigital::A];
  okapi::ControllerButton btnGoUp = master[okapi::ControllerDigital::up];
//a goes down as far as possible
}
namespace config{
  okapi::ControllerButton BtnCalabrate = master[okapi::ControllerDigital::left];
}
namespace intake{
  okapi::ControllerButton BtnOn = master[okapi::ControllerDigital::R1];
  //when held turns on intake
  okapi::ControllerButton BtnOut = master[okapi::ControllerDigital::R2];
  //when held puts intake in reverse
  okapi::ControllerButton BtnLeft = master[okapi::ControllerDigital::down];
  //outfeeds with a left spin
  okapi::ControllerButton BtnRight = master[okapi::ControllerDigital::B];
  //outfeeds with a right spin

}
namespace lift{
okapi::ControllerButton BtnUp = master[okapi::ControllerDigital::L1];
okapi::ControllerButton BtnDown = master[okapi::ControllerDigital::L2];

}
