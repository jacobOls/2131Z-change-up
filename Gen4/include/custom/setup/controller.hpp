#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "main.h"
extern okapi::Controller master;

namespace drive{

}

namespace tilter{
extern okapi::ControllerButton BtnUp;
extern okapi::ControllerButton BtnDown;
}

namespace config{
}

namespace intake{
  extern okapi::ControllerButton BtnIn;
  extern okapi::ControllerButton BtnOut;
  extern okapi::ControllerButton BtnRight;
  extern okapi::ControllerButton BtnLeft;
}

namespace lift{
  extern okapi::ControllerButton BtnUp;
  extern okapi::ControllerButton BtnDown;
  extern okapi::ControllerButton BtnL;
  extern okapi::ControllerButton BtnM;

}
#endif /* end of include guard: CONTROLLER_HPP */
