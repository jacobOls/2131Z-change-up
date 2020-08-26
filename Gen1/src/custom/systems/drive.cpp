#include "custom/systems/drive.hpp"
#include "custom/settup/controller.hpp"
#include "custom/settup/motors.hpp"
#include "main.h"
namespace drive {
State state = State::NONE;
Side side = Side::NONE;

void execute() {}
void userDrive() {
  // std::cout << "init" << std::endl;
  // leftDriveStraight();
  // rightDriveStraight();
  // leftStrafeDrive();
  // rightStrafeDrive();
  execute();
}
} // namespace drive
