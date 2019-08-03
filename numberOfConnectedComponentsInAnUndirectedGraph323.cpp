/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:

Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4 

Output: 2
Example 2:

Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

     0           4
     |           |
     1 --- 2 --- 3

Output:  1
Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/
class Solution {
public:
    void go (int i, vector<vector<int>>& edges, vector<bool>& visited) {
        if (visited[i]) return;
        visited[i] = true;
        for (int j = 0; j < edges.size(); j++) {
            if (edges[j][0] == i) {
                go (edges[j][1], edges, visited);
            } else if (edges[j][1] == i) {
                go (edges[j][0], edges, visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<bool>visited(n,false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                go (i, edges, visited);
                ans++;
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
    class UnionFind {
    public:
        UnionFind(int n) {
            parent.resize(n);
            counter = n;
            iota(parent.begin(), parent.end(), 0);
            rank.resize(n);
        }
        int Find(int i) {
            while (parent[i] != i) {
                parent[i] = parent[parent[i]];
                i = parent[i];
            }
            return i;
        } 
        void Union(int i, int j) {
            int p1 = Find(i);
            int p2 = Find(j);
            if (p1 != p2) {
                if (rank[p1] < rank[p2]) {
                    parent[p1] = p2;
                } else if (rank[p1] == rank[p2]) {
                    parent[p1] = p2;
                    ++rank[p2];
                } else {
                    parent[p2] = p1;
                }
                --counter;
            }
        }
        int GetCounter() const {
            return counter;
        }
    private:
        vector<int> parent;
        vector<int> rank;
        int counter;
    };
    
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (const auto& edge : edges) {
            uf.Union(edge[0], edge[1]);
        }
        return uf.GetCounter();
    }
};
/*the concept
This is 1D version of Number of Islands II. For more explanations, check out this 2D Solution.

n points = n islands = n trees = n roots.
With each edge added, check which island is e[0] or e[1] belonging to.
If e[0] and e[1] are in same islands, do nothing.
Otherwise, union two islands, and reduce islands count by 1.
Bonus: path compression can reduce time by 50%.
Hope it helps!
*/
public int countComponents(int n, int[][] edges) {
    int[] roots = new int[n];
    for(int i = 0; i < n; i++) roots[i] = i; 

    for(int[] e : edges) {
        int root1 = find(roots, e[0]);
        int root2 = find(roots, e[1]);
        if(root1 != root2) {      
            roots[root1] = root2;  // union
            n--;
        }
    }
    return n;
}

public int find(int[] roots, int id) {
    while(roots[id] != id) {
        roots[id] = roots[roots[id]];  // optional: path compression
        id = roots[id];
    }
    return id;
}
