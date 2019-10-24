#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "main.h"
extern okapi::Controller master;

namespace drive{
  // extern okapi::ControllerButton BtnBrake;
  extern okapi:: ControllerButton BtnBackUp;
}
namespace arma{
extern okapi:: ControllerButton BtnUp;
extern okapi:: ControllerButton BtnDown;

}
namespace claw{
  extern okapi:: ControllerButton BtnOpen;
  extern okapi:: ControllerButton BtnClose;

}
#endif
