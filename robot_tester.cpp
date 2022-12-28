#include <iostream>
#include "greedy_robot.h"
using namespace std; 

int main(int argc, char* argv[]) 
{    
    int x;
    int y;
    int xt;
    int yt; 
    int maxDist;
	cout << "Enter in x, y, treasure x, treasure y, max distance: ";
	cin >> x >> y >>  xt >> yt >> maxDist;
    GreedyRobot g1(x, y, xt, yt, maxDist);
    g1.solve();
	cout << g1 << endl;
}