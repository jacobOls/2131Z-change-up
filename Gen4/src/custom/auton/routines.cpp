#include "main.h"
#include "custom/systems/drive.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/tilter.hpp"
#include "custom/systems/intake.hpp"

namespace auton
{


  /* stacking 101
  intake::auton::intakeOn(-50);
  wait(900);
  intake::auton::intakeOff();
  intake::auton::intakeOn(25);
  wait(400);
  intake::auton::intakeOff();
  tilter::auton::stack(1800, 25);
  intake::auton::intakeOn(-75);
  tilter::auton::stack(1900, 25);
  intake::auton::intakeOff();
  tilter::auton::stack(2020, 25);
  intake::auton::intakeOn(-200);
  wait(250);
  intake::auton::intakeOff();
  intake::auton::stackReverseAuton(-100, 25, 25);
  tilter::auton::trayDown(1500, 100);
  */
  void wait(int time)
  {
    pros::delay(time);
  }

  void red5()
  {
    intake::auton::intakeOn(200);
    drive::auton::driving(900, 60);
    drive::auton::driveBack(-300, -125);
    drive::auton::rightTurn(375, 50);
    drive::auton::driving(90, 100);
    //stacking
    intake::auton::intakeOn(-50);
    wait(900);
    intake::auton::intakeOff();
    intake::auton::intakeOn(25);
    wait(400);
    intake::auton::intakeOff();
    tilter::auton::stack(1800, 25);
    intake::auton::intakeOn(-75);
    tilter::auton::stack(1900, 25);
    intake::auton::intakeOff();
    tilter::auton::stack(2020, 25);
    intake::auton::intakeOn(-200);
    wait(250);
    intake::auton::intakeOff();
    intake::auton::stackReverseAuton(-100, 25, 25);
    tilter::auton::trayDown(1500, 100);
  }

  void red7(){
    intake::auton::intakeOn(200);
    drive::auton::driving(600, 80);
    drive::auton::leftTurn(15,25);
    drive::auton::driveBack(-800,-200);
    drive::auton::rightTurn(15,25);
    drive::auton::driving(400,80);
    drive::auton::driveBack(-300,-200);
    intake::auton::intakeOff();
    drive::auton::rightTurn(400,100);
    drive::auton::driving(200,100);
    //stacking
    intake::auton::intakeOn(-50);
    wait(900);
    intake::auton::intakeOff();
    intake::auton::intakeOn(25);
    wait(400);
    intake::auton::intakeOff();
    tilter::auton::stack(1800, 25);
    intake::auton::intakeOn(-75);
    tilter::auton::stack(1900, 25);
    intake::auton::intakeOff();
    tilter::auton::stack(2020, 25);
    intake::auton::intakeOn(-200);
    wait(250);
    intake::auton::intakeOff();
    intake::auton::stackReverseAuton(-100, 25, 25);
    tilter::auton::trayDown(1500, 100);
  }

  void red2(){
    intake::auton::intakeOn(200);
    drive::auton::driving(400, 60);
    drive::auton::leftTurn(250,50);
    drive::auton::driving(75, 60);
    drive::auton::leftTurn(250,50);
    intake::auton::intakeOn(-250);
    wait(1000);
    intake::auton::intakeOff();
    drive::auton::driving(50,50);
    drive::auton::driveBack(-250, -60);
  }





  void blue5()
  {
    intake::auton::intakeOn(200);
    drive::auton::driving(900, 60);
    drive::auton::driveBack(-300, -125);
    drive::auton::leftTurn(375, 50);
    drive::auton::driving(90, 100);
    //stacking
    intake::auton::intakeOn(-50);
    wait(900);
    intake::auton::intakeOff();
    intake::auton::intakeOn(25);
    wait(400);
    intake::auton::intakeOff();
    tilter::auton::stack(1800, 29);
    intake::auton::intakeOn(-75);
    tilter::auton::stack(1900, 29);
    intake::auton::intakeOff();
    tilter::auton::stack(2050, 29);
    intake::auton::intakeOn(-200);
    wait(250);
    intake::auton::intakeOff();
    intake::auton::stackReverseAuton(-100, 25, 25);
    tilter::auton::trayDown(1500, 100);
  }

