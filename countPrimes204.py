class Solution:
    def countPrimes(self, n: int) -> int:
        np = [False]*n
        ans = 0
        for i in range(2, n):
            if np[i] == False:
                ans+=1
                for j in range(2, n):
                    if j*i >= n:
                        break
                    np[j*i] = True
        return ans
