#include "main.h"
#include "custom/setup/controller.hpp"
okapi::Controller master;
namespace drive{
  // okapi::ControllerButton BtnBrake = master[okapi::ControllerDigital::X];
  //toggles the brake
}
namespace claw{
  okapi::ControllerButton BtnOpen = master[okapi::ControllerDigital::R2];
  okapi::ControllerButton BtnClose = master[okapi::ControllerDigital::R1];

}
namespace arma{
  okapi::ControllerButton BtnUp = master[okapi::ControllerDigital::L2];
  okapi::ControllerButton BtnDown = master[okapi::ControllerDigital::L1];

}
