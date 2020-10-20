#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "main.h"
extern okapi::Controller master;
namespace drive {
extern okapi::ControllerButton BtnBrake;
} // namespace drive
namespace selection {
extern okapi::ControllerButton BtnSwap;
} // namespace selection
namespace intake {
extern okapi::ControllerButton BtnIn;
extern okapi::ControllerButton BtnOut;
} // namespace intake
namespace elevator {
extern okapi::ControllerButton BtnIn;
extern okapi::ControllerButton BtnOut;
extern okapi::ControllerButton BtnBack;
extern okapi::ControllerButton Unjam;
extern okapi::ControllerButton UpOnly;

} // namespace elevator
#endif /* end of include guard: CONTROLLER_HPP */
