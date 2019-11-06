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

} // namespace auton
