#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "main.h"
extern okapi::Controller master;
namespace intake
{
extern okapi::ControllerButton BtnIn;
extern okapi::ControllerButton BtnOut;
extern okapi::ControllerButton BtnRight;
extern okapi::ControllerButton BtnLeft;
extern okapi::ControllerButton BtnBackUp;
} // namespace intake
namespace drive
{
  extern okapi::ControllerButton BtnHold;
}

namespace tilter
{
extern okapi::ControllerButton BtnForward;
extern okapi::ControllerButton BtnBackward;
extern okapi::ControllerButton BtnReturn;
extern okapi::ControllerButton BtnGoUp;
} // namespace tilter


namespace lift
{
extern okapi::ControllerButton BtnUp;
extern okapi::ControllerButton BtnDown;
}
#endif /* end of include guard: CONTROLLER_HPP */
