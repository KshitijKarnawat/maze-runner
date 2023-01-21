/**
 * @file    main.cpp
 * @author  Kshitij Karnawat (kshitij@umd.edu)
 * @author  Akashkumar Parmar (akasparm@umd.edu)
 * @author  Sai Teja Gilukara (saitejag@umd.edu)
 * @brief
 * @version 0.1
 * @date    2022-11-07
 *
 * @copyright Copyright (c) 2022
 *
 */

//-------------------------------------Importing required libraries------------------------------------------
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include "simulator/simulator.h"
#include "micromouse/micromouse.h"
#include <cstdlib>

//---------------------------------------------Main File------------------------------------------------------
int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        std::cerr << "Usage: ./main l/r \n";
        return 1;
    }

    int direction{10};                      // Variable for current direction facing
    int *p{&direction};                     // Pointer to integer

    rwa2group11::Goal a1;                   // Generating object
    int *temp = a1.set_goal();
    a1.color_goal();                        // Setting the goal in simulator

    rwa2group11::Algorithm b1;              // Generating object
    b1.set_borders();                       // Setting the borders

    if (*argv[1] == 'r')
    {

        b1.right_wall_following(p, temp);   // Right Wall Follwer
    }

    if (*argv[1] == 'l')
    {

        b1.left_wall_following(p, temp);    // Left Wall Follwer
    }

    b1.way_back(p);                         // Returning the robot from the goal to the home

    return 0;
}