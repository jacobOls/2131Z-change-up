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
    // lift::auton::lift(1000,200);
    intake::auton::intakeOn(-200);
    lift::pulse();
    // wait(500);
    intake::auton::intakeOn(200);
    wait(800);
    // lift::auton::lift(0,200);
  }

  //red autons
  void betterStartup(){
    lift::motor.tarePosition();
    tilter::motor.tarePosition();
    drive::auton::resetPos();
    // lift::auton::lift(1000,200);
    // lift::pulse();
    intake::auton::intakeOn(-200);
    wait(100);
    lift::motor.moveVelocity(-125);
    wait(200);
    intake::auton::intakeOn(200);
    lift::motor.moveAbsolute(0,200);
    wait(800);
  }

  void redBig(){
    const int startTime = pros::millis();
    startup();
    drive::auton::drive(-30, -125);
    drive::auton::drive(50, 100);
    drive::auton::turn(40, -75);
    // lift::motor.moveAbsolute(150,200);
    drive::auton::driveNRE(65, 100);
    wait(200);
    lift::motor.moveAbsolute(2650, 200);
    drive::auton::driveNRB(100, 200);
    drive::auton::turn(48, 70);
    // intake::auton::intakeOff();
    drive::auton::drive(90, 170);
    intake::auton::intakeOn(200);
    // wait(300);
    // drive::auton::drive(35,200);
    lift::auton::lift(300, 160, startTime, 9500);
    drive::auton::turn(260, -120);
    lift::motor.moveAbsolute(0, 200);
    drive::auton::driveNRE(300, 200);
    tilter::motor.moveAbsolute(350, 50);
    drive::auton::driveNRB(25, 200);
    intake::auton::intakeOff();
    //stack
    tilter::auton::tilter(650, 95);
    intake::auton::intakeOn(-45);
    tilter::auton::tilter(850, 75);
    intake::auton::intakeOff();
    tilter::auton::tilter(1050, 50);
    intake::auton::intakeOn(-15);
    drive::auton::drive(-200, -85);
    tilter::motor.moveAbsolute(0, -200);
    lift::auton::lift(2700, 200, 14151, 1235);
  }

  void redBig4(){
    // startup();
    //deployment
    lift::motor.tarePosition();
    tilter::motor.tarePosition();
    drive::auton::resetPos();
    // lift::auton::lift(1000,200);
    intake::auton::intakeOn(-200);
    lift::pulse();
    lift::motor.moveAbsolute(60,200);
    // wait(500);
    intake::auton::intakeOn(200);
    // wait(800);
    //starting
    // drive::auton::drive(-30,-125);
    drive::auton::drive(70, 150);
    drive::auton::turn(50, 70);
    drive::auton::drive(100, 150);
    drive::auton::turn(130, 70);
    drive::auton::drive(85, 150);
    drive::auton::drive(-85, -150);
    drive::auton::turn(450, -100);
    drive::auton::drive(200, 150);
    drive::auton::turn(75, -70);
    //stack
    intake::auton::intakeOn(-25);
    lift::motor.moveAbsolute(0,-200);
    drive::auton::drive(70, 100);
    intake::auton::intakeOff();
    intake::auton::intakeOn(0);
    //stacking
    tilter::auton::tilter(750, 75);
    intake::auton::intakeOn(-65);
    tilter::auton::tilter(850, 75);
    intake::auton::intakeOff();
    tilter::auton::tilter(1050, 75);
    intake::auton::intakeOn(-15);
    drive::auton::drive(-125, -115);
    tilter::motor.moveAbsolute(0, -200);
  }

  void blueBig4(){
    // startup();
    //deployment
    lift::motor.tarePosition();
    tilter::motor.tarePosition();
    drive::auton::resetPos();
    // lift::auton::lift(1000,200);
    intake::auton::intakeOn(-200);
    lift::pulse();
    // wait(500);
    intake::auton::intakeOn(200);
    lift::motor.moveAbsolute(60,200);
    wait(300);
    //starting
    // drive::auton::drive(-30,-125);
    drive::auton::drive(70, 150);
    drive::auton::turn(50, -70);
    drive::auton::drive(100, 150);
    drive::auton::turn(130, -70);
    drive::auton::drive(85, 150);
    drive::auton::drive(-85, -150);
    drive::auton::turn(490, 100);
    drive::auton::drive(200, 150);
    drive::auton::turn(50, 70);
    //stack
    intake::auton::intakeOn(-25);
    lift::motor.moveAbsolute(0,-200);
    drive::auton::drive(70, 100);
    intake::auton::intakeOff();
    intake::auton::intakeOn(0);
    //stacking
    tilter::auton::tilter(750, 75);
    intake::auton::intakeOn(-65);
    tilter::auton::tilter(850, 75);
    intake::auton::intakeOff();
    tilter::auton::tilter(1050, 75);
    intake::auton::intakeOn(-15);
    drive::auton::drive(-125, -115);
    tilter::motor.moveAbsolute(0, -200);
  }

  void redBig5(){
    startup();
    drive::auton::drive(-30, -125);
    drive::auton::drive(50, 100);
    drive::auton::turn(40, 75);
    drive::auton::drive(50, 100);
    drive::auton::drive(-50, -100);
    drive::auton::turn(40, -75);
    drive::auton::turn(40, -75);
    // lift::motor.moveAbsolute(150,200);
    drive::auton::drive(165, 100);
    drive::auton::turn(160, -60);
    drive::auton::drive(350, 100);
    drive::auton::turn(90, -60);
    drive::auton::drive(150, 100);
    lift::motor.moveAbsolute(400, 200);
    intake::auton::intakeOn(-200);
  }

  void redSmall(){ //5 point
    //startup
    lift::motor.tarePosition();
    tilter::motor.tarePosition();
    drive::auton::resetPos();
    // lift::auton::lift(1000,200);
    lift::pulse();
    intake::auton::intakeOn(-200);
    wait(400);
    intake::auton::intakeOn(200);
    wait(800);
    // lift::auton::lift(0,200);  drive::auton::drive(1100, 60);

    drive::auton::drive(1100,60);
    intake::auton::intakeOn(50);
    drive::auton::drive(300,-200);
    drive::auton::turn(360,75);
    intake::auton::intakeOn(-20);
    drive::auton::driveNRE(65,100);
    // intake::auton::intakeOn(-15);
    lift::motor.moveAbsolute(0,-100);
    drive::auton::drive(60,100);
    //stacking
    intake::auton::intakeOn(0);
    tilter::auton::tilter(750, 75);
    intake::auton::intakeOn(-65);
    tilter::auton::tilter(850, 75);
    intake::auton::intakeOff();
    tilter::auton::tilter(1050, 75);
    intake::auton::intakeOn(-15);


    intake::auton::intakeOn(-15);
    drive::auton::drive(-125, -115);
    tilter::motor.moveAbsolute(0, -200);
  }



