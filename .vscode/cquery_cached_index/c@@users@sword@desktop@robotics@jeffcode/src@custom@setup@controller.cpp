#include "main.h"
#include "custom/setup/controller.hpp"
okapi::Controller myController;

namespace drive
{
  okapi::ControllerButton BtnBrake = myController[okapi::ControllerDigital::X];
}
namespace lift
{
  okapi::ControllerButton BtnUp = myController[okapi::ControllerDigital::L1];
  okapi::ControllerButton BtnDown = myController[okapi::ControllerDigital::L2];
}
namespace intake
{
  okapi::ControllerButton BtnOn = myController[okapi::ControllerDigital::R1];
  okapi::ControllerButton BtnOut = myController[okapi::ControllerDigital::R2];
  okapi::ControllerButton BtnLeft = myController[okapi::ControllerDigital::down];
  okapi::ControllerButton BtnRight = myController[okapi::ControllerDigital::B];

}
namespace tilter
{
  okapi::ControllerButton BtnTiltF = myController[okapi::ControllerDigital::up];
  okapi::ControllerButton BtnTiltB = myController[okapi::ControllerDigital::left];

}
