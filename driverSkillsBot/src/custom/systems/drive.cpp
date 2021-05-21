#include "custom/systems/drive.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "main.h"
#include <iostream>
namespace drive {
// retrieve and transform input values of analogs
double mult = 200;
int rY() { return (master.getAnalog(okapi::ControllerAnalog::rightY)) * mult; };
int lY() { return (master.getAnalog(okapi::ControllerAnalog::leftY)) * mult; };

// sets motor voltage
std::string multString;
int sgn(double foo) { return foo > 0 ? 1 : foo < 0 ? -1 : 0; }

void userDrive() {
  int dz = .05 * mult; // dead zone
  if (abs(lY()) > dz) {
    leftFront.moveVelocity(lY());
  } else
    leftFront.moveVoltage(0);

  if (abs(lY()) > dz) {
    leftBack.moveVelocity(lY());
  } else
    leftBack.moveVelocity(0);

  if (abs(rY()) > dz) {
    rightFront.moveVelocity(rY());
  } else
    rightFront.moveVelocity(0);

  if (abs(rY()) > dz) {
    rightBack.moveVelocity(rY());
  } else
    rightBack.moveVelocity(0);
}
} // namespace drive
