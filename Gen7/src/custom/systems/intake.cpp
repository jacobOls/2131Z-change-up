#include "custom/systems/intake.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
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

void stack() {
  if (BtnBackUp.isPressed()) {
    state = State::STACK;
  } else if (state == State::STACK) {
    state = State::DEINIT;
  }
}

void execute() {
  switch (state) {

  case State::IN:
    intakegroup.moveVelocity(200);
    break;

  case State::OUT:
    intakegroup.moveVelocity(-200);
    break;

  case State::STACK:
    intakegroup.moveVelocity(-35);
    break;

  case State::DEINIT:
    intakegroup.moveVelocity(0);
    state = State::NONE;
    break;

  case State::NONE:
    break;
  }
}

void init() {
  in();
  out();
  stack();
  execute();
}

} // namespace intake
