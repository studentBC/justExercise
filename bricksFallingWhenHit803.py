"""
Reverse Time and Union-Find [Accepted]
Disjoint Set Union (DSU) data structure
Intuition

The problem is about knowing information about the connected components of a graph as we cut vertices. In particular, we'll like to know the size of the "roof" (component touching the top edge) between each cut. Here, a cut refers to the erasure of a vertex.

As we may know, a useful data structure for joining connected components is a disjoint set union structure. The key idea in this problem is that we can use this structure if we work in reverse: instead of looking at the graph as a series of sequential cuts, we'll look at the graph after all the cuts, and reverse each cut.

Algorithm

We'll modify our typical disjoint-set-union structure to include a dsu.size operation, that tells us the size of this component. The way we do this is whenever we make a component point to a new parent, we'll also send it's size to that parent.

We'll also include dsu.top, which tells us the size of the "roof", or the component connected to the top edge. We use an ephemeral "source" node with label R * C where all nodes on the top edge (with row number 0) are connected to the source node.

For more information on DSU, please look at Approach #2 in the article here.

Next, we'll introduce A, the grid after all the cuts have happened, and initialize our disjoint union structure on the graph induced by A (nodes are grid squares with a brick; edges between 4-directionally adjacent nodes).

After, if we get an cut at (r, c) but the original grid[r][c] was always 0, then we couldn't have had a meaningful cut - the number of dropped bricks is 0.

Otherwise, we'll look at the size of the new roof after adding this brick at (r, c), and compare them to find the number of dropped bricks.

Since we were working in reverse time order, we should reverse our working answer to arrive at our final answer.
"""

class DSU:
    def __init__(self, R, C):
        self.par = range(R*C+1)
        self.rnk = [0]*(R*C+1)
        self.sz = [1]*(R*C+1)
    def find(self, x):
        if self.par[x]!=x:
            self.par[x] = self.find(self.par[x])
        return self.par[x]
    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px == py: return
        if self.rnk[px] < self.rnk[py]:
            px, py = py, px 
        if self.rnk[px] == self.rnk[py]:
            self.rnk[px]+=1
        self.par[py] = px
        self.sz[px]+=self.sz[py]
    def size(self, x):
        return self.sz[self.find(x)]
    def top(self):
        # Size of component at ephemeral "source" node at index R*C,
        # minus 1 to not count the source itself in the size
        return self.size(len(self.sz)-1)-1

class Solution(object):
    def hitBricks(self, grid, hits):
        R, C = len(grid), len(grid[0])
        def index(r, c):
            return r*C+c 
        def neighbors(r, c):
            for nr, nc in ((r-1, c), (r+1, c), (r, c-1), (r, c+1)):
                if 0 <= nr < R and 0 <= nc < C:
                    yield nr, nc
        A = [row[:] for row in grid]
        for i, j in hits:
            A[i][j] = 0
        dsu = DSU(R, C)
        for r, row in enumerate(A):
            for c, val in enumerate(row):
                if val:
                    i = index(r, c)
                    if r == 0:
                        dsu.union(i, R*C)
                    if r and A[r-1][c]:
                        dsu.union(i, index(r-1, c))
                    if c and A[r][c-1]:
                        dsu.union(i, index(r, c-1))
        ans = []
        for r, c in reversed(hits):
            pre_roof = dsu.top()
            if grid[r][c] == 0:
                ans.append(0)
            else:
                i = index(r, c)
                for nr, nc in neighbors(r, c):
                    if A[nr][nc]:
                        dsu.union(i, index(nr, nc))
                if r == 0:
                    dsu.union(i, R*C)
                A[r][c] = 1
                ans.append(max(0, dsu.top()- pre_roof -1))
        return ans[::-1]
