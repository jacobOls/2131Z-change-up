#include "custom/settup/controller.hpp"
#include "main.h"
okapi::Controller master;

namespace drive {
okapi::ControllerButton BtnBrake = master[okapi::ControllerDigital::right];
}

namespace intake {
okapi::ControllerButton BtnIn = master[okapi::ControllerDigital::R1];
okapi::ControllerButton BtnOut = master[okapi::ControllerDigital::R2];
} // namespace intake
namespace wheel {
okapi::ControllerButton BtnIn = master[okapi::ControllerDigital::L1];
okapi::ControllerButton BtnOut = master[okapi::ControllerDigital::L2];
okapi::ControllerButton BtnBack = master[okapi::ControllerDigital::Y];
okapi::ControllerButton Unjam = master[okapi::ControllerDigital::down];
okapi::ControllerButton UpOnly = master[okapi::ControllerDigital::B];
} // namespace wheel
