#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "main.h"
extern okapi::Controller master;

namespace drive{
  extern okapi::ControllerButton BtnBrake;
}
namespace tray{
  extern okapi::ControllerButton BtnF;
  extern okapi::ControllerButton BtnB;
}
namespace intake{
  extern okapi::ControllerButton BtnOn;
  extern okapi::ControllerButton BtnOut;
  extern okapi::ControllerButton BtnRight;
  extern okapi::ControllerButton BtnLeft;
}
namespace lift{
  extern okapi::ControllerButton BtnUp;
  extern okapi::ControllerButton BtnDown;
}
#endif /* end of include guard: CONTROLLER_HPP */
