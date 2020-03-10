#ifndef TILTER_HPP
#define TILTER_HPP

namespace tilter {
enum class State { UP, DOWN, RETURN, DEINIT, NONE };
void init(void);
void tilt(int pos, int vel);
void stack(int pos, int time);
} // namespace tilter

#endif /* end of include guard: TILTER_HPP */