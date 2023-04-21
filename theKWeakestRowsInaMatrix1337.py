class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        row = len(mat)
        rank, ans = [], []
        for i in range(row):
            c = mat[i].count(1)
            rank.append((c, i))
        tmp = sorted(rank, key=lambda x:(x[0], x[1]))
        for i in range(k):
            ans.append(tmp[i][1])
        return ans
        
