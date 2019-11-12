#ifndef LIFT_HPP
#define LIFT_HPP

namespace lift
{
enum class Controllers
{
  UP,
  DOWN,
  DEINIT,
  NONE
};
void init(void);
void execute(void);
namespace auton
{
void popOpen();
void autonLiftDown(double wantedPosition, double targetVelocity);
} // namespace auton
} // namespace lift

#endif /* end of include guard: LIFT_HPP */
