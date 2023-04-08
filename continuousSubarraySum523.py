class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        used = dict()
        s = 0
        for i in range(len(nums)):
            s+=nums[i]
            s%=k
            if s == 0 and i > 0:
                return True
            if s in used:
                if i-used[s] > 1: return True
            else:
                used[s] = i
        return False
