#include "main.h"
#include "custom/setup/motors.hpp"
#include "custom/setup/controller.hpp"
#include "custom/systems/tilter.hpp"
#include "custom/systems/lift.hpp"
namespace tilter{
  const double epsilon = 10;
  const double upPosition = 2200;
  const double liftPosition = 100;
  // bool trayMove = false;
  const double traySpeed = 75.0;
  const double position =  1500.0;
  Controllers controller = Controllers::NONE;
  double encoder(){
    return lift::liftSensor.get_value();
  }
  double tilterPos(){
    return tilterSensor.get_value();
  }
  bool motorCanTravel() {
    return tilterPos() >= position;
  }
  bool trayDown(){
    return tilterPos() >= 2795 ;
  }
  const double finalPosition = 0;

  bool isLiftDown() {
    double liftPosition = lift::motor.getPosition();
    if (liftPosition > finalPosition - epsilon) {
      return true;
    }
    if (liftPosition < finalPosition + epsilon) {
      return true;
    }
    return false;
  }
  bool liftUp(){
    return lift::motor.getPosition() >= 10;
  }
  bool liftButtons(){
    return lift::BtnUp.isPressed() || lift::BtnDown.isPressed();
  }
  void forward(){
    if( BtnForward.isPressed()){
      controller = Controllers::FORWARD;
    }
    else if (controller==Controllers::FORWARD){
      controller = Controllers::DEINIT;
    }
  }


  void back(){
    if(BtnBackward.isPressed()){
      controller = Controllers::BACKWARD;
    }
    else if(controller == Controllers::BACKWARD){
      controller = Controllers::DEINIT;
    }
  }

  void travel(){
    if(BtnR.isPressed()){
      controller = Controllers::RETURN;
    }
    else if(controller == Controllers::RETURN && motor.getActualVelocity() > -10){
      controller = Controllers::DEINIT;
    }

  }



    // if(encoder() < 1500 && tilterPos() < 2350 ){
    //   intake::intakegroup.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    // }
    // else {
    //   intake::intakegroup.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    // }

  void execute(){
    // if(encoder() > 1350 && tilterPos() > upPosition) controller= Controllers::LIFT;
    // if(!motorCanTravel() && controller== Controllers::FORWARD) controller= Controllers::DEINIT;
    // if(trayDown() && controller== Controllers::BACKWARD) controller= Controllers::DEINIT;
    switch (controller) {
      // pros::lcd::set_text(3,std::to_string(static_cast<int>(controller));
      case Controllers::FORWARD:
      motor.moveVelocity(75);
      // intake::intakegroup.moveVelocity(-25);
      break;

      case Controllers::BACKWARD:
      motor.moveVelocity(-100);
      break;

      case Controllers::DEINIT:
      motor.moveVelocity(0);
      controller = Controllers::NONE;
      break;

      case Controllers::NONE:
      break;

case Controllers::TOUP:
break;

      case Controllers::RETURN:
      if(tilterPos() < 2790)
      motor.moveVelocity(-100);
      // if(motor.getActualVelocity() >= 60){
      // }
      // pros::delay(motor.isStopped());
      if (tilterPos() > 2790){
        if(motor.isStopped())
        {
          controller = Controllers::DEINIT;
        }
      }
      break;
    }

}
    void init(){
      forward();
      back();
      travel();
      execute();
}
}

      // case Controllers::LIFT:
      // static int i;
      // i++;
      // pros::lcd::set_text(2,std::to_string(i));
      // if (tilterPos() > upPosition){
      //   motor.moveVelocity(100);
      // }
      // else if (tilterPos() < upPosition){
      //   motor.moveVelocity(0);
      // }
      // if(encoder() < 1250 ) controller = Controllers::RETURN;
      // // (upPosition +25, 100);
      // break;

  //     case Controllers::RETURN:
  //     if(encoder()  > 1450 && tilterPos() > upPosition){
  //       motor.moveAbsolute(upPosition, -100);
  //       if(tilterPos() < upPosition){
  //         motor.moveVelocity(-100);
  //       }
  //     }
  //     else{
  //       motor.moveAbsolute(0,-100);
  //     }
  //     break;
  //
  //   }
  // }


