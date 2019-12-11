#ifndef DRIVE_HPP
#define DRIVE_HPP
namespace drive{
void drive(void);

namespace auton{
void driving(int distance, int speed);
void turn(int deg, int velocity);
void resetPositions();
void driveVolt(int distance, int volts);
}
}
#endif /* end of include guard: DRIVE_HPP */