void largeRed6(){
  betterStartup();

  drive::auton::drive(50,100);
  drive::auton::turn(40, 75);
drive::auton::drive(200,100);
drive::auton::turn(40,-75);
drive::auton::drive(700,100);
//getting ready for slurping stack
lift::motor.moveAbsolute(500,200);
drive::auton::turn(100,50);
lift::auton::liftNoTime(2650, 200);
drive::auton::drive(300,100);
lift::auton::liftNoTime(0,-200);
//slurped stack
drive::auton::turn(600,100);
intake::auton::intakeOff();
drive::auton::drive(800,100);
//stacking
tilter::auton::tilter(750, 75);
intake::auton::intakeOn(-85);
tilter::auton::tilter(850, 75);
intake::auton::intakeOff();
tilter::auton::tilter(1050, 75);
intake::auton::intakeOn(-15);
drive::auton::drive(-125, -115);
tilter::motor.moveAbsolute(0, -200);
}

  //blue autons

  void blueBig(){
    const int startTime = pros::millis();
    startup();
    drive::auton::drive(-30, -125);
    drive::auton::drive(50, 100);
    drive::auton::turn(40, 75);
    // lift::motor.moveAbsolute(150,200);
    drive::auton::driveNRE(75, 100);
    wait(200);
    lift::motor.moveAbsolute(2650, 200);
    drive::auton::driveNRB(90, 200);
    drive::auton::turn(49, -70);
    // intake::auton::intakeOff();
    drive::auton::drive(82, 150);
    intake::auton::intakeOn(200);
    // wait(300);
    // drive::auton::drive(35,200);
    lift::auton::lift(300, 160, startTime, 9500);
    drive::auton::turn(300, 120);
    lift::motor.moveAbsolute(0, 200);
    drive::auton::driveNRE(300, 200);
    tilter::motor.moveAbsolute(350, 50);
    drive::auton::driveNRB(35, 200);
    intake::auton::intakeOff();
    //stack
    tilter::auton::tilter(650, 95);
    intake::auton::intakeOn(-45);
    tilter::auton::tilter(850, 75);
    intake::auton::intakeOff();
    tilter::auton::tilter(1050, 50);
    intake::auton::intakeOn(-15);
    drive::auton::drive(-200, -85);
    tilter::motor.moveAbsolute(0, -200);
    lift::auton::lift(2700, 200, 14151, 1235);
  }

  void safeBlue(){
    const int startTime = pros::millis();
    startup();
    drive::auton::drive(-30, -125);
    drive::auton::drive(50, 100);
    drive::auton::turn(40, 75);
    // lift::motor.moveAbsolute(150,200);
    drive::auton::drive(165, 100);
    drive::auton::turn(160, 60);
    drive::auton::drive(350, 100);
    drive::auton::turn(90, 60);
    drive::auton::drive(150, 100);
    lift::motor.moveAbsolute(400, 200);
    intake::auton::intakeOn(-200);
  }

  void safeRed(){
    const int startTime = pros::millis();
    startup();
    drive::auton::drive(-30, -125);
    drive::auton::drive(50, 100);
    drive::auton::turn(40, -75);
    // lift::motor.moveAbsolute(150,200);
    drive::auton::drive(165, 100);
    drive::auton::turn(160, -60);
    drive::auton::drive(350, 100);
    drive::auton::turn(90, -60);
    drive::auton::drive(150, 100);
    lift::motor.moveAbsolute(400, 200);
    intake::auton::intakeOn(-200);
  }

  /*
  const int startTime = pros::millis();
  startup();
  drive::auton::drive(-30,-125);
  drive::auton::drive(50,100);
  drive::auton::turn(37,75);
  // lift::motor.moveAbsolute(150,200);
  drive::auton::driveNRE(80,100);
  wait(100);
  lift::motor.moveAbsolute(2650,200);
  wait(150);
  drive::auton::driveNRB(85,200);
  drive::auton::turn(42,-60);
  // intake::auton::intakeOff();
  drive::auton::drive(82,180);
  intake::auton::intakeOn(200);
  // wait(300);
  // drive::auton::drive(35,200);
  lift::auton::lift(300,160,startTime,9500);
  drive::auton::drive(-20,-100);
  drive::auton::turn(260,100);
  lift::motor.moveAbsolute(0,200);
  drive::auton::driveNRE(300,200);
  tilter::motor.moveAbsolute(350,50);
  drive::auton::driveNRB(75,200);
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
  */
  void blueSmall(){ //5 point
    //startup
    lift::motor.tarePosition();
    tilter::motor.tarePosition();
    drive::auton::resetPos();
    // lift::auton::lift(1000,200);
    lift::pulse();
    intake::auton::intakeOn(-200);
    wait(400);
    intake::auton::intakeOn(200);
    wait(800);
    //end startup
    drive::auton::drive(1100, 70);
    intake::auton::intakeOn(50);
    drive::auton::drive(300, -200);
    drive::auton::turn(360, -75);
    intake::auton::intakeOff();
    drive::auton::drive(125, 100);
    //stacking
    tilter::auton::tilter(750, 75);
    intake::auton::intakeOn(-85);
    tilter::auton::tilter(850, 75);
    intake::auton::intakeOff();
    tilter::auton::tilter(1050, 75);
    intake::auton::intakeOn(-15);
    drive::auton::drive(-125, -115);
    tilter::motor.moveAbsolute(0, -200);

    // tilter::auton::tilter(800,75);
    // intake::auton::intakeOn(-45); //Phase 2: first outake going up
    // tilter::auton::tilter(950,75);
    // intake::auton::intakeOff(); //Phase 3: outtake off for rest of stack
    // tilter::auton::tilter(1050,75);
    // intake::auton::intakeOn(-15); //Phase 4: outtake to back off
    // drive::auton::drive(-200,-85);
    // tilter::motor.moveAbsolute(0,-200);
  }

  //misc autons

  void skills(){
    lift::motor.tarePosition();
    tilter::motor.tarePosition();
    drive::auton::resetPos();
    // lift::auton::lift(1000,200);
    lift::pulse();
    intake::auton::intakeOn(-200);
    wait(300);
    lift::motor.moveAbsolute(60,100);
    intake::auton::intakeOn(200);
    wait(1000);
    drive::auton::drive(1000,60);
    //z turn
    drive::auton::turn(70,-50);
    drive::auton::drive(-450,-150);
    drive::auton::turn(75,50);
    //end z turn
    drive::auton::drive(1000,40);
    drive::auton::turn(25,-10);
    drive::auton::drive(100,40);
    drive::auton::drive(100,-40);
    drive::auton::turn(25,10);
    drive::auton::drive(-500,-100);
    drive::auton::turn(350,50);
    lift::motor.moveAbsolute(0,-100);
    intake::auton::intakeOff();
    intake::auton::intakeOn(0);
    drive::auton::drive(250,50);
    //stack
    const int stackTime = pros::millis();
tilter::auton::tilterTime(650, 60,stackTime, 1100);
    // tilter::motor.moveAbsolute(900,60);
    intake::auton::isIt8or9(130,700);
    tilter::auton::tilterTime(1100, 55,stackTime,4000);
    intake::auton::intakeOn(-35);
    //end stacking
    drive::auton::drive(200,-35);
    intake::auton::intakeOn(0);
    tilter::auton::tilterDown(0, -100);
  }

