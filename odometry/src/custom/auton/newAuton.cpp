#include "custom/setup/motors.hpp"
#include "main.h"
#include "custom/setup/odom.hpp"
pros::Imu gyro(5);
namespace auton{

  	//miscellaneous values
  	#define wheelDiameter 2.75
  	#define dontHog 25
  	#define stopError 17
  	#define stopTime 200

  	//Encoder PID Values
  	#define lEnc_Kp  1.1
    #define lEnc_Ki  0.0001// if you dont want an i keep it 0
  	#define lEnc_Kd  0.02

  	#define rEnc_Kp  1.1
  	#define rEnc_Ki  0.0001// if you dont want an i keep it 0
  	#define rEnc_Kd 0.02

  	//Gyro PID Values
  	float gyro_Kp=0.2;
  	float gyro_ki=0.000001;// if you dont want an i keep it 0
  	float gyro_Kd=8;

  	//Drive ramp values
  	int rampInterval = 3;
  	int RampingChange = 10;
  	int initalRamp = 5;
  	int lEncRampBias = 0;
  	int rEncRampBias = 0;
  	int RP;
  	int P;
  	int lEncPrevPower;
  	int rEncPrevPower;
  	//#endregion
    double sgn(int foo){
      return (foo > 0) ? 1 : ((foo < 0) ? -1 : 0);
    }
  	//#region System Variables
  	int driveMode = 0; //0 is drivestraight, 1 is turn
  	int direction = 0; //0 is stopped, 1 is forward/right, -1 is backward/left
  	int distance = 0; //drivestraight distance or turn angle
  	int countsToInches(float value) //converts drive encoder counts into inches
  	{
  	 return (value * 36000)/(PI * wheelDiameter);
  	}

  	//Encoder PID Values

  	int lEncRequestedValue;
  	float lEncErr;//proportional error
  	float lEncPrevErr; //prop error from previous loop
  	float lEncInt;//integral error
  	float lEncDer;//derivative error
  	long lEncPrevTime;
  	float lEncDt; //difference in time
  	float lEncCurrentValue;
  	int lEncOutput;

  	int rEncRequestedValue;
  	float rEncErr;//proportional error
  	float rEncPrevErr; //prop error from previous loop
  	float rEncInt;//integral error
  	float rEncDer;//derivative error
  	long rEncPrevTime;
  	float rEncDt; //difference in time
  	float rEncCurrentValue;
  	int rEncOutput;

  	//Gyro PID values
  	int gyroRequestedValue;
  	float gyroErr;//proportional error
  	float gyroPrevErr; //prop error from previous loop
  	float gyroInt;//integral error
  	float gyroDer;//derivative error
  	long gyroPrevTime;
  	float gyroDt; //difference in time
  	float gyroCurrentValue;
  	int gyroOutput;
  	//#endregion

  	//#region Main Functions
  	void driveWaity(int distance)
  	{
  	 int ticks = fabs(countsToInches(distance));
  	 while(fabs(left.get_position()) <= ticks - stopError){}
  	 pros::delay(stopTime);
  	 ticks = 0;
  	}
  	void turnwaity(int degrees)
  	 {
  	 while(fabs(gyro.get_rotation()-degrees) > 50){}
  	 pros::delay(stopTime);
  	 }
  	void unityStraight(int distance, bool waity = false, bool correct = false) //for correction to work properly waity must be true
  	{
  	 driveMode = 2;
  	 if (correct){
  	 gyro.reset();}
  	 left.set_position(0);
  	 right.set_position(0);
  	 int ticks = fabs(countsToInches(distance));
  	 lEncRequestedValue = ticks;
  	 rEncRequestedValue = ticks;
  	 driveMode = 0;
  	 if(waity) {
  	 pros::delay(stopTime);
  	 driveWaity(distance);

  	 if (correct){
  	 driveMode = 1;
  	 gyroRequestedValue = 0;
  	 turnwaity(0);
  	 pros::delay(stopTime);
  	 }
  	}
  	}

