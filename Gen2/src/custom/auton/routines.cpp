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
    drive::auton::autonDriveBack(-20, -50);
    drive::auton::autonDrive(800,70);
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

  void redRight(){
    tray::motor.tarePosition();
    drive::auton::resetPositions();
    drive::auton::autonDrive(300,85);
    lift::auton::popOpen();
    drive::auton::autonDriveBack(-290,-200);
    lift::auton::autonLiftDown(2380,-100);
    tray::auton::trayDown(0,-100);
    intake::auton::intakeOn(200);
    drive::auton::autonDriveBack(-50, -100);
    drive::auton::autonDrive(1050,60);
    drive::auton::autonDriveBack(-175,-150);
    drive::auton::leftTurn(3,20);
    drive::auton::autonDrive(310,50);
    wait(200);
    drive::auton::autonDriveBack(-250,-150);
    drive::auton::rightTurn(85,50);
    drive::auton::autonDrive(320,70);
    wait(1100);
    intake::auton::intakeOff();
    drive::auton::autonDriveBack(-1000, -200);
    drive::auton::rightTurn(155,60);
    drive::auton::autonDrive(500, 150);
    intake::auton::intakeOn(-25);
    wait(1000);
    intake::auton::intakeOff();
    tray::auton::stack(415,20);
    wait(500);
    intake::auton::stackReverseAuton(-500, 25, 25);
    tray::auton::trayDown(0,-100);
  }

void red5(){
  tray::motor.tarePosition();
  drive::auton::resetPositions();
  drive::auton::autonDrive(300,75);
  lift::auton::popOpen();
  drive::auton::autonDriveBack(-290,-125);
  drive::auton::autonDriveBack(-250,-150);
  lift::auton::autonLiftDown(2380,-100);
  tray::auton::trayDown(0,-100);
  intake::auton::intakeOn(200);
  drive::auton::autonDrive(1000,60);
  intake::auton::intakeOff();
  drive::auton::autonDriveBack(-750,-150);
  drive::auton::rightTurn(360,50);
  drive::auton::autonDrive(50,50);
  intake::auton::intakeOn(-25);\
  wait(800);
  intake::auton::intakeOff();
  tray::auton::stack(415,20);
  intake::auton::stackReverseAuton(-500, 25, 25);
  tray::auton::trayDown(0,-100);

}

}
