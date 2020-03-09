#include "custom/systems/lift.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "main.h"

namespace lift {

State state = State::NONE;

void up() {
  if (BtnUp.isPressed()) {
    state = State::UP;
  } else if (state == State::UP) {
    state = State::DEINIT;
  }
}

void down() {
  if (BtnDown.isPressed()) {
    state = State::DOWN;
  } else if (state == State::DOWN) {
    state = State::DEINIT;
  }
}
void recycle() {
  if (BtnUp.isPressed()) {
    state = State::RECYCLE;
  } else if (state == State::RECYCLE) {
    state = State::RECYCLE;
  }
}

void execute() {

  if (motor.getPosition() <= 0 && state == State::DOWN) {
    state = State::DEINIT;
  }
  if (motor.getPosition() >= 3500 && state == State::UP) {
    state = State::DEINIT;
  }

  switch (state) {

  case State::UP:
    motor.moveVelocity(100);
    break;

  case State::DOWN:
    motor.moveVelocity(-100);
    break;

  case State::RECYCLE:
    motor.moveVelocity(-65);
    intake::intakegroup.moveVelocity(200);
    break;

  case State::DEINIT:
    motor.moveVelocity(0);
    intake::intakegroup.moveVelocity(0);
    break;

  case State::NONE:
    break;
  }
}

void init() {
  up();
  down();
  recycle();
  execute();
}

void lift(int pos, int vel) {
  while (motor.getPosition() < pos - 5 && motor.getPosition() > pos + 5) {
    motor.moveVelocity(vel);
  }
}
void liftTimed(int pos, int vel, int time) {
  int started = pros::millis();
  while (motor.getPosition() != pos || pros::millis() - started < time) {
    motor.moveVelocity(vel);
  }
}
} // namespace lift
