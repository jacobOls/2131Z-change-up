#ifndef DRIVE_HPP
#define DRIVE_HPP

namespace drive {
void userDrive(void);
enum class Controllers { DRIVE, DEINIT, NONE };
namespace auton {
void drive(int distance, int velocity);
void driveVolt(int startTime, int time, int velocity);
void driveNRE(int distance, int velocity);
void driveNRB(int distance, int velocity);
void driveNR(int distance, int velocity);
void turn(int deg, int velocity);
void resetPos(void);
void swingTurnLeft(int distance, int velocity, int rVel);
void swingTurnRight(int distance, int velocity, int lVel);
} // namespace auton
} // namespace drive

#endif /* end of include guard: DRIVE_HPP */
