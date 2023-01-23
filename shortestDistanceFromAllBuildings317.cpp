/*
Intuition

Instead of making a new matrix each time to track the visited cells, we can use the input grid matrix for this purpose. During the first BFS we can change the visited empty land values from 0 to -1. Then during the next BFS we will only visit empty lands with a value of -1s (meaning they can reach the first house), then change -1 to -2 and then perform the next BFS only on -2s, and so on...

This approach allows us to avoid visiting any cell that cannot reach all houses.

Can we also use this decrement in empty land value to denote that the cell has been visited?

Imagine we are currently at cell (2, 3) with value -1 and we change its value to -2.
In the queue the next element is (2, 4), its value is also -1 and we change its value to -2. While exploring paths from (2, 4), we see that the cell (2, 3) is adjacent, and has the value -2. However, currently, we are checking for -1 valued cells only. Hence, (2, 3) will not be inserted again in the queue, so this decrease in value can be used as a visited cell check because when a cell has been visited, then its value will be 1 less and it will not satisfy the condition to be inserted in the queue.

If there was an empty land cell that was not reachable in the previous iteration, then its value has not been decreased, hence we will not insert that cell in the queue when we start a BFS from another house cell.
Therefore, this approach prunes many iterations and saves some time since we are not creating a new matrix to track visited cells for each BFS call.

Algorithm

For each grid[i][j] that is equal to 1, start a BFS. During the BFS:
All 4-directionally adjacent grid cells with values equal to emptyLandValue are valid.
Visit them one by one and store the distances of these cells from the source in a total matrix.
Decrease the value of visited cells by 1.
After each BFS traversal, decrement emptyLandValue by 1.
Before we start a BFS call for a house, we set minDist equal to INT_MAX.
Then we will traverse all of the empty land cells with values equal to emptyLandValue
After the last BFS traversal, if the minimum distance equals INT_MAX, then there has not been any cell that can be reached by all the houses, so return -1.
Otherwise, return the minimum distance minDist.
*/

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), x, y;
        int steps[5] = {-1 , 0, 1, 0, -1};
        int emptyLandValue = 0, ans = INT_MAX;
        vector<vector<int>>total(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    ans = INT_MAX;
                    int step = 0;
                    queue<pair<int, int>> next;
                    next.push({i, j});
                    while (!next.empty()) {
                        step++;
                        for (int k = next.size(); k > 0; k--) { //good work here
                            for (int a = 0; a < 4; a++) {
                                x = next.front().first+steps[a];
                                y = next.front().second+steps[a+1];
                                if (x < 0 || x >= row || y < 0 || y >= col || grid[x][y]!= emptyLandValue) continue;
                                grid[x][y]--;
                                total[x][y]+=step;
                                next.push({x, y});
                                ans = min(ans, total[x][y]);
                            }
                            next.pop();
                        }
                    }
                    emptyLandValue--;
                }
            }
        }
        return ans == INT_MAX? -1 : ans;
    }
};
