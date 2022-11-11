class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        sum = a+b+c
        A, B, C = 0, 0, 0
        s = []
        ans = ""
        for i in range(0, sum):
            if (a>=b and a>= c and A !=2) or (B == 2 and a > 0) or (C == 2 and a > 0):
                s.append('a')
                a-=1
                A+=1
                B, C = 0,0
            elif (b>=a and b>= c and B !=2) or (A == 2 and b > 0) or (C == 2 and b > 0):
                s.append('b')
                b-=1
                B+=1
                A, C= 0,0
            elif (c>=a and c>= b and C !=2) or (A == 2 and c > 0) or (B == 2 and c > 0):
                s.append('c')
                c-=1
                C+=1
                A=B=0
        for c in s:
            ans+=c 
        return ans 
