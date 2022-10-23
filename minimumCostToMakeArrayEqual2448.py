#Assume the final equal values are x
#the total cost function y = f(x) is a convex function
#on the range of [min(A), max(A)].
#
#To find the minimum value of f(x),
#we can binary search x by comparing f(mid) and f(mid + 1).
#
#If f(mid) <= f(mid + 1),
#the minimum f(x) is on the left of mid,
#where x <= mid
#
#If f(mid) >= f(mid + 1),
#the minimum f(x) is on the right of mid + 1,
#where x >= mid.
#
#Repeatly doing this while left < right,
#until we find the minimum value and return it.
#
#This method is known as trinary search,
#if we check f(mid1) and f(mid2).

class Solution:
    def minCost(self, nums: List[int], cost: List[int]) -> int:
        def get(x):
            return sum(abs(i-x)*c for i, c in zip(nums, cost))

        left, right = min(nums), max(nums)
        ans = get(left)
        while left < right:
            mid = (left+right)//2
            y1, y2 = get(mid), get(mid+1)
            ans = min(y1, y2)
            if y1 < y2:
                right = mid
            else:
                left = mid+1
        return ans

