
#ifndef GREEDY_ROBOT_H_
#define GREEDY_ROBOT_H_
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class GreedyRobot
{
public:
    // Constructors
    GreedyRobot();
    GreedyRobot(int x, int y, int treasureX, int treasureY, int maxDistance);
    ~GreedyRobot();

    // Getters-Setters
    int x() const;
    int y() const;
    int treasureX() const;
    int treasureY() const;
    int maxDistance() const; 
    void setRobotLocation(int x, int y);
    void setTreasureLocation(int treasureX, int treasureY);

    // Actions
    void solve(); 
    void xMoves(int x, int y, int treasureX, int treasureY, int maxDistance, string path, int maxCounterX,
        int maxCounterY);
    void yMoves(int x, int y, int treasureX, int treasureY, int maxDistance, string path, int maxCounterX,
        int maxCounterY);
    void countPaths(int x, int y, int treasureX, int treasureY, int maxDistance, string path, int maxCounterX,
        int maxCounterY);

    // Print out operator
    friend ostream & operator<<(ostream &os, GreedyRobot &robot);

private:
    int x_;
    int y_;
    int treasureX_;
    int treasureY_;
    int maxDistance_;

    // Compiles a string of the path taken by the robot
    string path_;

    // Collects all of the string paths created
    vector<string> totalPaths_;

    // Keeps track of number of unique paths found
    int pathCounter_;

    // Counts number of times travelled in x axis 
    int maxCounterX_;

    // Counts number of times travelled in y axis 
    int maxCounterY_; 
};
#endif

