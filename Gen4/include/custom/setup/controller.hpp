#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "main.h"
extern okapi::Controller master;

namespace drive
{
}

namespace tilter
{
extern okapi::ControllerButton BtnUp;
extern okapi::ControllerButton BtnDown;
extern okapi::ControllerButton BtnR;
extern okapi::ControllerButton BtnGoUp;
} // namespace tilter

namespace intake
{
extern okapi::ControllerButton BtnIn;
extern okapi::ControllerButton BtnOut;
extern okapi::ControllerButton BtnRight;
extern okapi::ControllerButton BtnLeft;
} // namespace intake

namespace lift
{
extern okapi::ControllerButton BtnUp;
extern okapi::ControllerButton BtnDown;


} // namespace lift
#endif /* end of include guard: CONTROLLER_HPP */
