#include "custom/systems/drive.hpp"
#include "custom/settup/controller.hpp"
#include "custom/settup/motors.hpp"
#include "main.h"
namespace drive {
Left left = Left::NONE;
Right right = Right::NONE;
Brake brake = Brake::NONE;

void userDrive() {
  left_front.moveVoltage(
      (okapi::deadband(master.getAnalog(okapi::ControllerAnalog::leftY), -0.05,
                       0.05) +
       okapi::deadband(master.getAnalog(okapi::ControllerAnalog::leftX), -0.05,
                       0.05)) *
      12000);
  left_back.moveVoltage(
      (okapi::deadband(master.getAnalog(okapi::ControllerAnalog::leftY), -0.05,
                       0.05) -
       okapi::deadband(master.getAnalog(okapi::ControllerAnalog::leftX), -0.05,
                       0.05)) *
      12000);

  right_front.moveVoltage(
      (okapi::deadband(master.getAnalog(okapi::ControllerAnalog::rightY), -0.05,
                       0.05) -
       okapi::deadband(master.getAnalog(okapi::ControllerAnalog::rightX), -0.05,
                       0.05)) *
      12000);
  right_back.moveVoltage(
      (okapi::deadband(master.getAnalog(okapi::ControllerAnalog::rightY), -0.05,
                       0.05) +
       okapi::deadband(master.getAnalog(okapi::ControllerAnalog::rightX), -0.05,
                       0.05)) *
      12000);
}
} // namespace drive

namespace auton {
int remDist;
void drive(int distance, int velocity) {
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
  int epsilon;
  if (velocity == 200 || velocity == -200)
    epsilon = 300;
  else if (velocity == 150 || velocity == -150)
    epsilon = 300;
  else if (velocity == 100 || velocity == -100)
    epsilon = 300;
  else if (velocity == 50 || velocity == -50)
    epsilon = 300;
  while (abs(drive::left_front.getPosition()) <= abs((distance)) - epsilon) {
    drive::accelDrive.accelMath(accel, &drive::left_drive, velocity);
    drive::accelDrive.accelMath(accel, &drive::right_drive, velocity);
    pros::delay(drive::accelDrive.rateOfChange);
    // std::cout << "ramping" << std::endl;
    // std::cout << "looping" << std::endl;
  }
  // std::cout << "stopping" << std::endl;
  while (abs(drive::left_front.getActualVelocity()) != 0) {

    // std::cout << drive::left_drive.getPosition() << std::endl;
    drive::deAccelDrive.deAccelMath(accel, &drive::left_drive, 0, velocity);
    drive::deAccelDrive.deAccelMath(accel, &drive::right_drive, 0, velocity);
    pros::delay(drive::deAccelDrive.rateOfChange);
  }
  std::cout << drive::left_drive.getPosition() << std::endl;
  // drive::left_drive.moveVelocity(0);
  // drive::right_drive.moveVelocity(0);
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
}

void driveNE(int distance, int velocity) {
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
  while (abs(drive::left_front.getPosition()) <= abs(distance)) {
    drive::accelDrive.accelMath(accel, &drive::left_drive, velocity);
    drive::accelDrive.accelMath(accel, &drive::right_drive, velocity);
    pros::delay(drive::accelDrive.rateOfChange);
    // std::cout << "ramping" << std::endl;
    // std::cout << "looping" << std::endl;
  }
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
}
void strafe(int distance, int velocity, std::string direction) {
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();

  while (abs(drive::left_front.getPosition()) <= abs(distance) * (7 / 10)) {

    if (direction == "right") {
      drive::accelDrive.accelMath(accel, &drive::left_strafe, velocity);
      drive::accelDrive.accelMath(accel, &drive::right_strafe, -velocity);
      pros::delay(drive::accelDrive.rateOfChange);
    }

    else if (direction == "left") {
      drive::accelDrive.accelMath(accel, &drive::left_strafe, -velocity);
      drive::accelDrive.accelMath(accel, &drive::right_strafe, velocity);
      pros::delay(drive::accelDrive.rateOfChange);
    }
  }
  while (abs(drive::left_front.getPosition()) <= abs(distance)) {
    remDist = distance - abs(drive::left_front.getPosition());
    if (abs(remDist) > abs(velocity))
      remDist = velocity;
    if (velocity < 0 && remDist > 0)
      remDist *= -1;
    if (direction == "right") {
      drive::accelDrive.deAccelMath(accel, &drive::left_strafe, remDist,
                                    velocity);
      drive::accelDrive.deAccelMath(accel, &drive::right_strafe, -remDist,
                                    velocity);
    } else if (direction == "left") {
      drive::accelDrive.deAccelMath(accel, &drive::left_strafe, -remDist,
                                    velocity);
      drive::accelDrive.deAccelMath(accel, &drive::right_strafe, remDist,
                                    velocity);
    }
    pros::delay(drive::accelDrive.rateOfChange);
  }
  std::cout << drive::left_front.getPosition() << std::endl;
  drive::left_strafe.moveVelocity(0);
  drive::right_strafe.moveVelocity(0);
  drive::left_strafe.tarePosition();
  drive::right_strafe.tarePosition();
}

void timeStrafe(int voltage, int time, std::string direction) {
  if (direction == "right") {
    drive::left_strafe.moveVoltage(voltage);
    drive::right_strafe.moveVoltage(-voltage);
  } else if (direction == "left") {
    drive::left_strafe.moveVoltage(-voltage);
    drive::right_strafe.moveVoltage(voltage);
  }
  pros::delay(time);
  drive::right_strafe.moveVelocity(0);
  drive::left_strafe.moveVelocity(0);
  drive::left_strafe.tarePosition();
  drive::right_strafe.tarePosition();
}

void turn(int turnAmount, int velocity, std::string direction) {
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
  while (abs(drive::left_front.getPosition()) <= abs(turnAmount) * (7 / 10)) {
    if (direction == "left") {
      drive::accelDrive.accelMath(accel, &drive::left_drive, -velocity);
      drive::accelDrive.accelMath(accel, &drive::right_drive, velocity);
      pros::delay(drive::accelDrive.rateOfChange);
    }

    else if (direction == "right") {
      drive::accelDrive.accelMath(accel, &drive::left_drive, velocity);
      drive::accelDrive.accelMath(accel, &drive::right_drive, -velocity);
      pros::delay(drive::accelDrive.rateOfChange);
    }
  }
  while (abs(drive::left_front.getPosition()) <= abs(turnAmount) - 2) {
    remDist = turnAmount - abs(drive::left_front.getPosition());
    if (abs(remDist) > abs(velocity))
      remDist = velocity;
    if (direction == "left") {
      drive::accelDrive.deAccelMath(accel, &drive::left_drive, -remDist,
                                    velocity);
      drive::accelDrive.deAccelMath(accel, &drive::right_drive, remDist,
                                    velocity);
    } else if (direction == "right") {
      drive::accelDrive.deAccelMath(accel, &drive::left_drive, remDist,
                                    velocity);
      drive::accelDrive.deAccelMath(accel, &drive::right_drive, -remDist,
                                    velocity);
    }
    pros::delay(drive::accelDrive.rateOfChange);
  }
  std::cout << drive::left_drive.getPosition() << std::endl;
  drive::left_drive.moveVelocity(0);
  drive::right_drive.moveVelocity(0);
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
}

} // namespace auton
