#dp(i,j,k) means the cost that,
#to fix robot[i] and its following roberts
#with factory[j] already fix k robert.
#
#In each iteration of DP:
#If i == robot.length,
#means already fixed all robert,
#return cost = 0.
#
#If j == factory.length,
#means no more available factory
#return cost = inf.
#
#Option 1: Skip the current factory[i], res1 = dp(i, j + 1, 0)
#Option 2: Fix in the current factory[i] with cost abs(A[i] - B[j][0])
#Still need to fix robert[i + 1] and other roberts,
#so res2 = dp(i + 1, j, k + 1) + abs(A[i] - B[j][0])
#
#Finally return min(res1, res2) as the result.
#
class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        robot.sort()
        factory.sort()
        @lru_cache(None)
        def go(i, j, k):
            if i == len(robot): return 0
            if j == len(factory): return inf
            skip = go(i, j+1, 0)
            cur = go(i+1, j, k+1) + abs(robot[i]-factory[j][0]) if factory[j][1] > k else inf
            return min(skip, cur)
        return go(0, 0, 0)
