#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "main.h"
extern okapi::Controller master;
namespace drive {
extern okapi::ControllerButton BtnBrake;
} // end namespace drive
namespace selection {
extern okapi::ControllerButton BtnSwap;
} // end namespace selection
namespace intake {
extern okapi::ControllerButton BtnIn;
extern okapi::ControllerButton BtnOut;
} // end namespace intake
namespace wheel {
extern okapi::ControllerButton BtnIn;
extern okapi::ControllerButton BtnOut;
extern okapi::ControllerButton BtnBack;
extern okapi::ControllerButton Unjam;
extern okapi::ControllerButton UpOnly;

} // end namespace wheel
#endif /* end of include guard: CONTROLLER_HPP */
