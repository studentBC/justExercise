/*
Note that if a node u contains an apple then all edges in the path from the root to the node u have to be used forward and backward (2 times).
Therefore use a depth-first search (DFS) to check if an edge will be used or not.
*/
class Solution {
public:
    unordered_map<int,vector<int>>graph;
    unordered_map<int,bool>visited;
    int go (int start, int cost, vector<bool>& hasApple) {
        if (visited[start]) return 0;
        int c = 0;
        visited[start] = true;
        for (auto& i: graph[start]) {
            c+=go (i, 2, hasApple);
        }   
        if (!c && !hasApple[start]) return 0;
        return cost+c;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        return go (0, 0, hasApple);
    }
};


class Solution {
public:
    unordered_map<int, vector<int>> g; // to store the graph
    unordered_map<int, bool> visited; // to stop exploring same nodes again and again.
	
    void createGraph(vector<vector<int>>& edges) {
      for (auto e: edges) {
        g[e[0]].push_back(e[1]); // adjecency list representation
		g[e[1]].push_back(e[0]); // adjecency list representation
      }
    }
  
    int dfs(int node, int myCost, vector<bool>& hasApple) {
	  if (visited[node]) {
		  return 0;
	  }
	  visited[node] = true;
	  
      int childrenCost = 0; // cost of traversing all children. 
      for (auto x: g[node]) { 
        childrenCost += dfs(x, 2, hasApple);  // check recursively for all apples.
      }

      if (childrenCost == 0 && hasApple[node] == false) {
	  // If no child has apples, then we won't traverse the subtree, so cost will be zero.
	  // similarly, if current node also does not have the apple, we won't traverse this branch at all, so cost will be zero.
        return 0;
      }
	  
	  // Children has at least one apple or the current node has an apple, so add those costs.
      return (childrenCost + myCost);
    }
  
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
      createGraph(edges); // construct the graph first.
      return dfs(0, 0, hasApple); // cost of reaching the root is 0. For all others, its 2.
    }
};
//192 ms solution
//sample 192 ms submission
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int sz = (int)edges.size();
        int ans=0;
        for(int i=sz-1;i>=0;i--){
            if(hasApple[edges[i][1]]) {
                ans+=2;
                hasApple[edges[i][0]]=true;
            }
        }
        return ans;
    }
};
static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
