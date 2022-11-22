class Solution:
    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        graph = defaultdict(list)
        for x, y in roads:
            graph[x].append(y)
            graph[y].append(x)
        self.ans = 0
        def go (i, prev, people = 1):
            for x in graph[i]:
                if x == prev: continue
                people+=go(x, i)
            self.ans+=( int(ceil(people/seats)) if i else 0)
            return people
        go(0, 0) 
        return self.ans
