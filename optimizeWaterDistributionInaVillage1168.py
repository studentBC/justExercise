"""
There are n houses in a village. We want to supply water for all the houses by building wells and laying pipes.

For each house i, we can either build a well inside it directly with cost wells[i - 1] (note the -1 due to 0-indexing), or pipe in water from another well to it. The costs to lay pipes between houses are given by the array pipes where each pipes[j] = [house1j, house2j, costj] represents the cost to connect house1j and house2j together using a pipe. Connections are bidirectional, and there could be multiple valid connections between the same two houses with different costs.

Return the minimum total cost to supply water to all houses.

 

Example 1:


Input: n = 3, wells = [1,2,2], pipes = [[1,2,1],[2,3,1]]
Output: 3
Explanation: The image shows the costs of connecting houses using pipes.
The best strategy is to build a well in the first house with cost 1 and connect the other houses to it with cost 2 so the total cost is 3.
Example 2:

Input: n = 2, wells = [1,1], pipes = [[1,2,1],[1,2,2]]
Output: 2
Explanation: We can supply water with cost two using one of the three options:
Option 1:
  - Build a well inside house 1 with cost 1.
  - Build a well inside house 2 with cost 1.
The total cost will be 2.
Option 2:
  - Build a well inside house 1 with cost 1.
  - Connect house 2 with house 1 with cost 1.
The total cost will be 2.
Option 3:
  - Build a well inside house 2 with cost 1.
  - Connect house 1 with house 2 with cost 1.
The total cost will be 2.
Note that we can connect houses 1 and 2 with cost 1 or with cost 2 but we will always choose the cheapest option. 
pproach 1: Prim's Algorithm with Heap
Intuition

Prim's (also known as Jarník's) algorithm is a greedy algorithm used to find the minimum spanning tree in a weighted and undirected graph.

The algorithm operates by building the tree one vertex at a time, from an arbitrary starting vertex, at each step adding the cheapest possible connection from any vertex in the tree to a vertex that is not in the tree.

Prim Demo

The above illustration demonstrates how Prim's algorithm works.
Starting from an arbitrary vertex, Prim's algorithm grows the minimum spanning tree by adding one vertex at a time to the tree.
The choice of a vertex is based on the greedy strategy, i.e. the addition of the new vertex incurs the minimum cost.

Algorithm

To implement Prim's algorithm, essentially we will need the following three data structures:

adjacency list: we need this to represent the graph, i.e. vertices and edges. The adjacency list can be a list of lists or a dictionary of lists.

set: we need a set to maintain all the vertices that we have added to the final minimum spanning tree, during the construction of the tree.
With the help of set, we can determine whether a vertex has been added or not.

heap: due to the nature of the greedy strategy, at each step, we can determine the best edge to be added based on the cost it will add to the tree.
Heap (also known as a priority queue) is a data structure that allows us to retrieve the minimum element in constant time and to remove the minimum element in logarithmic time. This fits our need to repeatedly find the lowest cost edge perfectly.

Implementation

By applying the above three data structures, the following steps can be used to implement Prim's algorithm.

First of all, given the input, we need to build a graph representation with the adjacency list.

Note that, since the graph is undirected (i.e. bidirectional), for each pipe, we need to add two entries in the adjacency list, with each end of the pipe as a starting vertex.
Also, to convert our problem into the MST problem, we need to add a virtual vertex (we index it as 0) together with the additional n edges to each house.
Starting from the virtual vertex, we build the MST by iteratively adding one vertex at a time.

Note, when using Prim's algorithm, we can use any vertex as a starting point.
Here, for the sake of convenience, we start from the newly-added virtual vertex.
The process of building MST consists of a loop with the following substeps:

Each iteration, we pop an element from the heap. This element contains a vertex along with the cost that is associated with the edge that connecting the vertex to the tree.
The vertex is chosen if it is not already in the tree.
We know that the cost of this vertex is minimal among all choices because it was popped from the heap.

Once the vertex is added, we then examine its neighboring vertices.
Specifically, we add these vertices along with their edges into the heap as the candidates for the next round of selection.

The loop terminates when we have added all the vertices from the graph into the MST.

"""


class Solution:
    def minCostToSupplyWater(self, n: int, wells: List[int], pipes: List[List[int]]) -> int:

        # bidirectional graph represented in adjacency list
        graph = defaultdict(list)

        # add a virtual vertex indexed with 0.
        #   then add an edge to each of the house weighted by the cost
        for index, cost in enumerate(wells):
            graph[0].append((cost, index + 1))

        # add the bidirectional edges to the graph
        for house_1, house_2, cost in pipes:
            graph[house_1].append((cost, house_2))
            graph[house_2].append((cost, house_1))

        # A set to maintain all the vertex that has been added to
        #   the final MST (Minimum Spanning Tree),
        #   starting from the vertex 0.
        mst_set = set([0])

        # heap to maitain the order of edges to be visited,
        #   starting from the edges originated from the vertex 0.
        # Note: we can start arbitrarily from any node.
        heapq.heapify(graph[0])
        edges_heap = graph[0]

        total_cost = 0
        while len(mst_set) < n + 1:
            cost, next_house = heapq.heappop(edges_heap)
            if next_house not in mst_set:
                # adding the new vertex into the set
                mst_set.add(next_house)
                total_cost += cost
                # expanding the candidates of edge to choose from
                #   in the next round
                for new_cost, neighbor_house in graph[next_house]:
                    if neighbor_house not in mst_set:
                        heapq.heappush(edges_heap, (new_cost, neighbor_house))

        return total_cost
