/*
Intuition

This solution is based on the same idea as maze solving algorithm called right-hand rule. Go forward, cleaning and marking all the cells on the way as visited. At the obstacle turn right, again go forward, etc. Always turn right at the obstacles and then go forward. Consider already visited cells as virtual obstacles.

What to do if after the right turn there is an obstacle just in front ?

Turn right again.

How to explore the alternative paths from the cell ?

Go back to that cell and then turn right from your last explored direction.

When to stop ?

Stop when you explored all possible paths, i.e. all 4 directions (up, right, down, and left) for each visited cell.

Algorithm

Time to write down the algorithm for the backtrack function backtrack(cell = (0, 0), direction = 0).

Mark the cell as visited and clean it up.

Explore 4 directions : up, right, down, and left (the order is important since the idea is always to turn right) :

Check the next cell in the chosen direction :

If it's not visited yet and there is no obtacles :

Move forward.

Explore next cells backtrack(new_cell, new_direction).

Backtrack, i.e. go back to the previous cell.

Turn right because now there is an obstacle (or a virtual obstacle) just in front.
*/
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    set<pair<int, int>>beenTo;
    vector<pair<int, int>> step{
        {0, 1}, {-1, 0}, {0, -1}, {1, 0}
    };
    void back(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    void go (int i, int j, int direction, Robot& robot) {
        beenTo.insert({i, j});
        robot.clean();
        int d, x, y;
        for (int a = 0; a < 4; a++) {
            d = (direction+a)%4;
            x = i+step[d].first;
            y = j+step[d].second;
            if (!beenTo.count({x, y}) && robot.move()) {
                go (x, y, d, robot);
                back(robot);
            }
            robot.turnRight();
        }

    }
    void cleanRoom(Robot& robot) {
        go (0, 0, 0, robot);
    }
};
