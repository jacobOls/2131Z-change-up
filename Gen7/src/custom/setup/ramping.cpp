#include "custom/setup/ramping.hpp"
#include "main.h"

ramping::ramping(int changeRate, int changeVal, int minimum, int maximum) {

  roc = changeRate;
  cv = changeVal;
  min = minimum;
  max = maximum;
}
