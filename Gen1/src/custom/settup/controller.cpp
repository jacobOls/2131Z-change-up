#include "main.h"
okapi::Controller master;

namespace drive{}

namespace intake{
    okapi::ControllerButton BtnIn = master[okapi::ControllerDigital::R1];
    okapi::ControllerButton BtnOut = master[okapi::ControllerDigital::R2];
}
namespace wheel{
    okapi::ControllerButton BtnIn = master[okapi::ControllerDigital::L1];
    okapi::ControllerButton BtnOut = master[okapi::ControllerDigital::L2];
}
