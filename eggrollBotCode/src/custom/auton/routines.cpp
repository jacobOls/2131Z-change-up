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
    drive::auton::autonDrive(300,75);
    lift::auton::popOpen();
    drive::auton::autonDriveBack(-290,-125);
    lift::auton::autonLiftDown(2380,-100);
    tray::auton::trayDown(0,-100);
    intake::auton::intakeOn(200);
    drive::auton::autonDriveBack(-10, -50);
    drive::auton::autonDrive(1000,70);
    drive::auton::autonDriveBack(-175,-125);
    drive::auton::leftTurn(3,25);
    drive::auton::autonDrive(480,60);
    wait(200);
    drive::auton::autonDriveBack(-250,-150);
    drive::auton::rightTurn(90,50);
    drive::auton::autonDrive(390,70);
    wait(1100);
    intake::auton::intakeOff();
    drive::auton::autonDriveBack(-930, -150);
    drive::auton::rightTurn(180,60);
    drive::auton::autonDrive(500, 125);
    intake::auton::intakeOn(-25);
    wait(1000);
    intake::auton::intakeOff();
    tray::auton::stack(450,30);
    wait(500);
    intake::auton::stackReverseAuton(-500, 25, 25);
    tray::auton::trayDown(0,-100);
  }

  void redRight(){
    tray::motor.tarePosition();
    drive::auton::resetPositions();
    drive::auton::autonDrive(300,75);
    lift::auton::popOpen();
    drive::auton::autonDriveBack(-290,-125);
    lift::auton::autonLiftDown(2380,-100);
    tray::auton::trayDown(0,-100);
    intake::auton::intakeOn(200);
    drive::auton::autonDriveBack(-20, -50);
    drive::auton::autonDrive(1000,70);
    drive::auton::autonDriveBack(-175,-125);
    drive::auton::leftTurn(3,20);
    drive::auton::autonDrive(480,50);
    wait(200);
    drive::auton::autonDriveBack(-250,-150);
    drive::auton::rightTurn(90,50);
    drive::auton::autonDrive(390,70);
    wait(1100);
    intake::auton::intakeOff();
    drive::auton::autonDriveBack(-930, -150);
    drive::auton::rightTurn(155,60);
    drive::auton::autonDrive(500, 125);
    intake::auton::intakeOn(-25);
    wait(1000);
    intake::auton::intakeOff();
    tray::auton::stack(450,30);
    wait(500);
    intake::auton::stackReverseAuton(-500, 25, 25);
    tray::auton::trayDown(0,-100);
  }
}
