/*
Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example 1:

Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true
Example 2:

Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.

wrong test case:
4
[[0,1],[2,3]]

3
[[0,1],[0,2],[1,2]]

5
[[0,1],[0,2],[0,3],[0,4]]
*/
//the concept which i follow https://www.geeksforgeeks.org/detect-cycle-undirected-graph/
class Solution {
public:
    void go (int i, vector<bool>& visited, vector<vector<bool>>& graph, bool& circle, int parent, int& count) {    
        count++;
        visited[i] = true;
        for (int j = 0; j < graph[i].size(); j++) {
            if (graph[i][j]) {
                if (!visited[j]) {
                    go (j, visited, graph, circle, i, count);
                } else {
                    if (j != parent) circle = true;
                }
            }
        }
        return;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>>graph(n, vector<bool>(n,false));
        vector<bool>visited(n,false);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]][edges[i][1]] = true;
            graph[edges[i][1]][edges[i][0]] = true;
        }
        int count = 0, degree = 4, start;
        for (int i = 0; i < n; i++) {
            count = 0;
            for (int j = 0; j < n; j++) {
                if (graph[i][j]) count++;
            }
            if (degree > count) {
                degree = count;
                start = i;
            }
        }
        bool circle = false;
        count = 0;
        go (start, visited, graph, circle, -1, count);
        return !circle && (count == n);
    }
};

//the fatest method
class Solution {
private:
    int find(int i, vector<int>& p)
    {
        if(p[i] != i)
            p[i] = find(p[i], p);
        return p[i];
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> p(n);
        for(int i = 0; i < n; ++i) p[i] = i;
        for(auto c: edges)
        {
            int p1 = find(c[0], p), p2 = find(c[1], p);
            if(p1 == p2) return false;
            p[p1] = p2;
        }
        return edges.size() == n - 1;
    }
};
//union find method
/*
To tell whether a graph is a valid tree, we have to:

Make sure there is no cycle in the graph - this has to be a none-cyclic graph;
Make sure every node is reached - this has to be a connected graph;
Reference: https://en.wikipedia.org/wiki/Tree_(graph_theory)

Solution:

To test cyclic, we can make an array for each node (as array index), and the array will store the parent of the node (as array index). Every time we fetch a new pair of nodes, we trace the root node (the deepest parent node) of these two nodes, if it has the same root, then is will be a cycle; otherwise, we set the parent of second node to be the first node;
After we make sure there is node cycle in the graph, we simple test if there is enough edges to make this graph connected.
*/
public class Solution {
    public boolean validTree(int n, int[][] edges) {
        // initialize n isolated islands
        int[] nums = new int[n];
        Arrays.fill(nums, -1);
        
        // perform union find
        for (int i = 0; i < edges.length; i++) {
            int x = find(nums, edges[i][0]);
            int y = find(nums, edges[i][1]);
            
            // if two vertices happen to be in the same set
            // then there's a cycle
            if (x == y) return false;
            
            // union
            nums[x] = y;
        }
        
        return edges.length == n - 1;
    }
    
    int find(int nums[], int i) {
        if (nums[i] == -1) return i;
        return find(nums, nums[i]);
    }
}
