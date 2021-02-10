#ifndef DRIVE_HPP
#define DRIVE_HPP
#include "main.h"
namespace drive {
void brake(void);
void userDrive(void);
} // namespace drive
namespace auton {
extern pros::Rotation sTracker;
void sCorrect(int reqAng);
void drive(double distance, int velocity);
void clampDrive(double distance, double clampDistance, int velocity);
void strafe(int distance, int velocity, std::string direction);
void turn(double turnAmount, int velocity, std::string direction);
void swingTurn(int turnAmount, int velocity, std::string direction);
extern pros::Rotation sTracker; // rotation sensors
extern pros::Rotation leftTracker;
extern pros::Rotation rightTracker;
} // namespace auton
#endif /* end of include guard: DRIVE_HPP */
