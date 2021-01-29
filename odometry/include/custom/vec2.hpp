#ifndef VEC2_H
#define VEC2_H
#include <cmath>

struct Vec2 {
  double x;
  double y;

  static Vec2 from_mag_dir(double mag, double dir) {
    return Vec2{mag * cos(dir), mag * sin(dir)};
  }

  Vec2 scale(double b) const { return Vec2{this->x * b, this->y * b}; }

  Vec2 operator+(const Vec2 &other) const {
    return Vec2{this->x + other.x, this->y + other.y};
  }

  Vec2 operator-(const Vec2 &other) const {
    return Vec2{this->x - other.x, this->y - other.y};
  }

  Vec2 operator*(double b) const { return this->scale(b); }

  Vec2 operator/(double b) const { return Vec2{this->x / b, this->y / b}; }

  Vec2 &operator+=(const Vec2 &other) {
    *this = *this + other;
    return *this;
  }

  Vec2 &operator-=(const Vec2 &other) {
    *this = *this - other;
    return *this;
  }

  Vec2 &operator*=(double b) {
    *this = *this * b;
    return *this;
  }

  Vec2 &operator/=(double b) {
    *this = *this / b;
    return *this;
  }

  double mag() const { return sqrt((this->x * this->x) + (this->y * this->y)); }

  Vec2 normalized() const {
    double mag = this->mag();
    return Vec2{this->x / mag, this->y / mag};
  }

  double dir() const { return atan2(this->y, this->x); }

  double dir_to(const Vec2 &other) const { return (other - *this).dir(); }

  double angle_between(const Vec2 &other) const {
    return acos((this->mul_dot(other) / (this->mag() * other.mag())));
  }

  double mul_dot(const Vec2 &other) const {
    return (this->x * other.x) + (this->y * other.y);
  }

  bool operator==(const Vec2 &other) const {
    return (this->x == other.x) && (this->y == other.y);
  }
};

inline Vec2 operator*(double a, const Vec2 &b) { return b * a; }

#endif
