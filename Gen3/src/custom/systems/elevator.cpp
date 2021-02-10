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

void autoRatchet(){
  if(autoElev.isPressed() && state != State::FOO){
    state = State::AUTO;
  } else if (state == State::AUTO && state != State::FOO){
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
int curTime;
int redTol = 55;
int blueTol = 70;
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

    case State::FOO:
    if(pros::millis() - curTime > 100){
      state = State::AUTO;
    }
    break;

    case State::AUTO:
    int curTime = pros::millis();
    elevMotor.moveVoltage(12000);
    intake::intakeGroup.moveVelocity(200);
    int vel = red ? 12000 : -12000;
    if(opt.get_hue() < redTol){
      ratchetMotor.moveVoltage(vel);
      state = State::FOO;
    } else if(opt.get_hue() > blueTol){
      ratchetMotor.moveVoltage(-vel);
      state = State::FOO;
    } else{
      ratchetMotor.moveVoltage(12000);
    }
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

namespace auton {
pros::Distance disSense(18);
void scoreUntil(){
  int curTime = pros::millis();
  elevator::elevGroup.moveVelocity(600);
  if(elevator::red == true){ while(opt.get_hue() > 45){
    if (pros::millis() - curTime > 2000) {
      break;
    }
    }
  if(elevator::red == false){ while(opt.get_hue() < 85){
    if (pros::millis() - curTime > 2000) {
      break;
    }
    }
  }
  intake::intakeGroup.moveVoltage(0);
  pros::delay(80);
   elevator::elevGroup.moveVelocity(0);
    }
}
void score() {
  int curTime = pros::millis();
  elevator::elevGroup.moveVelocity(600);
  while (disSense.get() > 90) {
    if (pros::millis() - curTime > 1500) {
      break;
    }
  }
  pros::delay(350);
  elevator::elevGroup.moveVelocity(0);
}
void runElevator(int velocity) { elevator::elevGroup.moveVoltage(velocity); }
void eject() {
  elevator::elevMotor.moveVoltage(12000);
  elevator::ratchetMotor.moveVoltage(-12000);
}


} // namespace auton
