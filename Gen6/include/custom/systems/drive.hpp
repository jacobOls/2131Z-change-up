#ifndef DRIVE_HPP
#define DRIVE_HPP

namespace drive{
  void userDrive(void);
  enum class Controllers{
DRIVE,
DEINIT,
NONE
  };
  namespace auton{
    void drive(int distance, int velocity);
    void turn(int deg, int velocity);
  }
}

#endif /* end of include guard: DRIVE_HPP */
