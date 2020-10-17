#include "main.h"

pros::Vision visionSensor(11);
okapi::Motor motor(1, false, okapi::AbstractMotor::gearset::green,
                   okapi::AbstractMotor::encoderUnits::degrees);
void init() {
  visionSensor.set_wifi_mode(0);
  pros::vision_signature_s_t RED_BALL = visionSensor.signature_from_utility(
      1, 4953, 6495, 5724, -303, 259, -22, 3.000, 0);
  pros::vision_signature_s_t BLUE_BALL = visionSensor.signature_from_utility(
      2, -3551, -2285, -2918, 7295, 15009, 11152, 3.000, 0);
}
void execute() {
  pros::vision_object_s_t rtn = visionSensor.get_by_sig(0, 1);
  pros::vision_object_s_t rtn2 = visionSensor.get_by_sig(0, 1);
  int n = visionSensor.get_object_count();
  if (rtn.signature != 255)
    std::cout << "sig: " << rtn.signature << std::endl;
  // std::cout << n << std::endl;
  if (rtn.signature == 1) {
    motor.moveVelocity(200);
  } else {
    motor.moveVelocity(0);
  }
}
void initialize() {
  pros::lcd::initialize();
  init();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
#define SIG_1 1
  while (true) {

    execute();
    pros::delay(20);
  }
}
