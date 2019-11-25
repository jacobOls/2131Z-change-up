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
  void startup(){
    lift::motor.tarePosition();
    tilter::motor.tarePosition();
    drive::auton::resetPositions();
    intake::auton::intakeOn(200);
  }

  void stack(){
    tilter::auton::tilter(1525,35);
intake::auton::intakeOn(-37);
tilter::auton::tilter(2300, 30);
intake::auton::intakeOff();
tilter::auton::tilter(2350, 25);
wait(250);
intake::auton::intakeOff();
intake::auton::stackReverseAuton(-100, 30, 25);
tilter::auton::tilter(0, -100);
  }

  void red9(){
    startup();
    drive::auton::driving(1000,100);
   drive::auton::turn(20,-25);
   drive::auton::driving(-800,150);
   drive::auton::turn(20,25);
   drive::auton::driving(1000,100);
   drive::auton::driving(-1000,-100);
   drive::auton::turn(200,75);
   drive::auton::driving(200,100);
   intake::auton::intakeOff();
  stack();
  }




}
