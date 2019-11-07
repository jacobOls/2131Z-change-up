#include "main.h"
#include "custom/systems/drive.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/tilter.hpp"
#include "custom/systems/intake.hpp"

namespace auton
{
void wait(int time)
{
  pros::delay(time);
}

void red5()
{
  intake::auton::intakeOn(200);
  drive::auton::driving(800, 60);
  drive::auton::driving(-600, -200);
  drive::auton::rightTurn(350, 75);
  drive::auton::driving(200, 100);
  intake::auton::intakeOn(-25);
  wait(800);
  tilter::auton::stack(400, 25);
  intake::auton::stackReverseAuton(-300, -300, -25);
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
  intake::auton::intakeOn(-25);
  wait(800);
  intake::auton::intakeOff();
  tilter::auton::stack(1600,25);
  intake::auton::stackReverseAuton(-300, -25, -25);
  tilter::auton::trayDown(1170,-200);

}


void blue5()
{

  intake::auton::intakeOn(200);
  drive::auton::driving(800, 60);
  drive::auton::driving(-600, -200);
  drive::auton::leftTurn(350, 75);
  drive::auton::driving(200, 100);
  intake::auton::intakeOn(-25);
  wait(800);
  tilter::auton::stack(400, 25);
  intake::auton::stackReverseAuton(-300, -300, -25);
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
  intake::auton::intakeOn(-25);
  wait(800);
  intake::auton::intakeOff();
  tilter::auton::stack(1600,25);
  intake::auton::stackReverseAuton(-300, -25, -25);
  tilter::auton::trayDown(1170,-200);

}

} // namespace auton
