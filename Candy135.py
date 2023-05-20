class Solution:
    def candy(self, ratings: List[int]) -> int:
        tmp = []
        for i in range(len(ratings)):
            tmp.append((ratings[i], i))
        rat = sorted(tmp, key=lambda t: (t[0], t[1]))
        ans = 0
        ll = len(rat)
        given = [0]*ll
        for i in range(ll):
            give = 1
            if rat[i][1] > 0:
                if ratings[rat[i][1]] > ratings[rat[i][1]-1]:
                    give = max(give, given[rat[i][1]-1]+1)
            if rat[i][1]+1 < ll:
                if ratings[rat[i][1]] > ratings[rat[i][1]+1]:
                    give = max(give, given[rat[i][1]+1]+1)
            given[rat[i][1]] = give 
            ans+=give
        return ans 

