class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        ans = 0
        count = dict()
        for i in range(len(time)):
            time[i]%=60
            if time[i] in count:
                count[time[i]].append(i)
            else:
                count[time[i]] = [i]

        for k, v in count.items():
            if k == 0 or k == 30:
                n = len(v)
                ans+=(n*(n-1))/2
            else:
                if (60-k) in count:
                    l = len(count[60-k])
                    for j in v:
                        index = bisect.bisect_left(count[60-k], j)
                        ans+= (l-index)
        return int(ans)
        
