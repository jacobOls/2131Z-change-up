#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP

namespace elevator {
enum class State { IN, OUT, DOWN, UP, BACK, DEINIT, MID, AUTO, FOO, NONE };
void init(void);
void initVision(void);
void autoRatchet(void);
// void runWheel(int velocity);
} // namespace elevator
namespace auton {
void runElevator(int velocity);
void autoBack(int delay);
void eject();
void score(void);
} // namespace auton
#endif /* end of include guard: ELEVATOR_HPP */
