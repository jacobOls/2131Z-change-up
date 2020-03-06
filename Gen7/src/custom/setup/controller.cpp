#include "custom/setup/controller.hpp"
#include "main.h"
okapi::Controller master;
namespace intake {
okapi::ControllerButton BtnIn = master[okapi::ControllerDigital::R1];
okapi::ControllerButton BtnOut = master[okapi::ControllerDigital::R2];
okapi::ControllerButton BtnBackUp = master[okapi::ControllerDigital::X];
} // namespace intake

namespace tilter {
okapi::ControllerButton BtnForward = master[okapi::ControllerDigital::up];
okapi::ControllerButton BtnBackward = master[okapi::ControllerDigital::left];
// okapi::ControllerButton BtnGoUp = master[okapi::ControllerDigital::right];
okapi::ControllerButton BtnReturn = master[okapi::ControllerDigital::right];

} // namespace tilter

namespace lift {
okapi::ControllerButton BtnUp = master[okapi::ControllerDigital::L1];
okapi::ControllerButton BtnDown = master[okapi::ControllerDigital::L2];
okapi::ControllerButton BtnSlowDown = master[okapi::ControllerDigital::Y];

} // namespace lift
