#ifndef INTAKE_HPP
#define INTAKE_HPP
#include "main.h"
namespace intake {
enum class State { IN, OUT, DEINIT, MANUAL, NONE };
void init(void);
extern ADIButton leftIntake;
extern ADIButton rightIntake;
} // namespace intake
namespace auton {
void runIntake(int velocity);
void open(void);
void release(void);
} // namespace auton
#endif /* end of include guard: INTAKE_HPP */
