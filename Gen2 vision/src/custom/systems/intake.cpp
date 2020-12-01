#include "custom/systems/intake.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "main.h"

namespace intake {

State state = State::NONE;
pros::ADIAnalogIn intakeSense(8);
pros::ADIAnalogIn highElevator(5);
bool inIntake = false;
bool inVision = false;
void in() {
  if (BtnIn.isPressed()) {
    state = State::IN;
  } else if (state == State::IN) {
    state = State::DEINIT;
  }
}
int low() { return intakeSense.get_value(); }
int high() { return intakeSense.get_value(); }
int lThresh;
int hThresh;
void out() {
  if (BtnOut.isPressed()) {
    state = State::OUT;
  } else if (state == State::OUT) {
    state = State::DEINIT;
  }
}
void manIn() {
  if (ManualIn.isPressed()) {
    state = State::MANUAL;
  } else if (state == State::MANUAL) {
    state = State::DEINIT;
  }
}

void execute() {

  switch (state) {
  case State::IN: {
    intakeGroup.moveVoltage(12000);

    break;
  }

  case State::OUT:
    intakeGroup.moveVoltage(-12000);
    break;

  case State::MANUAL:
    intakeGroup.moveVoltage(12000);
    break;

  case State::DEINIT:
    intakeGroup.moveVoltage(0);
    elevator::elevGroup.moveVoltage(0);
    state = State::NONE;
    break;

  case State::NONE:
    break;
  }
}

void init() {
  in();
  out();
  // manIn();
  execute();
}

} // namespace intake

namespace auton {

void runIntake(int velocity) { intake::intakeGroup.moveVoltage(velocity); }

} // namespace auton
