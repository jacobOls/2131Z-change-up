#include "main.h"
#include "custom/setup/controller.hpp"
okapi::Controller master;
namespace drive
{
  okapi::ControllerButton BtnHold = master[okapi::ControllerDigital::Y];

}

namespace tilter
{
okapi::ControllerButton BtnForward = master[okapi::ControllerDigital::left];
okapi::ControllerButton BtnBackward = master[okapi::ControllerDigital::up];
okapi::ControllerButton BtnGoUp = master[okapi::ControllerDigital::right];
okapi::ControllerButton BtnReturn = master[okapi::ControllerDigital::A];

} // namespace tilter

namespace intake
{
okapi::ControllerButton BtnIn = master[okapi::ControllerDigital::R1];
okapi::ControllerButton BtnOut = master[okapi::ControllerDigital::R2];
okapi::ControllerButton BtnLeft = master[okapi::ControllerDigital::down];
okapi::ControllerButton BtnRight = master[okapi::ControllerDigital::B];
okapi::ControllerButton BtnBackUp = master[okapi::ControllerDigital::X];
} // namespace intake

namespace lift
{
okapi::ControllerButton BtnUp = master[okapi::ControllerDigital::L1];
okapi::ControllerButton BtnDown = master[okapi::ControllerDigital::L2];

} // namespace lift
