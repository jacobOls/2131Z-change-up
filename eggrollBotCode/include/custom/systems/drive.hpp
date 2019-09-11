#ifndef DRIVE_HPP
#define DRIVE_HPP
#include "okapi/api.hpp"

namespace drive{

  void tankDrive(void);
  void brakeMode(void);
  namespace auton{

    void autonDrive(double distance, double targetVelocity);
    void turn(double amount, double targetVelocity);
  }
}
#endif
