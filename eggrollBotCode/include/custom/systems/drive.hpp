#ifndef DRIVE_HPP
#define DRIVE_HPP
#include "okapi/api.hpp"

namespace drive{

  void tankDrive(void);
  // void brakeMode(void);
  //25 outake and drive
  namespace auton{
    void resetPositions(void);
    void stackMacro(double backup, double speed);
    void autonDrive(double distance, double targetVelocity);
    void turn(double amount, double targetVelocity);
  }
}
#endif
