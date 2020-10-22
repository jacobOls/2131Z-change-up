#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP

namespace elevator {
enum class State { IN, OUT, DOWN, UP, BACK, DEINIT, NONE };
void init(void);
// void runWheel(int velocity);
} // namespace elevator
namespace auton {
void runElevator(int velocity);
void back(int velocity);
} // namespace auton
#endif /* end of include guard: ELEVATOR_HPP */
