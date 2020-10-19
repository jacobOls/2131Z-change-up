#include "custom/systems/intake.hpp"
#include "custom/settup/controller.hpp"
#include "custom/settup/motors.hpp"
#include "main.h"

namespace intake {
State state = State::NONE;
pros::ADIAnalogIn intakeEntry(8);
pros::ADIAnalogIn midElevator(2);
pros::ADIAnalogIn highElevator(5);
void in() {
  if (BtnIn.isPressed()) {
    state = State::IN;
  } else if (state == State::IN) {
    state = State::DEINIT;
  }
}

void out() {
  if (BtnOut.isPressed()) {
    state = State::OUT;
  } else if (state == State::OUT) {
    state = State::DEINIT;
  }
}

void execute() {
  switch (state) {

  case State::IN:
    // if (intakeEntry.get_value() > 2800 && midElevator.get_value() > 2900) {
    //   std::cout << "nothing" << std::endl;
    //   intakeGroup.moveVelocity(200);
    // } else if (intakeEntry.get_value() < 2800 &&
    //            midElevator.get_value() > 2900) {
    //   std::cout << "ball in" << std::endl;
    //   intakeGroup.moveVelocity(200);
    //   wheel::wheelGroup.moveVelocity(200);
    // } else if (intakeEntry.get_value() > 2800 &&
    //            midElevator.get_value() < 2900) {
    //   std::cout << "ball in elevator" << std::endl;
    //   intakeGroup.moveVelocity(200);
    //   wheel::wheelGroup.moveVelocity(0);
    // } else {
    //   std::cout << "ball in both" << std::endl;
    //   intakeGroup.moveVelocity(0);
    //   wheel::wheelGroup.moveVelocity(0);
    //   state = State::DEINIT;
    // }
    intake::intakeGroup.moveVelocity(200);
    break;

  case State::OUT:
    intakeGroup.moveVelocity(-200);
    break;

  case State::DEINIT:
    intakeGroup.moveVelocity(0);
    wheel::wheelGroup.moveVelocity(0);
    state = State::NONE;
    break;

  case State::NONE:
    break;
  }
}

void init() {
  in();
  out();
  execute();
}

} // namespace intake

namespace auton {

void runIntake(int velocity) { intake::intakeGroup.moveVelocity(velocity); }

} // namespace auton
