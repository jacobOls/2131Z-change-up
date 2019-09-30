#ifndef TRAY_HPP
#define TRAY_HPP

namespace tray{
  enum class Controllers{FORWARD,BACKWARD,DEINIT,NONE,LIFT,RETURN,TRAVELBACK};
  void tray(void);
  void execute(void);
  void tilter(void);
  void ramping(void);
  namespace auton{
    void stack(double targetPosition, double targetVelocity);
  }
}


#endif /* end of include guard: TRAY_HPP */
