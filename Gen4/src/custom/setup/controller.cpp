#include "main.h"
#include "custom/setup/controller.hpp"
okapi::Controller master;
namespace drive
{
}

namespace tilter
{
okapi::ControllerButton BtnUp = master[okapi::ControllerDigital::Y];
okapi::ControllerButton BtnDown = master[okapi::ControllerDigital::right];
} // namespace tilter

namespace intake
{
okapi::ControllerButton BtnIn = master[okapi::ControllerDigital::R1];
okapi::ControllerButton BtnOut = master[okapi::ControllerDigital::R2];
okapi::ControllerButton BtnR = master[okapi::ControllerDigital::A];
okapi::ControllerButton BtnLeft = master[okapi::ControllerDigital::down];
okapi::ControllerButton BtnRight = master[okapi::ControllerDigital::B];
} // namespace intake

namespace lift
{
okapi::ControllerButton BtnUp = master[okapi::ControllerDigital::L1];
okapi::ControllerButton BtnDown = master[okapi::ControllerDigital::L2];
okapi::ControllerButton BtnL = master[okapi::ControllerDigital::left];
okapi::ControllerButton BtnM = master[okapi::ControllerDigital::up];
} // namespace lift
