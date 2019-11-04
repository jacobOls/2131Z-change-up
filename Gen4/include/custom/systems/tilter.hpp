#ifndef TILTER_HPP
#define TILTER_HPP

namespace tilter
{
enum class Controllers
{
    UP,
    DOWN,
    RETURN,
    DEINIT,
    NONE
};
void init(void);
namespace auton{
 void trayDown(double wantedPosition, double targetVelocity);
 void stack(double wantedPosition, double targetVelocity);
}
} // namespace tilter

#endif /* end of include guard: TILTER_HPP */
