#ifndef MOTORS_HPP
#define MOTORS_HPP
#include "main.h"
namespace drive{
  extern okapi::Motor right_drive;
  extern okapi::Motor left_drive;

}
namespace claw{

  extern okapi::Motor motor;
}

namespace arma{

  extern okapi::Motor motor;

}
#endif