/*
intake::auton::intakeOn(0);
tilter::auton::tilter(750, 75);
intake::auton::intakeOn(-65);
tilter::auton::tilter(850, 75);
intake::auton::intakeOff();
tilter::auton::tilter(1050, 75);
intake::auton::intakeOn(-15);
*/


  void smallRed9(){
    const int startTime = pros::millis();
    lift::motor.tarePosition();
    tilter::motor.tarePosition();
    drive::auton::resetPos();
    // lift::auton::lift(1000,200);
    // lift::pulse();
    intake::auton::intakeOn(-200);
    wait(100);
    lift::motor.moveVelocity(-125);
    wait(200);
    intake::auton::intakeOn(200);
    lift::motor.moveAbsolute(0,200);
    wait(800);
    //end startup
    drive::auton::drive(890, 80);
    drive::auton::swingTurnLeft(550, 100, 20);
    drive::auton::swingTurnLeft(750, 100, 20);
    drive::auton::drive(570, 70);
    wait(150);
    drive::auton::turn(155, -60);
    drive::auton::driveNRE(150, 200);
    intake::auton::intakeOff();
    drive::auton::drive(230,200);
    //stack
    // intake::auton::intakeOn(-10);
    // tilter::motor.tarePosition();
    const int stackTime = pros::millis();
    tilter::auton::tilterTime(850, 60,stackTime, 1100);
    // tilter::motor.moveAbsolute(900,60);
    intake::auton::isIt8or9(130,400);
    tilter::auton::tilter(1100, 55);
    intake::auton::intakeOn(-35);
    //end stack
    drive::auton::drive(-150,-200);
    tilter::auton::tilterDown(0,-100);

  }


  void noStack9(){
    const int startTime = pros::millis();
    startup();
    drive::auton::drive(1050, 60);
    drive::auton::swingTurnLeft(550, 100, 20);
    drive::auton::swingTurnLeft(750, 100, 20);
    drive::auton::drive(570, 50);
    drive::auton::turn(160, -60);
    drive::auton::driveNRE(150, 200);
    intake::auton::intakeOff();
    drive::auton::drive(230,200);
    //stacking
    // const int stackTime = pros::millis();
    tilter::auton::tilter(850, 60);
    intake::auton::isIt8or9(130,130);
    tilter::auton::tilter(1100, 55);
    intake::auton::intakeOn(-35);
    drive::auton::drive(-100,-35);
  }


  void doNothing(){
    startup();
  }

  void driveABit(){
    startup();
    drive::auton::drive(150, 150);
    drive::auton::drive(-150, -150);
  }

  void nothing(){
  }

  void onePoint(){
    drive::auton::drive(300, -100);
    drive::auton::drive(300, 100);
  }


