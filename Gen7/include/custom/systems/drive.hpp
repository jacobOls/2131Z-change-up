#ifndef DRIVE_HPP
#define DRIVE_HPP

namespace drive {
void userDrive(void);

void exDrive(int vel, int distance);  // eponential ramping drive
void linDrive(int vel, int distance); // linear ramping drive
void swingTurnLeft(int distance, int velocity, int rVel);
void swingTurnRight(int distance, int velocity, int lVel);
void leftTurn(int deg, int velocity);
void rightTurn(int deg, int velocity);

} // namespace drive

#endif /* end of include guard: DRIVE_HPP */
