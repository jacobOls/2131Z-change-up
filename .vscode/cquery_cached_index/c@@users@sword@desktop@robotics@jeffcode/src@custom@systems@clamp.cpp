#include "main.h"
#include "custom/systems/clamp.hpp"
#include "custom/setup/controller.hpp"
#include "custom/setup/motors.hpp"
bool clampOpen = false;
namespace clamp{
void clampdump(){
  if(clampOpen == false){
if(BtnToggle.isPressed())
{
  clampOpen = true;
  clampMotor.moveAbsolute(180,100);

}
}
if(clampOpen == true)
{
  clampOpen = false;
  clampMotor.moveAbsolute(0,-100);
}
}
}
