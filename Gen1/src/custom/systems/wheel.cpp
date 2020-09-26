#include "custom/systems/wheel.hpp"
#include "custom/settup/controller.hpp"
#include "custom/settup/motors.hpp"
#include "main.h"

namespace wheel {
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

void back() { // enters back(ejection) state
  if (BtnBack.isPressed()) {
    state = State::BACK;
  } else if (state == State::BACK) {
    state = State::DEINIT;
  }
}

void unjam() { // enters unjam state
  if (Unjam.isPressed()) {
    state = State::UNJAM;
  } else if (state == State::UNJAM) {
    state = State::DEINIT;
  }
}

void up() {
  if (UpOnly.isPressed()) {
    state = State::UP;
  } else if (state == State::UNJAM) {
    state = State::DEINIT;
  }
}

void execute() {
  switch (state) {

  case State::IN:
    wheelGroup.moveVelocity(200);
    intake::intakeGroup.moveVelocity(200);
    break;

  case State::OUT:
    wheelGroup.moveVelocity(-200);
    intake::intakeGroup.moveVelocity(-200);
    break;

  case State::BACK: // moves wheel motors to eject ball out back
    left_motor.moveVelocity(200);
    right_motor.moveVelocity(-200);
    break;

  case State::UNJAM: // moves wheel alone to unjam
    wheelGroup.moveVelocity(-200);
    break;

  case State::UP:
    wheelGroup.moveVelocity(200);
    break;

  case State::DEINIT:
    wheelGroup.moveVelocity(0);
    intake::intakeGroup.moveVelocity(0);
    state = State::NONE;
    break;

  case State::NONE:
    break;
  }
}

void init() {
  back();
  unjam();
  up();
  in();
  out();
  execute();
}

// void runWheel(int velocity) { wheelGroup.moveVelocity(velocity); }

} // namespace wheel

namespace auton {
void runWheel(int velocity) { wheel::wheelGroup.moveVelocity(velocity); }
void back(int velocity) {
  wheel::left_motor.moveVelocity(velocity);
  wheel::right_motor.moveVelocity(-velocity);
}

} // namespace auton
