#ifndef DRIVE_HPP
#define DRIVE_HPP

namespace drive {
void userDrive(void);

void exDrive(int distance, int vel);  // eponential ramping drive
void linDrive(int distance, int vel); // linear ramping drive
void swingTurnLeft(int distance, int velocity, int rVel);
void swingTurnRight(int distance, int velocity, int lVel);
void leftTurn(int deg, int velocity);
void rightTurn(int deg, int velocity);
void noRampEnd(int distance, int vel);

} // namespace drive

#endif /* end of include guard: DRIVE_HPP */
