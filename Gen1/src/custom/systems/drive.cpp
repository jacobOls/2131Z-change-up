#include "main.h"
#include "custom/settup/motors.hpp"
#include "custom/settup/controller.hpp"
namespace drive{
void userDrive(){
// left drive Y axis
if(abs(master.getAnalog(ControllerAnalog::leftY)) < 0.05){
  left_drive.moveVelocity(0);
}
else if(master.getAnalog(ControllerAnalog::leftY) > master.getAnalog(ControllerAnalog::leftX)){
  left_drive.moveVelocity(master.getAnalog(ControllerAnalog::leftY) * 200);
}
//left drive X axis
if(abs(master.getAnalog(ControllerAnalog::leftX)) < 0.05){
  left_strafe.moveVelocity(0);
}
else if(abs(master.getAnalog(ControllerAnalog::leftY)) < abs(master.getAnalog(ControllerAnalog::leftX))){
  left_strafe.moveVelocity(master.getAnalog(ControllerAnalog::leftX) * 200);
}

// right drive Y axis
if(abs(master.getAnalog(ControllerAnalog::rightY)) < 0.05){
  right_drive.moveVelocity(0);
}
else if(master.getAnalog(ControllerAnalog::rightY) > master.getAnalog(ControllerAnalog::rightX)){
  right_drive.moveVelocity(master.getAnalog(ControllerAnalog::rightY) * 200);
}
//right drive X axis
if(abs(master.getAnalog(ControllerAnalog::rightX)) < 0.05){
  right_strafe.moveVelocity(0);
}
else if(abs(master.getAnalog(ControllerAnalog::rightY)) < abs(master.getAnalog(ControllerAnalog::rightX))){
  right_strafe.moveVelocity(master.getAnalog(ControllerAnalog::leftX) * 200);
}



}
}
