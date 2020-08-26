#ifndef DRIVE_HPP
#define DRIVE_HPP
namespace drive {
enum class Side { STRAIGHT, STRAFE, NONE };
enum class State {
  LEFTSTRAFE,
  LEFTSTRAIGHT,
  RIGHTSTRAFE,
  RIGHTSTRAIGHT,
  DEINIT,
  NONE
};
void userDrive(void);
} // namespace drive
#endif /* end of include guard: DRIVE_HPP */
