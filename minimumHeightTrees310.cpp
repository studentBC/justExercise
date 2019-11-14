class Solution {
public:
    void go (int i, vector<vector<int>>& edges, int depth, int& deep, vector<bool>& visited, int& far) {
        if (visited[i]) return;
        if (deep < depth) {
            deep = depth;
            far = i;
        }
        visited[i]  = true;
        for (int j = 0; j < edges.size(); j++) {
            if (edges[j][0] == i ) {
                go (edges[j][1], edges, depth+1, deep, visited, far);
            } else if (edges[j][1] == i) {
                go (edges[j][0], edges, depth+1, deep, visited, far);
            }
        }
    }
    void Go (int i, int des , vector<vector<int>>& edges, vector<int>& temp, vector<int>& path, bool& found, vector<bool>& visited) {
        if (visited[i] || found) return;
        visited[i] = true;
        if (i == des) {
            found = true;
            for (int j :temp) path.emplace_back(j);
            path.emplace_back(i);
            return;
        }
        for (int j = 0; j < edges.size(); j++) {
            if (edges[j][0] == i ) {
                temp.emplace_back(i);
                Go (edges[j][1], des, edges,  temp, path, found, visited);
                temp.pop_back();
            } else if (edges[j][1] == i) {
                temp.emplace_back(i);
                Go (edges[j][0], des, edges,  temp, path, found, visited);
                temp.pop_back();
            }
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //cout << n << endl;
        int deepest = INT_MAX, deep = 0, far1 = -1, far2 = -1;
        vector<pair<int,int>>depth;
        vector<int>ans;
        if (edges.size() == 0) return {0};
        deep = 0;
        vector<bool>visited(n, false);
        go (0, edges, 0, deep, visited, far1);
        //cout << far1 << endl;
        deep = 0;
        vector<bool>visit(n, false);
        go (far1, edges, 0, deep, visit, far2);
        //cout << far1 <<" , " << far2 << endl;
        vector<int>temp, path;
        vector<bool>vis(n, false);
        bool found = false;
        //temp.emplace_back(far1);
        Go (far1, far2, edges, temp, path, found, vis);
        //for (int i :path) cout << i <<" , ";
        int half = path.size()/2;
        ans.emplace_back(path[path.size()/2]);
        if (path.size()%2 == 0) ans.emplace_back(path[half-1]);
        return ans;
    }

};
/*
First let's review some statement for tree in graph theory:

(1) A tree is an undirected graph in which any two vertices are
connected by exactly one path.

(2) Any connected graph who has n nodes with n-1 edges is a tree.

(3) The degree of a vertex of a graph is the number of
edges incident to the vertex.

(4) A leaf is a vertex of degree 1. An internal vertex is a vertex of
degree at least 2.

(5) A path graph is a tree with two or more vertices that is not
branched at all.

(6) A tree is called a rooted tree if one vertex has been designated
the root.

(7) The height of a rooted tree is the number of edges on the longest
downward path between root and a leaf.

OK. Let's stop here and look at our problem.

Our problem want us to find the minimum height trees and return their root labels. First we can think about a simple case -- a path graph.

For a path graph of n nodes, find the minimum height trees is trivial. Just designate the middle point(s) as roots.

Despite its triviality, let design a algorithm to find them.

Suppose we don't know n, nor do we have random access of the nodes. We have to traversal. It is very easy to get the idea of two pointers. One from each end and move at the same speed. When they meet or they are one step away, (depends on the parity of n), we have the roots we want.

This gives us a lot of useful ideas to crack our real problem.

For a tree we can do some thing similar. We start from every end, by end we mean vertex of degree 1 (aka leaves). We let the pointers move the same speed. When two pointers meet, we keep only one of them, until the last two pointers meet or one step away we then find the roots.

It is easy to see that the last two pointers are from the two ends of the longest path in the graph.

The actual implementation is similar to the BFS topological sort. Remove the leaves, update the degrees of inner vertexes. Then remove the new leaves. Doing so level by level until there are 2 or 1 nodes left. What's left is our answer!

The time complexity and space complexity are both O(n).

Note that for a tree we always have V = n, E = n-1.
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (edges.size() == 0) return {0};
        vector<int>ans;
        unordered_map<int, vector<int>>graph;
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].emplace_back(edges[i][1]);
            graph[edges[i][1]].emplace_back(edges[i][0]);
        }
        vector<int>leaves;
        for (auto& it: graph) {
            if (it.second.size() == 1) leaves.emplace_back(it.first);
        }
        while (n > 2) {
            n-=leaves.size();
            vector<int>newleaves;
            for (int i:leaves) {
                int j = graph[i][0];
                graph[j].erase(find(graph[j].begin(), graph[j].end(), i));
                if (graph[j].size() == 1) newleaves.emplace_back(j);
            }
            leaves = newleaves;
        }
        return leaves;
    }
};
//the fatest solution 36ms
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        std::vector<int> leaves;
        
        if (n <= 1)
        {
            leaves.emplace_back(0);
            return leaves;
        }
        
        std::vector<std::pair<int, int>>  nhb(n);
        
        for (auto & edge : edges)
        {
            ++nhb[edge[0]].first;
            nhb[edge[0]].second += edge[1];
            
            ++nhb[edge[1]].first;
            nhb[edge[1]].second += edge[0]; 
        }
        
        for (int i = 0; i < nhb.size(); ++i)
        {
            if (nhb[i].first == 1)
            {
                leaves.emplace_back(i);
            }
        }
        
        auto end = leaves.end();
        // For each iteration, the remaining leaves are between leaves.begin() and end
        while (n > 2)
        {
            auto new_end = leaves.begin();

            // Iterating over the remaing leaves
            for (auto it = leaves.begin(); it < end; ++it, --n)
            {
                int const dest = nhb[*it].second;
                nhb[dest].second -= *it;
                
                // If the destination is now a leaf
                if (--nhb[dest].first == 1)
                {
                    // Adding it to leaves
                    *new_end = dest;
                    // Moving forward tail
                    ++new_end;
                }
            }
            // Updating end
            end = new_end;
        }
        leaves.erase(end, leaves.end());
        return leaves;
    }
};
