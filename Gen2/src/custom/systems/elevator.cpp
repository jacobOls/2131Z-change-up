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

void eject() {
  if (BtnBack.isPressed()) {
    state = State::BACK;
  } else if (state == State::BACK) {
    state = State::DEINIT;
  }
}

void lower() {
  if (Down.isPressed()) {
    state = State::DOWN;
  } else if (state == State::DOWN) {
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

  case State::DOWN: // moves wheel alone downward
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
  eject();
  lower();
  up();
  in();
  out();
  execute();
}

} // namespace elevator

namespace auton {
void runElevator(int velocity) { elevator::elevGroup.moveVelocity(velocity); }
void back(int velocity) {
  elevator::upperMotor.moveVelocity(velocity);
  elevator::lowerMotor.moveVelocity(-velocity);
}

} // namespace auton
