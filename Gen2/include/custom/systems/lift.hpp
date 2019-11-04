#ifndef LIFT_HPP
#define LIFT_HPP
namespace lift{
  enum class Controllers{UP,DOWN,NONE,DEINIT,BOTTOM};
  void lift(void);
void execute();
  double getPosition();

  namespace auton{

    void autonLiftUp(double targetPosition, double targetVelocity);
    void autonLiftDown(double wantedPosition, double targetVelocity);
    void popOpen(void);
  }
}


#endif /* end of include guard: LIFT_HPP */
