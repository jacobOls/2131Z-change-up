#include "custom/systems/drive.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
#include "custom/setup/ramping.hpp"
#include "custom/systems/intake.hpp"
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
int rY() { return (master.getAnalog(okapi::ControllerAnalog::rightY)) * 200; };
int lY() { return (master.getAnalog(okapi::ControllerAnalog::leftY)) * 200; };

int lX() { return (master.getAnalog(okapi::ControllerAnalog::leftX)) * 200; };
int rX() { return (master.getAnalog(okapi::ControllerAnalog::rightX)) * 200; };
int stVal() {
   return ((lX() + rX()) / 2); };
int flVal() { return abs(lY()) > abs(lX() + .3) ? lY() : lY() + stVal(); };
int blVal() { return abs(lY()) > abs(lX() + .3) ? lY() :  lY() - stVal(); };
int brVal() { return abs(rY()) > abs(rX() + .3) ? rY() :  rY() + stVal(); };
int frVal() { return abs(rY()) > abs(rX() + .3) ? rY() :  rY() - stVal(); };
// sets motor velocity
int dz = .05 * 200; // dead zone
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
//   if(abs(lY()) > dz){
//     left_drive.moveVelocity(lY());
//   } else{ left_drive.moveVelocity(0);}
//   if(abs(rY()) > dz){
//     right_drive.moveVelocity(rY());
//   } else{right_drive.moveVelocity(0);}
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
int vel;
std::string velocity;
void velCheck() {
  vel = drive::rightBack.getActualVelocity();
  std::string velocity = std::to_string(vel);
  pros::lcd::set_text(1, velocity);
  pros::delay(20);
  // pros::lcd::clear_line(1);
  // pros::lcd::clear_line(2);
}
// 250 corner towers
// 350 middle towers
pros::Rotation sTracker(19); // rotation sensors
pros::Rotation leftTracker(17);
pros::Rotation rightTracker(8);
double lEnc2Inch() { // conversion 2 inches
  return (leftTracker.get_position() / 36000) * (M_PI * 2.75);
}
double rEnc2Inch() {
  return (rightTracker.get_position() / 36000) * (M_PI * 2.75);
}
double avg2Inch() { return (lEnc2Inch() + rEnc2Inch()) / 2; }
int track() {
  return abs((rightTracker.get_position()) +
             abs(leftTracker.get_position()) / 2);
}
int turnTrack() {
  return abs(rightTracker.get_position()) + abs(leftTracker.get_position()) / 2;
};
void driveNoRamp(double distance, int velocity) {
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
  leftTracker.set_reversed(true);
  leftTracker.set_position(0);
  rightTracker.set_position(0);
  int req = 5;
  while (track() <= abs((distance))) {
    drive::driveGroup.moveVelocity(velocity);
    if (track() >= distance) {
      break;
    }
  }
  std::cout << "end " << drive::driveGroup.getPosition() << std::endl;
  std::cout << "vel " << drive::leftFront.getActualVelocity() << std::endl;
  reset();
  drive::driveGroup.moveVelocity(0);
  drive::driveGroup.moveVelocity(0);
  leftTracker.reset();
  rightTracker.reset();
  drive::driveGroup.tarePosition();
}
void drive(double distance, int velocity) {
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
  leftTracker.set_position(0);
  rightTracker.set_position(0);
  distance = (distance * 36000) / (M_PI * 2.75);
  double multiplier = velocity > 0 ? 282.1 : 110;
  double epsilon = abs(velocity) * multiplier;
  int req = 10;
  while (track() <= abs((distance)) - epsilon) {
    if (track() >= distance - epsilon) {
      break;
    }
    std::cout << track() << std::endl;
    drive::accelDrive.accelMath(accel, &drive::driveGroup, velocity);
  }
  std::cout << "stopping " << track() << std::endl;
  reset();
  while (track() <= distance) {
    if (velocity < 0 && req > 0) {
      req *= -1;
    }
    drive::deAccelDrive.deAccelMath(accel, &drive::driveGroup, req,
                                    drive::driveGroup.getActualVelocity());

    if (track() >= distance) {
      std::cout << " break early " << drive::driveGroup.getPosition()
                << std::endl;
      break;
    }
    pros::delay(drive::deAccelDrive.rateOfChange);
    if (track() >= distance) {
      std::cout << " break early " << drive::driveGroup.getPosition()
                << std::endl;
      break;
    }
  }
  std::cout << "end " << drive::driveGroup.getPosition() << std::endl;
  std::cout << "vel " << drive::leftFront.getActualVelocity() << std::endl;
  reset();
  drive::driveGroup.moveVelocity(0);
  drive::driveGroup.tarePosition();
}
void clampDrive(double distance, double clampDistance, int velocity) {
  // open();
  bool released = false;
  intake::intakeGroup.setBrakeMode(AbstractMotor::brakeMode::hold);
  intake::intakeGroup.moveVelocity(-200);
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
  rightTracker.set_position(0);
  leftTracker.set_position(0);
  distance = (distance * 36000) / (M_PI * 2.75);
  clampDistance = (clampDistance * 36000) / (M_PI * 2.75);
  double multiplier = velocity > 0 ? 242.1 : 242.2;
  double epsilon = abs(velocity) * multiplier;
  int req = 10;
  while (track() <= abs((distance)) - epsilon) {
    if (intake::leftIntake.isPressed()) {
      intake::left_motor.moveVelocity(0);
    }
    if (intake::rightIntake.isPressed()) {
      intake::right_motor.moveVelocity(0);
    }
    if (track() >= clampDistance && released == false) {
      release();
      released = true;
    }
    if (track() >= distance - epsilon) {
      break;
    }
    drive::accelDrive.accelMath(accel, &drive::driveGroup, velocity);
  }

  std::cout << "stopping " << drive::driveGroup.getPosition() << std::endl;
  reset();
  while (drive::driveGroup.getActualVelocity() != 5000) {
    if (velocity < 0 && req > 0) {
      req *= 1;
    }
    if (track() >= clampDistance && released == false) {
      release();
      released = true;
    }
    drive::deAccelDrive.deAccelMath(accel, &drive::driveGroup, req,
                                    drive::driveGroup.getActualVelocity());
    if (track() >= distance) {
      std::cout << " break early " << drive::driveGroup.getPosition()
                << std::endl;
      break;
    }
    pros::delay(drive::deAccelDrive.rateOfChange);
  }
  std::cout << "end " << drive::driveGroup.getPosition() << std::endl;
  std::cout << "vel " << drive::leftFront.getActualVelocity() << std::endl;
  reset();
  released = false;
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
    drive::accelDrive.strafeAccel(accel, &drive::left_strafe, velocity);
    drive::accelDrive.strafeAccel(accel, &drive::right_strafe, -velocity);
    pros::delay(drive::accelDrive.rateOfChange);
  }
  reset();
  if (abs(drive::leftFront.getPosition()) < abs(velocity)) {
    drive::left_strafe.moveVelocity(velocity);
    drive::right_strafe.moveVelocity(-velocity);

    pros::delay(10);
  }
  while (abs(drive::leftFront.getPosition()) != 2500) {

    drive::accelDrive.deAccelMath(accel, &drive::left_strafe, request,
                                  velocity * .5);
    drive::accelDrive.deAccelMath(accel, &drive::right_strafe, -request,
                                  velocity * .5);

    if (abs(drive::leftFront.getPosition()) >= distance) {
      std::cout << " break early " << sTracker.get_position() << std::endl;
      break;
    }
    pros::delay(drive::deAccelDrive.rateOfChange);
  }
  reset();
  if (direction == "left") {
    request *= -1;
    velDir = false;
  }
  std::cout << drive::leftFront.getPosition() << std::endl;
  drive::left_strafe.moveVelocity(0);
  drive::right_strafe.moveVelocity(0);
  sTracker.reset_position();
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
  rightTracker.set_position(0);
  leftTracker.set_position(0);
  int epsilon = velocity * 40;
  turnAmount = (turnAmount * 100) * 3.16;
  reset();
  if (direction == "left") {
    velocity *= -1;
    turnReq *= -1;
  }
  while (turnTrack() <= turnAmount - epsilon) {
    drive::accelDrive.accelMath(accel, &drive::left_drive, velocity);
    drive::accelDrive.accelMath(accel, &drive::right_drive, -velocity);
    pros::delay(drive::accelDrive.rateOfChange);
  }
  // std::cout << "accelFinish<<" << std::endl;
  reset();

  // std::cout << "slowing<<" << std::endl;
  while (abs(drive::leftFront.getActualVelocity()) != 12349) {

    drive::accelDrive.deAccelMath(accel, &drive::left_drive, turnReq,
                                  drive::left_drive.getActualVelocity() * .4);
    drive::accelDrive.deAccelMath(accel, &drive::right_drive, -turnReq,
                                  drive::right_drive.getActualVelocity() * .4);
    if (turnTrack() >= turnAmount) {
      std::cout << " break early " << drive::leftFront.getPosition()
                << std::endl;
      break;
    }
    pros::delay(drive::accelDrive.rateOfChange);
  }
  reset();
  sTracker.reset();
  if (direction == "left") {
    turnReq *= -1;
  }
  std::cout << drive::left_drive.getPosition() << std::endl;
  drive::left_drive.moveVelocity(0);
  drive::right_drive.moveVelocity(0);
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
}

