#ifndef TRAY_HPP
#define TRAY_HPP

namespace tray{
  enum class Controllers{FORWARD,BACKWARD,DEINT,NONE,LIFT};
  void tray(void);
  void execute(void);
  void tilter(void);
  namespace auton{
    void stack(double tiltPosition, double targetVelocity);
  }
}


#endif /* end of include guard: TRAY_HPP */
