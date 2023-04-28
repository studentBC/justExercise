class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ans, count = 0, 0
        num = []
        #print(len(nums))
        for i in nums:
            if i == 0:
                if count > 0:
                    num.append(count)
                num.append(0)
                count = 0
            else:
                count+=1
                ans = max(ans, count)
        if count > 0:
            num.append(count)
        left, right = 0, 0
        #print(num)
        for i in range(len(num)):
            if num[i] == 0:
                left = right = 0
                if i > 0 and num[i-1] > 0:
                    left = num[i-1]
                if i+1 < len(num) and num[i+1] > 0:
                    right = num[i+1]
                ans = max(ans, left+right+ 1)
        return ans
                
