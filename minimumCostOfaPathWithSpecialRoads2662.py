import heapq
class Solution:
    def minimumCost(self, start: List[int], target: List[int], specialRoads: List[List[int]]) -> int:
        specialRoads = [[a,b,c,d,x] for a,b,c,d,x in specialRoads if x < abs(a-c)+abs(b-d)]
        dist = {(start[0], start[1]): 0}
        pq = [(0, start[0], start[1])]
        while len(pq) > 0:
            curdist, x, y = heapq.heappop(pq)
            for a, b, c, d, cost in specialRoads:
                if dist.get((c, d), float('inf')) > curdist + abs(x-a)+abs(y-b) + cost:
                    dist[(c,d)] = curdist + abs(x-a)+abs(y-b) + cost
                    heapq.heappush(pq, (dist[(c,d)], c, d))
        ans = abs(target[1]-start[1]) + abs(target[0]-start[0])
        for a,b,c,d,cost in specialRoads:
            ans = min(ans, dist.get((c, d), float('inf'))+abs(target[0]-c)+abs(target[1]-d))
        return ans
