#include "custom/systems/vision.hpp"
#include "main.h"
namespace vision {
pros::Vision visionSensor(11);
void init() {
  visionSensor.set_wifi_mode(0);
  pros::vision_signature_s_t RED_BALL = visionSensor.signature_from_utility(
      1, 4953, 6495, 5724, -303, 259, -22, 3.000, 0);
  pros::vision_signature_s_t BLUE_BALL = visionSensor.signature_from_utility(
      2, -3551, -2285, -2918, 7295, 15009, 11152, 3.000, 0);
}
void execute() {
  pros::vision_object_s_t rtn = visionSensor.get_by_sig(0, 1);
  pros::vision_object_s_t rtn2 = visionSensor.get_by_sig(0, 2);
  int n = visionSensor.get_object_count();
  std::cout << rtn.signature << std::endl;
}
} // namespace vision
