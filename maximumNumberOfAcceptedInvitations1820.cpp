/*
 There are m boys and n girls in a class attending an upcoming party.

You are given an m x n integer matrix grid, where grid[i][j] equals 0 or 1. If grid[i][j] == 1, then that means the ith boy can invite the jth girl to the party. A boy can invite at most one girl, and a girl can accept at most one invitation from a boy.

Return the maximum possible number of accepted invitations.

 

Example 1:

Input: grid = [[1,1,1],
               [1,0,1],
               [0,0,1]]
Output: 3
Explanation: The invitations are sent as follows:
- The 1st boy invites the 2nd girl.
- The 2nd boy invites the 1st girl.
- The 3rd boy invites the 3rd girl.
Example 2:

Input: grid = [[1,0,1,0],
               [1,0,0,0],
               [0,0,1,0],
               [1,1,1,0]]
Output: 3
Explanation: The invitations are sent as follows:
-The 1st boy invites the 3rd girl.
-The 2nd boy invites the 1st girl.
-The 3rd boy invites no one.
-The 4th boy invites the 2nd girl.
 

Constraints:

grid.length == m
grid[i].length == n
1 <= m, n <= 200
grid[i][j] is either 0 or 1.

solution refer to:
https://www.geeksforgeeks.org/maximum-bipartite-matching/
 */
class Solution {
public:
    int girls;
    bool go (vector<vector<int>>& grid, int start, vector<bool>& visited, vector<int>& match) {
        for (int i = 0; i < girls; i++) {
            if (grid[start][i] && !visited[i]) {
                visited[i] = true;
                if (match[i] < 0 || go (grid, match[i], visited, match)) {
                    match[i] = start;
                    return true;
                }
            }
        }
        return false;
    }
    int maximumInvitations(vector<vector<int>>& grid) {
        int row = grid.size(), ans = 0, girls = grid[0].size();
        vector<int>match(girls, -1);
        for (int i = 0; i < row; i++) {
            vector<bool> visited(girls, false);
            if (go(grid, i, visited, match)) ans++;
        }
        return ans;
    }
};
