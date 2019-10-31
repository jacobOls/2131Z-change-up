#include "main.h"
#include "custom/systems/tilter.hpp"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/ramping.hpp"
//moves the cubes forwards to stack them
namespace tilter
{
  void tilter()
  {
    if(BtnTiltF.isPressed())
    {
      tiltmotor.moveVelocity(75);
    }
    else if(BtnTiltB.isPressed())
    {
      tiltmotor.moveVelocity(-75);

    }
    else
    {
      tiltmotor.moveVelocity(0);
      tiltmotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);

    }
  }
  void ramping(void*)
  {
    static uint32_t start;
    //x.accel
    // if (std::abs(tilter.output()) > 100) {
    //   tilter.update_changeVal(5);
    // } else if (std::abs(tilter.output()) > 50) {
    //   tilter.update_changeVal(3);
    // } else {
    //   tilter.update_changeVal(1.75);
    // }
    tilt.calculate();
    pros::Task::delay_until(&start, tilt.get_changeMsec());
  }
  //adds ramping to the tilter
  void taskInit(){
    pros::Task rampingTask(ramping, (void*) "test", TASK_PRIORITY_DEFAULT,
    TASK_STACK_DEPTH_DEFAULT,"tilt");
    // ra.suspend();
    // tilt.resume();


  }
}
