#include "custom/systems/wheel.hpp"
#include "custom/settup/controller.hpp"
#include "custom/settup/motors.hpp"
#include "main.h"

namespace wheel {
State state = State::NONE;
void pull() {
  if (BtnIn.isPressed()) {
    state = State::IN;
  } else if (state == State::IN) {
    state = State::DEINIT;
  }
}

void eject() {
  if (BtnOut.isPressed()) {
    state = State::OUT;
  } else if (state == State::OUT) {
    state = State::DEINIT;
  }
}


void execute() {
  switch (state) {

  case State::IN:
    wheelGroup.moveVelocity(200);
    break;

  case State::OUT:
    wheelGroup.moveVelocity(-200);
    break;

  case State::DEINIT:
    wheelGroup.moveVelocity(0);
    state = State::NONE;
    break;

  case State::NONE:
    break;
  }
}

void init() {
  pull();
  eject();
  execute();
}

// void runWheel(int velocity) { wheelGroup.moveVelocity(velocity); }

} // namespace wheel
