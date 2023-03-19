#Explanation
#Split A[i] into different group by the value of A[i] % k.
#Count the frequency of A[i].
#Sort A[i] and then do 198. House Robber.
#
#dp0 is the ways that without A[i]
#dp1 is the ways that with A[i]
#
class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        count = [Counter() for i in range(k)]
        for i in nums:
            count[i%k][i]+=1
        ans = 1
        for i in range(k):
            prev, dp0, dp1 = 0, 1, 0
            for c in sorted(count[i]):
                v = pow(2, count[i][c])
                if prev+k == c:
                    dp0, dp1 = dp0+dp1, dp0*(v-1)
                else:
                    dp0, dp1 = dp0+dp1, (dp1+dp0)*(v-1)
                prev = c
            ans*=dp0+dp1
        return ans-1
