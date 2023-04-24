class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        total, maxSum, curMax, minSum, curMin = 0, nums[0], 0, nums[0], 0
        for i in nums:
            curMax = max(curMax+i, i)
            maxSum = max(maxSum, curMax)
            curMin = min(curMin+i, i)
            minSum = min(minSum, curMin)
            total+=i
        return max(maxSum, total-minSum) if maxSum > 0 else maxSum
