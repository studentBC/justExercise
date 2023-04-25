class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        small, big = [], []
        for i in range(len(arrays)):
            small.append((arrays[i][0], i))
            big.append((arrays[i][-1], i))
        ss = sorted(small, key=lambda x:(x[0], x[1]))
        bb = sorted(big, key=lambda x:(x[0], x[1]), reverse=True)
        ans = 0
        for i in range(len(ss)):
            for j in range(len(bb)):
                if ss[i][1] != bb[j][1]:
                    ans = max(ans, bb[j][0]-ss[i][0])
                    break
        return ans

        

