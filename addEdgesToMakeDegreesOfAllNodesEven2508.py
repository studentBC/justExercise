'''
Intuition
The number of odd degree node must be even: 0,2,4,...
if odd.size() == 0, return True
if odd.size() == 2, TODO
if odd.size() == 4, TODO
if odd.size() > 4, return false


Explanation
find the mapping G where G[i] is the neighbour set of node i.
Find out the list of nodes with odd degree.

In case if we have 2 odds:
option1:
we can link them together,
if they are not neighbour.

option2:
we can link both them to node i,
if node i is not neighbour of either of them.

otherwise return false.

In case if we have 4 odds a,b,c,d
option1: We can link (a,b) and (c,d)
option2: We can link (a,c) and (b,d)
option3: We can link (a,d) and (c,b)
otherwise return false.


Complexity
Time O(edges)
Space O(edges)
'''

class Solution:
    def isPossible(self, n: int, edges: List[List[int]]) -> bool:
        graph = [set() for i in range(n)]
        for i, j in edges:
            graph[i-1].add(j-1)
            graph[j-1].add(i-1)
        odd = [i for i in range(n) if len(graph[i])%2]
        def notContain(a, b):
            return a not in graph[b]
        if len(odd) == 2:
            a, b = odd
            return any(notContain(a, i) and notContain(b, i) for i in range(n))
        if len(odd) == 4:
            a, b, c, d = odd
            return notContain(a, b) and notContain(c, d) or \
                    notContain(a, c) and notContain(b, d) or \
                    notContain(a, d) and notContain(c, b)
        return len(odd) == 0

