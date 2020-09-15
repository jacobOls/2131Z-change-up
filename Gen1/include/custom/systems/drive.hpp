#ifndef DRIVE_HPP
#define DRIVE_HPP
#include "main.h"
namespace drive {
enum class Left { STRAIGHT, STRAFE, NONE };
enum class Right { STRAIGHT, STRAFE, NONE };
void userDrive(void);
} // namespace drive
namespace auton {
void drive(int distance, int velocity);
void strafe(int distance, int velocity, std::string direction);
void turn(int turnAmount, int velocity, std::string direction);
} // namespace auton
#endif /* end of include guard: DRIVE_HPP */
