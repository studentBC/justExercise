class Solution:
    def minimizeSet(self, divisor1: int, divisor2: int, uniqueCnt1: int, uniqueCnt2: int) -> int:
        l, r, g = 0, 10**10, lcm(divisor1, divisor2)
        while l < r:
            m = (l+r)//2
            x = m-m//divisor1 >= uniqueCnt1
            y = m-m//divisor2 >= uniqueCnt2
            z = m-m//g >= uniqueCnt1 + uniqueCnt2
            if x and y and z: r = m
            else : l = m+1
        return l 
