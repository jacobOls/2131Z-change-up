#ifndef TRAY_HPP
#define TRAY_HPP

namespace tray
{
  // enum class Contollers{FORWARD,BACKWARD,DEINT,NONE};
  void tray(void);
  void execute(void);
  void tilter(void);
  namespace auton
  {
    void stack(double tiltPosition, double targetVelocity);
  }
}


#endif /* end of include guard: TRAY_HPP */
