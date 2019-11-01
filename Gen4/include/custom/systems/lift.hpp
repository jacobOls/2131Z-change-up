#ifndef LIFT_HPP
#define LIFT_HPP

namespace lift
{
enum class Controllers
{
    UP,
    DOWN,
    LOWT,
    MIDT,
    DEINIT,
    NONE
};
void init(void);
} // namespace lift

#endif /* end of include guard: LIFT_HPP */
