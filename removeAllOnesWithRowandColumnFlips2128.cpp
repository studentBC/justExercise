/*
You are given an m x n binary matrix grid.

In one operation, you can choose any row or column and flip each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Return true if it is possible to remove all 1's from grid using any number of operations or false otherwise.

 

Example 1:


Input: grid = [[0,1,0],[1,0,1],[0,1,0]]
Output: true
Explanation: One possible way to remove all 1's from grid is to:
- Flip the middle row
- Flip the middle column
Example 2:


Input: grid = [[1,1,0],[0,0,0],[0,0,0]]
Output: false
Explanation: It is impossible to remove all 1's from grid.
Example 3:


Input: grid = [[0]]
Output: true
Explanation: There are no 1's in grid.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is either 0 or 1.


this kind of matrix has a property:
<Each row is the exact same.>
If we then flip some rows, that leaves only two possible arrangements for each row: the same as the original or the opposite.
*/
class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        vector<int>r1 = grid[0], rr1;
        for (int i = 0; i < r1.size(); i++) rr1.push_back(1-r1[i]);
        bool valid;
        for (int i = 1; i < grid.size(); i++) {
            valid = true;
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == r1[j]) continue;
                else {
                    valid = false;
                    break;
                }
            }
            if (valid) continue;
            valid = true;
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == rr1[j]) continue;
                else {
                    valid = false;
                    break;
                }
            }
            if (!valid) return false;
        }
        return true;
    }
};

class Solution:
    def removeOnes(self, grid: List[List[int]]) -> bool:
        r1, r1_invert = grid[0], [1-val for val in grid[0]]
        for i in range(1, len(grid)):
            if grid[i] != r1 and grid[i] != r1_invert:
                return False
        return True