// namespace tilter
// {
//     Controllers controller = Controllers::NONE;
//     double sensor()
//     {
//         return tilterSensor.get_value();
//     }
//     double lSensor()
//     {
//         return lift::liftSensor.get_value();
//     }
//
//     int halfDown =1850;
//     int allDown = 1170;
//     int upPlace = 1850;
//
//     void up()
//     {
//         if (BtnForward.isPressed())
//         {
//             controller = Controllers::FORWARD;
//         }
//         else if (controller == Controllers::FORWARD)
//         {
//             controller = Controllers::DEINIT;
//         }
//     }
//
//     void goUp(){
//         if(BtnGoUp.isPressed()){
//             controller = Controllers::TOUP;
//         }
//         else if(controller == Controllers::TOUP && motor.getActualVelocity() < 10){
//             controller = Controllers::DEINIT;
//         }
//     }
//
//
//     void down()
//     {
//         if (BtnBackward.isPressed())
//         {
//             controller = Controllers::BACKWARD;
//         }
//         else if (controller == Controllers::BACKWARD)
//         {
//             controller = Controllers::DEINIT;
//         }
//     }
//
//     void returnDown()
//     {
//         if (BtnR.isPressed())
//         {
//             controller = Controllers::RETURN;
//         }
//         else if (controller == Controllers::RETURN)
//         {
//             controller = Controllers::DEINIT;
//         }
//     }
//
//     void execute()
//     {
//         if (controller == Controllers::FORWARD)
//         {
//             if (sensor() > 2300)
//             {
//                 controller = Controllers::DEINIT;
//             }
//         }
//         if (controller == Controllers::BACKWARD)
//         {
//             if (sensor() < 1450)
//             {
//                 controller = Controllers::DEINIT;
//             }
//         }
//         switch (controller)
//         {
//
//             case Controllers::FORWARD:
//                 motor.moveVelocity(75);
//                 break;
//
//             case Controllers::BACKWARD:
//                 motor.moveVelocity(-75);
//
//                 break;
//
//             case Controllers::TOUP:
//                 if(sensor() < upPlace){
//                     motor.moveVelocity(100);
//                 }
//                 else motor.moveVelocity(0);
//                 break;
//
//             case Controllers::RETURN:
//                 if (lSensor() > 1200)
//                 {
//                     if (sensor() >= halfDown)
//                     {
//                         motor.moveVelocity(-100);
//                     }
//                 else if (sensor() >= allDown)
//                 {
//                     motor.moveVelocity(-100);
//                   }
//                 }
//                 break;
//
//             case Controllers::DEINIT:
//                 motor.moveVelocity(0);
//                 controller = Controllers::NONE;
//                 break;
//
//             case Controllers::NONE:
//                 break;
//         }
//     }
//
//     void init()
//     {
//         up();
//         down();
//         goUp();
//         execute();
//         returnDown();
//     }
//
//     namespace auton
//     {
//
//         void trayDown(double wantedPosition, double targetVelocity)
//         {
//             while (sensor() > wantedPosition)
//             {
//                 motor.moveVelocity(targetVelocity);
//             }
//             if (motor.getPosition() <= wantedPosition)
//             {
//                 motor.moveVelocity(0);
//             }
//         }
//
//         void stack(double wantedPosition, double targetVelocity)
//         {
//             while (sensor() < wantedPosition)
//             {
//                 motor.moveVelocity(targetVelocity);
//             }
//             if (sensor() >= wantedPosition)
//             {
//                 motor.moveVelocity(0);
//             }
//         }
//     } // namespace auton
//
// } // namespace tilter
