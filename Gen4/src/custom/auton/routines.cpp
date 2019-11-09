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
    drive::auton::driving(800, 60);
    drive::auton::driving(-150,-100);
    drive::auton::leftTurn(5,25);
    drive::auton::driving(150,60);
    drive::auton::driving(-150,-100);
    drive::auton::rightTurn(40,50);
    drive::auton::driving(200,60);
    drive::auton::driving(-600,-200);
    intake::auton::intakeOff();
    drive::auton::rightTurn(300,75);
    drive::auton::driving(300,150);
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
    intake::auton::intakeOn(-50);
    wait(900);
    intake::auton::intakeOff();
    intake::auton::intakeOn(25);
    wait(400);
    intake::auton::intakeOff();
    tilter::auton::stack(1800, 27);
    intake::auton::intakeOn(-75);
    tilter::auton::stack(1900, 27);
    intake::auton::intakeOff();
    tilter::auton::stack(2045, 27);
    // intake::auton::intakeOn(20);
    // drive::auton::driving(25,25);
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
    drive::auton::driving(800, 60);
    drive::auton::driving(-150,-100);
    drive::auton::rightTurn(5,25);
    drive::auton::driving(150,60);
    drive::auton::driving(-150,-100);
    drive::auton::leftTurn(40,50);
    drive::auton::driving(200,60);
    drive::auton::driving(-600,-200);
    intake::auton::intakeOff();
    drive::auton::leftTurn(300,75);
    drive::auton::driving(300,150);
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
