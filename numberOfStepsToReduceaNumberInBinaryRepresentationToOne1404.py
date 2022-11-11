class Solution:
    def numSteps(self, s: str) -> int:
        ans, num = 0, 0
        for c in s:
            if c == '1':
                num|=1
                num<<=1
            else:
                num<<=1
        while num > 1:
            #print (num)
            if num%2 == 0:
                num>>=1
            else:
                num+=1
            ans+=1
        
        return ans-1
