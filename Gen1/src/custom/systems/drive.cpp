#include "custom/systems/drive.hpp"
#include "custom/settup/controller.hpp"
#include "custom/settup/motors.hpp"
#include "main.h"
namespace drive {
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
/*
IME (Integrated motor Encoder) torque: 627.2
IME speed: 392
IME turbo: 261.333
*/
void drive(int distance, int velocity) {
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
  int epsilon = velocity * 1.725;

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
  while (abs(drive::left_front.getActualVelocity()) != 5000) {

    // std::cout << drive::left_drive.getPosition() << std::endl;
    drive::deAccelDrive.deAccelMath(accel, &drive::driveGroup, 5, velocity);
    if (drive::driveGroup.getPosition() >= distance) {
      std::cout << " break early " << drive::driveGroup.getPosition()
                << std::endl;
      break;
    }
    pros::delay(drive::deAccelDrive.rateOfChange);
  }
  std::cout << "end " << drive::driveGroup.getPosition() << std::endl;
  std::cout << "vel " << drive::left_front.getActualVelocity() << std::endl;
  reset();
  drive::driveGroup.moveVelocity(0);
  drive::driveGroup.tarePosition();
}

void strafe(int distance, int velocity, std::string direction) {
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
  int epsilon = velocity * 0.625;
  while (abs(drive::left_front.getPosition()) <= distance - epsilon) {

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
  reset();
  if (abs(drive::driveGroup.getActualVelocity()) < abs(velocity)) {
    if (direction == "left") {
      drive::left_strafe.moveVelocity(-velocity);
      drive::right_strafe.moveVelocity(velocity);
    } else if (direction == "right") {
      drive::right_strafe.moveVelocity(-velocity);
      drive::left_strafe.moveVelocity(velocity);
    }
    pros::delay(10);
  }
  while (abs(drive::left_front.getActualVelocity()) != 2500) {

    if (direction == "right") {
      drive::accelDrive.deAccelMath(accel, &drive::left_strafe, 10,
                                    velocity * .7);
      drive::accelDrive.deAccelMath(accel, &drive::right_strafe, -10,
                                    velocity * .7);
    } else if (direction == "left") {
      drive::accelDrive.deAccelMath(accel, &drive::left_strafe, -10,
                                    velocity * .7);
      drive::accelDrive.deAccelMath(accel, &drive::right_strafe, 10,
                                    velocity * .7);
    }
    if (abs(drive::left_front.getPosition()) >= distance) {
      std::cout << " break early " << drive::left_front.getPosition()
                << std::endl;
      break;
    }
    pros::delay(drive::deAccelDrive.rateOfChange);
  }
  reset();
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
  int epsilon = velocity * 1.125;
  while (abs(drive::left_front.getPosition()) <= turnAmount - epsilon) {
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
  // std::cout << "accelFinish<<" << std::endl;
  reset();
  if (abs(drive::driveGroup.getActualVelocity()) < abs(velocity)) {
    if (direction == "left") {
      drive::left_drive.moveVelocity(-velocity);
      drive::right_drive.moveVelocity(velocity);
    } else if (direction == "right") {
      drive::left_drive.moveVelocity(velocity);
      drive::right_drive.moveVelocity(-velocity);
    }
    pros::delay(10);
  }
  // std::cout << "slowing<<" << std::endl;
  while (abs(drive::left_front.getActualVelocity()) != 12349) {

    if (direction == "left") {
      drive::accelDrive.deAccelMath(accel, &drive::left_drive, -20,
                                    velocity * .4);
      drive::accelDrive.deAccelMath(accel, &drive::right_drive, 20,
                                    velocity * .4);
    } else if (direction == "right") {
      drive::accelDrive.deAccelMath(accel, &drive::left_drive, 20,
                                    velocity * .4);
      drive::accelDrive.deAccelMath(accel, &drive::right_drive, -20,
                                    velocity * .4);
    }
    if (abs(drive::left_front.getPosition()) >= turnAmount) {
      std::cout << " break early " << drive::left_front.getPosition()
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
