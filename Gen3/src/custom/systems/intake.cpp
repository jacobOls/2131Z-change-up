#include "custom/systems/intake.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "main.h"

namespace intake {

State state = State::NONE;
pros::ADIAnalogIn intakeSense(8);
pros::ADIAnalogIn highElevator(5);
ADIButton leftIntake('b');
ADIButton rightIntake('a');
bool leftOpened = false;
bool rightOpened = false;
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
void execute() {

  if (state != State::OUT) {
    intakeGroup.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    leftOpened = false;
    rightOpened = false;
  }
  switch (state) {
  case State::IN: {
    intakeGroup.moveVoltage(12000);
    break;
  }

  case State::OUT:
    if (leftOpened == false) {
      left_motor.moveVelocity(-200);
    } else if (leftIntake.isPressed()) {
      leftOpened = true;
      left_motor.moveVelocity(0);
      left_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    }
    if (leftOpened == true) {
      left_motor.moveVelocity(0);
      left_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    }
    if (rightOpened == false) {
      right_motor.moveVelocity(-200);
    } else if (rightIntake.isPressed()) {
      leftOpened = true;
      right_motor.moveVelocity(0);
      right_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    }
    if (rightOpened == true) {
      right_motor.moveVelocity(0);
      right_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    }
    // std::cout << leftOpened << std::endl;
    intakeGroup.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    break;

  case State::MANUAL:
    intakeGroup.moveVelocity(200);
    break;

  case State::DEINIT:
    intakeGroup.moveVelocity(0);
    intakeGroup.moveVoltage(0);
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

int timer = pros::millis();
void runIntake(int velocity) { intake::intakeGroup.moveVoltage(velocity); }
void open() {
  intake::intakeGroup.tarePosition();
  intake::left_motor.moveRelative(-70, -100);
  intake::right_motor.moveRelative(-150, -100);
  intake::intakeGroup.setBrakeMode(AbstractMotor::brakeMode::hold);
}
void release() {
  intake::intakeGroup.setBrakeMode(AbstractMotor::brakeMode::coast);
  intake::intakeGroup.moveRelative(2000, 200);
  elevator::elevGroup.moveRelative(200, 100);
  intake::intakeGroup.setBrakeMode(AbstractMotor::brakeMode::coast);
}

} // namespace auton
