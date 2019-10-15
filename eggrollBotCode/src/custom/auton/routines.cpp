#include "custom/auton/routines.hpp"
#include "custom/systems/drive.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/tray.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/intake.hpp"
#include "custom/setup/motors.hpp"
#include "main.h"
namespace auton{
  void wait(double waitTime){
    pros::delay(waitTime);
  }
  //about 300 for 90 degree turn
  //autonomous routines start here
  void skillsAuton(){
    tray::motor.tarePosition();
    drive::auton::resetPositions();
    drive::auton::autonDrive(300,50);
    drive::auton::autonDriveBack(-310,-50);
    lift::auton::popOpen();
    lift::auton::autonLiftDown(2380,-100);
    tray::auton::trayDown(0,-100);
    intake::auton::intakeOn(200);
    drive::auton::autonDriveBack(-30,-50);
    drive::auton::autonDrive(1100,50);
    drive::auton::autonDriveBack(-300,-50);
    drive::auton::leftTurn(8,50);
    drive::auton::autonDrive(450,50);
    drive::auton::autonDriveBack(-225,-50);
    drive::auton::rightTurn(5,50);
    drive::auton::autonDrive(500,50);
    drive::auton::autonDrive(-100,50);
    wait(1000);
    intake::auton::intakeOff();
    drive::auton::autonDriveBack(-850,-100);
    drive::auton::rightTurn(300,50);
    drive::auton::autonDrive(200,50);
    tray::auton::stack(300,25);
  }

  void redRight(){
    tray::motor.tarePosition();
    drive::auton::resetPositions();
    drive::auton::autonDrive(300,50);
    drive::auton::autonDriveBack(-290,-50);
    lift::auton::popOpen();
    lift::auton::autonLiftDown(2380,-100);
    tray::auton::trayDown(0,-100);
    intake::auton::intakeOn(200);
    drive::auton::autonDriveBack(-50,-50);
    drive::auton::autonDrive(1100,50);
    drive::auton::autonDriveBack(-300,-50);
    drive::auton::leftTurn(8,50);
    drive::auton::autonDrive(450,50);
    drive::auton::autonDriveBack(-200,-50);
    drive::auton::rightTurn(120,50);
    drive::auton::autonDrive(420,50);
    wait(1000);
    intake::auton::intakeOff();
    drive::auton::autonDriveBack(-800, -50);
    drive::auton::rightTurn(300,50);
  }
}
