#ifndef DRIVE_HPP
#define DRIVE_HPP

namespace drive
{
void drive(void);

namespace auton
{
void driving(int distance, int velocity);
void rightTurn(double distance, double velocity);
void leftTurn(double distance, double velocity);
} // namespace auton
} // namespace drive

#endif /* end of include guard: DRIVE_HPP */
