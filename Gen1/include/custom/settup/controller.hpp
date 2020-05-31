#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "main.h"
extern okapi::Controller master;
namespace drive{}
namespace intake{
extern okapi::ControllerButton BtnIn;
extern okapi::ControllerButton BtnOut;
}
namespace wheel{
extern okapi::ControllerButton BtnIn;
extern okapi::ControllerButton BtnOut;

}
#endif /* end of include guard: CONTROLLER_HPP */
