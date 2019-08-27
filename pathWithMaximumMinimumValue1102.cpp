/*
Given a matrix of integers A with R rows and C columns, find the maximum score of a path starting at [0,0] and ending at [R-1,C-1].

The score of a path is the minimum value in that path.  For example, the value of the path 8 →  4 →  5 →  9 is 4.

A path moves some number of times from one visited cell to any neighbouring unvisited cell in one of the 4 cardinal directions (north, east, west, south).

 

Example 1:



Input: [[5,4,5],[1,2,6],[7,4,6]]
Output: 4
Explanation: 
The path with the maximum score is highlighted in yellow. 
Example 2:



Input: [[2,2,1,2,2,2],[1,2,2,2,1,2]]
Output: 2
Example 3:



Input: [[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
Output: 3
 

Note:

1 <= R, C <= 100
0 <= A[i][j] <= 10^9
*/
class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int ans = A[0][0];
        int pace[] = {0,1,0,-1,0};
        priority_queue<tuple<int,int,int>>next;
        next.emplace(ans,0,0);
        int x, y, temp, ni, nj;
        while (next.size()) {
            auto [a, i, j] = next.top();
            x = i;
            y = j;
            ans = min(ans, a);
            next.pop();
            A[x][y] = -2;
            if (x+1 == A.size() && j+1 == A[0].size()) return ans;
            temp = -1;
            for (int a = 0; a < 4; a++) {
                x = i+pace[a];
                y = j+pace[a+1];
                if (x < A.size() && x > -1 && y < A[0].size() && y > -1 && A[x][y] >= 0) {
                    next.emplace(A[x][y],x,y);
                }
            }
        }
        return ans;
    }
};
//the fatest method
constexpr int MATRIX_SIZE_LIMIT = 101;

int encode(int r, int c) { return (r+c) * MATRIX_SIZE_LIMIT*MATRIX_SIZE_LIMIT + r * MATRIX_SIZE_LIMIT + c; }
int row   (int code)     { return code % (MATRIX_SIZE_LIMIT*MATRIX_SIZE_LIMIT) / MATRIX_SIZE_LIMIT; }
int col   (int code)     { return code % (MATRIX_SIZE_LIMIT*MATRIX_SIZE_LIMIT) % MATRIX_SIZE_LIMIT; }

class Solution {
public:
  int maximumMinimumPath(vector<vector<int>>& A) {
    int const R = A.size();
    int const C = A[0].size();

    // Handle trivial case
    if (R == 1 && C == 1)
      return A[0][0];

    // Max-heap for Dijkstra's algorithm
    priority_queue<pair<int, int>> qu;

    // Process initial node
    qu.push({ A[0][0], encode(0, 0) });
    A[0][0] = -1; // mark visited

    while (!qu.empty()) {
      int const value  = qu.top().first;
      int const coords = qu.top().second;
      qu.pop();

      static constexpr array<int, 5> D = {{ 0, +1, 0, -1, 0 }};
      for (int d = 0; d < 4; ++d) {
        // Decode row and column of the next node
        int const nr = row(coords) + D[d];
        int const nc = col(coords) + D[d+1];
        
        // If it's invalid, skip it
        if (nr < 0 || nr >= R || nc < 0 || nc >= C || A[nr][nc] == -1)
          continue;
        
        // Compute value of next node
        int const nvalue = min(value, A[nr][nc]);
        
        // If it's the target node, we are done
        if (nr == R-1 && nc == C-1)
          return nvalue;
        
        // Otherwise, process it
        qu.push({ nvalue, encode(nr, nc) });
        A[nr][nc] = -1; // mark visited
      }
    }

    assert(false);
  }
};

static auto const magic = [](){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();
