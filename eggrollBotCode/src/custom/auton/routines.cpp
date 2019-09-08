#include "custom/auton/routines.hpp"
#include "custom/systems/drive.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/tray.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/intake.hpp"
#include "main.h"
namespace auton
{
void driveTest()
{
intake::auton::intakeOn(100);
pros::delay(1000);
intake::auton::intakeOff();
pros::delay(10000);
}




}
