// WAVEFRONT ALGORITHM
#include "custom/auton/selection.hpp"
#include "custom/setup/motors.hpp"
#include "custom/setup/ramping.hpp"
#include "custom/systems/drive.hpp"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
namespace auton {
// in main, declare map matrix //12x12 map
int nothing = 0;
int wall = 255;
int goal = 1;
int robot = 254;
int tower = 253;
// declare starting robot/goal locations
int robot_x = 5;
int robot_y = 5;
void initSense() {
  lTracker.set_position(robot_x * 100);
  rTracker.set_position(robot_y * 100);
}
int curX = robot_x;
int curY = robot_y;
int goal_x = 6;
int goal_y = 6;

// map locations
int x = 0;
int y = 0;

// temp variables
int temp_A = 0;
int temp_B = 0;
int counter = 0;
int steps = 0; // to determine how processor intensive the algorithm was

// when searching for a node with a lower value
int minimum_node = 250;
int min_node_location = 250;
int new_state = 1;
int old_state = 1;
int trans = 50;
int reset_min =
    250; // anything above this number is a special item, ie a wall or robot
// 255 wall, 254 robot
// X is vertical, Y is horizontal
int map[12][12] = {{253, 253, 0, 0, 0, 253, 253, 0, 0, 0, 0, 253},
                   {253, 253, 0, 0, 0, 253, 253, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {253, 253, 0, 0, 0, 253, 253, 0, 0, 0, 253, 253},
                   {253, 253, 0, 0, 0, 253, 253, 0, 0, 0, 253, 253},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {253, 253, 0, 0, 0, 253, 253, 0, 0, 0, 253, 253},
                   {253, 253, 0, 0, 0, 253, 253, 0, 0, 0, 253, 253}};

FILE *out;

// declare functions here, first
int propagate_wavefront(int robot_x, int robot_y);
void unpropagate(int robot_x, int robot_y);
int min_surrounding_node_value(int x, int y);
// void print_map(void);

int main(void) {
  out = fopen("results.txt", "w");
  // fprintf(out,"Starting Wavefront\n");
  // printf("Starting Wavefront\n\n");

  //////////////wavefront code//////////////
  while (map[robot_x][robot_y] != goal) {
    // find new location to go to
    new_state = propagate_wavefront(robot_x, robot_y);
    // update new location of robot
    if (new_state == 1) {
      robot_x--;
      // printf("x=%d y=%d\n\n",robot_x,robot_y);
    }
    if (new_state == 2) {
      robot_y++;
      // printf("x=%d y=%d\n\n",robot_x,robot_y);
    }
    if (new_state == 3) {
      robot_x++;
      // printf("x=%d y=%d\n\n",robot_x,robot_y);
    }
    if (new_state == 4) {
      robot_y--;
      // printf("x=%d y=%d\n\n",robot_x,robot_y);
    }

    while (curX <= robot_x) {
      drive::accelDrive.accelMath(accel, &drive::driveGroup, 150);
    }
    while (curX >= robot_x) {
      drive::accelDrive.accelMath(accel, &drive::driveGroup, -150);
    }
    while (curY <= robot_y) {
      drive::accelDrive.accelMath(accel, &drive::left_strafe, 150);
      drive::accelDrive.accelMath(accel, &drive::right_strafe, -150);
    }
    while (curY >= robot_y) {
      drive::accelDrive.accelMath(accel, &drive::left_strafe, -150);
      drive::accelDrive.accelMath(accel, &drive::right_strafe, 150);
    }
    /*
                    //if not pointed in the right direction, rotate
                    if (abs(old_state - new_state) == 2)//rotate 180 degrees
                            rotate_CCW(200,200);
                    if ((old_state - new_state) == 1 || (signed int)(old_state -
       new_state) == -3)//rotate 90 degrees CW rotate_CW(100,200); if ((signed
       int)(old_state - new_state) == -1 || (old_state - new_state) ==
       3)//rotate 90 degrees CCW rotate_CCW(100,200);

                    //go to new location
                    straight(30,100);*/

    // make new state the old state
    old_state = new_state;
    trans--;
  }
  //////////////////////////////////////////

  // printf("steps: %d\n", steps);
  // fclose(out);
  system("PAUSE");
  return 0;
}

int propagate_wavefront(int robot_x, int robot_y) {
  // clear old wavefront
  unpropagate(robot_x, robot_y);

  // start location to begin scan at goal location
  map[goal_x][goal_y] = goal; // goal at 3,3 for error

  // printf("Adding Goal:\n");
  // print_map();

  counter = 0;
  while (counter < 50) // allows for recycling until robot is found
  {
    x = 0;
    y = 0;
    while (x < 12 && y < 12) // while the map hasnt been fully scanned
    {
      // if this location is a wall or the goal, or tower just ignore it
      if (map[x][y] != wall && map[x][y] != goal && map[x][y] != tower) {
        // a full trail to the robot has been located, finished!
        if (min_surrounding_node_value(x, y) < reset_min &&
            map[x][y] == robot) {
          // printf("Finished Wavefront:\n");
          // print_map();
          // finshed! tell robot to start moving down path
          return min_node_location;
        }
        // record a value in to this node
        else if (minimum_node != reset_min) // if this isnt here, 'nothing' will
                                            // go in the location
          map[x][y] = minimum_node + 1;
      }

      // go to next node and/or row
      y++;
      if (y == 12 && x != 12) {
        x++;
        y = 0;
      }
    }
    // printf("Sweep #: %d\n", counter + 1);
    // print_map();
    counter++;
  }
  return 0;
}

void unpropagate(int robot_x,
                 int robot_y) // clears old path to determine new path
{
  // printf("Old Map:\n");
  // print_map();

  // printf("Starting Unpropagate\n");

  // stay within boundary
  for (x = 0; x < 12; x++)
    for (y = 0; y < 12; y++)
      if (map[x][y] != wall &&
          map[x][y] !=
              goal) // if this location is a wall or goal, just ignore it
        map[x][y] = nothing; // clear that space

  // old robot location was deleted, store new robot location in map
  map[robot_x][robot_y] = robot;

  // printf("Unpropagation Complete:\n");
  // fprintf(out, "Unpropagation Complete:\n");
  // print_map();
}

// this function looks at a node and returns the lowest value around that node
int min_surrounding_node_value(int x, int y) {
  minimum_node = reset_min; // reset minimum

  // down
  if (x < 11) // not out of boundary
    if (map[x + 1][y] < minimum_node &&
        map[x + 1][y] != nothing) // find the lowest number node, and exclude
                                  // empty nodes (0's)
    {
      minimum_node = map[x + 1][y];
      min_node_location = 3;
    }

  // up
  if (x > 0)
    if (map[x - 1][y] < minimum_node && map[x - 1][y] != nothing) {
      minimum_node = map[x - 1][y];
      min_node_location = 1;
    }

  // right
  if (y < 11)
    if (map[x][y + 1] < minimum_node && map[x][y + 1] != nothing) {
      minimum_node = map[x][y + 1];
      min_node_location = 2;
    }

  // left
  if (y > 0)
    if (map[x][y - 1] < minimum_node && map[x][y - 1] != nothing) {
      minimum_node = map[x][y - 1];
      min_node_location = 4;
    }

  return minimum_node;
}

// void print_map(void) {
//   for (temp_B = 0; temp_B < 12; temp_B++) {
//     for (temp_A = 0; temp_A < 12; temp_A++) {
//       if (map[temp_B][temp_A] == wall)
//         printf("W ");
//       else if (map[temp_B][temp_A] == robot)
//         printf("R ");
//       else if (map[temp_B][temp_A] == goal)
//         printf("G ");
//       else
//         printf("%d ", map[temp_B][temp_A]);
//
//       // fprintf(out, "%d",map[temp_A][temp_B]);
//     }
//     printf("\n"); // then go to next line Y
//     // fprintf(out, "\n");
//   }
//   printf("\n");
//   steps++;
// }
} // namespace auton
