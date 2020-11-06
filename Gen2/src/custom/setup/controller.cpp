#include "custom/setup/controller.hpp"
#include "main.h"
okapi::Controller master;

namespace drive {
okapi::ControllerButton BtnBrake = master[okapi::ControllerDigital::right];
}
namespace selection {
okapi::ControllerButton BtnSwap = master[okapi::ControllerDigital::left];
}
namespace intake {
okapi::ControllerButton BtnIn = master[okapi::ControllerDigital::R1];
okapi::ControllerButton BtnOut = master[okapi::ControllerDigital::R2];
okapi::ControllerButton ManualIn = master[okapi::ControllerDigital::Y];
} // namespace intake
namespace elevator {
okapi::ControllerButton BtnIn = master[okapi::ControllerDigital::L1];
okapi::ControllerButton BtnOut = master[okapi::ControllerDigital::X];
okapi::ControllerButton BtnBack = master[okapi::ControllerDigital::L2];
okapi::ControllerButton Down = master[okapi::ControllerDigital::down];
okapi::ControllerButton UpOnly = master[okapi::ControllerDigital::B];
} // namespace elevator
