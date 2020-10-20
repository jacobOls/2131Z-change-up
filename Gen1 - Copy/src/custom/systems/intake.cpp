#include "custom/systems/intake.hpp"
#include "custom/settup/controller.hpp"
#include "custom/settup/motors.hpp"
#include "custom/systems/vision.hpp"
#include "main.h"

namespace intake {
pros::Vision visionSensor(10);

State state = State::NONE;
pros::ADIAnalogIn intakeEntry(8);
pros::ADIAnalogIn midElevator(2);
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

void out() {
  if (BtnOut.isPressed()) {
    state = State::OUT;
  } else if (state == State::OUT) {
    state = State::DEINIT;
  }
}
bool red = true;
void execute() {
  pros::vision_object_s_t rtn = visionSensor.get_by_sig(0, 1);
  pros::vision_object_s_t rtn2 = visionSensor.get_by_sig(0, 2);
  if (selection::BtnSwap.changedToReleased()) {
    if (red)
      red = false;
    else if (!red)
      red = true;
  }
  switch (state) {
  case State::IN:
    if (red) {
      intakeGroup.moveVelocity(200);
      if (rtn.signature == 1) {
        wheel::wheelGroup.moveVelocity(200);
      } else if (rtn2.signature == 2) {
        wheel::left_motor.moveVelocity(200);
        wheel::right_motor.moveVelocity(-200);
      } else {
        wheel::wheelGroup.moveVelocity(0);
      }
    } else if (!red) {
      intakeGroup.moveVelocity(200);
      if (rtn2.signature == 2) {
        wheel::wheelGroup.moveVelocity(200);
      } else if (rtn.signature == 1) {
        wheel::left_motor.moveVelocity(200);
        wheel::right_motor.moveVelocity(-200);
      } else {
        wheel::wheelGroup.moveVelocity(0);
      }
    } else {
      intakeGroup.moveVelocity(200);
      wheel::wheelGroup.moveVelocity(0);
    }
    break;

  case State::OUT:
    intakeGroup.moveVelocity(-200);
    break;

  case State::DEINIT:
    intakeGroup.moveVelocity(0);
    wheel::wheelGroup.moveVelocity(0);
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
