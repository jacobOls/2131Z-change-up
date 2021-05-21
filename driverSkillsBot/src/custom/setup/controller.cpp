#include "custom/setup/controller.hpp"
#include "main.h"
okapi::Controller master;

namespace drive {
okapi::ControllerButton BtnBrake = master[okapi::ControllerDigital::up];
}
namespace selection {
okapi::ControllerButton BtnSwap = master[okapi::ControllerDigital::left];
}
namespace intake {
okapi::ControllerButton BtnIn = master[okapi::ControllerDigital::R1];
okapi::ControllerButton BtnOut = master[okapi::ControllerDigital::R2];
okapi::ControllerButton ManualIn = master[okapi::ControllerDigital::X];
} // namespace intake
namespace elevator {
okapi::ControllerButton BtnIn = master[okapi::ControllerDigital::L1];
okapi::ControllerButton BtnOut = master[okapi::ControllerDigital::L2];
okapi::ControllerButton BtnBack = master[okapi::ControllerDigital::Y];
okapi::ControllerButton Down = master[okapi::ControllerDigital::down];
okapi::ControllerButton UpOnly = master[okapi::ControllerDigital::B];
okapi::ControllerButton mid = master[okapi::ControllerDigital::A];
okapi::ControllerButton autoElev = master[okapi::ControllerDigital::right];
} // namespace elevator
