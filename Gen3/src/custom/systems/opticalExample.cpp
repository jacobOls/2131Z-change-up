// #include "main.h"
// /* this code is an example setup for the optical sensor
//    E team should have an easier time implementhing this because their elevator is similar to ours
//    F team will have a harder time because their elevator is similar to P teams with the double ratchet
// */
// //make sure to read the bottom text
// pros::Optical opt(1);
//  // replace 1 with whatever port its plugged into
// opt.set_led_pwm(75);
//  // put this in initialize to set LED to 75% power to provide consistant lighting, change as neccesary
// bool red = true;
// //change this to set default color. true keeps red and ejects blue, false does the opposite
// int ratchetDirection = red ? 600 : -600;
// //ternary operator returns either 600 or -600 depending if red is true or false.
// // if your elevator is a 200 rpm then change the 600 to 200
//
//   //put into control loop
//   if(toggleButton.changedToPressed(){
//     // this changes which ball it keeps, you can add some sort of way to know what it currently is, for example
//     // my brain screen will change to the color of ball it is keeping, so it is red by default and i can press the button to change the screen to blue
//     //when the filter color changes
//     red = !red;
//   }
// if(buttonFoo.isPressed()){ // runs the elevator to filter
//     noneRatchetMotor.moveVelocity(600);
//     if(opt.get_hue() < 45){
//       // check your sensor and replace 45 with an appropriate value, this is just what mine is set to to check if it is red
//       //this just checks if it is under the hue of 45, which is orange, red is about 20 but better safe then sorry.
//       ratchetMotor.moveVelocity(ratchetDirection);
//       pros::delay(50);
//       // delay to give the ball time to get out, change as needed. maybe the elevator is fast enough to not need this delay
//       //but i have not tested that yet
//     } else if(opt.get_hue() > 95){
//        // same as with 45, 95 is green and about 150+ is blue, but often times it picks up blue as green and red as orange
//       ratchetMotor.moveVelocity(-ratchetDirection);
//       pros::delay(50);
//     } else{
//       ratchetMotor.moveVelocity(600);
//        // if it doesnt see a color just run up
//     }
// }
//
// /* I highly recommend finding a better way of adding a delay, as the pros::delay() will prevent other things from changing during the 50ms
// since I have my control setup in a switch i wont be able to just provide code for this, but the idea behind how i do it is pretty simple. esentially
// once it sees a ball, I set a variable curTime to equal pros::millis() which returns the amount of milliseconds since the program started
// i then also swap to a different state (i use a switch to control everything) that only exists while pros::millis() - curTime < 100, so as soon
// as 100 milliseconds pass it goes back into the main loop. While it is in the seperate case, it does not stop the elevator motors nor does it change
// its velocity at all, so this essential adds a 100 ms delay without interfering with anything else.
//
// I know that Jayden has his version of the code setup in an if else statement which is the more common way of controlling systems
// i believe that he checks for the color and adds the delay in a task https://pros.cs.purdue.edu/v5/tutorials/topical/multitasking.html to run it seperatly
// if you do try the task version you can go to the link in the previous line, ignore the bottom part about mutex
//
// i have no doubt*/
