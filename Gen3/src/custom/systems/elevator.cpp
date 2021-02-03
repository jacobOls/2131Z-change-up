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

void autoRatchet(){
  if(autoElev.isPressed()){
    state = State::AUTO;
  } else if (state == State::AUTO){
    state = State::DEINIT;
  }
}

// int n = visionSensor.get_object_count();
void toggle() {
  if (selection::BtnSwap.changedToReleased()) {
    if (red)
      red = false;
    else if (!red)
      red = true;
  }
}
int curTime = pros::millis();
int redTol = 55;
int blueTol = 70;
void execute() {
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
    elevGroup.moveVoltage(9000);
    break;
  case State::OUT:
    elevGroup.moveVoltage(-12000);
    break;

  case State::BACK: // moves wheel motors to eject ball out back
  intake::intakeGroup.moveVelocity(200);
    elevMotor.moveVoltage(12000);
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

    case State::AUTO:
    elevMotor.moveVoltage(12000);
    int vel = red ? 12000 : -12000;
    if(opt.get_hue() < redTol){
      ratchetMotor.moveVoltage(vel);
      pros::delay(100);
    } else if(opt.get_hue() > blueTol){
      ratchetMotor.moveVoltage(-vel);
      pros::delay(100);
    } else{
      ratchetMotor.moveVoltage(12000);
    }
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
  middle();
  autoRatchet();
  pros::delay(3);
}

} // namespace elevator

namespace auton {
pros::Distance disSense(18);
void score() {
  int curTime = pros::millis();
  elevator::elevGroup.moveVelocity(600);
  while (disSense.get() > 90) {
    if (pros::millis() - curTime > 1500) {
      break;
    }
  }
  pros::delay(400);
  elevator::elevGroup.moveVelocity(0);
}
void runElevator(int velocity) { elevator::elevGroup.moveVoltage(velocity); }
void eject() {
  elevator::elevMotor.moveVoltage(12000);
  elevator::ratchetMotor.moveVoltage(-12000);
}
void autoBack(int delay) {
  int startTime = pros::millis();
  intake::intakeGroup.moveVoltage(12000);
  while (pros::millis() - startTime < delay) {
    pros::vision_object_s_t rtn = elevator::visionSensor.get_by_sig(0, 1);
    pros::vision_object_s_t rtn2 = elevator::visionSensor.get_by_sig(0, 2);
    // elevator::n = elevator::visionSensor.get_object_count();
    if (rtn.signature == 1) {
      elevator::elevGroup.moveVoltage(12000);
    } else if (rtn2.signature == 2) {
      elevator::elevMotor.moveVoltage(12000);
      elevator::ratchetMotor.moveVelocity(-12000);
    } else {
      elevator::elevGroup.moveVoltage(12000);
    }
  }
  elevator::elevGroup.moveVoltage(0);
}

} // namespace auton
