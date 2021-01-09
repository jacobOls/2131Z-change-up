#ifndef ODOM_HPP
#define ODOM_HPP
#include "main.h"
#include <cmath>
#include <mutex>
void posCalc();

struct Pos {
  double &x;
  double &y;
  double &r;
};

class PosGuard {
private:
  pros::Mutex mtx;

public:
  double &x;
  double &y;
  double &r;
  PosGuard(pros::Mutex &mtx, double &x, double &y, double &r);
  ~PosGuard();
  PosGuard(const PosGuard &) = delete;
  PosGuard &operator=(const PosGuard &) = delete;
  PosGuard(PosGuard &&) = default;
};

class PosTracking {
  static pros::Mutex mtx;
  static double lazyX;
  static double lazyY;
  static double lazyR;
  static double strictX;
  static double strictY;
  static double strictR;
  static void update_lazy();

public:
  static Pos pos();

  static PosGuard strict_pos();
};
#endif /* end of include guard: ODOM_HPP */
