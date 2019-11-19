#ifndef TILTER_HPP
#define TILTER_HPP

namespace tilter
{
enum class Controllers
{
    FORWARD,
    BACKWARD,
    RETURN,
    DEINIT,
    TOUP,
    LIFTDOWN,
    NONE
};
void execute(void);
void init(void);
extern bool trayLock;
namespace auton
{
void trayDown(double wantedPosition, double targetVelocity);
void stack(double wantedPosition, double targetVelocity);
} // namespace auton
} // namespace tilter

#endif /* end of include guard: TILTER_HPP */
