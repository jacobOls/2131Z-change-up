#include "custom/setup/auton.hpp"

#include "custom/systems/drive.hpp"
#include "custom/systems/intake.hpp"
#include "custom/systems/lift.hpp"
// DriveEndWait=0;
// TurnEndWait=0;
// PuncherEndWait=0;
namespace auton {
  bool inAuton = false;
  void set_auton(bool b) {
    inAuton = b;
  }
  void Task(void *why) {
    std::uint32_t test = pros::millis(); //init delay
    int beg=pros::millis();
    while (1) {
      if (inAuton) {

      }
      // std::cout << "T: "<< (pros::millis()-beg)/5 <<" BLv: " << drive::back_left_motor.get_actual_velocity() << std::endl;
      pros::Task::delay_until(&test, 5); //delay for 5 millis exact
    }
  }
} // namespace auton
