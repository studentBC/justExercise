class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        sum = 0
        for i in range(len(shift)):
            if shift[i][0] == 0:
                sum-=shift[i][1]
            else:
                sum+=shift[i][1]
        #print(sum)
        n = len(s)
        sum%=n
        if sum == 0:
            return s
        elif sum < 0:
            n = -sum
            return s[: n]+s[n: ]
        else:
            n-=sum
            return s[n: ] + s[: n]
