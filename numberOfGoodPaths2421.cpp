/*
Intuition
An intuitive approach would be to start from a node and traverse to its neighbors, which have a lower value than the node. From the neighbors, we move to their neighbors. If we find another node with a value similar to the start node, we have one good path. We can repeat the same process for every node in the tree. In such a way, we traverse the tree, moving to neighbors with lower values for every node, and count the total number of good paths. We can choose BFS or DFS for the graph traversal. Each graph traversal takes O(n) time, and since we would do a complete traversal starting from every node, we would take O(n^2) time. This approach would indicate that the time limit has been exceeded (TLE).

Let's think of a faster way by making some observations.

There is no point in traversing from a node to its neighbor where the vals[neighbor] > vals[node]. It violates the good path constraints. So, for any node, the only nodes that matter are the ones that have values less than vals[node]. Intuitively, this does give some hints about sorting the nodes according to their values, starting with the smallest value first and then going to higher values.

Let's look at an example. Consider a node with the value X in a tree T. Let's try to find the number of good paths that start and end with the value X. The nodes having values greater than X are of no use, so let's remove them and form a new subgraph of all the nodes (and edges in T connected to these nodes) having values less than or equal to X. Note that the new subgraph could be a connected tree, or there could be multiple connected trees separated from each other.

Let's say we have two existing trees (components) c1 and c2 which are subgraphs of T.

Imagine if there were 6 nodes with the value X, say a, b, c, d, e, and f. We want to add all of them to the subgraph and find the number of good paths starting and ending with X. Let's say a, b, and c connect with some nodes in c1. Nodes d and e connect with some nodes in c2. Node f does not connect with any existing component and creates a new component c3 with just the node f.

Let's compute the number of good paths. In component c1, if we start with node a we get three good paths. The a node itself as well as the paths from a to b and a to c. For node b, we have the node itself and the path to c (the path to a is already covered). And for node c, we just have the node itself. So, there are six good paths formed in component c1. What if there were N nodes in place of three? Starting from the first node, we would have N good paths: the node itself and N - 1 paths to other nodes with the same value. For the second node, we would have N - 1 options (since the first node is already covered), and so on. So, if N nodes having the same value connect in a component, the good paths would be N + N - 1 + N - 2 + .. + 1 = N * (N + 1) / 2.

Similary, we can count three good paths forming in component c2. We can also use the same formula with N = 2 which gives (2 * (2 + 1) / 2) = 3 good paths.

For the component c3, there is one good path for node f, the node itself. It needs nodes with higher values to connect to other nodes in the original tree T, which do not lead to the formation of a good path. Here, N = 1, so using the formula gives us one good path.

Having added all the nodes with the value X, how can we compute the good paths with starting nodes having a value X + 1 (or next higher value)? To the subgraph formed above, we add all the nodes having the value X + 1 and repeat the same process to compute all the good paths starting with the value X + 1. The nodes with the value X can serve as intermediate nodes in a good path starting and ending with the value X + 1.

We can extend the above to start with value 1 first, then add nodes with value 2, then add nodes with value 3, and so on, to the subgraph formed in the previous iteration. We should begin from the lowest and move to the higher values of the nodes. For each value, we should add all the nodes with the same value to the existing subgraph and calculate the number of good paths formed in each component. This way, we build the complete tree at the end by adding nodes of the same value at each step.

This approach can be implemented with a disjoint-set data structure, also called a union-find data structure. It is a data structure that stores a collection of disjoint (non-overlapping) sets. Equivalently, it stores a partition of a set into disjoint subsets. It provides operations for adding new sets, merging sets (replacing them by their union), and finding a representative member of a set. It implements two useful operations:

a) Find: Determine which subset a particular element is in. This can be used to determine if two elements are in the same subset. b) Union: Join two subsets into a single subset.

If you are new to Union-Find, we suggest you read our Leetcode Explore Card. We will not talk about implementation details in this article, but only about the interface to the data structure.

In this approach, we will create a map, say valuesToNodes to map a value to all the nodes that have that value. The map is sorted with respect to the keys, which are the node values. We iterate over every value, nodes[] entry in valuesToNodes.

For each node in nodes[], we check all neighbor. If vals[node] >= vals[neighbor], neighbor is already covered, and it is a node in the subgraph. It can be used as an intermediate node in a good path if formed using it. We perform union (node, neighbor) to add node to the current subgraph. Otherwise, if vals[node] < vals[neighbor], the node is not added to the existing components, and it creates a new component with the node itself.

The next step is to compute the number of nodes with the same value added to each component and use the above formula to count the number of good paths. We can do this by using a map, say groups where the key is the unique id of the component (or tree) and the value is the count of nodes from nodes[] in that component. Iterate over all the nodes[] and for each node, we increment group[find(node)] by one. This way, we have the count of nodes in each component.

We iterate over the group map, and for each entry id, size, we add size * (size + 1) / 2 to the count of good paths.
*/

class uf {
    public:
        vector<int>parent, rank;
        uf (int size) {
            parent.resize(size);
            rank.resize(size, 0);
            for (int i = 0; i < size; i++) parent[i] = i;
        }
        int find (int x) {
            if (parent[x]!=x) parent[x] = find(parent[x]);
            return parent[x];
        }
        void union_set(int x, int y) {
            int px = find(x), py = find(y);
            if (px == py) return;
            else if (rank[px] < rank[py]) parent[px] = py;
            else if (rank[px] > rank[py]) parent[py] = px;
            else {
                parent[py] = px;
                rank[px]++;
            }
        }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>>graph(n);
        for (auto& it: edges) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        map<int, vector<int>>index; //key: value 
        for (int i = 0; i < n; i++) {
            index[vals[i]].push_back(i);
        }
        uf dsu(n);
        int ans = 0;
        for (auto& it: index) {
            for (int i : it.second) {
                for (int neighbor : graph[i]) {
                    if (vals[i] >= vals[neighbor]) {
                        dsu.union_set(i, neighbor);
                    }
                }
            }
            unordered_map<int, int>group;
            for (int n : it.second) {
                group[dsu.find(n)]++;
            }
            for (auto& it : group) {
                ans+= (it.second*(it.second+1)/2);
            }
        }
        return ans;
    }
};
