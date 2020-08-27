#ifndef WHEEL_HPP
#define WHEEL_HPP

namespace wheel {
enum class State { IN, OUT, UNJAM, BACK, DEINIT, NONE };
void init(void);
// void runWheel(int velocity);
} // namespace wheel

#endif /* end of include guard: WHEEL_HPP */
