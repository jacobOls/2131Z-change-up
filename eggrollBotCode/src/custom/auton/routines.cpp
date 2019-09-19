#include "custom/auton/routines.hpp"
#include "custom/systems/drive.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/tray.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/intake.hpp"
#include "main.h"
namespace auton{
  void wait(double waitTime){
    pros::delay(waitTime);
  }
//about 300 for 90 degree turn
//autonomous routines start here
  void initalAuton(){
    // lift::auton::popOpen();
    intake::auton::intakeOn(200);
    drive::auton::autonDrive(900,50);
    drive::auton::turn(450,-50);
    drive::auton::autonDrive(100,50);
    drive::auton::autonDrive(-100,50);
    drive::auton::turn(100,50);
    drive::auton::autonDrive(200,50);
  }




}
