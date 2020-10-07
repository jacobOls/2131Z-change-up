#include "custom/systems/vision.hpp"
#include "main.h"
namespace vision {
pros::Vision colorSensor(1);

void init() {
  colorSensor.signature_from_utility(1, 4953, 6495, 5724, -303, 259, -22, 3.000,
                                     0); // red ball
  colorSensor.signature_from_utility(2, -3551, -2285, -2918, 7295, 15009, 11152,
                                     3.000, 0); // blue ball

  pros::vision_object_s_t rtn = colorSensor.get_by_sig(0, 1);
}
} // namespace vision
