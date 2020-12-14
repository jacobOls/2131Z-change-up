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
void drive(int distance, int velocity);
void driveNE(int distance, int velocity);
void clampDrive(int distance, int clampDistance, int velocity);
void strafe(int distance, int velocity, std::string direction);
void timeStrafe(int voltage, int time, std::string direction);
void turn(int turnAmount, int velocity, std::string direction);
void straightLineup(int distance);
} // namespace auton
#endif /* end of include guard: DRIVE_HPP */