//old skills
  // const int startTime = pros::millis();
  // lift::motor.tarePosition();
  // tilter::motor.tarePosition();
  // drive::auton::resetPos();
  // // lift::auton::lift(1000,200);
  // lift::pulse();
  // intake::auton::intakeOn(-200);
  // wait(300);
  // intake::auton::intakeOn(200);
  // wait(1000);
  // // betterStartup();
  // //end startup
  // drive::auton::drive(1050, 60);
  // drive::auton::swingTurnLeft(550, 100, 20);
  // drive::auton::swingTurnLeft(750, 100, 20);
  // drive::auton::drive(620, 30);
  // drive::auton::turn(165, -60);
  // drive::auton::driveNRE(150, 200);
  // intake::auton::intakeOff();
  // drive::auton::drive(240,200);
  // //stack
  // const int stackTime = pros::millis();
  // tilter::auton::tilterTime(850, 60,stackTime, 1100);
  // // tilter::motor.moveAbsolute(900,60);
  // intake::auton::isIt8or9(130,130);
  // tilter::auton::tilter(1100, 55);
  // intake::auton::intakeOn(-35);
  // drive::auton::drive(-100,-35);
  // //end match for when copying
  // drive::auton::turn(500,80);
  // intake::auton::intakeOn(200);
  // drive::auton::drive(500,200);
  // drive::auton::drive(-25,-25);
  // lift::auton::lift(600,200,startTime,22000);
  // intake::auton::intakeOn(-200);


} // namespace auton
