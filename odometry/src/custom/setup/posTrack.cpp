#include "custom/setup/motors.hpp"
#include "custom/setup/odom.hpp"
#include "main.h"
#include <cmath>
PosGuard::PosGuard(pros::Mutex &mtx, double &x, double &y, double &r)
    : mtx(mtx), x(x), y(y), r(r) {
  this->mtx.take(666);
}
PosGuard::~PosGuard() { mtx.give(); }
void PosTracking::update_lazy() {
  mtx.take(666);
  PosTracking::lazyX = PosTracking::strictX;
  PosTracking::lazyY = PosTracking::strictY;
  PosTracking::lazyR = PosTracking::strictR;
  mtx.give();
}
Pos PosTracking::pos() {
  PosTracking::update_lazy();
  return Pos{.x = PosTracking::lazyX,
             .y = PosTracking::lazyY,
             .r = PosTracking::lazyR};
}

PosGuard PosTracking::strict_pos() {
  return PosGuard(PosTracking::mtx, PosTracking::strictX, PosTracking::strictY,
                  PosTracking::strictR);
}
