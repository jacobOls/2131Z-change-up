#ifndef LIFT_HPP
#define LIFT_HPP
namespace lift {
enum class State { UP, DOWN, RECYCLE, DEINIT, NONE };
void init(void);
void lift(int pos, int vel);
void liftTimed(int pos, int vel, int time);
} // namespace lift
#endif /* end of include guard: LIFT_HPP */
