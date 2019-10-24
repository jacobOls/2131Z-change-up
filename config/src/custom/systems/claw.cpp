#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"

namespace claw{

void claw(){
if(BtnOpen.isPressed()){
motor.moveVelocity(100);

}
else if(BtnClose.isPressed()){
  motor.moveVelocity(-100);
}
else{
motor.moveVelocity(0);


}
}





}
