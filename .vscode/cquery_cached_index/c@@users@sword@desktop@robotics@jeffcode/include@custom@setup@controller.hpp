#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "okapi/api.hpp"
extern okapi::Controller myController;

namespace drive{
  extern okapi::ControllerButton BtnBrake;
}
namespace lift{
  extern okapi::ControllerButton BtnUp;
  extern okapi::ControllerButton BtnDown;
}
namespace intake{
  extern okapi::ControllerButton BtnOn;
  extern okapi::ControllerButton BtnOut;
  extern okapi::ControllerButton BtnRight;
  extern okapi::ControllerButton BtnLeft;
}
// namespace clamp{
//   extern okapi::ControllerButton BtnOpen;
//   extern okapi::ControllerButton BtnClose;
// }
//clamp does not exist right now, im keeping the code for it thats in here for if one gets added
namespace tilter
{
  extern okapi::ControllerButton BtnTiltF;
  extern okapi::ControllerButton BtnTiltB;
}
#endif /* end of include guard: CONTROLLER_HPP */