void swingTurn(int turnAmount, int velocity, std::string direction) {
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
  sTracker.set_position(0);
  int epsilon = velocity * 40;
  turnAmount = (turnAmount * 100) * 3.16;
  reset();
  if (direction == "left") {
    velocity *= -1;
    turnReq *= -1;
  }
  while (abs(sTracker.get_position()) <= turnAmount - epsilon) {
    drive::accelDrive.accelMath(accel, &drive::left_drive, velocity);
    // drive::accelDrive.accelMath(accel, &drive::right_drive, -velocity);
    pros::delay(drive::accelDrive.rateOfChange);
  }
  // std::cout << "accelFinish<<" << std::endl;
  reset();

  if (abs(drive::driveGroup.getActualVelocity()) < abs(velocity)) {
    // drive::left_drive.moveVelocity(-velocity);
    drive::right_drive.moveVelocity(velocity);
    pros::delay(10);
  }
  // std::cout << "slowing<<" << std::endl;
  while (abs(drive::leftFront.getActualVelocity()) != 12349) {

    // drive::accelDrive.deAccelMath(accel, &drive::left_drive, turnReq,
    // velocity * .4);
    drive::accelDrive.deAccelMath(accel, &drive::right_drive, -turnReq,
                                  velocity * .4);
    if (abs(sTracker.get_position()) >= turnAmount) {
      std::cout << " break early " << drive::leftFront.getPosition()
                << std::endl;
      break;
    }
    pros::delay(drive::accelDrive.rateOfChange);
  }
  reset();
  sTracker.set_position(0);
  if (direction == "left") {
    turnReq *= -1;
  }
  std::cout << drive::left_drive.getPosition() << std::endl;
  drive::left_drive.moveVelocity(0);
  drive::right_drive.moveVelocity(0);
  drive::left_drive.tarePosition();
  drive::right_drive.tarePosition();
}
} // namespace auton
