#include "okapi/api/device/button/buttonBase.hpp"

namespace okapi {
ButtonBase::ButtonBase(const bool iinverted) : inverted(iinverted) {
}

bool ButtonBase::isPressed() {
  return currentlyPressed();
}

bool ButtonBase::changed() {
  return changedImpl(wasPressedLast_c);
}

bool ButtonBase::changedToPressed() {
  return changedImpl(wasPressedLast_ctp) && wasPressedLast_ctp;
}

bool ButtonBase::changedToReleased() {
  return changedImpl(wasPressedLast_ctr) && !wasPressedLast_ctr;
}

bool ButtonBase::changedImpl(bool &prevState) {
  static bool out;
  if(currentlyPressed() != prevState)  out=true;
  else                      out=false;
  prevState = currentlyPressed();
  return out;
}
} // namespace okapi
