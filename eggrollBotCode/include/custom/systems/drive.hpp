#ifndef DRIVE_HPP
#define DRIVE_HPP
#include "okapi/api.hpp"

namespace drive{
  void tankDrive(void);
  // void brakeMode(void);
  //25 outake and drive
  namespace auton{
    void resetPositions(void);
    void autonDrive(double distance, double targetVelocity);
    void autonDriveBack(double distance, double targetVelocity);
    void leftTurn(double amount, double targetVelocity);
    void rightTurn(double amount, double targetVelocity);
  }
}
#endif
