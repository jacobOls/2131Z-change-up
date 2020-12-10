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
  if (BtnIn.isPressed() /*|| elevator::BtnBack.isPressed()*/) {
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
  if (BtnOut.isPressed() || elevator::BtnOut.isPressed()) {
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
int curTime;
void execute() {

  if (state != State::OUT) {
    intakeGroup.tarePosition();
    intakeGroup.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  }
  switch (state) {
  case State::IN: {
    intakeGroup.moveVelocity(200);
    curTime = pros::millis();
    break;
  }

  case State::OUT:
    if (abs(left_motor.getPosition()) < 60) {
      left_motor.moveVelocity(-200);
    } else {
      left_motor.moveVelocity(0);
      left_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    }
    if (abs(right_motor.getPosition()) < 60) {
      right_motor.moveVelocity(-200);
    } else {
      right_motor.moveVelocity(0);
      right_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    }

    // intakeGroup.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    break;

  case State::MANUAL:
    intakeGroup.moveVelocity(200);
    break;

  case State::DEINIT:
    intakeGroup.moveVelocity(0);
    elevator::elevGroup.moveVelocity(0);
    state = State::NONE;
    break;

  case State::NONE:
    break;
  }
}

void init() {
  // int yeet = right_motor.getPosition();
  // std::string str = std::to_string(yeet);
  in();
  out();
  // manIn();
  execute();
  // master.setText(1, 1, str);
}

} // namespace intake

namespace auton {

void runIntake(int velocity) { intake::intakeGroup.moveVoltage(velocity); }
void open() {
  intake::intakeGroup.tarePosition();
  intake::left_motor.moveAbsolute(-60, -200);
  intake::right_motor.moveAbsolute(-60, -200);
  intake::intakeGroup.setBrakeMode(AbstractMotor::brakeMode::hold);
}
void release() {
  intake::intakeGroup.setBrakeMode(AbstractMotor::brakeMode::coast);
}

} // namespace auton
