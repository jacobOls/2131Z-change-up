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
void middle() {
  if (mid.isPressed()) {
    state = State::MID;
  } else if (state == State::MID) {
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
bool red = true;

void autoRatchet() {
  if (autoElev.isPressed() && state != State::FOO) {
    state = State::AUTO;
  } else if (state == State::AUTO && state != State::FOO) {
    state = State::DEINIT;
  }
}

// int n = visionSensor.get_object_count();
void toggle() {
  if (selection::BtnSwap.changedToPressed()) {
    if (red)
      red = false;
    else if (!red)
      red = true;
  }
}

void execute() {
  // while(true){
  if (state != State::OUT && state != State::NONE) {
    intake::intakeGroup.tarePosition();
    intake::intakeGroup.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  }
  switch (state) {
  case State::IN: {

    if (abs(drive::driveGroup.getActualVelocity()) > 15) {
      elevGroup.moveVoltage(9000);
    }
    elevGroup.moveVoltage(12000);
    intake::intakeGroup.moveVelocity(200);
    break;
  }
  case State::MID:
    elevGroup.moveVoltage(12000 * .6);
    break;
  case State::OUT:
    elevGroup.moveVoltage(-12000);
    break;

  case State::BACK: // moves wheel motors to eject ball out back
    intake::intakeGroup.moveVelocity(200);
    elevMotor.moveVoltage(12000);
    elevMotor2.moveVoltage(12000);
    ratchetMotor.moveVoltage(-12000);
    break;

  case State::DOWN: // moves wheel alone downward
    elevGroup.moveVoltage(-12000);
    break;

  case State::UP:
    elevGroup.moveVoltage(12000);
    break;

  case State::DEINIT:
    elevGroup.moveVoltage(0);
    intake::intakeGroup.moveVelocity(0);
    state = State::NONE;
    break;

  case State::NONE:
    break;

  case State::FOO:

    break;

  case State::AUTO:

    break;
  }
}
// }

void init() {
  eject();
  lower();
  up();
  in();
  out();
  toggle();
  execute();
  middle();
  autoRatchet();
  // pros::delay(10);
}

} // namespace elevator
