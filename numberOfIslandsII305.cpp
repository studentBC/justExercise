/*
You are given an empty 2D binary grid grid of size m x n. The grid represents a map where 0's represent water and 1's represent land. Initially, all the cells of grid are water cells (i.e., all the cells are 0's).

We may perform an add land operation which turns the water at position into a land. You are given an array positions where positions[i] = [ri, ci] is the position (ri, ci) at which we should operate the ith operation.

Return an array of integers answer where answer[i] is the number of islands after turning the cell (ri, ci) into a land.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:


Input: m = 3, n = 3, positions = [[0,0],[0,1],[1,2],[2,1]]
Output: [1,1,2,3]
Explanation:
Initially, the 2d grid is filled with water.
- Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land. We have 1 island.
- Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land. We still have 1 island.
- Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land. We have 2 islands.
- Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land. We have 3 islands.
Example 2:

Input: m = 1, n = 1, positions = [[0,0]]
Output: [1]
 

Constraints:

1 <= m, n, positions.length <= 104
1 <= m * n <= 104
positions[i].length == 2
0 <= ri < m
0 <= ci < n
 

Follow up: Could you solve it in time complexity O(k log(mn)), where k == positions.length?
*/

class Solution {
public:
    vector<vector<int>>land;
    int step[5] = {-1, 0, 1, 0, -1};
    class unionF {
        public:
            vector<int>parent, rank;
            unionF (int n) {
                parent = vector<int>(n, 0);
                rank = vector<int>(n, 0);
            };
            bool Union(int a, int b) {
                int pa = find(a);
                int pb = find(b);
                if (pa == pb) return false;
                if (rank[pa] > rank[pb]) {
                    parent[pb] = pa;
                } else if (rank[pa] < rank[pb]) {
                    parent[pa] = pb;
                } else {
                    parent[pa] = pb;
                    rank[pb]++;
                }
                return true;
            }
            int find(int a) {
                if (parent[a] == a) return a;
                return parent[a] = find(parent[a]);
            }

    };
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        land = vector<vector<int>>(m, vector<int>(n, 0));
        int s = 0, no = 1,x, y;
        unionF uf(m*n+1);
        for (int i = 0; i < uf.parent.size(); i++) uf.parent[i] = i;
        vector<int>ans;
        for (int i = 0; i < positions.size(); i++) {
            if (land[positions[i][0]][positions[i][1]]) {
                ans.push_back(s);
                continue;
            }
            for (int j = 0; j < 4; j++) {
                x = positions[i][0]+step[j];
                y = positions[i][1]+step[j+1];
                if (x < m && x > -1 && y < n && y > -1) {
                    if (land[x][y]) {
                        if (uf.Union(land[x][y], no)) s--;
                    }
                }
            }
            s++;
            land[positions[i][0]][positions[i][1]] = no;
            no++;

            ans.push_back(s);
        }

        return ans;
    }
};
