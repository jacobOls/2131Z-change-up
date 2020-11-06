#include "custom/systems/elevator.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "main.h"

namespace elevator {
State state = State::NONE;
pros::Vision visionSensor(2);
void initVision() {
  visionSensor.set_wifi_mode(0);
  pros::vision_signature_s_t RED_BALL = visionSensor.signature_from_utility(
      1, 4953, 6495, 5724, -303, 259, -22, 3.000, 0);
  pros::vision_signature_s_t BLUE_BALL = visionSensor.signature_from_utility(
      2, -3551, -2285, -2918, 7295, 15009, 11152, 1.500, 0);
}
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
bool red = true;

int n = visionSensor.get_object_count();
void toggle() {
  if (selection::BtnSwap.changedToReleased()) {
    if (red)
      red = false;
    else if (!red)
      red = true;
  }
}
void execute() {
  switch (state) {
  case State::IN: {
    // pros::vision_object_s_t rtn = visionSensor.get_by_sig(0, 1);
    // pros::vision_object_s_t rtn2 = visionSensor.get_by_sig(0, 2);
    // n = visionSensor.get_object_count();
    // if (red) {
    //   intake::intakeGroup.moveVelocity(200);
    //   if (rtn.signature == 1 && rtn2.signature != 2) {
    //     elevator::elevGroup.moveVelocity(200);
    //   } else if (rtn2.signature == 2 && rtn.signature != 1) {
    //     elevator::lowerMotor.moveVelocity(600);
    //     elevator::upperMotor.moveVelocity(-600);
    //   } else {
    //     elevator::elevGroup.moveVelocity(600);
    //   }
    // } else if (!red) {
    //   intake::intakeGroup.moveVelocity(600);
    //   if (rtn2.signature == 2 && rtn.signature != 1) {
    //     elevator::elevGroup.moveVelocity(600);
    //   } else if (rtn.signature == 1 && rtn2.signature != 2) {
    //     elevator::lowerMotor.moveVelocity(600);
    //     elevator::upperMotor.moveVelocity(-600);
    //   } else {
    //     elevator::elevGroup.moveVelocity(600);
    //   }
    // } else {
    //   intake::intakeGroup.moveVelocity(600);
    //   elevator::elevGroup.moveVelocity(600);
    // }
    elevGroup.moveVelocity(600);
    intake::intakeGroup.moveVelocity(600);
    break;
  }

  case State::OUT:
    elevGroup.moveVelocity(-600);
    intake::intakeGroup.moveVelocity(-600);
    break;

  case State::BACK: // moves wheel motors to eject ball out back
    upperMotor.moveVelocity(-600);
    lowerMotor.moveVelocity(600);
    break;

  case State::DOWN: // moves wheel alone downward
    elevGroup.moveVelocity(-600);
    break;

  case State::UP:
    elevGroup.moveVelocity(600);
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
  toggle();
}

} // namespace elevator

namespace auton {
void runElevator(int velocity) { elevator::elevGroup.moveVoltage(velocity); }
void autoBack(int delay) {
  int startTime = pros::millis();
  intake::intakeGroup.moveVelocity(200);
  while (pros::millis() - startTime < delay) {
    pros::vision_object_s_t rtn = elevator::visionSensor.get_by_sig(0, 1);
    pros::vision_object_s_t rtn2 = elevator::visionSensor.get_by_sig(0, 2);
    elevator::n = elevator::visionSensor.get_object_count();
    if (rtn.signature == 1) {
      elevator::elevGroup.moveVelocity(200);
    } else if (rtn2.signature == 2) {
      elevator::lowerMotor.moveVelocity(200);
      elevator::upperMotor.moveVelocity(-200);
    } else {
      elevator::elevGroup.moveVelocity(200);
    }
  }
  elevator::elevGroup.moveVelocity(0);
}

} // namespace auton
