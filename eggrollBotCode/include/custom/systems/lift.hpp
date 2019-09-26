#ifndef LIFT_HPP
#define LIFT_HPP
namespace lift{
  enum class Controllers{UP,DOWN,NONE,DEINIT,MIDTOWER,LOWTOWER,};
  void lift(void);

  double getPosition();

  namespace auton{

    void autonLift(double targetPosition, double targetVelocity);
    void popOpen(void);
  }
}


#endif /* end of include guard: LIFT_HPP */