  	void unityTurn(int degrees,bool waity=false)
  	{
  	 driveMode = 2;
  	 gyro.reset();
  	 gyroRequestedValue = degrees;
  	 driveMode = 1;
  	 if(waity)
  	 {
  	 turnwaity(degrees);
  	 }

  	}
  	int driveRamp(int RequestedPower,int Power,int sidebias=0 )
  	{
  	 RP = RequestedPower;
  	 P = Power;
  		if (abs(RP)>abs(P) && RP!=0)
  		{
  		if(abs(P)<initalRamp)	P=initalRamp;
  		else P = abs(P) + RampingChange + sidebias;
  		P = abs(P) * sgn(RP);
  		}
  		else	P=RP;
  	 return P;
  		pros::delay(rampInterval);
  	}
  	void setLDriveMotors(int power)
  	{
  		drive::leftFront.moveVelocity(power);
  		drive::leftBack.moveVelocity(power);
  	}
  	void setRDriveMotors(int power)
  	{
      drive::rightFront.moveVelocity(power);
      drive::rightBack.moveVelocity(power);
  	}
  	//#endregion

  	//#region PID Functions
  	 void lEncController()
  	 {
  	 lEncCurrentValue = left.get_position();

  	 lEncErr = lEncRequestedValue - lEncCurrentValue;
  	 lEncInt = lEncInt + lEncErr;
  	 lEncDer = lEncErr - lEncPrevErr;
  	 lEncDt = pros::millis() - lEncPrevTime;
  	 if(lEncDt < 1)
  	 lEncDt = 1;

  	 lEncOutput = (lEnc_Kp * lEncErr) + (lEnc_Ki * lEncInt * lEncDt) + (lEnc_Kd * lEncDer / lEncDt );

  	 lEncPrevErr = lEncErr;
  	 lEncPrevTime = pros::millis();
  	 if (fabs(lEncCurrentValue)>fabs(right.get_position()))
  	 {
  	 lEncOutput = lEncOutput-((fabs(lEncCurrentValue) - fabs(right.get_position())/2*sgn(lEncCurrentValue)));
  	 }
  	 lEncPrevPower = driveRamp(lEncOutput,lEncPrevPower,lEncRampBias);
  	 setLDriveMotors(lEncPrevPower);
  	 }
  	// lEncDt
  	 void rEncController()
  	 {
  	 rEncCurrentValue = right.get_position();

  	 rEncErr = rEncRequestedValue - rEncCurrentValue;
  	 rEncInt = rEncInt + rEncErr;
  	 rEncDer = rEncErr - rEncPrevErr;
  	 rEncDt = pros::millis() - rEncPrevTime;
  	 if(rEncDt < 1)
  	 rEncDt = 1;

  	 rEncOutput = (rEnc_Kp * rEncErr) + (rEnc_Ki * rEncInt * rEncDt) + (rEnc_Kd * rEncDer / rEncDt );

  	 rEncPrevErr = rEncErr;
  	 rEncPrevTime = pros::millis();
  	 if (fabs(rEncCurrentValue)>fabs(left.get_position()))
  	 {
  	 rEncOutput = rEncOutput-((fabs(rEncCurrentValue) - fabs(left.get_position()))/2*sgn(rEncCurrentValue));
  	 }
  	 rEncPrevPower = driveRamp(rEncOutput,rEncPrevPower,rEncRampBias);
  	 setRDriveMotors(rEncPrevPower);

  	 }
  	// rEncDt
  	 void gyroController()
  	 {
  	 gyroCurrentValue = gyro.get_rotation();

  	 gyroErr = gyroRequestedValue - gyroCurrentValue;
  	 gyroInt = gyroInt + gyroErr;
  	 gyroDer = gyroErr - gyroPrevErr;
  	 gyroDt = pros::millis() - gyroPrevTime;
  	 if(gyroDt < 1)
  	 gyroDt = 1;

  	 gyroOutput = (gyro_Kp * gyroErr) + (gyro_ki * gyroInt * gyroDt) + (gyro_Kd * gyroDer / gyroDt );

  	 gyroPrevErr = gyroErr;
  	 gyroPrevTime = pros::millis();
  	 setLDriveMotors(-gyroOutput);
  	 setRDriveMotors(gyroOutput);
  	 }
  	// gyroDt
  	//#endregion


  	int test;
  	//#region Tasks
  	void unity2()
  	{
  	 right.set_position(0);
  	 left.set_position(0);
  	 gyro.reset();
  	 pros::delay(25);
  	 while(true)
  	 {
  	 test = pros::millis();
  	 if (driveMode == 0)
  	 {
  	 lEncController();
  	 rEncController();
  	 pros::delay(3);
  	 }
  	 else if(driveMode == 1)
  	 {
  	 gyroController();
  	 pros::delay(25);
  	 }
  	 else
  	 {
  	 setLDriveMotors(0);
  	 setRDriveMotors(0);
  	 }
  	 }
  	}
}
