#include "main.h"
#include "custom/systems/drive.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/tilter.hpp"
#include "custom/systems/intake.hpp"
#include "custom/setup/motors.hpp"
namespace auton{

//managment stuff

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


//red autons

  void redBig(){
    const int startTime = pros::millis();
    startup();
    drive::auton::drive(-30,-125);
    drive::auton::drive(50,100);
    drive::auton::turn(40,-75);
    // lift::motor.moveAbsolute(150,200);
    drive::auton::driveNRE(65,100);
    lift::motor.moveAbsolute(2650,200);
    drive::auton::driveNRB(110,200);
    drive::auton::turn(48,75);
    // intake::auton::intakeOff();
    drive::auton::drive(100,180);
    intake::auton::intakeOn(200);
    // wait(300);
    // drive::auton::drive(35,200);
    lift::auton::lift(300,160,startTime,9750);
    drive::auton::turn(250,-120);
    lift::motor.moveAbsolute(0,200);
    drive::auton::driveNRE(300,200);
    tilter::motor.moveAbsolute(350,50);
    drive::auton::driveNRB(25,200);
    intake::auton::intakeOff();
    //stack
    tilter::auton::tilter(650,95);
    intake::auton::intakeOn(-45);
    tilter::auton::tilter(850,75);
    intake::auton::intakeOff();
    tilter::auton::tilter(1050,50);
    intake::auton::intakeOn(-15);
    drive::auton::drive(-200,-85);
    tilter::motor.moveAbsolute(0,-200);
    lift::auton::lift(2700,200,14151,1235);
  }




  void redSmall(){
    startup();
    drive::auton::drive(1100,70);
    intake::auton::intakeOn(50);
    drive::auton::drive(300,-200);
    drive::auton::turn(360,75);
    intake::auton::intakeOn(-15);
    drive::auton::drive(125,100);
    //stacking
    tilter::auton::tilter(650,95);
    intake::auton::intakeOn(-45);
    tilter::auton::tilter(850,75);
    intake::auton::intakeOff();
    tilter::auton::tilter(1050,50);
    intake::auton::intakeOn(-15);
    drive::auton::drive(-200,-85);
    tilter::motor.moveAbsolute(0,-200);
  }

  void redBigLOL(){
    startup();
    drive::auton::drive(30,50);
    drive::auton::turn(40,-50);
    drive::auton::drive(126,100);
    // drive::auton::turn(30,50);
    // drive::auton::drive(115,125);
    // intake::auton::intakeOff();
    // wait(300);
    // lift::auton::lift(2750,200);
    // intake::auton::intakeOn(200);
    // drive::auton::drive(40,50);
    // lift::auton::lift(250,200);
    // drive::auton::drive(-200,-125);
    // lift::auton::lift(0,200);
    // wait(150);
    // drive::auton::turn(150,-100);
    // drive::auton::drive(275,175);
    // intake::auton::intakeOn(0);
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

//blue autons

  void blueBig(){
    const int startTime = pros::millis();
    startup();
    drive::auton::drive(-30,-125);
    drive::auton::drive(50,100);
    drive::auton::turn(40,75);
    // lift::motor.moveAbsolute(150,200);
    drive::auton::driveNRE(75,100);
    lift::motor.moveAbsolute(2650,200);
    drive::auton::driveNRB(110,200);
    drive::auton::turn(48,-75);
    // intake::auton::intakeOff();
    drive::auton::drive(100,180);
    intake::auton::intakeOn(200);
    // wait(300);
    // drive::auton::drive(35,200);
    lift::auton::lift(300,160,startTime,9750);
    drive::auton::turn(250,120);
    lift::motor.moveAbsolute(0,200);
    drive::auton::driveNRE(300,200);
    tilter::motor.moveAbsolute(350,50);
    drive::auton::driveNRB(25,200);
    intake::auton::intakeOff();
    //stack
    tilter::auton::tilter(650,95);
    intake::auton::intakeOn(-45);
    tilter::auton::tilter(850,75);
    intake::auton::intakeOff();
    tilter::auton::tilter(1050,50);
    intake::auton::intakeOn(-15);
    drive::auton::drive(-200,-85);
    tilter::motor.moveAbsolute(0,-200);
    lift::auton::lift(2700,200,14151,1234);
  }

  void blueSmall(){
    startup();
    drive::auton::drive(1100,70);
    intake::auton::intakeOn(50);
    drive::auton::drive(300,-200);
    drive::auton::turn(360,-75);
    intake::auton::intakeOn(-15);
    drive::auton::drive(125,100);
    //stacking
    tilter::auton::tilter(650,95);
    intake::auton::intakeOn(-45);
    tilter::auton::tilter(850,75);
    intake::auton::intakeOff();
    tilter::auton::tilter(1050,50);
    intake::auton::intakeOn(-15);
    drive::auton::drive(-200,-85);
    tilter::motor.moveAbsolute(0,-200);
  }


//misc autons
  void doNothing(){
    startup();
  }

  void driveABit(){
    startup();
    drive::auton::drive(150,150);
    drive::auton::drive(-150,-150);
  }

  void nothing(){

  }

  void onePoint(){
    drive::auton::drive(300,-100);
    drive::auton::drive(300,100);
  }


}
