#ifndef INTAKE_HPP
#define INTAKE_HPP

namespace intake {
enum class State { IN, OUT, DEINIT, NONE };
void init(void);
void runIntake(int velocity);
} // namespace intake

#endif /* end of include guard: INTAKE_HPP */
