class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        left = 0
        right = max(nums)
        ans = sys.maxsize
        end = len(nums)-1
        while (left <= right):
            mid = int((left+right)/2)
            temp = nums[:]
            for i in range(end, 0, -1):
                if temp[i] > mid:
                    temp[i-1]+=(temp[i]-mid)
                    temp[i] = mid
            # for i in temp:
            #     print (i, end = ", ")
            # print()
            big = temp[0]
            ans = min(ans, max(big, mid))
            #print(mid, big)
            if big == mid:
                return big
            elif big > mid:
                left = mid+1
            else:
                right = mid-1
        return ans
                
