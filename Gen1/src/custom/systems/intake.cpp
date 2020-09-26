#include "custom/systems/intake.hpp"
#include "custom/settup/controller.hpp"
#include "custom/settup/motors.hpp"
#include "main.h"

namespace intake {
State state = State::NONE;
pros::ADIAnalogIn intakeEntry(8);
pros::ADIAnalogIn midElevator(2);
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
    if (intakeEntry.get_value() > 1500 && midElevator.get_value() > 1500) {
      intakeGroup.moveVelocity(200);
    } else if (intakeEntry.get_value() < 1500 &&
               midElevator.get_value() > 1500) {
      intakeGroup.moveVelocity(200);
      wheel::wheelGroup.moveVelocity(50);
    } else if (intakeEntry.get_value() > 1500 &&
               midElevator.get_value() < 1500) {
      intakeGroup.moveVelocity(200);
    } else {
      state = State::DEINIT;
    }
    break;

  case State::OUT:
    intakeGroup.moveVelocity(-200);
    break;

  case State::DEINIT:
    intakeGroup.moveVelocity(0);
    state = State::NONE;
    break;

  case State::NONE:
    break;
  }
}

void init() {
  out();
  execute();
}

} // namespace intake

namespace auton {

void runIntake(int velocity) { intake::intakeGroup.moveVelocity(velocity); }

} // namespace auton
