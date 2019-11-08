#ifndef DRIVE_HPP
#define DRIVE_HPP

namespace drive
{
void drive(void);
void init(void);
namespace auton
{
void driving(int distance, int velocity);
void driveBack(double distance, double velocity);
  void rightTurn(double distance, double velocity);
void leftTurn(double distance, double velocity);
} // namespace auton
} // namespace drive

#endif /* end of include guard: DRIVE_HPP */
