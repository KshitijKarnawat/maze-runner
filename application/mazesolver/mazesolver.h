/**
 * @file    maze_solver.h
 * @author  Kshitij Karnawat (kshitij@umd.edu)
 * @brief 
 * @version 0.1
 * @date    2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef ___MAZE_SOLVER_H___
#define ___MAZE_SOLVER_H___

#include <iostream>
#include <array>
#include <vector>
#include "../simulator/simulator.h"


/**
 * @brief Namespace under which all classes are defined
 * 
 */
namespace maze_solver
{
    /**
     * @brief Class that contains methods related to Goal Position
     * 
     */
    class Goal{
    
        // friend class Algorithm;

        protected:
            std::array<int, 2> goal_pos;

        public:
            /**
             * @brief Set the goal
             *
             */
            int* set_goal();

            /**
             * @brief Change the color of the Goal and Set text as 'G'
             *
             */
            void color_goal();
    };

    /**
     * @brief Class that contains methods related to Algorithms to move the Robot
     * 
     */
    class Algorithm{

        private:
            std::array<int, 2> curr_pos{0, 0};
            int i{10};

        public:
            /**
             * @brief Follow left wall
             * 
             * @param dir pointer to an integer, points to the direction which robot faces
             * @param temp pointer to an array, points to the current coordinate position
             */
            void left_wall_following(int* goal);

            /**
             * @brief Follow left wall
             * 
             * @param dir pointer to an integer, points to the direction which robot faces
             * @param temp pointer to an array, points to the current coordinate position
             */
            void right_wall_following(int* goal);

            /**
             * @brief Follow left wall
             * 
             * @param dir pointer to an integer, points to the direction which robot faces
             */
            void way_back(); //TODO

            /**
             * @brief Follow left wall
             * 
             * @param dir pointer to an integer, points to the direction which robot faces
             */
            void set_walls(int dir);

            /**
             * @brief Follow left wall
             * 
             */
            void set_borders();

            /**
             * @brief 
             * 
             * @param i 
             */
            void check_direction(int i);

            /**
             * @brief 
             * 
             * @param goal 
             */
            void dfs(int* goal); // TODO

            /**
             * @brief 
             * 
             * @param goal 
             */
            void bfs(int* goal); // TODO
    };

}

#endif