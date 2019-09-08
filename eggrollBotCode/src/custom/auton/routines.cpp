#include "custom/auton/routines.hpp"
#include "custom/systems/drive.hpp"
#include "custom/setup/controller.hpp"
#include "main.h"
namespace auton
{
void driveTest()
{
drive::auton::autonDrive(3000, 40);
pros::delay(1000);
drive::auton::turn(400,50);
pros::delay(1000);

}




}
