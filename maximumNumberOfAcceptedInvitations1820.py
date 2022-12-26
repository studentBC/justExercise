"""
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
"""

class Solution:
    def maximumInvitations(self, grid: List[List[int]]) -> int:
        M, N = len(grid), len(grid[0])
        matches = {}                        # Stores matches formed. key = girl, value = boy.
        
        def dfs(boy: int, visited: set) -> bool:
            """A depth first search function to match a boy at index `boy` with potential girls.
            
            DFS will go through all of the boy's options and choose the one that maximizes global
            optimum.
            """
            
            for girl in range(N):
                
                # Rule 1. Only ask that girl if you haven't asked her before already.
                # Rule 2. If you wish to ask a girl that's taken, she will only go with you
                #         if her current partner finds a new girl.
                
                if grid[boy][girl] and girl not in visited:
                    visited.add(girl)
                    
                    if girl not in matches or dfs(matches[girl], visited): 
                        matches[girl] = boy                        
                        return True
                
            return False
            
        for boy in range(M):
            dfs(boy, set())
            
        return len(matches)
