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
    void driveNRE(int distance, int velocity);
    void driveNRB(int distance, int velocity);

    void turn(int deg, int velocity);
    void resetPos(void);
  }
}

#endif /* end of include guard: DRIVE_HPP */
