#include "custom/systems/intake.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "main.h"

namespace intake {

State state = State::NONE;
pros::ADIAnalogIn intakeSense(8);
pros::Vision visionSensor(10);
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
bool red = true;
void autoElev() {
  pros::vision_object_s_t rtn = visionSensor.get_by_sig(0, 1);
  pros::vision_object_s_t rtn2 = visionSensor.get_by_sig(0, 2);
  if (selection::BtnSwap.changedToReleased()) {
    if (red)
      red = false;
    else if (!red)
      red = true;
    if (red) {
      if (high() < hThresh) {
        if (rtn.signature == 1) {
          elevator::elevGroup.moveVelocity(200);
        } else if (rtn2.signature == 2) {
          elevator::upperMotor.moveVelocity(200);
          elevator::lowerMotor.moveVelocity(-200);
        }
      } else if (high() >= hThresh && rtn2.signature == 2) {
        elevator::upperMotor.moveVelocity(200);
        elevator::lowerMotor.moveVelocity(-200);
      } else if (high() >= hThresh && rtn.signature == 1) {
        elevator::elevGroup.moveVelocity(0);
      }
    } else if (!red) {
      if (high() < hThresh) {
        if (rtn2.signature == 2) {
          elevator::elevGroup.moveVelocity(200);
        } else if (rtn.signature == 1) {
          elevator::upperMotor.moveVelocity(200);
          elevator::lowerMotor.moveVelocity(-200);
        }
      } else if (high() >= hThresh && rtn.signature == 1) {
        elevator::upperMotor.moveVelocity(200);
        elevator::lowerMotor.moveVelocity(-200);
      } else if (high() >= hThresh && rtn2.signature == 2) {
        elevator::elevGroup.moveVelocity(0);
      }
    }
  }
}
void execute() {

  switch (state) {
  case State::IN:

    if (low() < lThresh && high() < hThresh) {
      intakeGroup.moveVelocity(200);
    } else if (low() >= lThresh) {
      intakeGroup.moveVelocity(200);
      autoElev();
    } else if (high() >= hThresh) {
      autoElev();
      intakeGroup.moveVelocity(200);
    } else if (low() > lThresh && high() > hThresh) {
      elevator::elevGroup.moveVelocity(0);
      intakeGroup.moveVelocity(0);
    }

    break;

  case State::OUT:
    intakeGroup.moveVelocity(-200);
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
  in();
  out();
  execute();
}

} // namespace intake

namespace auton {

void runIntake(int velocity) { intake::intakeGroup.moveVelocity(velocity); }

} // namespace auton
