#ifndef DRIVE_HPP
#define DRIVE_HPP
#include "main.h"
namespace drive {
void brake(void);
void userDrive(void);
} // namespace drive
namespace auton {
extern pros::Rotation sTracker;
extern pros::Rotation rTracker;
extern pros::Rotation lTracker;
void sCorrect(int reqAng);
void drive(int distance, int velocity);
void driveNE(int distance, int velocity);
void strafe(int distance, int velocity, std::string direction);
void timeStrafe(int voltage, int time, std::string direction);
void turn(int turnAmount, int velocity, std::string direction);
} // namespace auton
#endif /* end of include guard: DRIVE_HPP */