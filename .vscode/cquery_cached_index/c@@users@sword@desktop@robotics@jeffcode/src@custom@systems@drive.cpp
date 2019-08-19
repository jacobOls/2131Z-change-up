#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/drive.hpp"
#include "custom/setup/vars.hpp"
#include "custom/systems/lift.hpp"
#include "custom/setup/ramping.hpp"
namespace drive{
	int rightVel; //right side velocity
	int leftVel; //left side velocity
	double liftPos;
	bool isBraked = false;
	void tankDrive()
	{
		if(std::abs(myController.getAnalog(okapi::ControllerAnalog::leftY))<0.05) leftVel=0;
		//if input is not great enough, do not move motor so there is no accidetnal input
		else	leftVel=(myController.getAnalog(ControllerAnalog::leftY)*100);
		if(std::abs(myController.getAnalog(okapi::ControllerAnalog::rightY))<0.05) rightVel=0;
		//if input is not great enough, do not move motor so there is no accidetnal input
		else	rightVel=(myController.getAnalog(ControllerAnalog::rightY)*100);
		//

	}

	void execute()
	{
		if(lift::group2.getPosition() <= -550)
		{
			double reducer = -lift::group2.getPosition()/366;
			//reducer is number found to set -550 to 1.5
			leftVel /=reducer;
			rightVel /=reducer;

		}
		right_motor.moveVelocity(rightVel);
		left_motor.moveVelocity(leftVel);
//sets variable to make setting drive speeds in less words
	}





	void brakeMode()
	//sets brake for easier time stacking
	{
		if(BtnBrake.isPressed())
		{
			isBraked = true;
			while (isBraked)
			{
				right_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
				left_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
				if(BtnBrake.isPressed())
				{
					isBraked = false;
					right_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
					left_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
				}
			}


		}
	}
}
