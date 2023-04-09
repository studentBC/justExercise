class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        nums.sort()
        l, r, n = 0, nums[-1]-nums[0], len(nums)
        while l < r:
            mid = (l+r)//2
            count, i = 0, 1
            while i < n:
                if nums[i]-nums[i-1] <= mid:
                    count+=1
                    i+=1
                i+=1
            if count >= p:
                r = mid
            else:
                l = mid+1
        return l
