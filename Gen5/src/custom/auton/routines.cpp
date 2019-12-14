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
    drive::auton::resetPositions();
    // intake::auton::intakeOn(200);
  }


  void stack(){
    tilter::motor.tarePosition();
    intake::auton::intakeOn(-5);
    tilter::auton::tilter(500,100);
    intake::auton::intakeOn(-50);
    tilter::auton::tilter(950, 50);
  }


  void red8(){
    //all commands are distance ,velocity, one int in the () means its only velocity;
    startup(); //sets positions to 0
    intake::intakegroup.moveVelocity(-45);//starts deployment
    wait(200);
    intake::auton::intakeOff();
    lift::auton::lift(175,100);
    intake::intakegroup.moveVelocity(200);
    lift::auton::lift(0,50);
    //finished deploying
    drive::auton::driving(525,200);
    drive::auton::turn(60,-70);
    intake::auton::intakeOn(50);
    drive::auton::driving(435,-200);
    drive::auton::turn(65,70);
    intake::auton::intakeOn(200);
    drive::auton::driving(400,200);
    drive::auton::driving(-550,-200);
    drive::auton::turn(340,175);
    intake::auton::intakeOn(50);
    drive::auton::driving(370,200);
    intake::auton::intakeOn(-35);
    // drive::auton::driving(200,200);
    //stacking
    tilter::auton::tilter(450,100);
    intake::auton::intakeOn(-40);
    tilter::auton::tilter(800, 100);
    intake::auton::intakeOff();
    tilter::auton::tilter(850,100);
    drive::auton::driving(20,-10);
    tilter::auton::tilter(920, 90);
    // wait(250);
    intake::auton::intakeOn(-25);
    drive::auton::driving(100,-45);
    tilter::auton::tilterDown(0, -100);
  }



void red6(){
  startup();
  intake::intakegroup.moveVelocity(-45);//starts deployment
  wait(200);
  intake::auton::intakeOff();
  lift::auton::lift(175,100);
  intake::intakegroup.moveVelocity(200);
  lift::auton::lift(0,50);
  intake::auton::intakeOn(200);
  drive::auton::driving(500,200);
  drive::auton::turn(10,10);
  drive::auton::driving(25,100);
  drive::auton::driving(50,-200);
  intake::auton::intakeOn(50);
  drive::auton::turn(300,200);
  drive::auton::driving(500,200);
//stacking
tilter::auton::tilter(450,100);
intake::auton::intakeOn(-40);
tilter::auton::tilter(800, 100);
intake::auton::intakeOff();
tilter::auton::tilter(850,100);
// drive::auton::driving(20,-10);
tilter::auton::tilter(920, 60);
// wait(250);
intake::auton::intakeOn(-25);
drive::auton::driving(100,-45);
tilter::auton::tilterDown(0, -100);
}





  void blue8(){
    //all commands are distance ,velocity, one int in the () means its only velocity;
    startup(); //sets positions to 0
    intake::intakegroup.moveVelocity(-45);//starts deployment
    wait(200);
    intake::auton::intakeOff();
    lift::auton::lift(150,100);
    intake::intakegroup.moveVelocity(200);
    lift::auton::lift(0,50);
    //finished deploying
    drive::auton::driving(525,200);
    drive::auton::turn(80,85);
    drive::auton::driving(440,-200);
    drive::auton::turn(85,-85);
    drive::auton::driving(400,200);
    drive::auton::driving(-550,-200);
    drive::auton::turn(410,-150);
    // intake::auton::intakeOn(-15);
    drive::auton::driving(385,200);
    // drive::auton::driving(200,200);
    intake::auton::intakeOn(-35);
    //stacking
    tilter::auton::tilter(450,100);
    intake::auton::intakeOn(-35);
    tilter::auton::tilter(800, 80);
    intake::auton::intakeOff();
    tilter::auton::tilter(920, 80);
    // wait(250);
    intake::auton::intakeOn(-25);
    drive::auton::driving(100,-30);
    tilter::auton::tilterDown(0, -100);
  }


  void red7(){
    startup();
    drive::auton::driving(1000,100);
    drive::auton::turn(200,-50);
    drive::auton::driving(375,75);
    stack();
  }

  void blue7(){
    startup();
    drive::auton::driving(1000,100);
    drive::auton::turn(-200,-50);
    drive::auton::driving(375,75);
    stack();
  }


  void skills(){
    intake::auton::intakeOn(200);
    drive::auton::driving(2000,100);
    drive::auton::turn(-150,-75);
    drive::auton::driving(800,100);
    stack();
    drive::auton::turn(-300,150);
    drive::auton::driving(2000,100);
    drive::auton::turn(200,150);
    drive::auton::driving(500,100);
    stack();
    drive::auton::turn(-200,-80);
    drive::auton::driving(800,100);
    drive::auton::driving(-100,-100);
    drive::auton::turn(100,50);
    drive::auton::driving(400,80);
    lift::auton::lift(500,100);
    intake::auton::intakeOn(-25);
  }


}
