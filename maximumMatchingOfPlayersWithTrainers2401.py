class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        heapq.heapify(players)
        heapq.heapify(trainers)
        ans = 0
        while (len(players) and len(trainers)):
            p = heapq.heappop(players)
            t = heapq.heappop(trainers)
            while p > t and len(trainers):
                t = heapq.heappop(trainers)
            if p <= t:
                ans+=1
                
        return ans
        
