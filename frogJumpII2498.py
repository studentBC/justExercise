class Solution:
    def maxJump(self, stones: List[int]) -> int:
        l, r, n = 1, stones[-1]-stones[0], len(stones)
        def check(step):
            prev = 0
            notused = [True]*(n+1)
            i = 1
            while prev < n-1:
                next = -1
                for i in range(prev+1, n):
                    if stones[i]-stones[prev] <= step:
                        if notused[i]:
                            next = i
                    else:
                        break
                if next < 0:
                    return False
                else:
                    prev = next
                    notused[prev] = False
                
            prev = n-1
            notused[-1] = True
            while prev > 0:
                next = -1
                for i in range(prev-1, -1, -1):
                    if stones[prev]-stones[i] <= step:
                        if notused[i]: next = i
                    else:
                        break
                if next < 0:
                    return False
                else:
                    prev = next
                    notused[prev] = False
            return True

        while l <= r:
            mid = (l+r)//2
            if check(mid):
                r = mid-1
            else:
                l = mid+1
        return l

