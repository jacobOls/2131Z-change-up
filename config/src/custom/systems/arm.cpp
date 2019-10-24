#include "custom/systems/arm.hpp"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"

namespace arma{

void arm(){

if(BtnUp.isPressed()){


motor.moveVelocity(200);

}

else if(BtnDown.isPressed()){

motor.moveVelocity(-200);

}

else{
motor.moveVelocity(0);


}

}





}
