#include "custom/systems/elevator.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "main.h"

namespace elevator {
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
  } else if (state == State::UP) {
    state = State::DEINIT;
  }
}

void execute() {
  switch (state) {

  case State::IN:
    elevGroup.moveVelocity(200);
    intake::intakeGroup.moveVelocity(200);
    break;

  case State::OUT:
    elevGroup.moveVelocity(-200);
    intake::intakeGroup.moveVelocity(-200);
    break;

  case State::BACK: // moves wheel motors to eject ball out back
    upperMotor.moveVelocity(200);
    lowerMotor.moveVelocity(-200);
    break;

  case State::UNJAM: // moves wheel alone to unjam
    elevGroup.moveVelocity(-200);
    break;

  case State::UP:
    elevGroup.moveVelocity(200);
    break;

  case State::DEINIT:
    elevGroup.moveVelocity(0);
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

} // namespace elevator

namespace auton {
void runWheel(int velocity) { elevator::elevGroup.moveVelocity(velocity); }
void back(int velocity) {
  elevator::upperMotor.moveVelocity(velocity);
  elevator::lowerMotor.moveVelocity(-velocity);
}

} // namespace auton
