#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <memory>
#include <unistd.h>
#include "mazesolver.h"

int* maze_solver::Goal::set_goal(){
    
    srand((unsigned)time(NULL));
    
    int flag1 = rand() % 2;
    int flag2 = rand() % 2;

    if (flag1){

        goal_pos[0] = rand() % 15 + 1;
        if (flag2){

            goal_pos[1] = 0;
        }
        else{

            goal_pos[1] = 15;
        }
    }

    else{

        goal_pos[1] = rand() % 15 + 1;
        if (flag2){

            goal_pos[0] = 0;
        }
        else{

            goal_pos[0] = 15;
        }
    }

    return goal_pos.data();
}

void maze_solver::Goal::color_goal(){
    
    // colorize and add text
    Simulator::setColor(goal_pos[0], goal_pos[1], 'Y');
    Simulator::setText(goal_pos[0], goal_pos[1], "G");
    Simulator::setColor(0, 0, 'y');
    Simulator::setText(0, 0, "H");
}

void maze_solver::Algorithm::left_wall_following(int* goal){

    while ((curr_pos[0] != *goal) || (curr_pos[1] != *(goal+1))){

        set_walls(i % 4);

        if (!Simulator::wallLeft()){
    
            Simulator::turnLeft();
            Simulator::moveForward();
            i--;
        }

        else if(!Simulator::wallFront()){
    
            Simulator::moveForward();
        } 

        else if(!Simulator::wallRight()){
    
            Simulator::turnRight();
            Simulator::moveForward();
            i++;
        }

        else{
    
            Simulator::turnRight();
            Simulator::turnRight();
            Simulator::moveForward();
            i += 2;
        }

        check_direction(i % 4);
        Simulator::setColor(curr_pos[0], curr_pos[1], 'g');
    }
}

void maze_solver::Algorithm::right_wall_following(int* goal){

    while ((curr_pos[0] != *goal) || (curr_pos[1] != *(goal+1))){
    
        set_walls(i % 4);

        if (!Simulator::wallRight()){
    
            Simulator::turnRight();
            Simulator::moveForward();
            i++;
        }

        else if(!Simulator::wallFront()){
    
            Simulator::moveForward();
        } 

        else if(!Simulator::wallLeft()){
    
            Simulator::turnLeft();
            Simulator::moveForward();
            i--;
        }

        else{
    
            Simulator::turnRight();
            Simulator::turnRight();
            Simulator::moveForward();
            i += 2;
        }

        check_direction(i % 4);
        Simulator::setColor(curr_pos[0], curr_pos[1], 'g');
    }
}

void maze_solver::Algorithm::check_direction(int i){

    std::array<char,4> dir{'s', 'w', 'n', 'e'};
    char curr_dir = dir[i];
    // std::cerr << i << std::endl;

    if (curr_dir == 'n'){
        curr_pos[1]++;
    }
    if (curr_dir == 'e'){
        curr_pos[0]++;
    }
    if (curr_dir == 'w'){
        curr_pos[0]--;
    }
    if (curr_dir == 's'){
        curr_pos[1]--;
    }

    // std::cerr << "x: "<< curr_pos[0] << " y: " << curr_pos[1] << std::endl;
}

void maze_solver::Algorithm::set_borders(){

    for (int j=0; j<16; j++){
        for (int k=0; k<16;k++){
            if (j==0)
                Simulator::setWall(j,k,'w');
            
            if (j==15)
                Simulator::setWall(j,k,'e');

            if (k==0)
                Simulator::setWall(j,k,'s');

            if (k==15)
                Simulator::setWall(j,k,'n');
        }
    }
}

