#include "custom/setup/motors.hpp"
#include "custom/systems/drive.hpp"
#include "main.h"
// pros::Imu gyro(5);
namespace auton {
// miscellaneous values
#define wheelDiameter 2.75
#define dontHog 25
#define stopError 60
#define stopTime 150
#define turnStopTime 150
#define turnError 5
// Encoder PID Values
#define lEnc_Kp 0.257 // 0.33
#define lEnc_Ki 0     // if you dont want an i keep it 0
#define lEnc_Kd 0.6   // 0.31

#define rEnc_Kp 0.257 // 0.41
#define rEnc_Ki 0     // if you dont want an i keep it 0
#define rEnc_Kd 0.6   // 0.48

#define turn_Kp .425
#define turn_Ki 0.0
#define turn_Kd 0.1

#define strafe_Kp 0.58
#define strafe_Ki 0
#define strafe_Kd 0.02

// intertial PID Values
float inertial_Kp = 0.3;
float inertial_Ki = 0.000001; // if you dont want an i keep it 0
float inertial_Kd = 0.75;

// Drive ramp values
int rampInterval = 3;
int RampingChange = 12;
int initalRamp = 25;
int lEncRampBias = 0;
int rEncRampBias = 6;
int bEncRampBias = 0;
int turnRampBias = 0;
double RP;
double P;
int lEncPrevPower;
double rEncPrevPower;
//#endregion
double sgn(int foo) { return (foo > 0) ? 1 : ((foo < 0) ? -1 : 0); }
//#region System Variables
int driveMode = 0; // 0 is drivestraight, 1 is turn
int direction = 0; // 0 is stopped, 1 is forward/right, -1 is backward/left
int distance = 0;  // drivestraight distance or turn angle
int countsToInches(float value) // converts drive encoder counts into inches
{
  return (value * 360) / (PI * wheelDiameter);
}

// Encoder PID Values

int lEncRequestedValue;
float lEncErr;     // proportional error
float lEncPrevErr; // prop error from previous loop
float lEncInt;     // integral error
float lEncDer;     // derivative error
long lEncPrevTime;
float lEncDt; // difference in time
float lEncCurrentValue;
int lEncOutput;

int rEncRequestedValue;
float rEncErr;     // proportional error
float rEncPrevErr; // prop error from previous loop
float rEncInt;     // integral error
float rEncDer;     // derivative error
long rEncPrevTime;
float rEncDt; // difference in time
float rEncCurrentValue;
int rEncOutput;

int rbEncRequestedValue;
int rbEncPrevPower;
float rbEncErr;     // proportional error
float rbEncPrevErr; // prop error from previous loop
float rbEncInt;     // integral error
float rbEncDer;     // derivative error
long rbEncPrevTime;
float rbEncDt; // difference in time
float rbEncCurrentValue;
int rbEncOutput;

int lbEncRequestedValue;
int lbEncPrevPower;
float lbEncErr;     // proportional error
float lbEncPrevErr; // prop error from previous loop
float lbEncInt;     // integral error
float lbEncDer;     // derivative error
long lbEncPrevTime;
float lbEncDt; // difference in time
float lbEncCurrentValue;
int lbEncOutput;

int lfEncRequestedValue;
int lfEncPrevPower;
float lfEncErr;     // proportional error
float lfEncPrevErr; // prop error from previous loop
float lfEncInt;     // integral error
float lfEncDer;     // derivative error
long lfEncPrevTime;
float lfEncDt; // difference in time
float lfEncCurrentValue;
int lfEncOutput;

int rfEncRequestedValue;
int rfEncPrevPower;
float rfEncErr;     // proportional error
float rfEncPrevErr; // prop error from previous loop
float rfEncInt;     // integral error
float rfEncDer;     // derivative error
long rfEncPrevTime;
float rfEncDt; // difference in time
float rfEncCurrentValue;
int rfEncOutput;
// inertial PID values
int inertialRequestedValue;
float inertialErr;     // proportional error
float inertialPrevErr; // prop error from previous loop
float inertialInt;     // integral error
float inertialDer;     // derivative error
long inertialPrevTime;
float inertialDt; // difference in time
float inertialCurrentValue;
int inertialOutput;
//#endregion
int turnRequestedValue;
float turnErr;     // proportional error
float turnPrevErr; // prop error from previous loop
float turnInt;     // integral error
float turnDer;     // derivative error
long turnPrevTime;
float turnDt; // difference in time
float turnCurrentValue;
int turnOutput;
float turnPrevPower;
//#region Main Functions
void driveWaity(int distance) {
  int ticks = fabs(countsToInches(distance));
  while (fabs(leftTracker.get_position() / 100) <= ticks - stopError) {
  }
  pros::delay(stopTime);
  ticks = 0;
}

void strafeWaity(int distance) {
  int ticks = fabs(countsToInches(distance));
  while (fabs(sTracker.get_position() / 100) <= ticks - stopError) {
  }
  pros::delay(stopTime);
  ticks = 0;
}

void turnwaity(int degrees) {
  while (fabs(gyro.get_heading() - degrees) > 25) {
  }
  pros::delay(stopTime);
}
//   int curTime = pros::millis();
//   int ticks = fabs(countsToInches(degrees));
// while(fabs((leftTracker.get_position()) / 100) <= ticks - turnError){
//   if(leftTracker.get_velocity() != 0 && pros::millis() - curTime > 450){
//     break;
//   }

// pros::delay(10);
// while(leftTracker.get_velocity() != 0){
// }
// pros::delay(turnStopTime);

void unityStraight(
    int distance,
    bool waity = false) // for correction to work properly waity must be true
{
  driveMode = 2;

  leftTracker.set_position(0);
  rightTracker.set_position(0);
  int ticks = fabs(countsToInches(distance));

  lEncRequestedValue = ticks;
  rEncRequestedValue = ticks;
  driveMode = 0;
  if (waity) {
    pros::delay(stopTime);
    driveWaity(distance);
  }
}

void unityStrafe(int distance, bool waity = false) {
  driveMode = 2;

  leftTracker.set_position(0);
  rightTracker.set_position(0);
  sTracker.set_position(0);
  int ticks = fabs(countsToInches(distance));

  rbEncRequestedValue = ticks;
  lbEncRequestedValue = ticks;
  rfEncRequestedValue = ticks;
  lfEncRequestedValue = ticks;

  driveMode = 3;
  if (waity) {
    pros::delay(stopTime);
    driveWaity(distance);
  }
}

void unityBack(int distance, bool waity = false) {
  driveMode = 2;

  leftTracker.set_position(0);
  rightTracker.set_position(0);
  int ticks = fabs(countsToInches(distance));

  lEncRequestedValue = -ticks;
  rEncRequestedValue = -ticks;
  driveMode = 0;
  if (waity) {
    pros::delay(stopTime);
    driveWaity(distance);
  }
}
void unityTurn(int degrees, bool waity = false) {
  driveMode = 2;
  // if(gyro.get_rotation() - degrees < 0){
  // degrees = -degrees;
  // }
  // degrees = degrees + 5;
  inertialRequestedValue = degrees;

  driveMode = 1;
  if (waity) {
    turnwaity(degrees);
  }
}

int driveRamp(int RequestedPower, int Power, int sidebias = 0) {
  RP = RequestedPower;
  P = Power;
  if (abs(RP) > abs(P) && RP != 0) {
    if (abs(P) < initalRamp)
      P = initalRamp;
    else
      P = abs(P) + RampingChange + sidebias;
    P = abs(P) * sgn(RP);
  } else
    P = RP;
  return P;
  // pros::delay(rampInterval);
}

void setLDriveMotors(int power) {
  drive::leftFront.moveVelocity(power);
  drive::leftBack.moveVelocity(power);
}
void setRDriveMotors(double power) {
  drive::rightFront.moveVelocity(power);
  drive::rightBack.moveVelocity(power);
}
//#endregion

//#region PID Functions
void lEncController() {
  lEncCurrentValue = leftTracker.get_position() / 100;

  lEncErr = lEncRequestedValue - lEncCurrentValue;
  lEncInt = lEncInt + lEncErr;
  lEncDer = lEncErr - lEncPrevErr;
  lEncDt = pros::millis() - lEncPrevTime;
  if (lEncDt < 1)
    lEncDt = 1;

  lEncOutput = (lEnc_Kp * lEncErr) + (lEnc_Ki * lEncInt * lEncDt) +
               (lEnc_Kd * lEncDer / lEncDt);

  lEncPrevErr = lEncErr;
  lEncPrevTime = pros::millis();
  if (fabs(lEncCurrentValue) > fabs(rightTracker.get_position() / 100)) {
    lEncOutput =
        lEncOutput -
        (((fabs(lEncCurrentValue) - fabs(rightTracker.get_position() / 100)) /
          2) *
         2 * sgn(lEncCurrentValue));
  }
  lEncPrevPower = driveRamp(lEncOutput, lEncPrevPower, lEncRampBias);

  setLDriveMotors(lEncPrevPower);
}
// lEncDt
void rEncController() {
  rEncCurrentValue = rightTracker.get_position() / 100;

  rEncErr = rEncRequestedValue - rEncCurrentValue;
  rEncInt = rEncInt + rEncErr;
  rEncDer = rEncErr - rEncPrevErr;
  rEncDt = pros::millis() - rEncPrevTime;
  if (rEncDt < 1)
    rEncDt = 1;

  rEncOutput = (rEnc_Kp * rEncErr) + (rEnc_Ki * rEncInt * rEncDt) +
               (rEnc_Kd * rEncDer / rEncDt);

  rEncPrevErr = rEncErr;
  rEncPrevTime = pros::millis();
  if (fabs(rEncCurrentValue) > fabs(leftTracker.get_position() / 100)) {
    rEncOutput =
        rEncOutput -
        (((fabs(rEncCurrentValue) - fabs(leftTracker.get_position() / 100)) /
          2) *
         2 * sgn(rEncCurrentValue));
  }
  rEncPrevPower = driveRamp(rEncOutput, rEncPrevPower, rEncRampBias);

  setRDriveMotors(rEncPrevPower);
}
// rEncDt

void gyroController() {
  inertialCurrentValue = gyro.get_heading();

  inertialErr = inertialRequestedValue - inertialCurrentValue;
  inertialInt = inertialInt + inertialErr;
  inertialDer = inertialErr - inertialPrevErr;
  inertialDt = pros::millis() - inertialPrevTime;
  if (inertialDt < 1)
    inertialDt = 1;

  inertialOutput =
      ((inertial_Kp * inertialErr) + (inertial_Ki * inertialInt * inertialDt) +
       (inertial_Kd * inertialDer / inertialDt)) *
      20;

  inertialPrevErr = inertialErr;
  inertialPrevTime = pros::millis();
  if (inertialRequestedValue > 230 && inertialCurrentValue < 80) {
    inertialOutput = -inertialOutput;
  }
  if (inertialRequestedValue < 160 && inertialCurrentValue > 240) {
    inertialOutput = -inertialOutput;
  }
  // if(inertialCurrentValue - inertialRequestedValue < inertialRequestedValue -
  // inertialCurrentValue){
  //   inertialOutput = -inertialOutput;
  // }
  setLDriveMotors(inertialOutput);
  setRDriveMotors(-inertialOutput);
}

void strafeController() {
  rbEncCurrentValue = sTracker.get_position() / 100;
  lbEncCurrentValue = sTracker.get_position() / 100;
  rfEncCurrentValue = sTracker.get_position() / 100;
  lfEncCurrentValue = sTracker.get_position() / 100;

  rbEncErr = rbEncRequestedValue - rbEncCurrentValue;
  rbEncInt = rbEncInt + rbEncErr;
  rbEncDer = rbEncErr - rbEncPrevErr;
  rbEncDt = pros::millis() - rbEncPrevTime;
  if (rbEncDt < 1)
    rbEncDt = 1;

  rbEncPrevErr = rbEncErr;
  rbEncPrevTime = pros::millis();

  lbEncErr = lbEncRequestedValue - lbEncCurrentValue;
  lbEncInt = lbEncInt + lbEncErr;
  lbEncDer = lbEncErr - lbEncPrevErr;
  lbEncDt = pros::millis() - lbEncPrevTime;
  if (lbEncDt < 1)
    lbEncDt = 1;

  rfEncErr = rfEncRequestedValue - rfEncCurrentValue;
  rfEncInt = rfEncInt + rfEncErr;
  rfEncDer = rfEncErr - rfEncPrevErr;
  rfEncDt = pros::millis() - rfEncPrevTime;
  if (rfEncDt < 1)
    rfEncDt = 1;

  rfEncPrevErr = rfEncErr;
  rfEncPrevTime = pros::millis();

  lfEncErr = lfEncRequestedValue - lfEncCurrentValue;
  lfEncInt = lfEncInt + lfEncErr;
  lfEncDer = lfEncErr - lfEncPrevErr;
  lfEncDt = pros::millis() - lfEncPrevTime;
  if (lfEncDt < 1)
    lfEncDt = 1;

  lbEncOutput = (strafe_Kp * lbEncErr) + (strafe_Ki * lbEncInt * lbEncDt) +
                (strafe_Kd * lbEncDer / lbEncDt);
  rbEncOutput = (strafe_Kp * rbEncErr) + (strafe_Ki * rbEncInt * rbEncDt) +
                (strafe_Kd * rbEncDer / rbEncDt);
  lfEncOutput = (strafe_Kp * lfEncErr) + (strafe_Ki * lfEncInt * lfEncDt) +
                (strafe_Kd * lfEncDer / lfEncDt);
  rfEncOutput = (strafe_Kp * rfEncErr) + (strafe_Ki * rfEncInt * rfEncDt) +
                (strafe_Kd * rfEncDer / rfEncDt);

  rbEncPrevErr = rbEncErr;
  rbEncPrevTime = pros::millis();
  if (fabs(rightTracker.get_position()) > fabs(leftTracker.get_position())) {
    rbEncOutput = rbEncOutput - ((fabs(rightTracker.get_position()) -
                                  fabs(leftTracker.get_position())) /
                                 75 * sgn(rightTracker.get_position()));

    rfEncOutput = rfEncOutput - ((fabs(rightTracker.get_position()) -
                                  fabs(leftTracker.get_position())) /
                                 75 * sgn(rightTracker.get_position()));
  }
  if (fabs(leftTracker.get_position()) > fabs(rightTracker.get_position())) {
    lbEncOutput = lbEncOutput - ((fabs(leftTracker.get_position()) -
                                  fabs(rightTracker.get_position())) /
                                 75 * sgn(leftTracker.get_position()));

    lfEncOutput = lfEncOutput - ((fabs(leftTracker.get_position()) -
                                  fabs(rightTracker.get_position())) /
                                 75 * sgn(leftTracker.get_position()));
  }
  rbEncPrevPower = driveRamp(rbEncOutput, rbEncPrevPower, rEncRampBias);
  lbEncPrevPower = driveRamp(lbEncOutput, lbEncPrevPower, lEncRampBias);
  rfEncPrevPower = driveRamp(rfEncOutput, rfEncPrevPower, rEncRampBias);
  lfEncPrevPower = driveRamp(lfEncOutput, lfEncPrevPower, lEncRampBias);

  drive::leftFront.moveVelocity(lfEncPrevPower);
  drive::leftBack.moveVelocity(-lbEncPrevPower);
  drive::rightBack.moveVelocity(rbEncPrevPower);
  drive::rightFront.moveVelocity(-rfEncPrevPower);
}
// inertialDt

//#endregion

void unityStop() { driveMode = 5; }
int test;
//#region Tasks
void unity2(void *param) {
  leftTracker.set_position(0);
  rightTracker.set_position(0);
  pros::delay(25);
  while (true) {
    test = pros::millis();
    if (driveMode == 0) {
      lEncController();
      rEncController();
      pros::delay(6);
    } else if (driveMode == 1) {
      gyroController();
      pros::delay(6);
    } else if (driveMode == 3) {
      strafeController();

    } else if (driveMode == 5) {

    } else {
      setLDriveMotors(0);
      setRDriveMotors(0);
    }
  }
}
} // namespace auton
