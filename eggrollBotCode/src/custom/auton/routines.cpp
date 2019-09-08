#include "custom/auton/routines.hpp"
#include "custom/systems/drive.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/tray.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/intake.hpp"
#include "main.h"
namespace auton
{
  void wait(double waitTime)
  {
    pros::delay(waitTime);

//autonomous routines start here
  }
  void driveTest()
  {
    drive::auton::autonDrive(500,50);
  }




}
