#ifndef DRIVE_HPP
#define DRIVE_HPP
namespace drive{
void drive(void);

namespace auton{
void driving(int distance, int speed);
void turn(int deg, int velocity);
void resetPositions();
void driveVolt(int distance);
}
}
#endif /* end of include guard: DRIVE_HPP */
