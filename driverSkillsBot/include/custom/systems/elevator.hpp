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
#endif /* end of include guard: ELEVATOR_HPP */
