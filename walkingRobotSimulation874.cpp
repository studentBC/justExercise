class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int direct = 0;
        int x = 0, y = 0, nx , ny, ans = 0;
        for (int com:commands) {
            if (com == -2) {
                direct+=3;
            } else if (com == -1) {
                direct++;
            } else {
                direct = direct%4;
                if (direct == 0) {
                    ny=y+com;
                    for (int i = 0; i < obstacles.size(); i++) {
                        if (obstacles[i][0] == x && obstacles[i][1] > y ) ny = min( obstacles[i][1]-1, ny);
                    }
                    y = ny;
                } else if (direct == 1) {
                    nx = x+com;
                    for (int i = 0; i < obstacles.size(); i++) {
                        if (obstacles[i][1] == y && obstacles[i][0] > x ) nx = min(obstacles[i][0]-1, nx);
                    }
                    x = nx;
                } else if (direct == 2) {
                    ny = y-com;
                    for (int i = 0; i < obstacles.size(); i++) {
                        if (obstacles[i][0] == x && obstacles[i][1] < y ) ny = max(obstacles[i][1]+1, ny);
                    }
                    y = ny;
                } else {
                    nx = x-com;
                    for (int i = 0; i < obstacles.size(); i++) {
                        if (obstacles[i][1] == y && obstacles[i][0] < x ) nx = max(obstacles[i][0]+1, nx);
                    }
                    x = nx;
                }
            }
            ans = max (ans, x*x+y*y);
        }
        return ans;
    }
};
//the fatest method
/*
 * @lc app=leetcode id=874 lang=cpp
 *
 * [874] Walking Robot Simulation
 *
 * https://leetcode.com/problems/walking-robot-simulation/description/
 *
 * algorithms
 * Easy (31.19%)
 * Total Accepted:    9.2K
 * Total Submissions: 29.2K
 * Testcase Example:  '[4,-1,3]\n[]'
 *
 * A robot on an infinite grid starts at point (0, 0) and faces north.  The
 * robot can receive one of three possible types of commands:
 * 
 * 
 * -2: turn left 90 degrees
 * -1: turn right 90 degrees
 * 1 <= x <= 9: move forward x units
 * 
 * 
 * Some of the grid squares are obstacles. 
 * 
 * The i-th obstacle is at grid point (obstacles[i][0], obstacles[i][1])
 * 
 * If the robot would try to move onto them, the robot stays on the previous
 * grid square instead (but still continues following the rest of the route.)
 * 
 * Return the square of the maximum Euclidean distance that the robot will be
 * from the origin.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: commands = [4,-1,3], obstacles = []
 * Output: 25
 * Explanation: robot will go to (3, 4)
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
 * Output: 65
 * Explanation: robot will be stuck at (1, 4) before turning left and going to
 * (1, 8)
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= commands.length <= 10000
 * 0 <= obstacles.length <= 10000
 * -30000 <= obstacle[i][0] <= 30000
 * -30000 <= obstacle[i][1] <= 30000
 * The answer is guaranteed to be less than 2 ^ 31.
 * 
 * 
 */
int optimization = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        return h1 ^ h2;
    }
};
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        if (commands.size() == 0) return 0;

		int max_dist = 0;
        unordered_set<pair<int, int>, pair_hash> obs;
        pair<int, int> cur (0, 0);

        for (const auto &ob : obstacles) {
            obs.insert(make_pair(ob[0], ob[1]));
        }

        vector<pair<int, int>> dir = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };
        int dir_i = 0;

        for (int c : commands) {
            if (c == -2) {
                ++dir_i;
                if (dir_i == dir.size()) dir_i = 0;
            }
            else if (c == -1) {
                --dir_i;
                if (dir_i == -1) dir_i = dir.size() - 1;
            }
            else {
                int x = dir[dir_i].first, y = dir[dir_i].second;
                while (c > 0) {
                    pair<int, int> next (cur.first + x, cur.second + y);
                    if (obs.count(next) > 0) break;
                    cur = next;
                    max_dist = max(max_dist, cur.first * cur.first + cur.second * cur.second);
                    --c;
                }
            }
        }

        return max_dist;
    }
};
