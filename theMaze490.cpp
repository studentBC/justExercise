/*
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

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

Output: true

Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.

Example 2:

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)

Output: false

Explanation: There is no way for the ball to stop at the destination.

 

Note:

There is only one ball and one destination in the maze.
Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.

worng test case:
[[0,0,0],[0,0,0],[0,0,0]]
[0,0]
[1,2]

[[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]]
[4,3]
[0,1]

[[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]]
[0,4]
[3,2]

[[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]]
[0,4]
[1,2]
*/
class Solution {
public:
    void go (int i, int j, int tx, int ty, vector<vector<int>>& maze, vector<vector<bool>>& visited, bool& arrive, int direction) {
        if (arrive || visited[i][j]) return;
        int x = i, y = j;
        if (i == tx && j == ty) {
            arrive = true;
            return;
        }
        visited[i][j] = true;
        while (i+1 < maze.size() && !maze[i+1][j] ) i++;
        if (!visited[i][j]) {
            go (i,j,tx,ty,maze,visited,arrive,0);
        }
        i = x; j = y;
        while (j+1 < maze[0].size() && !maze[i][j+1] ) j++;
        if (!visited[i][j]) {
            go (i,j,tx,ty,maze,visited,arrive,0);
        }
        i = x; j = y;
        while (i-1 > -1 && !maze[i-1][j] ) i--;
        if (!visited[i][j]) {
            go (i,j,tx,ty,maze,visited,arrive,0);
        }
        i = x; j = y;
        while (j-1 > -1 && !maze[i][j-1] ) j--;
        if (!visited[i][j]) {
            go (i,j,tx,ty,maze,visited,arrive,0);
        }
            i = x; j = y;
    }



    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<bool>>visited(maze.size(), vector<bool>(maze[0].size(), false));
        bool arrive = false;
        go (start[0], start[1], destination[0], destination[1], maze, visited, arrive,-1);
        return arrive;
    }
};
//the fatest method
class Solution {
public:
    int getid(int x,int y,int dir)
    {
        return dir*10000 + y*100 + x;
    }
    
    void getxyz(int id ,int& x,int& y,int& dir)
    {
        dir = id/10000;
        id = id%10000;
        y = id/100;
        x = id%100;
    }
    
    bool visit(int cur,queue<int> &q, vector<vector<int>>& maze)
    {
        int dir,X,Y;
        getxyz(cur,X,Y,dir);
        int delta = 1;
        while(delta>=-1)
        {
            int x = X,y = Y,ny = Y,nx = X;
            dir?nx+=delta:ny+=delta;
            while(nx>=0&&nx<maze.size()&&ny>=0&&ny<maze[0].size()&&maze[nx][ny]%2==0)
            {
                x = nx;
                y = ny;
                dir?nx+=delta:ny+=delta;
            }
            if(maze[x][y]==-2)  return true;
            else if(maze[x][y]==0)
            {
                q.push(getid(x,y,1-dir));
                maze[x][y]=2;
            }
            delta -= 2;
        }
        return false;
    }
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& d) {
        queue<int> q;
        q.push(getid(start[0],start[1],0));
        q.push(getid(start[0],start[1],1));
        maze[d[0]][d[1]] = -2;
        maze[start[0]][start[1]] = 2;
        while(!q.empty())
        {
            auto cur = q.front(); q.pop();
            if(visit(cur,q,maze)) return true;
        }
        return false;
    }
};
static const auto speedup = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();

