"""
Intuition
We can move level by level from the the leaves and make sure that the adjacent nodes have equal cost. First make the cost of adjacent leaves equal. Then move one level up. Make sure that the cost of the two children are equal and so on. If they are not equal just increment the node with the lower cost to make it equal to the other node.

Approach
Use (2 * i + 1) instead of 2 * i for child node because 2 * i will go into infinite loop when you run dfs(0)
"""

class Solution:
    def minIncrements(self, n: int, cost: List[int]) -> int:
        self.ans = 0
        def go(n):
            if n >= len(cost): return 0
            a, b = go(2*n+1), go(2*n+2)
            self.ans+=abs(a-b)
            print(a, b, self.ans)
            return cost[n]+max(a,b)
        go(0)
        return self.ans
