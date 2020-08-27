#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "main.h"
extern okapi::Controller master;
namespace drive {
extern okapi::ControllerButton BtnBrake;
}
namespace intake {
extern okapi::ControllerButton BtnIn;
extern okapi::ControllerButton BtnOut;
} // namespace intake
namespace wheel {
extern okapi::ControllerButton BtnIn;
extern okapi::ControllerButton BtnOut;

} // namespace wheel
#endif /* end of include guard: CONTROLLER_HPP */
