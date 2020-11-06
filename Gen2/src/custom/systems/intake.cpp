#include "custom/systems/intake.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "main.h"

namespace intake {
pros::Vision visionSensor(2);
void initVision() {
  visionSensor.set_wifi_mode(0);
  pros::vision_signature_s_t RED_BALL = visionSensor.signature_from_utility(
      1, 4953, 6495, 5724, -303, 259, -22, 3.000, 0);
  pros::vision_signature_s_t BLUE_BALL = visionSensor.signature_from_utility(
      2, -3551, -2285, -2918, 7295, 15009, 11152, 1.500, 0);
}
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
bool red = true;

int n = visionSensor.get_object_count();
void execute() {
  if (selection::BtnSwap.changedToReleased()) {
    if (red)
      red = false;
    else if (!red)
      red = true;
  }
  switch (state) {
  case State::IN: {
    pros::vision_object_s_t rtn = visionSensor.get_by_sig(0, 1);
    pros::vision_object_s_t rtn2 = visionSensor.get_by_sig(0, 2);
    n = visionSensor.get_object_count();
    if (red) {
      intakeGroup.moveVelocity(200);
      if (rtn.signature == 1) {
        elevator::elevGroup.moveVelocity(200);
      } else if (rtn2.signature == 2) {
        elevator::lowerMotor.moveVelocity(200);
        elevator::upperMotor.moveVelocity(-200);
      } else {
        elevator::elevGroup.moveVelocity(0);
      }
    } else if (!red) {
      intakeGroup.moveVelocity(200);
      if (rtn2.signature == 2) {
        elevator::elevGroup.moveVelocity(200);
      } else if (rtn.signature == 1) {
        elevator::lowerMotor.moveVelocity(200);
        elevator::upperMotor.moveVelocity(-200);
      } else {
        elevator::elevGroup.moveVelocity(0);
      }
    } else {
      intakeGroup.moveVelocity(200);
      elevator::elevGroup.moveVelocity(0);
    }

    break;
  }

  case State::OUT:
    intakeGroup.moveVelocity(-12000);
    break;

  case State::MANUAL:
    intakeGroup.moveVelocity(200);
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
  manIn();
  execute();
}

} // namespace intake

namespace auton {

void runIntake(int velocity) { intake::intakeGroup.moveVoltage(velocity); }

} // namespace auton
