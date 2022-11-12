#Binary Search
# Let's subtract (the corresponding values) the second array from the first one (n1[i] -= n2[i]). After this, we need to find pairs like n1[i] + n2[j] > 0.

# First, we can realize that we do not need to honor the i < j constraint, as the equation can be rewritten as n1[j] + n2[i] > 0. Therefore, we can sort the entire array, and for each n1[i], count how many values are greater than -n1[i]. We just need to make sure that we do not double-count our pairs by only considering values on the right side of i.
class Solution:
    def countPairs(self, nums1: List[int], nums2: List[int]) -> int:
        nums = [x-y for x, y in zip(nums1, nums2)]
        print(nums)
        nums.sort()
        print(nums)
        ans, n = 0, len(nums)
        for i,x in enumerate(nums):
            index = bisect_left(nums, 1-x)
            ans+= n-max(i+1, index)
        return ans
