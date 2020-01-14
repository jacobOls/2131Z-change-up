#include "main.h"
#include "custom/systems/drive.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/tilter.hpp"
#include "custom/systems/intake.hpp"
#include "custom/setup/motors.hpp"
namespace auton{

  void wait(int time){
    pros::delay(time);
  }
  //positive turn is left
  //negative turn is right
  void startup(){
    lift::motor.tarePosition();
    tilter::motor.tarePosition();
    drive::auton::resetPos();
    // lift::pulse();
    // lift::auton::lift(1000,200);
    intake::auton::intakeOn(-200);
    wait(200);
    intake::auton::intakeOn(200);
    wait(800);
    // lift::auton::lift(0,200);
  }
  //
  // void redBig(){
  //   startup();
  //   drive::auton::drive(325,125);
  //   intake::auton::intakeOff();
  //   wait(300);
  //   lift::auton::lift(2750,200);
  //   intake::auton::intakeOn(200);
  //   drive::auton::drive(40,50);
  //   lift::auton::lift(0,200);
  //   drive::auton::drive(75,-125);
  //   drive::auton::turn(150,-100);
  // }

void redBig(){
  startup();
  drive::auton::drive(30,100);
  drive::auton::turn(40,-75);
  // lift::motor.moveAbsolute(150,200);
  drive::auton::driveNRE(105,100);
  lift::motor.moveAbsolute(2750,200);
  drive::auton::driveNRB(60,200);
  drive::auton::turn(45,75);
  intake::auton::intakeOff();
  drive::auton::drive(95,200);
  intake::auton::intakeOn(200);
  // wait(300);
  // drive::auton::drive(35,200);
  lift::auton::lift(300,200);
  lift::motor.moveAbsolute(0,200);
  drive::auton::turn(245,-200);
  drive::auton::driveNRE(220,200);
  tilter::motor.moveAbsolute(875,50);
  intake::auton::intakeOff();
  drive::auton::driveNRB(100,200);
  intake::auton::intakeOn(-15);
  tilter::auton::tilter(1200,50);
}



  void redBigLOL(){
    startup();
    drive::auton::drive(30,50);
    drive::auton::turn(40,-50);
    drive::auton::drive(126,100);
    drive::auton::turn(30,50);
    drive::auton::drive(115,125);
    intake::auton::intakeOff();
    wait(300);
    lift::auton::lift(2750,200);
    intake::auton::intakeOn(200);
    drive::auton::drive(40,50);
    lift::auton::lift(250,200);
    drive::auton::drive(-200,-125);
    lift::auton::lift(0,200);
    wait(150);
    drive::auton::turn(150,-100);
    drive::auton::drive(275,175);
    intake::auton::intakeOn(0);
    // drive::auton::turn(100,-100);
    // drive::auton::drive(80,100);
    // intake::auton::intakeOff();
    //stack
//     intake::auton::intakeOn(-15);
// tilter::auton::tilter(450,60);
// intake::auton::intakeOn(-40);
// tilter::auton::tilter(660, 50);
// tilter::auton::tilter(750,40);
// intake::auton::intakeOn(-15);
// tilter::auton::tilter(1020,30);
// drive::auton::drive(100,-45);
// intake::auton::intakeOn(-25);
  }

void blueBig(){
  startup();
  drive::auton::drive(30,50);
  drive::auton::turn(40,50);
  drive::auton::drive(126,100);
  drive::auton::turn(30,-50);
  drive::auton::drive(115,125);
  intake::auton::intakeOff();
  wait(300);
  lift::auton::lift(2750,200);
  intake::auton::intakeOn(200);
  drive::auton::drive(40,50);
  lift::auton::lift(250,200);
  drive::auton::drive(-200,-125);
  lift::auton::lift(0,200);
  wait(150);
  drive::auton::turn(145,100);
  drive::auton::drive(275,175);
  intake::auton::intakeOn(0);
  // drive::auton::turn(100,100);
  // drive::auton::drive(80,100);
  // intake::auton::intakeOff();
}




}
