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

void down() {

  if (BtnForward.isPressed()) {
    state = State::DOWN;
  } else if (state == State::DOWN) {
    state = State::DEINIT;
  }
}

void returnDown() {
  if (BtnForward.isPressed()) {
    state = State::RETURN;
  } else if (state == State::RETURN && motor.getActualVelocity() == 0) {
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
    motor.moveVelocity(-100);
    break;

  case State::RETURN:
    motor.moveAbsolute(0, -100);
    break;

  case State::DEINIT:
    motor.moveVelocity(0);
    state = State::NONE;
    break;

  case State::NONE:
    break;
  }
}

void init() {
  execute();
  up();
  down();
  returnDown();
}

} // namespace tilter
