#include "custom/systems/drive.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "main.h"
namespace drive {
pros::Vision lineSet(4);
void initVision() {
  pros::Vision lineSet(4, pros::E_VISION_ZERO_CENTER);
  lineSet.set_wifi_mode(0);
  pros::vision_signature_s_t RED_BALL = lineSet.signature_from_utility(
      1, 4953, 6495, 5724, -303, 259, -22, 3.000, 0);
  pros::vision_signature_s_t BLUE_BALL = lineSet.signature_from_utility(
      2, -3551, -2285, -2918, 7295, 15009, 11152, 1.500, 0);
}
// retrieve and transform input values of analogs
int flX() { return (master.getAnalog(okapi::ControllerAnalog::leftX)) * 200; };
int flY() { return (master.getAnalog(okapi::ControllerAnalog::leftY)) * 100; };
int blX() { return (master.getAnalog(okapi::ControllerAnalog::leftX)) * 200; };
int blY() { return (master.getAnalog(okapi::ControllerAnalog::leftY)) * 100; };
int frX() { return (master.getAnalog(okapi::ControllerAnalog::rightX)) * 200; };
int frY() { return (master.getAnalog(okapi::ControllerAnalog::rightY)) * 100; };
int brX() { return (master.getAnalog(okapi::ControllerAnalog::rightX)) * 200; };
int brY() { return (master.getAnalog(okapi::ControllerAnalog::rightY)) * 100; };
// decides what to return for motors velocity
int flVal() {
  if (abs(flX()) > abs(flY()) * 2) {
    return flX();
  } else if (abs(brY()) > abs(brX()) && abs(flX()) < abs(flY()) * 2) {
    return flY() + brY();
  } else {
    return flY();
  }
};
int blVal() {
  if (abs(blX()) > abs(blY()) * 2) {
    return blX();
  } else if (abs(frY()) > abs(frX()) && abs(blX()) < abs(blY()) * 2) {
    return blY() - frY();
  } else {
    return blY();
  }
};
int brVal() {
  if (abs(brX()) > abs(brY()) * 2) {
    return brX();
  } else if (abs(flY()) > abs(flX()) && abs(brX()) < abs(brY()) * 2) {
    return flY() + brY();
  } else {
    return brY();
  }
};
int frVal() {
  if (abs(frX()) > abs(frY()) * 2) {
    return frX();
  } else if (abs(blY()) > abs(blX()) && abs(frX()) < abs(frY()) * 2) {
    return blY() - frY();
  } else {
    return frY();
  }
};
// sets motor velocity
int dz = 5; // dead zone
void userDrive() {
  if (abs(flVal()) > dz) {
    leftFront.moveVelocity(flVal());
  } else
    leftFront.moveVelocity(0);
  if (abs(blVal()) > dz) {
    leftBack.moveVelocity(blVal());
  } else
    leftBack.moveVelocity(0);
  if (abs(frVal()) > dz) {
    rightFront.moveVelocity(frVal());
  } else
    rightFront.moveVelocity(0);
  if (abs(brVal()) > dz) {
    rightBack.moveVelocity(brVal());
  } else
    rightBack.moveVelocity(0);
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

bool inRangeX(int x) { return (x > -5) && (x < 5); };

bool inRangeY(int y) { return (y > -5) && (y < 5); };
pros::vision_object_s_t vert = drive::lineSet.get_by_sig(0, 1);
pros::vision_object_s_t hori = drive::lineSet.get_by_sig(0, 1);
int y() { return vert.top_coord; };
int x() { return hori.left_coord; };

void lineUp() {
  while (!inRangeX(x()) && !inRangeY(y())) {
    while (y() > 5) {
      drive::driveGroup.moveVelocity(-y());
    }
    drive::driveGroup.moveVelocity(0);
    while (y() < -5) {
      drive::driveGroup.moveVelocity(y());
    }
    drive::driveGroup.moveVelocity(0);
    while (x() > 5) {
      drive::left_strafe.moveVelocity(-x());
      drive::right_strafe.moveVelocity(x());
    }
    drive::driveGroup.moveVelocity(0);
    while (x() < -5) {
      drive::left_strafe.moveVelocity(x());
      drive::right_strafe.moveVelocity(-x());
    }
    drive::driveGroup.moveVelocity(0);
  }
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
