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
    void driveNR(int distance, int velocity);
    void turn(int deg, int velocity);
    void resetPos(void);
    void swingTurnLeft(int distance, int velocity);
    void swingTurnRight(int distance, int velocity);
  }
}

#endif /* end of include guard: DRIVE_HPP */
