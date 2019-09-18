#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "main.h"
extern okapi::Controller master;

namespace drive{
  // extern okapi::ControllerButton BtnBrake;
  extern okapi:: ControllerButton BtnMacro;
}
namespace tray{
  extern okapi::ControllerButton BtnF;
  extern okapi::ControllerButton BtnB;
  extern okapi::ControllerButton BtnLowTower;
  extern okapi::ControllerButton BtnMidTower;
}
namespace config{
  extern okapi::ControllerButton BtnCalabrate;
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
