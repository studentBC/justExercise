class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        row = len(triangle)
        dp = []
        dp.append(triangle[0])
        for i in range(1, row):
            tmp = []
            col = len(triangle[i-1])
            for j in range(0, len(triangle[i])):
                left, right = 1e9, 1e9
                if  col > j:
                    right = dp[i-1][j]
                
                if j > 0:
                    left = dp[i-1][j-1]
                else:
                    left = dp[i-1][0]
                tmp.append(min(left, right)+triangle[i][j])
            dp.append(tmp)
        #print(dp[-1])
        return min(dp[-1])
