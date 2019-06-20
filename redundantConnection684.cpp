class Solution {
public:
    void go(int node, vector<vector<int>>edges, vector<bool>& visited, vector<int>& child) {
        if (visited[node-1]) return;
        visited[node-1] = true;
        child[node-1]++;
        for (int i = 0; i < edges.size(); ++i) {
            if (edges[i][0] == node) {
                go (edges[i][1], edges, visited, child);
            } else if (edges[i][1] == node) {
                go (edges[i][0], edges, visited, child);
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<int,int>count;
        map<int,int>::iterator it;
        unordered_set<int>choose; int amount = 0;
        bool isTree;
        for (int i = 0; i < edges.size(); ++i) {
            amount = max(amount , edges[i][0]);
            amount = max(amount , edges[i][1]);
            it = count.find(edges[i][0]);
            if (it == count.end()) {
                count.insert(pair<int,int>(edges[i][0],1));
            } else {
                it->second++;
                if (it->second >= 3) choose.insert(edges[i][0]);
            }
            it = count.find(edges[i][1]);
            if (it == count.end()) {
                count.insert(pair<int,int>(edges[i][1],1));
            } else {
                it->second++;
                if (it->second >= 3) choose.insert(edges[i][1]);
            }
        }
        //cout <<"total: " << amount <<" choose: " << choose << endl;
        for (int i = edges.size()-1; i > -1; --i) {
            if ((count[edges[i][0]] > 1 && count[edges[i][1]] > 1) || choose.empty() || choose.find(edges[i][0])!=choose.end() || choose.find(edges[i][1]) != choose.end()) {
                vector<vector<int>>temp = edges;
                vector<bool>visited(amount, false);
                vector<int>child(amount, 0);
                temp.erase(temp.begin()+i);
                //cout << temp.size() << endl;
                isTree = true;
                go (amount, temp, visited, child);
                for (int i:child) {
                    //cout << i <<" , ";
                    if (i!=1) {
                        isTree = false;
                        break;
                    }
                }
                //cout << endl;
                if (isTree) return {edges[i][0],edges[i][1]};
            }
        }
        return edges[0];
    }
};
//the fatest method
/*An edge will connect two nodes into one connected component.

When we count an edge in, if two nodes have already been in the same connected component, the edge will result in a cycle. That is, the edge is redundant.

We can make use of Disjoint Sets (Union Find).
If we regard a node as an element, a connected component is actually a disjoint set.

For example,

Given edges [1, 2], [1, 3], [2, 3],
  1
 / \
2 - 3
Initially, there are 3 disjoint sets: 1, 2, 3.
Edge [1,2] connects 1 to 2, i.e., 1 and 2 are winthin the same connected component.
Edge [1,3] connects 1 to 3, i.e., 1 and 3 are winthin the same connected component.
Edge [2,3] connects 2 to 3, but 2 and 3 have been winthin the same connected component already, so [2, 3] is redundant.
*/
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> p(2000, 0);
        for(int i=0;i<p.size();i++){
            p[i]=i;
        }
        vector<int> res;
        for(auto v:edges){
            int v1=v[0],v2=v[1];
            while(p[v1]!=v1) v1=p[v1];
            while(p[v2]!=v2) v2=p[v2];
            if(v1==v2)
                res=v;
            else
                p[v1]=v2;
        }
        return res;

    }
};
