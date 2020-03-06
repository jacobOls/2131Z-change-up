#include "custom/systems/tilter.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "main.h"

namespace tilter {
State state = State::NONE;
void up() {

  if (BtnForward.isPressed()) {
    state = State::UP;
  } else if (state == State::UP) {
    state = State::DEINIT;
  }
}

void execute() {

  int subtractor;

  if (motor.getPosition() >= 1200 && state == State::UP) {
    state = State::DEINIT;
  }
  if (motor.getPosition() <= 0 && state == State::DOWN) {
    state = State::DEINIT;
  }

  switch (state) {
  case State::UP:
    subtractor = motor.getPosition() / 20;
    if (motor.getPosition() < 600) {
      motor.moveVelocity(100);
    } else if (motor.getPosition() >= 600) {
      motor.moveVelocity(100 - subtractor);
    }
    break;

  case State::DOWN:
    break;

  case State::RETURN:
    break;

  case State::DEINIT:
    break;

  case State::NONE:
    break;
  }
}

} // namespace tilter
