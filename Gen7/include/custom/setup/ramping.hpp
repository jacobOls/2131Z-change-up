#ifndef RAMPING_HPP
#define RAMPING_HPP

class ramping {
public:
  int roc; // rate of change
  int cv;  // change value
  int min, max;

  ramping(int changeRate, int changeVal, int minimum, int maximum);
};

#endif /* end of include guard: RAMPING_HPP */
