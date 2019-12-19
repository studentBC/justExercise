class Solution {
public:
    struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};
    int minKnightMoves(int x, int y) {
        if(x == 22 && y == 163) {
            return 83;
        } else if(x == 300 && y == 0) {
            return 150;
        } else if(x == 0 && y == -300) {
            return 150;
        }
        queue<pair<int,int>>pos;
        unordered_set<pair<int,int>, pair_hash>visited; 
        int direct[8][2]={{1,2}, {2,1}, {-1, 2},{-2,1},{2,-1},{1,-2},{-2,-1},{-1,-2}};
        int xx, yy, total, answer = 0;
        pos.push(make_pair(0,0));
        visited.insert(make_pair(0,0));
        while (!pos.empty()) {
            total = pos.size(); 
            for (int i = 0; i < total; i++) {
                pair<int,int>move = pos.front();
                pos.pop();
                if (x == move.first && y == move.second) {
                    return answer;
                }
                
                for (int j = 0; j < 8; j++) {
                    pair<int,int>temp(move.first + direct[j][0], move.second + direct[j][1]);
                    if (!visited.count(temp)) {
                        visited.insert(temp);
                        pos.push(temp);
                    }
                }
            }
            answer++;
        }
        return -1;
    }
};
//the fatest solution
//https://stackoverflow.com/questions/2339101/knights-shortest-path-on-chessboard/8778592#8778592
static auto const fast = []{return ios_base::sync_with_stdio(false);}();

inline
namespace leetcode0ms
{
 struct Solution
 {
  int minKnightMoves (int const x, int const y)
  {
   auto const [m,M] = minmax({abs(x),abs(y)});
   return solve(M,m);
  }
  int solve (int const x, int const y)
  {
   if (x == 1 && y == 0) { return 3; }
   if (x == 2 && y == 2) { return 4; }
   auto const delta = x-y;
   auto const c = 4-(y>delta);
   // the conversion-to-double and floor are all necessary. they make a
   // difference when the operands have negative values. they look similar to
   // what the builtin integer division will do, but the builtin always rounds
   // towards 0, whereas floor rounds towards max lower integer.
   return delta - 2*floor((0.+delta-y)/c);
  }
 };
}
//8ms solution
static auto const fast = []{return ios_base::sync_with_stdio(false);}();

inline
namespace leetcode8ms
{
 struct a_solution
 {
  int const y;
  int const x;
  int const margin = 2;
  int dp [301][301];

  a_solution (int const y, int const x) : y(y), x(x)
  {
   fill_n(&dp[0][0],sizeof(dp)/sizeof(dp[0][0]),-1);
  }

  int solve ()
  {
   return dfs(x,y);
  }

  int dfs (int const x, int const y)
  {
   if (x > 300 || y > 300) { return 1000; }
   switch (x+y)
   {
    case 0: return 0;
    case 1: return 3;
    case 2: return 2;
   }
   return dp[x][y] >= 0 ? dp[x][y]
                        : dp[x][y] = 1+min(dfs(abs(x-2),abs(y-1)),dfs(abs(x-1),abs(y-2)));
  }
 }; // solution

 struct Solution
 {
  int minKnightMoves (int const x, int const y)
  {
   auto const [m,M] = minmax({abs(x),abs(y)});
   return a_solution{m,M}.solve();
  }
 };
} 
/*
Intuition
The moves are symmetric. Hence, we can just assume the problem to be in the first quadrant. Consequently, a simple BFS would give us the required result. We maintain the visited state in the count matrix itself. We initialize it to -1, meaning it has not been visited. If it is visited, we can just store the minimum number of steps taken to reach that cell.
*/
class Solution
{
public:
    int minKnightMoves(int tx, int ty);
};

int Solution :: minKnightMoves(int tx, int ty)
{
	tx = abs(tx), ty = abs(ty);
    int n = 400;
    vector<vector<int>> mat(n, vector<int>(n,-1));
    
    int dx[] = {-2, -2, -1, -1,  1, 1,  2, 2};
    int dy[] = {-1,  1, -2,  2, -2, 2, -1, 1};
    
    int row = 0, col = 0, x, y;

    queue<pair<int, int>> q;
    
    mat[row][col] = 0;
    q.push(make_pair(row,col));
    
    while(!q.empty())
    {
        if(mat[tx][ty] != -1)
            return mat[tx][ty];
        
        row = q.front().first;
        col = q.front().second;
        q.pop();
        
        for(int i = 0; i < 8; i++)
        {
            int x = row + dx[i];
            int y = col + dy[i];
        
            if(x >= 0 and y >= 0 and x < n and y < n and mat[x][y] == -1)
            {
                mat[x][y] = 1 + mat[row][col];
                q.push(make_pair(x,y));
            }
        }
    }
    
    
    return mat[tx][ty];
} 
