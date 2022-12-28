
#include "greedy_robot.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Default Constructor
GreedyRobot::GreedyRobot()
{
}

// Constructor intializes values to equal inputs from terminal
GreedyRobot::GreedyRobot(int x, int y, int treasureX, int treasureY, int maxDistance) : x_(x), y_(y),
    treasureX_(treasureX), treasureY_(treasureY), maxDistance_(maxDistance)
{  
    maxCounterX_ = 0; 
    maxCounterY_ = 0; 
    path_ = "";
    pathCounter_ = 0;
}

// Deconstructor
GreedyRobot::~GreedyRobot()
{
}

int GreedyRobot::x() const
{
    return x_;
}

int GreedyRobot::y() const
{
    return y_;
}

int GreedyRobot::treasureX() const
{
    return treasureX_;
}

int GreedyRobot::treasureY() const
{
    return treasureY_;
}

int GreedyRobot::maxDistance() const
{
    return maxDistance_;
}

// Calls countPaths to start recursive process
void GreedyRobot::solve()
{
    countPaths(x_, y_, treasureX_, treasureY_, maxDistance_, path_, maxCounterX_, maxCounterY_);
}

// Moves robot's X location accordingly, adds to path string, and increments maxDistance counter
void GreedyRobot::xMoves(int x, int y, int treasureX, int treasureY, int maxDistance, string path, 
    int maxCounterX, int maxCounterY)
{
    if ((treasureX > x) && (maxCounterX < maxDistance))
    {
        return countPaths((x + 1), y, treasureX, treasureY, maxDistance, path + "E", 
            maxCounterX + 1, maxCounterY);
    }
    else if ((treasureX < x) && (maxCounterX < maxDistance))
    {       
        return countPaths((x-1), y, treasureX, treasureY, maxDistance, path + "W", 
            maxCounterX + 1, maxCounterY);
    }    
}	

// Moves robot's y location accordingly, adds to path string, and increments maxDistance counter
void GreedyRobot::yMoves(int x, int y, int treasureX, int treasureY, int maxDistance, string path, int maxCounterX,
    int maxCounterY)
{
    if ((treasureY > y) && (maxCounterY < maxDistance))
    { 
        return countPaths(x, (y + 1), treasureX, treasureY, maxDistance, path + "N", 
            maxCounterX, maxCounterY + 1);
    }
    else if ((treasureY < y) && (maxCounterY < maxDistance))
    {
        return countPaths(x, (y - 1), treasureX, treasureY, maxDistance, path + "S", 
            maxCounterX, maxCounterY + 1);
    }
}	

// Calls functions that increment robot's x and y location 
void GreedyRobot::countPaths(int x, int y, int treasureX, int treasureY, int maxDistance, string path, 
    int maxCounterX, int maxCounterY)
{
    // Checks if maxDistance is not met and robot's x location doesn't equal treasure's x location
    if ((maxCounterX < maxDistance) && (x != treasureX))
    {
        xMoves(x, y, treasureX, treasureY, maxDistance, path, maxCounterX, maxCounterY);  
    }  
    
    // Changes maxDistance counter for y to zero if it is done with moving on the y axis
    if (path[path.size() - 1] != 'N' && path[path.size() - 1] != 'S') 
    {
        maxCounterY = 0;     
    }

    // Checks if maxDistance is not met and robot's y location doesn't equal treasure's y location
    if ((maxCounterY < maxDistance) && (y != treasureY))
    {
        maxCounterX = 0; 
        yMoves(x, y, treasureX, treasureY, maxDistance, path, maxCounterX, maxCounterY);  
    }

    // Changes maxDistance counter for x to zero if it is done with moving on the x axis 
    if (path[path.size() - 1] != 'E' && path[path.size() - 1] != 'W') 
    {
        maxCounterX = 0;     
    }

    // Base case
    if (treasureX == x && treasureY == y)
    {
        pathCounter_++; 
        totalPaths_.push_back(path);
        maxCounterX = 0; 
        maxCounterY = 0; 
    }   
}

// Prints out paths created and number of paths
ostream & operator<<(ostream &os, GreedyRobot &robot)
{
    for (int i = 0; i < robot.totalPaths_.size(); i++)
    {
	    os << robot.totalPaths_[i] << endl;
    }
    os << "Number of Paths: " << robot.pathCounter_ << endl;
	return os;
} 

