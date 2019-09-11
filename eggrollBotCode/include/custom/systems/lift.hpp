#ifndef LIFT_HPP
#define LIFT_HPP
namespace lift{
  void lift(void);

  double getPosition();

  namespace auton{

    void autonLift(double position, double targetVelocity);
    void popOpen(void);
  }
}


#endif /* end of include guard: LIFT_HPP */
