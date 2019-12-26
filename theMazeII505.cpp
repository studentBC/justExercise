/*There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, find the shortest distance for the ball to stop at the destination. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included). If the ball cannot stop at the destination, return -1.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

 

Example 1:

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)

Output: 12

Explanation: One shortest way is : left -> down -> left -> down -> right -> down -> right.
             The total distance is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.

Example 2:

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)

Output: -1

Explanation: There is no way for the ball to stop at the destination.

 

Note:

There is only one ball and one destination in the maze.
Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.*/
class Solution {
public: 
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int ans = INT_MAX, i, j, dis;
        bool enter;
        queue<tuple<int,int,int>>path;
        vector<vector<int>>dp (maze.size(), vector<int>(maze[0].size(), INT_MAX));
        path.push(make_tuple(start[0], start[1], 0));
        while (!path.empty()) {
            tuple<int, int, int>pos = path.front();
            path.pop();
            i = get<0>(pos); j = get<1>(pos); dis = get<2>(pos);
            dp[i][j] = min (dp[i][j], dis);
            dis = dp[i][j];
            if (i == destination[0] && j == destination[1]) ans = min(ans, dis);
            while (i-1 > -1 && maze[i-1][j]!=1) {
                i--;
                dis++;
            }
            if (dis < dp[i][j]) path.push(make_tuple(i, j , dis));
            i = get<0>(pos); j = get<1>(pos); dis = get<2>(pos);
            while (j-1 > -1 && maze[i][j-1]!=1) {
                j--;
                dis++;
            }
            if (dis < dp[i][j]) path.push(make_tuple(i, j , dis));
            i = get<0>(pos); j = get<1>(pos); dis = get<2>(pos);
            while (i+1 < maze.size() && maze[i+1][j]!=1) {
                i++;
                dis++;
            }
            if (dis < dp[i][j]) path.push(make_tuple(i, j , dis));
            i = get<0>(pos); j = get<1>(pos); dis = get<2>(pos);
            while (j+1 < maze[0].size() && maze[i][j+1]!=1) {
                j++;
                dis++;
            }
            if (dis < dp[i][j]) path.push(make_tuple(i, j , dis));
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};
//20 ms solution
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        if(maze.empty()||maze[0].empty()) return 0;
        int m=maze.size(), n=maze[0].size();
        queue<int> q{{start[0]*n+start[1]}};
        vector<int> dirs{-1,0,1,0,-1};
        maze[start[0]][start[1]] = -1; // init to -1 to skip maze[x][y]==0 check, hence start won't be accessed twice
        while(!q.empty()){
            int i=q.front()/n, j=q.front()%n; q.pop();
            for(int k=0;k<4;++k){
                int x=i, y=j;
                while(x>=0 && x<m && y>=0 && y<n && maze[x][y]!=1)
                    x+=dirs[k], y+=dirs[k+1];
                x-=dirs[k], y-=dirs[k+1];
                int cnt = abs(x-i) + abs(y-j);
                if(maze[x][y]==0 || // cur node is not visited before
                   abs(maze[x][y]) > abs(maze[i][j]) + cnt){ // cur path is better
                    maze[x][y] = -(abs(maze[i][j]) + cnt);
                    q.push(x*n+y);
                }
            }
        }
        return maze[dest[0]][dest[1]]==0? -1 : abs(maze[dest[0]][dest[1]])-1; // return dist - 1, because we set dist of start to be abs(-1)
    }
};
