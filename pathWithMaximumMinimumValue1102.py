"""
Given an m x n integer matrix grid, return the maximum score of a path starting at (0, 0) and ending at (m - 1, n - 1) moving in the 4 cardinal directions.

The score of a path is the minimum value in that path.

For example, the score of the path 8 → 4 → 5 → 9 is 4.
 

Example 1:


Input: grid = [[5,4,5],[1,2,6],[7,4,6]]
Output: 4
Explanation: The path with the maximum score is highlighted in yellow. 
Example 2:


Input: grid = [[2,2,1,2,2,2],[1,2,2,2,1,2]]
Output: 2
Example 3:


Input: grid = [[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
0 <= grid[i][j] <= 109
"""
class Solution:
    def maximumMinimumPath(self, grid: List[List[int]]) -> int:
        R = len(grid)
        C = len(grid[0])

        # 4 directions to a cell's possible neighbors.
        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        
        # Check if we can find a path of value = val.
        def path_exists(val):
            visited = [[False] * C for _ in range(R)]         
            def dfs(cur_row, cur_col):
                # If we reach the bottom-right cell, return true.
                if cur_row == R - 1 and cur_col == C - 1:
                    return True

                # Mark the current cell as visited.
                visited[cur_row][cur_col] = True
                for d_row, d_col in dirs:
                    new_row = cur_row + d_row
                    new_col = cur_col + d_col

                    # Make sure (new_row, new_col) is on the grid and has not been visited.
                    if not (0 <= new_row < R and 0 <= new_col < C) or visited[new_row][new_col]:
                        continue

                    # Check if the current cell has any unvisited neighbors
                    # with value greater than or equal to val.
                    if grid[new_row][new_col] >= val and dfs(new_row, new_col):
                        # If so, we continue search on this neighbor.
                        return True
                return False            
            return dfs(0,0)   
                        
        left = 0
        right = min(grid[0][0], grid[-1][-1])
 
        while left < right:
            # Get the middle value between left and right boundaries.
            middle = (left + right + 1) // 2

            # Check if we can find a path with value = middle, and cut 
            # the search space by half.
            if path_exists(middle):
                left = middle
            else:
                right = middle - 1
        
        # Once the left and right boundaries coincide, we find the target value,
        # that is, the maximum value of a path.
        return left
