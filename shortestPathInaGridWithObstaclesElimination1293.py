class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        next = deque()
        next.append((0,0,k,0))
        row = len(grid)
        col = len(grid[0])
        ans = row*col+1
        step = [-1,0,1,0,-1]
        beenTo = [ [ans]*col for i in range(row)]
        used = [ [0]*col for i in range(row)]
        while len(next) > 0:
            if next[0][0] == row-1 and next[0][1] == col-1:
                ans = min(ans, next[0][3])
            if beenTo[next[0][0]][next[0][1]] > next[0][3] or (used[next[0][0]][next[0][1]] < next[0][2] ):
                
                beenTo[next[0][0]][next[0][1]] = next[0][3]
                used[next[0][0]][next[0][1]] = next[0][2]
                for i in range(0, 4):
                    x = next[0][0]+step[i]
                    y = next[0][1]+step[i+1]

                    if x > -1 and x < row and y > -1 and y < col:
                        if grid[x][y] == 1:
                            if next[0][2] > 0:
                                next.append((x,y,next[0][2]-1, next[0][3]+1))
                        else:
                            next.append((x,y,next[0][2], next[0][3]+1))
            next.popleft()
        if ans > row*col:
            return -1
        else :
            return ans
