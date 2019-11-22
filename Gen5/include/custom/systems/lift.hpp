#ifndef LIFT_HPP
#define LIFT_HPP
namespace lift{

enum class Controllers
{
  UP,
  DOWN,
  DEINIT,
  NONE
};
void init(void);
void execute(void);
void init(void);
namespace auton{
  void lift(double pos, double velocity);
}
}


#endif /* end of include guard: LIFT_HPP */
