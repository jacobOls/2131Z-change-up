#include "custom/setup/motors.hpp"
#include "main.h"
#include "custom/systems/drive.hpp"
// pros::Imu gyro(5);
namespace auton{
  	//miscellaneous values
  	#define wheelDiameter 2.75
  	#define dontHog 25
  	#define stopError 60
  	#define stopTime 250
    #define turnStopTime 375
    #define turnError 5
  	//Encoder PID Values
  	#define lEnc_Kp  0.257//0.33
    #define lEnc_Ki  0// if you dont want an i keep it 0
  	#define lEnc_Kd  0.6 //0.31

  	#define rEnc_Kp  0.257//0.41
  	#define rEnc_Ki  0 //if you dont want an i keep it 0
  	#define rEnc_Kd  0.6 //0.48

    #define turn_Kp .425
    #define turn_Ki 0.0
    #define turn_Kd 0.1

    #define strafe_Kp .425
    #define strafe_Ki 0.0
    #define strafe_Kd 0.1

  	//Gyro PID Values
  	float gyro_Kp=0.3;
  	float gyro_ki=0.000001;// if you dont want an i keep it 0
  	float gyro_Kd=4;

  	//Drive ramp values
  	int rampInterval = 3;
  	int RampingChange = 9;
  	int initalRamp = 10;
  	int lEncRampBias = 0;
  	int rEncRampBias = 6;
    int bEncRampBias = 0;
    int turnRampBias = 0;
  	double RP;
  	double P;
  	int lEncPrevPower;
  	double rEncPrevPower;
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
  	 return (value * 360)/(PI * wheelDiameter);
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

    int bEncRequestedValue;
    int bEncPrevPower;
    float bEncErr;//proportional error
    float bEncPrevErr; //prop error from previous loop
    float bEncInt;//integral error
    float bEncDer;//derivative error
    long bEncPrevTime;
    float bEncDt; //difference in time
    float bEncCurrentValue;
    int bEncOutput;

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
    int turnRequestedValue;
  	float turnErr;//proportional error
  	float turnPrevErr; //prop error from previous loop
  	float turnInt;//integral error
  	float turnDer;//derivative error
  	long turnPrevTime;
  	float turnDt; //difference in time
  	float turnCurrentValue;
  	int turnOutput;
    float turnPrevPower;
  	//#region Main Functions
  	void driveWaity(int distance)
  	{
  	 int ticks = fabs(countsToInches(distance));
  	 while(fabs(leftTracker.get_position() / 100) <= ticks - stopError){}
  	 pros::delay(stopTime);
  	 ticks = 0;
  	}

    void strafeWaity(int distance){
      int ticks = fabs(countsToInches(distance));
      while(fabs(sTracker.get_position() / 100) <= ticks - stopError){}
      pros::delay(stopTime);
      ticks = 0;
    }

  	void turnwaity(int degrees)
  	 {
       int curTime = pros::millis();
       int ticks = fabs(countsToInches(degrees));
  	 while(fabs((leftTracker.get_position()) / 100) <= ticks - turnError){
       if(leftTracker.get_velocity() != 0 && pros::millis() - curTime > 450){
         break;
       }
     }
      // pros::delay(10);
     // while(leftTracker.get_velocity() != 0){
     // }
     pros::delay(turnStopTime);
  	 }

  	void unityStraight(int distance, bool waity = false) //for correction to work properly waity must be true
  	{
  	 driveMode = 2;

  	 leftTracker.set_position(0);
  	 rightTracker.set_position(0);
  	 int ticks = fabs(countsToInches(distance));

  	 lEncRequestedValue = ticks;
  	 rEncRequestedValue = ticks;
  	 driveMode = 0;
  	 if(waity) {
  	 pros::delay(stopTime);
  	 driveWaity(distance);

  	}
  	}

  void unityStrafe(int distance, bool waity = false){
    driveMode = 2;

    leftTracker.set_position(0);
    rightTracker.set_position(0);
    sTracker.set_position(0);
    int ticks = fabs(countsToInches(distance));

    bEncRequestedValue = ticks;
    driveMode = 0;
    if(waity) {
    pros::delay(stopTime);
    driveWaity(distance);

  }
}

  void unityBack(int distance, bool waity = false){
  driveMode = 2;

  leftTracker.set_position(0);
  rightTracker.set_position(0);
  int ticks = fabs(countsToInches(distance));

  lEncRequestedValue = -ticks;
  rEncRequestedValue = -ticks;
  driveMode = 0;
  if(waity) {
  pros::delay(stopTime);
  driveWaity(distance);
}
}
  	void unityTurn(int degrees,bool waity=false)
  	{
      driveMode = 2;
      // if(gyro.get_rotation() - degrees < 0){
        // degrees = -degrees;
      // }
      // degrees = degrees + 5;
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
  		// pros::delay(rampInterval);
  	}

  	void setLDriveMotors(int power)
  	{
  		drive::leftFront.moveVelocity(power);
  		drive::leftBack.moveVelocity(power);
  	}
  	void setRDriveMotors(double power)
  	{
      drive::rightFront.moveVelocity(power);
      drive::rightBack.moveVelocity(power);
  	}
  	//#endregion

