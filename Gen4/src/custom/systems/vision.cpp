#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/systems/vision.hpp"

namespace vision{

  void visionSense(){
    pros::vision_object_s_t rtn = vision.get_by_size(0);
    // Gets the largest object
    std::cout << "sig: " << rtn.signature;
    pros::delay(2);
  }
}
