#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP
#include "main.h"
namespace elevator {
enum class State { IN, OUT, DOWN, UP, BACK, DEINIT, MID, AUTO, FOO, NONE };
void init(void);
void initVision(void);
void autoRatchet(void);
void toggle();
extern bool red;
// void runWheel(int velocity);
} // namespace elevator
namespace auton {
extern pros::Distance disSense;
void runElevator(int velocity);
void autoBack(int delay);
void eject();
void score(void);
void scoreControlled(int vel);
void scoreUntil(bool color);
void ratchetUntil(bool color, int vel);
void load();
} // namespace auton
#endif /* end of include guard: ELEVATOR_HPP */