  	//#region PID Functions
  	 void lEncController()
  	 {
       lEncCurrentValue = leftTracker.get_position() / 100;

    	 lEncErr = lEncRequestedValue - lEncCurrentValue;
    	 lEncInt = lEncInt + lEncErr;
    	 lEncDer = lEncErr - lEncPrevErr;
    	 lEncDt = pros::millis() - lEncPrevTime;
    	 if(lEncDt < 1)
    	 lEncDt = 1;

    	 lEncOutput = (lEnc_Kp * lEncErr) + (lEnc_Ki * lEncInt * lEncDt) + (lEnc_Kd * lEncDer / lEncDt );

    	 lEncPrevErr = lEncErr;
    	 lEncPrevTime = pros::millis();
    	 if (fabs(lEncCurrentValue)>fabs(rightTracker.get_position() / 100))
    	 {
    	 lEncOutput = lEncOutput-((fabs(lEncCurrentValue) - fabs(rightTracker.get_position() / 100))/2*sgn(lEncCurrentValue));
    	 }
    	 lEncPrevPower = driveRamp(lEncOutput,lEncPrevPower,lEncRampBias);

    	 setLDriveMotors(lEncPrevPower);

  	 }
  	// lEncDt
  	 void rEncController()
  	 {
  	 rEncCurrentValue = rightTracker.get_position() / 100;

  	 rEncErr = rEncRequestedValue - rEncCurrentValue;
  	 rEncInt = rEncInt + rEncErr;
  	 rEncDer = rEncErr - rEncPrevErr;
  	 rEncDt = pros::millis() - rEncPrevTime;
  	 if(rEncDt < 1)
  	 rEncDt = 1;

  	 rEncOutput = (rEnc_Kp * rEncErr) + (rEnc_Ki * rEncInt * rEncDt) + (rEnc_Kd * rEncDer / rEncDt );

  	 rEncPrevErr = rEncErr;
  	 rEncPrevTime = pros::millis();
  	 if (fabs(rEncCurrentValue)>fabs(leftTracker.get_position() / 100))
  	 {
  	 rEncOutput = rEncOutput-((fabs(rEncCurrentValue) - fabs(leftTracker.get_position() / 100))/2*sgn(rEncCurrentValue));
  	 }
  	 rEncPrevPower = driveRamp(rEncOutput,rEncPrevPower,rEncRampBias);

  	 setRDriveMotors(rEncPrevPower);

  	 }
  	// rEncDt
    void turnController()
    {
      turnCurrentValue = rightTracker.get_position();

      turnErr = turnRequestedValue - turnCurrentValue;
      turnInt = turnInt + turnErr;
      turnDer = turnErr - turnPrevErr;
      turnDt = pros::millis() - turnPrevTime;
      if(turnDt < 1)
      turnDt = 1;

      turnOutput = (turn_Kp * turnErr) +  (rEnc_Ki * rEncInt * rEncDt) + (turn_Kd * turnDer / turnDt );

      turnPrevErr = turnErr;
      turnPrevTime = pros::millis();

      turnPrevPower = driveRamp(turnOutput,turnPrevPower,turnRampBias);
      setLDriveMotors(-turnPrevPower/2);
      setRDriveMotors(turnPrevPower/2);
    }

  	 void gyroController()
  	 {
       gyroCurrentValue = gyro.get_heading();

    	 gyroErr = gyroRequestedValue - gyroCurrentValue;
    	 gyroInt = gyroInt + gyroErr;
    	 gyroDer = gyroErr - gyroPrevErr;
    	 gyroDt = pros::millis() - gyroPrevTime;
    	 if(gyroDt < 1)
    	 gyroDt = 1;

    	 gyroOutput = ((gyro_Kp * gyroErr) + (gyro_ki * gyroInt * gyroDt) + (gyro_Kd * gyroDer / gyroDt )) * 20;

    	 gyroPrevErr = gyroErr;
    	 gyroPrevTime = pros::millis();
       if(gyroRequestedValue > 185 && gyroCurrentValue < 5){
         gyroOutput = -gyroOutput;
              }
    	 setLDriveMotors(gyroOutput);
    	 setRDriveMotors(-gyroOutput);
  	 }

     void strafeController()
     {
        bEncCurrentValue = sTracker.get_position() / 100;

       bEncErr = bEncRequestedValue - bEncCurrentValue;
       bEncInt = bEncInt + bEncErr;
       bEncDer = bEncErr - bEncPrevErr;
       bEncDt = pros::millis() - bEncPrevTime;
       if(bEncDt < 1)
       bEncDt = 1;

       bEncOutput = (strafe_Kp * bEncErr) + (strafe_Ki * bEncInt * bEncDt) + (strafe_Kd * bEncDer / bEncDt );

       bEncPrevErr = bEncErr;
       bEncPrevTime = pros::millis();
       if (fabs(leftTracker.get_position()/100)>fabs(rightTracker.get_position() / 100) + 20)
       {
       bEncOutput = bEncOutput-((fabs(bEncCurrentValue) - fabs(sTracker.get_position() / 100))/2*sgn(lEncCurrentValue));
       }
       bEncPrevPower = driveRamp(bEncOutput,bEncPrevPower,bEncRampBias);

       drive::leftFront.moveVelocity(bEncPrevPower);
       drive::leftBack.moveVelocity(-bEncPrevPower);
       drive::rightBack.moveVelocity(bEncPrevPower);
       drive::rightFront.moveVelocity(-bEncPrevPower);

     }
  	// gyroDt


  	//#endregion

    void unityStop(){
      driveMode = 5;
    }
  	int test;
  	//#region Tasks
  	void unity2(void *param)
  	{
  	 leftTracker.set_position(0);
  	 rightTracker.set_position(0);
  	 pros::delay(25);
  	 while(true)
  	 {
  	 test = pros::millis();
  	 if (driveMode == 0)
  	 {
  	 lEncController();
  	 rEncController();
  	 pros::delay(6);
  	 }
  	 else if(driveMode == 1)
  	 {
    gyroController();
  	 pros::delay(6);
   }
   else if (driveMode == 3){

   }
    else if(driveMode == 5){

   }
  	 else
  	 {
  	 setLDriveMotors(0);
  	 setRDriveMotors(0);
  	 }
  	 }
  	}
}
