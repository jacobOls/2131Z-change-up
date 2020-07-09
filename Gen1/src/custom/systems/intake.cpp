#include "custom/systems/intake.hpp"
#include "custom/settup/controller.hpp"
#include "custom/settup/motors.hpp"
#include "main.h"

namespace intake {
State state = State::NONE;
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
    intakeGroup.moveVelocity(200);
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
  in();
  out();
  execute();
}

void runIntake(int velocity) { intakeGroup.moveVelocity(velocity); }

} // namespace intake
