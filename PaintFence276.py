"""
recurrence relation:
    same (dp[i-2]*(k-1)*1) + not same (dp[i-1]*(k-1))
"""

class Solution:
    def numWays(self, n: int, k: int) -> int:
        if n == 1:
            return k
        elif n == 2:
            return k*k
        dp = [0]*n
        dp[0], dp[1] = k, k*k
        for i in range(2, n):
            dp[i] = (dp[i-2]+dp[i-1])*(k-1)
        return dp[-1]
