'''
If grid[0][1] > 1 and grid[1][0] > 1 we can not move anywhere from cell grid[0][0] hence answer is -1
Use priority queue to find next cell with minimum time to move to it
If time for a neighbor (target) cell is > 1 + time for current cell. We can not directly move to target cell. We will have to "ping pong" between previous cell and current cell. When playing ping pong between previous and current cell there can be two cases.
Let's say time for target cell is 4 and current time is 2, difference = 2 (even).
Move to prev cell, time = 3
Move to curr cell, time = 4
Move to target cell, time = 5.
Hence we reach target cell with time: target cell time + 1 when difference between target cell time and curr cell time is even.
Let's say time for target cell is 5 and current time is 2, difference = 3 (odd).
Move to prev cell, time = 3
Move to curr cell, time = 4
Move to target cell, time = 5.
Hence we reach target cell with time: target cell time when difference between target cell time and curr cell time is odd.
This "ping pong" is captured in the wait variable in the code
'''

class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1
        m, n = len(grid), len(grid[0])
        visited = set()
        direct = [-1, 0, 1, 0, -1]
        pq = [(grid[0][0], 0, 0)]
        while pq:
            time, row, col = heappop(pq)
            if row == m-1 and col == n-1:
                return time
            if (row, col) in visited:
                continue
            visited.add((row, col))
            for i in range(0, 4):
                r = row+direct[i]
                c = col+direct[i+1]
                if m > r > -1 and n > c > -1 and (r, c) not in visited:
                    wait = 0
                    if ((grid[r][c]-time)%2 == 0):
                        wait = 1
                    heappush(pq, (max(time+1, grid[r][c]+wait), r, c))
        return -1
                    
            
