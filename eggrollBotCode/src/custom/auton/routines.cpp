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
  void firstAuton()
  {
    lift::auton::popOpen();
    intake::auton::intakeOn(200);
    drive::auton::autonDrive(1000,200);
    drive::auton::turn(20,50);
    drive::auton::autonDrive(1200,200);
    tray::auton::stack(475, 35);
  }




}