  void blue2(){
    intake::auton::intakeOn(200);
    drive::auton::driving(400, 60);
    drive::auton::rightTurn(250,50);
    drive::auton::driving(75, 60);
    drive::auton::rightTurn(250,50);
    intake::auton::intakeOn(-250);
    wait(1000);
    intake::auton::intakeOff();
    drive::auton::driving(50,50);
    drive::auton::driveBack(-250, -60);
  }

  void blue7(){
    intake::auton::intakeOn(200);
    drive::auton::driving(600, 80);
    drive::auton::rightTurn(15,25);
    drive::auton::driveBack(-800,-200);
    drive::auton::leftTurn(15,25);
    drive::auton::driving(400,80);
    drive::auton::driveBack(-300,-200);
    intake::auton::intakeOff();
    drive::auton::leftTurn(400,100);
    drive::auton::driving(200,100);
    //stacking
    intake::auton::intakeOn(-50);
    wait(900);
    intake::auton::intakeOff();
    intake::auton::intakeOn(25);
    wait(400);
    intake::auton::intakeOff();
    tilter::auton::stack(1800, 25);
    intake::auton::intakeOn(-75);
    tilter::auton::stack(1900, 25);
    intake::auton::intakeOff();
    tilter::auton::stack(2020, 25);
    intake::auton::intakeOn(-200);
    wait(250);
    intake::auton::intakeOff();
    intake::auton::stackReverseAuton(-100, 25, 25);
    tilter::auton::trayDown(1500, 100);
  }

  void skills(){
    intake::auton::intakeOn(200);
    drive::auton::driving(1100, 60);
    drive::auton::leftTurn(15,50);
    drive::auton::driving(100,50);
    drive::auton::driveBack(-100,-50);
    drive::auton::rightTurn(15,50);
    drive::auton::driving(900,60);
    drive::auton::rightTurn(250,50);
    //stacking
    intake::auton::intakeOn(-50);
    wait(900);
    intake::auton::intakeOff();
    intake::auton::intakeOn(25);
    wait(400);
    intake::auton::intakeOff();
    tilter::auton::stack(1800, 25);
    intake::auton::intakeOn(-75);
    tilter::auton::stack(1900, 25);
    intake::auton::intakeOff();
    tilter::auton::stack(2020, 25);
    intake::auton::intakeOn(-200);
    wait(250);
    intake::auton::intakeOff();
    intake::auton::stackReverseAuton(-100, 25, 25);
    tilter::auton::trayDown(1500, 100);
    intake::auton::stackReverseAuton(-100, 25, 25);
    tilter::auton::trayDown(1500, 100);
    //back to driving
    intake::auton::intakeOn(200);
    drive::auton::rightTurn(350,50);
    drive::auton::driving(500,200);
    drive::auton::leftTurn(200,50);
    drive::auton::driving(1600,90);
    drive::auton::leftTurn(200,50);
    drive::auton::driving(1000,200);
    //stack
    intake::auton::intakeOn(-50);
    wait(900);
    intake::auton::intakeOff();
    intake::auton::intakeOn(25);
    wait(400);
    intake::auton::intakeOff();
    tilter::auton::stack(1800, 25);
    intake::auton::intakeOn(-75);
    tilter::auton::stack(1900, 25);
    intake::auton::intakeOff();
    tilter::auton::stack(2020, 25);
    intake::auton::intakeOn(-200);
    wait(250);
    intake::auton::intakeOff();
    intake::auton::stackReverseAuton(-100, 25, 25);
    tilter::auton::trayDown(1500, 100);
  }




} // namespace auton
