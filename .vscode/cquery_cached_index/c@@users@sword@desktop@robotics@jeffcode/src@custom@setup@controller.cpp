#include "main.h"
#include "custom/setup/controller.hpp"
okapi::Controller myController;
//declares controllers

//sets controller buttons
namespace drive
{
  okapi::ControllerButton BtnBrake = myController[okapi::ControllerDigital::X];
  //toggles the brake
}
namespace lift
{
  okapi::ControllerButton BtnUp = myController[okapi::ControllerDigital::L1];
  //extends up
  okapi::ControllerButton BtnDown = myController[okapi::ControllerDigital::L2];
  //extends down
}
namespace intake
{
  okapi::ControllerButton BtnOn = myController[okapi::ControllerDigital::R1];
  //when held turns on intake
  okapi::ControllerButton BtnOut = myController[okapi::ControllerDigital::R2];
  //when held puts intake in reverse
  okapi::ControllerButton BtnLeft = myController[okapi::ControllerDigital::down];
  //outfeeds with a left spin
  okapi::ControllerButton BtnRight = myController[okapi::ControllerDigital::B];
  //outfeeds with a right spin

}
namespace tilter
{
  okapi::ControllerButton BtnTiltF = myController[okapi::ControllerDigital::up];
  //move tilter forward
  okapi::ControllerButton BtnTiltB = myController[okapi::ControllerDigital::left];
  //moves tilter backwards
}
