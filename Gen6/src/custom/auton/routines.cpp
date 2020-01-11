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
    lift::pulse();
    lift::auton::lift(500,200);
    intake::auton::intakeOn(-200);
    wait(200);
    intake::auton::intakeOn(200);
    wait(500);
    lift::auton::lift(0,200);
  }

  void redBig(){
    startup();
    drive::auton::drive(325,125);
    intake::auton::intakeOff();
    wait(300);
    lift::auton::lift(2750,200);
    intake::auton::intakeOn(200);
    drive::auton::drive(40,50);
    lift::auton::lift(0,200);
    drive::auton::drive(75,-125);
    drive::auton::turn(150,-100);
  }








}
