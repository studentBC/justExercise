class Solution(object):
    def longestSubarray(self, nums, limit):
        """
        :type nums: List[int]
        :type limit: int
        :rtype: int
        """
        maxq,minq = [], []
        ans = i = 0
        for j, num in enumerate(nums):
            heapq.heappush(maxq, [-num, j])
            heapq.heappush(minq, [num, j])
            while -maxq[0][0] - minq[0][0] > limit:
                i = min(maxq[0][1], minq[0][1])+1
                while maxq[0][1] < i: heapq.heappop(maxq)
                while minq[0][1] < i: heapq.heappop(minq)
            ans = max(ans, j-i+1)
        return ans
