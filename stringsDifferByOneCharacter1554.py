class Solution:
    def differByOne(self, dict: List[str]) -> bool:
        n, m = len(dict), len(dict[0])
        for j in range(m):
            s = set()
            for i in range(n):
                tmp = dict[i][:j]+'*'+dict[i][j+1:]
                if tmp in s:
                    return True
                s.add(tmp)
        return False
