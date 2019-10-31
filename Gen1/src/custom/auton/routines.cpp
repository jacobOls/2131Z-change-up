#include "custom/auton/routines.hpp"
#include "custom/auton/selection.hpp"

#include "custom/systems/drive.hpp"
#include "custom/systems/intake.hpp"
#include "custom/systems/lift.hpp"
/*
// namespace auton {
//   int startedMills;
  // namespace Drive = drive::auton;
  // namespace Intake = intake::automatic;
  // namespace Lift = lift;
  // namespace Flipper = flipper;
  // namespace Puncher = puncher::auton;

  // using flipper::set_target;
  // namespace F { //flipper
  //   namespace F = flipper;
  //   namespace T = flipper::target;
  //   using F::set_target,
  //       F::wait;
   // namespace F

  // namespace L { //lift
  //   namespace T = lift::target;
  //   using Lift::set_target,
  //       Lift::wait;
  // } // namespace L
  // namespace routines {
  //
  //   void doubleShotFront() { //remove
  //   }
    //   Puncher::fire(true);
    //   Lift::set_target(lift::target::puncher::frontMiddle, true);
    //   int timer = 0;
    //   while (!Intake::balls::get_puncherActual() && timer < 50) {
    //     timer++;
    //     pros::delay(5);
    //   }
    //   Puncher::charge(false);
    //   Puncher::wait();
    //   lift::wait();
    //
    //   Puncher::wait();
    //   pros::delay(200);
    //   Puncher::fire(true);
    //   Lift::set_target(lift::target::down, true);
    // }

    void doubleShotBack() {
    }
//       Puncher::charge(false);
//       Lift::set_target(t1, true);
//       Lift::wait();
//       Puncher::fire(true);
//       Lift::set_target(t2);
//       int start = pros::millis();
//       while (!Intake::balls::get_puncherActual() && pros::millis() - start < 250) {
//         pros::delay(5);
//       }
//       Puncher::charge(false);
//       Lift::wait(timeDelay);
//       Puncher::fire(true);
//       // Puncher::wait(50); //wait for the ball to fully exit the ride
//       Lift::set_target(t3);
//     }
    void multiFlagSelect() {
    }
//       switch (f) {
//       case selection::Flags::BOTH:
//         doubleShotBack(t1, t2, time, t3);
//         break;
//       case selection::Flags::TOP:
//         Puncher::charge(false);
//         Lift::set_target(t1, true);
//         Lift::wait();
//         Puncher::fire(true);
//         Lift::set_target(t3);
//         break;
//       case selection::Flags::MID:
//         Puncher::charge(false);
//         Lift::set_target(t2, true);
//         Lift::wait();
//         Puncher::fire(true);
//         Lift::set_target(t3);
//         break;
//       case selection::Flags::HOLD:
//         lift::set_target(t3, true);
//       case selection::Flags::NONE:
//         break;
//       };
//     }
//     namespace red {
//       namespace front {
        void start() { //add bottom flag flipper hit
        }
//           startedMills = pros::millis();
//           { //wait
//             drive::Y.request(200);
//             { //ram speed; used to accel faster in short distance
//               // drive::Y.request(200);
//               while (drive::Y.output() < 50) { pros::delay(drive::Y.get_changeMsec()); }
//               const double yStartCV = drive::Y.get_changeVal();
//               drive::Y.update_changeVal(yStartCV * 2);
//               while (drive::Y.output() < 100) { pros::delay(drive::Y.get_changeMsec()); }
//               drive::Y.update_changeVal(yStartCV * 3);
//               while (drive::Y.output() < 150) { pros::delay(drive::Y.get_changeMsec()); }
//               drive::Y.update_changeVal(yStartCV);
//             }
//             while (pros::millis() - startedMills < 260) { pros::delay(drive::Y.get_changeMsec()); } //should be 250 but might not line up properly in round robin
//             Flipper::set_target({290, 37}, true);                                                   //set the flipper down to catch the cap
//           }
//
//           Drive::y(29, 200, -1);                    //get ball from cap without flipping cap
//           Drive::wait();                            //let yDir be corectly calculated; wait for the the drive to finish its movement but dont wait for it to settle
//           Drive::y(28, 200, -1);                    //wait via distance to put the flipper up
//           Flipper::set_target(flipper::target::up); //get flipper out of the way
//           int yTarSaved[2];                         //allow for abs targets to be stored
//           yTarSaved[0] = 22;                        //save the last abs target for making abs movements relitive to this movement but not others
//           Drive::y(yTarSaved[0], 200);              //drive back to line up to the flags
//
//           Puncher::charge(false); //get the puncher ready to fire
//           Drive::z(-86, 150);     //turn to the pole
//
//           { //wait if not parking
//             if (s == selection::Shoots::MID && o == selection::Options::NPARK) pros::delay(3500);
//             if (s == selection::Shoots::FAR && o == selection::Options::NPARK) pros::delay(3500);
//           }
//
//           doubleShotBack(lift::target::puncher::frontTop, {lift::target::puncher::frontMiddle.position + 40, lift::target::puncher::frontMiddle.velocity}, 100); //toggle the selected flags
//
//           Drive::rel::yx(-10, -1.25, 150, 50, -1); //line up to bottom flag
//           yTarSaved[1] = yTarSaved[0] + 19;        //relavate target to yTarSaved[0] insted of Drive::yTar
//           Drive::y(yTarSaved[1], 200, -1);         //drive into bottom flag and intake atleast one ball; should hit wall to straighten; ends 58-60
//           Drive::wait();                           //let yDir be corectly calculated; wait for the the drive to finish its movement but dont wait for it to settle
//           Drive::rel::y(11.5, 200);                //back up to turn to cap
//
//           Flipper::set_target({160, 100});            //start the flipper moving but not to far
//           Drive::z(10, 150, -1);                      //turn to get flipper to miss pole
//           Flipper::set_target(flipper::target::down); //start flipper down
//
//           {                                  //middle jank
//             if (s == selection::Shoots::MID) //mid
//               Drive::z(40, 150);             //finish turn to cap and middle flags
//             else                             //far
//               Drive::z(40, 150);             //finish turn to cap
//           }
//
//           Flipper::wait();            //finish flipper to get down
//           Drive::rel::x(-6, 200, -1); //line up to cap
//           // Drive::wait(0, 0, false, true, false);      //wait for the requested velocity to be 0 no need to wait for full stop
//
//           { //ram speed; used to accel faster in short distance
//             drive::Y.request(200);
//             while (drive::Y.output() < 50) { pros::delay(drive::Y.get_changeMsec()); }
//             const double yStartCV = drive::Y.get_changeVal();
//             drive::Y.update_changeVal(yStartCV * 2);
//             while (drive::Y.output() < 100) { pros::delay(drive::Y.get_changeMsec()); }
//             drive::Y.update_changeVal(yStartCV);
//           }
//         }
        void endShoots() {
        }
//           switch (s) {
//           case selection::Shoots::FAR:                                             //good
//             Drive::rel::y(10, 200, -1);                                            //ram cap; via encoder
//             Flipper::set_target(flipper::target::up.position, flipper::vMove / 2); //flip the cap
//             Drive::rel::y(20, 200);                                                //intake ball
//             Puncher::charge();
//             Drive::z(-30, 150);
//
//             switch (o) { //par
//             case selection::Options::PARK:
//
//               multiFlagSelect(lift::target::puncher::backTop,
//                               {lift::target::puncher::backMiddle.position + 1, lift::target::puncher::backMiddle.velocity},
//                               f, 100, lift::target::up); //toggle selected far flags
//               // Drive::rel::y(3, 200, -1);
//               Drive::xz(Drive::xTar - 12, -80, 90, 110, -1);
//               // Drive::rel::x(0, 200, -1);
//               Drive::rel::y(-22, 200, -1);
//               Lift::set_target(lift::target::down);
//               while (true) { pros::delay(5); }
//
//               // { //drivex
//               //   Drive::rel::x(15, 200, -1);
//               //   Drive::wait(0, 0, false, true, false);
//
//               //   Lift::set_target(lift::target::up, true);
//               //   Drive::z(-75, 200, -1);
//               //   Drive::rel::y(-14, 200);
//               // }
//               // Lift::set_target(lift::target::down, true);
//               Drive::rel::x(-5, 200, -1);
//               Lift::set_target(lift::target::up);
//               Drive::z(-90, 200, -1);
//               // Drive::xz(Drive::xTar-5,-90,100,100,-1);
//               Drive::rel::y(-15, 200, -1);
//               Lift::set_target(lift::target::down);
//               break;
//             case selection::Options::NPARK:
//               // lift::set_target(lift::target::down, true);
//               // pros::delay(2500);
//               multiFlagSelect({(double)163, (double)lift::vMove}, {(double)70, (double)lift::vMove}, f, 150);
//               break;
//             case selection::Options::NONE:
//               break;
//             };
//             break;
//           case selection::Shoots::MID:                //both shoots are to low
//             Drive::rel::y(5, 200, -1);                //ram cap; via encoder
//             Flipper::set_target(flipper::target::up); //flip the cap
//             Drive::rel::y(1, 200);                    //intake ball
//
//             Puncher::charge();
//             Drive::z(-40, 150); //line up to mid flags
//             // Drive::rel::y(1, 200);//back up to be in range
//             switch (o) { //par
//             case selection::Options::PARK:
//               multiFlagSelect({lift::target::down.position, (double)lift::vMove}, {160, (double)lift::vMove}, f, 100);
//               Drive::rel::y(2, 200, -1); //wheels slip here; probly makes problems with the instant setting of the z
//               Drive::z(-75, 200, -1);    //wheels slip here; probly makes problems with the instant setting of the z
//               Lift::set_target(lift::target::up, true);
//               Drive::rel::x(15, 200, -1);
//
//               Drive::rel::y(-35, 200, -1);
//               Lift::set_target(lift::target::down, true);
//               break;
//             case selection::Options::NPARK:
//               lift::set_target(lift::target::down, true);
//               // pros::delay(4000);//moved up top
//               multiFlagSelect({lift::target::down.position, (double)lift::vMove}, {(double)150, (double)lift::vMove}, f, 150);
//               break;
//             case selection::Options::NONE:
//               break;
//             };
//             break;
//           case selection::Shoots::NONE:
//             break;
//           };
//         }
        void all() {}
//           start(s, f, o);
//           endShoots(s, f, o);
//         }
//       } // namespace front
//       namespace back {
        void skills() { }
//           using Drive::rel::y, Drive::rel::x, Drive::z;
//           startedMills = pros::millis();
//
//           {
//             //testing
//
//             // pros::delay(500);
//             //   x(-10,200);
//             //   while (true) { pros::delay(1); } //stop
//           }
//           // pros::delay(500);
//           { //cap-1
//
//             F::set_target(F::T::mid); //prep to flip cap-1
//             y(33, 200);               //approach cap-1
//             // F::set_target(F::T::up); //flip cap-1
//             // F::wait(200, -1);        //wait for the flipper to get up to flip cap-1
//             // Drive::wait(0, 0);
//           }
//           { //cap-2
//
//             F::set_target(F::T::flag);                                                  //move the flipper to not hit cap-3's balls
//             x(5, 100, -1);                                                              //dont hit cap-1
//             Drive::rel::yx(16, 6, 100, 100, -1);                                        //keep going
//             y(6, 200, -1);                                                              //get past cap-2
//             while (drive::Y.output() >= 67) { pros::delay(drive::Y.get_changeMsec()); } //wait for the motors to beable to handle the velocity as y is still ramping down
//             x(10, 200, -1);                                                             //get inbetween cap-2 and cap-3
//             y(6, 200, -1);                                                              //drive back to not hit cap-3
//             F::set_target(F::T::down);                                                  //prep for cap-3
//             y(-4, 200, -1);                                                             //drive back to flip cap-2
//             L::set_target({200, 75});                                                   //flip cap-2
//           }
//           { //cap-3
//
//             y(14, 100, -1);          //drive forward into cap-3
//             F::set_target(F::T::up); //flip cap-3
//             y(14, 100, -1);          //drive past cap-4
//           }
//           { //cap-4
//
//             while (drive::Y.output() >= 67) { pros::delay(drive::Y.get_changeMsec()); } //wait for the motors to beable to handle the velocity as y is still ramping down
//             x(-13, 200);
//             L::set_target({200, 100});
//             y(-3, 200, -1); //drive back
//             L::set_target({250, 25});
//             y(-1, 200); //drive back
//             // Drive::wait();
//           }
//           { //recon
//
//             y(-8, 200); //drive forward
//             Drive::driveReconS(-100, 500);
//             Drive::reset();
//
//             x(1, 200);
//             y(6, 200);
//
//             z(-90, 100);
//             y(23, 200);
//             // y(3, 200, -1);
//             L::set_target(L::T::down);
//             Drive::driveReconS(-100, 500);
//             Drive::reset();
//           }
//           { //far flags
//
//             multiFlagSelect({100, 50}, {180, 50}, selection::Flags::BOTH); //shoot both flags
//           }
//           { //cap-5
//
//             x(1, 100, -1);                      //get off of the platform
//             Drive::rel::yx(1, 1, 100, 100, -1); //continue
//             y(9, 200);                          //pass platform
//             z(-45, 100, -1);                    //turn past cap-6
//             F::set_target(F::T::mid);           //prep to flip cap-5
//             z(-90, 100);                        //turn to cap-5
//             y(31, 200);                         //hit cap-5
//             F::set_target(F::T::up);            //release cap-5
//           }
//           { //cap-6
//
//             z(-45, 100, -1);           //wait to not hit cap-5
//             F::set_target(F::T::down); //prep for cap-6
//             z(45, 100);                //turn to cap-6
//             y(31, 200, -1);            //ram cap-6
//             // y(6, 100, -1);             //ram cap-6 slower
//             F::set_target({F::T::up.position, 100}); //flip cap-6
//             y(3, 100);                               //intake ball-4
//           }
//           { //far bottom flag
//
//             z(0, 100);                 //turn to far bottom flag
//             y(18, 200, -1);            //drive into far bottom flag
//             F::set_target(F::T::flag); //hit far bottom flag
//             Drive::wait();
//             y(9, 100, -1); //back up 3"ish ove shoot 14"ish
//             F::set_target(F::T::up);
//             Drive::wait();
//           }
//           { //mid bottom flag
//
//             x(-44, 200); //drive to middle bottom flag
//           }
//           { //recon
//
//             y(2, 200, -1); //hit mid bottom flag
//             // Drive::recon::x(100, 350);             //hit the flag
//             Drive::recon::y(150, 500, 0, 0, 2000); //straighten up on the wall
//             Drive::reset();                        //reset the drive target values and encoders
//           }
//
// #pragma region //mid flags
//
//           Drive::yx(-4, -4, 100, 100, -1);
//           y(-19, 100);
//           z(45, 100);
//           y(-25, 200);
//           z(37, 50);
//
//           multiFlagSelect({100, 50}, {180, 50}, selection::Flags::BOTH);
// #pragma endregion
// #pragma region //cap-7
//
//           F::set_target(F::T::mid);
//           z(90, 100);
//           y(-3, 200, -1);          //ram cap-7
//           F::set_target(F::T::up); //flip cap-7
//           Drive::wait();
//
// #pragma endregion
//
//           { //recon
//
//             y(11, 100); //drive back to cap-8
//             z(0, 100);
//
//             Drive::recon::y(-100, 350, 0, 0, 2000);
//             Drive::reset();
//           }
//           { //cap-8
//
//             F::set_target(F::T::down);
//             y(0.2, 50, -1);
//             x(-12, 200);
//
//             { //ram cap with speed
//
//               drive::Y.request(200);                                                      //get moving
//               while (drive::Y.output() < 25) { pros::delay(drive::Y.get_changeMsec()); }  //wait
//               const double startYacel = drive::Y.get_changeVal();                         //store
//               drive::Y.update_changeVal(startYacel * 2);                                  //jerk up
//               while (drive::Y.output() < 50) { pros::delay(drive::Y.get_changeMsec()); }  //wait
//               drive::Y.update_changeVal(startYacel * 3);                                  //jerk up
//               while (drive::Y.output() < 100) { pros::delay(drive::Y.get_changeMsec()); } //wait
//               drive::Y.update_changeVal(startYacel * 2);                                  //jerk down
//               while (drive::Y.output() < 150) { pros::delay(drive::Y.get_changeMsec()); } //wait
//               drive::Y.update_changeVal(startYacel);                                      //jerk down
//             }
//             y(14, 200, -1);          //ram cap-8
//             F::set_target(F::T::up); //flip cap-8
//             y(3, 200);               //intake ball-6
//           }
//           { //clo bottom flag
//
//             x(-29, 200);
//             y(21, 200, -1);
//             // F::set_target(F::T::flag);
//             Drive::recon::x(100, 250, -1);
//             Drive::recon::y(100, 250, 0, 0, 2000);
//             Drive::reset();
//             Drive::yx(-2,-2,100,100,-1);
//             // F::set_target(F::T::up);
//           }
//           { //recon
//
//             y(-30, 200, -1);
//             // Drive::rel::yx(-24, 5, 100, 100, -1);
//             Puncher::charge();
//             y(-20, 200);
//
//             // x(5, 200, -1);
//             // Drive::recon::x(100, 500, 0, 0, 2000);
//             // Drive::reset();
//           }
//           { //clo flags
//
//             // x(-4, 200);
//             multiFlagSelect({100, 50}, {180, 50}, selection::Flags::BOTH, 100, {180, 50});
//           }
//           { //park
//
//             z(-90, 100, -1);
//             y(-60, 200, -1);
//             L::set_target(L::T::down);
//           }
//
//           while (true) { pros::delay(1); } //stop
//         }
        // void start() {}
//           if (s == selection::Shoots::MID)
//             Drive::drive(38, 100, 5000);
//           else
//             Drive::drive(38, 100, 500);
//         }
        // void endShoots() {}
//           switch (s) {
//           case selection::Shoots::FAR:
//             Drive::driveReconS(-100, 300);
//             Drive::driveS(2.5, 100);
//
//             Drive::turnEnc(-65, 50, 4000);
//             switch (o) {
//             case selection::Options::PARK:
//               multiFlagSelect({(double)105, (double)lift::vMove}, {(double)158, (double)lift::vMove}, f, 130);
//
//               // Drive::drive(-1, 200);
//
//               Drive::turnEnc(165, 150);
//
//               Intake::disable();
//               Lift::set_target(lift::target::up, true);
//               Drive::drive(-34, 200);
//
//               Lift::set_target(lift::target::down, true);
//               break;
//             case selection::Options::NPARK:
//               pros::delay(2500);
//               multiFlagSelect({(double)105, (double)lift::vMove}, {(double)158, (double)lift::vMove}, f, 130);
//
//               break;
//             case selection::Options::NONE:
//               break;
//             };
//
//             break;
//           case selection::Shoots::MID:
//             Drive::driveReconS(-100, 300);
//             Drive::driveS(3, 150);
//
//             Drive::drive(-5, 200);
//
//             Drive::turnEnc(-87, 150);
//
//             switch (o) {
//             case selection::Options::PARK:
//               multiFlagSelect({(double)105, (double)lift::vMove}, {(double)180, (double)lift::vMove}, f, 150);
//
//               Drive::driveS(2, 200);
//
//               Drive::turnEnc(190, 200, 0, 1);
//
//               Intake::disable();
//               Lift::set_target(lift::target::up, true);
//               Drive::drive(-35, 200);
//
//               Lift::set_target(lift::target::down, true);
//               break;
//             case selection::Options::NPARK:
//               pros::delay(2500);
//               multiFlagSelect({(double)105, (double)lift::vMove}, {(double)180, (double)lift::vMove}, f, 150);
//
//               break;
//             case selection::Options::NONE:
//               break;
//             };
//             break;
//           default:
//             break;
//           }
//         }
//         void park(selection::Shoots s, selection::Flags f, selection::Options o) {
//         }
//         void all(selection::Shoots s, selection::Flags f, selection::Options o) {
//           start(s, f, o);
//           endShoots(s, f, o);
//           park(s, f, o);
//         }
//       } // namespace back
//     }   // namespace red
//     namespace blue {
//       namespace front {
//         void start(selection::Shoots s, selection::Flags f, selection::Options o) { //good
//           startedMills = pros::millis();
//           { //wait
//             drive::Y.request(200);
//             { //ram speed; used to accel faster in short distance
//               // drive::Y.request(200);
//               while (drive::Y.output() < 50) { pros::delay(drive::Y.get_changeMsec()); }
//               const double yStartCV = drive::Y.get_changeVal();
//               drive::Y.update_changeVal(yStartCV * 2);
//               while (drive::Y.output() < 100) { pros::delay(drive::Y.get_changeMsec()); }
//               drive::Y.update_changeVal(yStartCV * 3);
//               while (drive::Y.output() < 150) { pros::delay(drive::Y.get_changeMsec()); }
//               drive::Y.update_changeVal(yStartCV);
//             }
//             while (pros::millis() - startedMills < 260) { pros::delay(drive::Y.get_changeMsec()); } //should be 400 but might not line up properly in round robin
//             Flipper::set_target({290, 40}, true);                                                   //set the flipper down to catch the cap
//           }
//
//           Drive::y(29, 200, -1);                    //get ball from cap without flipping cap
//           Drive::wait();                            //let yDir be corectly calculated; wait for the the drive to finish its movement but dont wait for it to settle
//           Drive::y(28, 200, -1);                    //wait via distance to put the flipper up
//           Flipper::set_target(flipper::target::up); //get flipper out of the way
//           int yTarSaved[2];                         //allow for abs targets to be stored
//           yTarSaved[0] = 22;                        //save the last abs target for making abs movements relitive to this movement but not others
//           Drive::y(yTarSaved[0], 200);              //drive back to line up to the flags
//
//           Puncher::charge(false); //get the puncher ready to fire
//           Drive::z(86, 150);      //turn to the pole
//
//           { //wait if not parking
//             if (s == selection::Shoots::MID && o == selection::Options::NPARK) pros::delay(3500);
//             if (s == selection::Shoots::FAR && o == selection::Options::NPARK) pros::delay(3500);
//           }
//
//           doubleShotBack(lift::target::puncher::frontTop, {lift::target::puncher::frontMiddle.position + 40, lift::target::puncher::frontMiddle.velocity}, 100); //toggle the selected flags
//
//           Drive::rel::yx(-10, 1.25, 150, 50, -1);     //line up to bottom flag
//           yTarSaved[1] = yTarSaved[0] + 20;           //relavate target to yTarSaved[0] insted of Drive::yTar
//           Drive::y(yTarSaved[1], 200, -1);            //drive into bottom flag and intake atleast one ball; should hit wall to straighten; ends 58-60
//           Flipper::set_target(flipper::target::flag); //hit the bottom flag
//           Flipper::wait();
//           Flipper::set_target(flipper::target::up); //get out of the way
//           Drive::wait();                            //56.5;let yDir be corectly calculated; wait for the the drive to finish its movement but dont wait for it to settle
//           Drive::rel::y(12, 200);                   //back up to turn to cap
//
//           Flipper::set_target({160, 100});            //start the flipper moving but not to far
//           Drive::z(-10, 150, -1);                     //turn to get flipper to miss pole
//           Flipper::set_target(flipper::target::down); //start flipper down
//
//           {                                  //jank
//             if (s == selection::Shoots::MID) //mid
//               Drive::z(-40, 150);            //finish turn to cap and middle flags
//             else                             //far
//               Drive::z(-40, 150);            //finish turn to cap
//           }
//
//           Flipper::wait();           //finish flipper to get down
//           Drive::rel::x(6, 200, -1); //line up to cap
//           // Drive::wait(0, 0, false, true, false);      //wait for the requested velocity to be 0 no need to wait for full stop
//
//           { //ram speed; used to accel faster in short distance
//             drive::Y.request(200);
//             while (drive::Y.output() < 25) { pros::delay(drive::Y.get_changeMsec()); }
//             const double yStartCV = drive::Y.get_changeVal();
//             drive::Y.update_changeVal(yStartCV * 2);
//             while (drive::Y.output() < 75) { pros::delay(drive::Y.get_changeMsec()); }
//             drive::Y.update_changeVal(yStartCV * 3);
//             while (drive::Y.output() < 125) { pros::delay(drive::Y.get_changeMsec()); }
//             drive::Y.update_changeVal(yStartCV * 2);
//             while (drive::Y.output() < 175) { pros::delay(drive::Y.get_changeMsec()); }
//             drive::Y.update_changeVal(yStartCV);
//           }
//         }
//         void endShoots(selection::Shoots s, selection::Flags f, selection::Options o) {
//           switch (s) {
//           case selection::Shoots::FAR:                                             //far turn? parking: jturn xdis < good?
//             Drive::rel::y(10, 200, -1);                                            //ram cap; via encoder
//             Flipper::set_target(flipper::target::up.position, flipper::vMove / 2); //flip the cap
//             Drive::rel::y(20, 200);                                                //intake ball
//             Puncher::charge();                                                     //prep for shoot
//             Drive::z(42.6, 150);                                                   //line up to pole
//
//             switch (o) { //par
//             case selection::Options::PARK:
//
//               multiFlagSelect(lift::target::puncher::backTop,
//                               {lift::target::puncher::backMiddle.position - 17, lift::target::puncher::backMiddle.velocity},
//                               f, 100, lift::target::up); //toggle selected far flags
//               // Drive::rel::y(3, 200, -1);
//               Drive::xz(Drive::xTar + 3, 82, 90, 110, -1);
//               // Drive::rel::x(0, 200, -1);
//               Drive::rel::y(-8, 200, -1);
//               Lift::set_target(lift::target::down);
//               while (true) { pros::delay(5); }
//
//               // // { //drivex
//               // //   Drive::rel::x(15, 200, -1);
//               // //   Drive::wait(0, 0, false, true, false);
//
//               // //   Lift::set_target(lift::target::up, true);
//               // //   Drive::z(-75, 200, -1);
//               // //   Drive::rel::y(-14, 200);
//               // // }
//               // // Lift::set_target(lift::target::down, true);
//               // Drive::rel::x(5, 200, -1);
//               // Lift::set_target(lift::target::up);
//               // Drive::z(90, 200, -1);
//               // // Drive::xz(Drive::xTar-5,-90,100,100,-1);
//               // Drive::rel::y(-15, 200, -1);
//               // Lift::set_target(lift::target::down);
//               break;
//             case selection::Options::NPARK:
//               // lift::set_target(lift::target::down, true);
//               // pros::delay(2500);
//               multiFlagSelect({(double)163, (double)lift::vMove}, {(double)70, (double)lift::vMove}, f, 150);
//               break;
//             case selection::Options::NONE:
//               break;
//             };
//             break;
//           case selection::Shoots::MID:                //NULL
//             Drive::rel::y(5, 200, -1);                //ram cap; via encoder
//             Flipper::set_target(flipper::target::up); //flip the cap
//             Drive::rel::y(1, 200);                    //intake ball
//
//             Puncher::charge();
//             Drive::z(40, 150); //line up to mid flags
//             // Drive::rel::y(1, 200);//back up to be in range
//             switch (o) { //par
//             case selection::Options::PARK:
//               multiFlagSelect({lift::target::down.position, (double)lift::vMove}, {160, (double)lift::vMove}, f, 100);
//               Drive::rel::y(2, 200, -1); //wheels slip here; probly makes problems with the instant setting of the z
//               Drive::z(75, 200, -1);     //wheels slip here; probly makes problems with the instant setting of the z
//               Lift::set_target(lift::target::up, true);
//               Drive::rel::x(-15, 200, -1);
//
//               Drive::rel::y(-35, 200, -1);
//               Lift::set_target(lift::target::down, true);
//               break;
//             case selection::Options::NPARK:
//               lift::set_target(lift::target::down, true);
//               // pros::delay(4000);//moved up top
//               multiFlagSelect({lift::target::down.position, (double)lift::vMove}, {(double)150, (double)lift::vMove}, f, 150);
//               break;
//             case selection::Options::NONE:
//               break;
//             };
//             break;
//           case selection::Shoots::NONE:
//             break;
//           };
//         }
//         void all(selection::Shoots s, selection::Flags f, selection::Options o) {
//           start(s, f, o);
//           endShoots(s, f, o);
//         }
//       } // namespace front
//       namespace back {
//         void start(selection::Shoots s, selection::Flags f, selection::Options o) {
//           if (s == selection::Shoots::MID)
//             Drive::drive(37, 100, 5000);
//           else
//             Drive::drive(37, 100, 5000);
//         }
//         void endShoots(selection::Shoots s, selection::Flags f, selection::Options o) {
//           switch (s) {
//           case selection::Shoots::FAR:
//             Drive::driveReconS(100, 350);
//             Drive::driveS(-2.5, 100);
//
//             // Drive::drive(-10, 200, 0, 5, 50000);
//
//             if (f != selection::Flags::NONE) Puncher::charge(); //only charge if going to shoot
//             Drive::turnEnc(69, 100);
//             switch (o) {
//             case selection::Options::PARK:
//               pros::delay(1000);
//               multiFlagSelect({(double)90, (double)lift::vMove}, {(double)157, (double)lift::vMove}, f, 150);
//
//               Drive::driveS(0.3, 100);
//
//               Drive::turnEnc(-165, 200, 0, 1);
//
//               Intake::disable();
//               Lift::set_target(lift::target::up, true);
//               Drive::drive(-25, 200);
//
//               Lift::set_target(lift::target::down, true);
//               break;
//             case selection::Options::NPARK:
//               pros::delay(6000);
//               multiFlagSelect({(double)90, (double)lift::vMove}, {(double)157, (double)lift::vMove}, f, 150);
//
//               break;
//             case selection::Options::NONE:
//               break;
//             };
//             break;
//           case selection::Shoots::MID:
//             Drive::drive(-10, 200, 0, 5, 50000);
//
//             if (f != selection::Flags::NONE) Puncher::charge(); //charge if going to shoot
//             Drive::turnEnc(79, 100);
//
//             switch (o) {
//             case selection::Options::PARK:
//               pros::delay(5000);
//               multiFlagSelect({(double)90, (double)lift::vMove}, {(double)170, (double)lift::vMove}, f, 150);
//
//               Drive::driveS(-10, 200);
//
//               Drive::turnEnc(-180, 200, 0, 1);
//
//               Intake::disable();
//               Lift::set_target(lift::target::up, true);
//               Drive::drive(-32, 200);
//
//               Lift::set_target(lift::target::down, true);
//               break;
//             case selection::Options::NPARK:
//               pros::delay(8750);
//               multiFlagSelect({(double)90, (double)lift::vMove}, {(double)170, (double)lift::vMove}, f, 150);
//
//               break;
//             case selection::Options::NONE:
//               break;
//             };
//             break;
//           default:
//             break;
//           }
//         }
//         void all(selection::Shoots s, selection::Flags f, selection::Options o) {
//           start(s, f, o);
//           endShoots(s, f, o);
//         }
//       } // namespace back
//     }   // namespace blue
//     void skills() {
//     }
//     void testR() {
//       Drive::drive(24, 200, -1);
//       Drive::driveAbs(24, 200, 0);
//     }
//     void testB() {
//       Intake::enable();
//       Flipper::set_target(flipper::target::scoopPlatform);
//       Flipper::wait();
//       Drive::drive(-12, 200);
//     }
//     void defaultSelection() {}
//   } // namespace routines
// } // namespace auton
*/
