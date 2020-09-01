#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "main.h"
extern okapi::Controller master;
namespace drive {
extern okapi::ControllerButton BtnBrake;
} // end namespace drive
namespace intake {
extern okapi::ControllerButton BtnIn;
extern okapi::ControllerButton BtnOut;
} // end namespace intake
namespace wheel {
extern okapi::ControllerButton BtnIn;
extern okapi::ControllerButton BtnOut;
extern okapi::ControllerButton BtnBack;
extern okapi::ControllerButton Unjam;

} // end namespace wheel
#endif /* end of include guard: CONTROLLER_HPP */