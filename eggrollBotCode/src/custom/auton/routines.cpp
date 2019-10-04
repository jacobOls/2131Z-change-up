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
  void skillsAuton(){
    drive::auton::resetPositions();
    // drive::auton::autonDrive(300,50);
    // drive::auton::autonDriveBack(-300,-50);
    // lift::auton::popOpen();
    // lift::auton::autonLiftDown(10,-100);/
    // tray::auton::trayDown(10, -100);
    intake::auton::intakeOn(200);
    drive::auton::autonDrive(1000,50);
    drive::auton::autonDriveBack(-200,-50);
    drive::auton::leftTurn(10,50);
    drive::auton::autonDrive(200,50);
    drive::auton::autonDriveBack(-200,-50);
    drive::auton::rightTurn(15,50);
    drive::auton::autonDrive(350,50);
    drive::auton::autonDrive(-100,50);
    drive::auton::rightTurn(100,50);
    drive::auton::autonDrive(-200,50);
  }




}