void maze_solver::Algorithm::set_walls(int dir){

    if (dir == 0){
        if (Simulator::wallLeft())
            Simulator::setWall(curr_pos[0], curr_pos[1], 'e');
        
        if (Simulator::wallRight())
            Simulator::setWall(curr_pos[0], curr_pos[1], 'w');

        if (Simulator::wallFront())
            Simulator::setWall(curr_pos[0], curr_pos[1], 's');
    }

    if (dir == 1){
        if (Simulator::wallLeft())
            Simulator::setWall(curr_pos[0], curr_pos[1], 's');
        
        if (Simulator::wallRight())
            Simulator::setWall(curr_pos[0], curr_pos[1], 'n');

        if (Simulator::wallFront())
            Simulator::setWall(curr_pos[0], curr_pos[1], 'w');
    }

    if (dir == 2){
        if (Simulator::wallLeft())
            Simulator::setWall(curr_pos[0], curr_pos[1], 'w');
        
        if (Simulator::wallRight())
            Simulator::setWall(curr_pos[0], curr_pos[1], 'e');

        if (Simulator::wallFront())
            Simulator::setWall(curr_pos[0], curr_pos[1], 'n');
    }

    if (dir == 3){
        if (Simulator::wallLeft())
            Simulator::setWall(curr_pos[0], curr_pos[1], 'n');
        
        if (Simulator::wallRight())
            Simulator::setWall(curr_pos[0], curr_pos[1], 's');

        if (Simulator::wallFront())
            Simulator::setWall(curr_pos[0], curr_pos[1], 'e');
    }
}

void maze_solver::Algorithm::way_back(){

}

void maze_solver::Algorithm::dfs(int* goal){
    
    std::vector<std::array<int,2>> explored{curr_pos};
    std::vector<std::array<int,2>> stack{curr_pos};
    std::array<int,2> curr_node;
    std::array<int,2> next_node;

    while (stack.size() > 0){
        curr_node = stack.at(stack.size()-1);
        stack.pop_back();
        std::cerr << curr_node[0] << "," << curr_node[1] << std::endl;
        
        if (curr_node[0] == *goal && curr_node[1] == *(goal+1))
            break;

        // Left Wall Following
        // if (!Simulator::wallLeft()){
        //     Simulator::turnLeft();
        //     Simulator::moveForward();
        //     i--;
        // }

        // else if (!Simulator::wallFront()){
        //     Simulator::moveForward();
        // }

        // else if (!Simulator::wallRight()){
        //     Simulator::turnRight();
        //     Simulator::moveForward();
        //     i++;
        // }

        // else{
        //     Simulator::turnRight();
        //     Simulator::turnRight();
        //     Simulator::moveForward();
        //     i+=2;
        // }
        
        if(!Simulator::wallFront()){
            Simulator::moveForward();
            // stack.push_back(curr_node);
            // explored.push_back(curr_node);
        }

        else{
            if(!Simulator::wallLeft()){
                Simulator::turnLeft();
                Simulator::moveForward();
                i--;
            }

            else if(!Simulator::wallRight()){
                Simulator::turnRight();
                Simulator::moveForward();
                i++;
            }

            else{
                // turn 180 and step forward
                Simulator::turnRight();
                Simulator::turnRight();
                Simulator::moveForward();
                i+=2;

                //Check if left available if true turn left and move fwd else if check right if true turn right and move fwd else move fwd
                while(curr_node == stack.back()){
                    if(!Simulator::wallLeft()){
                        Simulator::turnLeft();
                        Simulator::moveForward();
                        i--;
                        break;
                    }

                    else if(!Simulator::wallRight()){
                        Simulator::turnRight();
                        Simulator::moveForward();
                        i++;
                        break;
                    }

                    else{
                        Simulator::moveForward();
                    }

                // TODO & FIX
                // 1. Infinte Circular Loop
                // 2. Robot revisits already explored nodes
                // 3. Robot doesn't go to next child of parent instead goes on until front is blocked
                }
            }
        }

        std::cerr << i%4 << std::endl;

        for (auto j =0; j<4;j++){
            
            if ((i%4) == 2)
                next_node = {curr_node[0], curr_node[1]+1};
            
            if ((i%4) == 0)
                next_node = {curr_node[0], curr_node[1]-1};
            
            if ((i%4) == 3)
                next_node = {curr_node[0]+1, curr_node[1]};
            
            if ((i%4) == 1)
                next_node = {curr_node[0]-1, curr_node[1]};
            
            for (auto k =0; k < explored.size(); k++){
            
                if (next_node == explored.at(k))
                    continue;
            }
            
            explored.push_back(next_node);
            stack.push_back(next_node); 
        }

        if (curr_node[0] > 15 || curr_node[1] > 15){
            break;
        }
    }
}