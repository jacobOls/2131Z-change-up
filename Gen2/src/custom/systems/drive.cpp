#include "custom/systems/drive.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "main.h"
namespace drive {
void userDrive() {
  leftFront.moveVoltage(
      (okapi::deadband(master.getAnalog(okapi::ControllerAnalog::leftY), -0.05,
                       0.05) +
       okapi::deadband(master.getAnalog(okapi::ControllerAnalog::leftX), -0.05,
                       0.05)) *
      12000);
  leftBack.moveVoltage(
      (okapi::deadband(master.getAnalog(okapi::ControllerAnalog::leftY), -0.05,
                       0.05) -
       okapi::deadband(master.getAnalog(okapi::ControllerAnalog::leftX), -0.05,
                       0.05)) *
      12000);

  rightFront.moveVoltage(
      (okapi::deadband(master.getAnalog(okapi::ControllerAnalog::rightY), -0.05,
                       0.05) -
       okapi::deadband(master.getAnalog(okapi::ControllerAnalog::rightX), -0.05,
                       0.05)) *
      12000);
  rightBack.moveVoltage(
      (okapi::deadband(master.getAnalog(okapi::ControllerAnalog::rightY), -0.05,
                       0.05) +
       okapi::deadband(master.getAnalog(okapi::ControllerAnalog::rightX), -0.05,
                       0.05)) *
      12000);
}
void brake() {
  if (BtnBrake.isPressed()) {
    drive::driveGroup.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  } else {
    drive::driveGroup.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  }
}
} // namespace drive

namespace auton {
/*
IME (Integrated motor Encoder) torque: 627.2
IME speed: 392
IME turbo: 261.333
*/
void drive(int distance, int velocity) {
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
  int epsilon = velocity * 1.725;
  int req = 5;
  while (abs(drive::driveGroup.getPosition()) <= abs((distance)) - epsilon) {
    if (abs(drive::driveGroup.getPosition()) >= distance - epsilon) {
      break;
    }
    drive::accelDrive.accelMath(accel, &drive::driveGroup, velocity);
  }
  if (drive::driveGroup.getActualVelocity() < velocity) {
    drive::driveGroup.moveVelocity(velocity);
    pros::delay(10);
  }
  std::cout << "stopping " << drive::driveGroup.getPosition() << std::endl;
  reset();
  while (abs(drive::leftFront.getActualVelocity()) != 5000) {
    if (velocity < 0 && req > 0) {
      req *= 1;
    }
    // std::cout << drive::left_drive.getPosition() << std::endl;
    drive::deAccelDrive.deAccelMath(accel, &drive::driveGroup, req, velocity);
    if (abs(drive::driveGroup.getPosition()) >= distance) {
      std::cout << " break early " << drive::driveGroup.getPosition()
                << std::endl;
      break;
    }
    pros::delay(drive::deAccelDrive.rateOfChange);
  }
  std::cout << "end " << drive::driveGroup.getPosition() << std::endl;
  std::cout << "vel " << drive::leftFront.getActualVelocity() << std::endl;
  reset();
  drive::driveGroup.moveVelocity(0);
  drive::driveGroup.tarePosition();
}

void strafe(int distance, int velocity, std::string direction) {
  bool velDir = false;
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
  int epsilon = velocity * 0.625;
  int request = 10;
  while (abs(drive::leftFront.getPosition()) <= distance - epsilon) {
    if (!velDir && direction == "left") {
      request *= -1;
      velocity *= -1;
      velDir = true;
    }
    drive::accelDrive.accelMath(accel, &drive::left_strafe, velocity);
    drive::accelDrive.accelMath(accel, &drive::right_strafe, -velocity);
    pros::delay(drive::accelDrive.rateOfChange);
  }
  reset();
  if (abs(drive::driveGroup.getActualVelocity()) < abs(velocity)) {
    drive::left_strafe.moveVelocity(velocity);
    drive::right_strafe.moveVelocity(-velocity);

    pros::delay(10);
  }
  while (abs(drive::leftFront.getActualVelocity()) != 2500) {

    drive::accelDrive.deAccelMath(accel, &drive::left_strafe, request,
                                  velocity * .5);
    drive::accelDrive.deAccelMath(accel, &drive::right_strafe, -request,
                                  velocity * .5);

    if (abs(drive::leftFront.getPosition()) >= distance) {
      std::cout << " break early " << drive::leftFront.getPosition()
                << std::endl;
      break;
    }
    pros::delay(drive::deAccelDrive.rateOfChange);
  }
  reset();
  std::cout << drive::leftFront.getPosition() << std::endl;
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
bool reversed = false;
int turnReq = 10;
void turn(int turnAmount, int velocity, std::string direction) {
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
  int epsilon = velocity * 0.8;
  reset();
  while (abs(drive::leftFront.getPosition()) <= turnAmount - epsilon) {
    if (direction == "left" && !reversed) {
      velocity *= -1;
      turnReq *= -1;
      reversed = true;
    }
    drive::accelDrive.accelMath(accel, &drive::left_drive, velocity);
    drive::accelDrive.accelMath(accel, &drive::right_drive, -velocity);
    pros::delay(drive::accelDrive.rateOfChange);
  }
  // std::cout << "accelFinish<<" << std::endl;
  reset();
  reversed = false;
  if (abs(drive::driveGroup.getActualVelocity()) < abs(velocity)) {
    drive::left_drive.moveVelocity(-velocity);
    drive::right_drive.moveVelocity(velocity);
    pros::delay(10);
  }
  // std::cout << "slowing<<" << std::endl;
  while (abs(drive::leftFront.getActualVelocity()) != 12349) {

    drive::accelDrive.deAccelMath(accel, &drive::left_drive, turnReq,
                                  velocity * .4);
    drive::accelDrive.deAccelMath(accel, &drive::right_drive, -turnReq,
                                  velocity * .4);
    if (abs(drive::leftFront.getPosition()) >= turnAmount) {
      std::cout << " break early " << drive::leftFront.getPosition()
                << std::endl;
      break;
    }
    pros::delay(drive::accelDrive.rateOfChange);
  }
  reset();
  std::cout << drive::left_drive.getPosition() << std::endl;
  drive::left_drive.moveVelocity(0);
  drive::right_drive.moveVelocity(0);
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
}

} // namespace auton