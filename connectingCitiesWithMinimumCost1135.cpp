/*
There are N cities numbered from 1 to N.

You are given connections, where each connections[i] = [city1, city2, cost] represents the cost to connect city1 and city2 together.  (A connection is bidirectional: connecting city1 and city2 is the same as connecting city2 and city1.)

Return the minimum cost so that for every pair of cities, there exists a path of connections (possibly of length 1) that connects those two cities together.  The cost is the sum of the connection costs used. If the task is impossible, return -1.

 

Example 1:



Input: N = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
Output: 6
Explanation: 
Choosing any 2 edges will connect all cities so we choose the minimum 2.
Example 2:



Input: N = 4, connections = [[1,2,3],[3,4,4]]
Output: -1
Explanation: 
There is no way to connect all cities even if all edges are used.
 

Note:

1 <= N <= 10000
1 <= connections.length <= 10000
1 <= connections[i][0], connections[i][1] <= N
0 <= connections[i][2] <= 10^5
connections[i][0] != connections[i][1]
*/
ass Solution {
public:
    class my_greater  {
        public:
            bool operator() (const tuple<int, int, int>& arg1, const tuple<int, int, int>& arg2) const
            {
                return get<0>(arg1) > get<0>(arg2);
                return false;
            }
    };
int minimumCost(int N, vector<vector<int>>& connections) {
        priority_queue<tuple<int, int, int>, std::vector<tuple<int, int, int>>, my_greater> city;
        for (int i = 0; i < connections.size(); i++) {
            city.emplace(connections[i][2], connections[i][0], connections[i][1]);
        }
        vector<int> visited(N+1, -1);
        int aa, bb, sum = 0, big, small;
        while (!city.empty()) {
            auto [d, a, b] = city.top();
            city.pop();
            aa = visited[a];
            bb = visited[b];
            //cout << a <<" , "<<b <<" : " <<aa <<" ::  "<<bb<< endl;
            if (aa == -1 || bb == -1) {
                if (aa == bb) {
                    visited[a] = visited[b] = count;
                    count++;
                } else {
                    visited[a] = visited[b] = max (aa, bb);
                }
				//cout <<"pick up " << d << endl;
                sum+=d;
            } else if ( aa != bb ) {
                small = min (aa, bb);
                big = max (aa, bb);
                for (int i = 1; i < visited.size(); i++) {
                    if (visited[i] == big) visited[i] = small;
                }
				//cout <<"pick up " << d << endl;
                sum+=d;
            }
        }
        for (int i = 2; i < visited.size(); i++) {
            //cout << visited[i] <<" , ";
            if (visited[i]!=visited[i-1]) return -1;
			
        }
        return sum;
	}
private:
    int count = 1;

};
//the fatest method
int _=[](){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
	}();
class UnionFind{
public:
    vector<int> parent;
    int count;
    UnionFind(int N) : count(N) {
        parent.resize(N + 1);
    }
    
    int Find(int child) {
        if(!parent[child]){
            parent[child] = child;
        }
        
        return parent[child] == child ? child : parent[child] = Find(parent[child]);
    }
    
    bool Union(int c1, int c2){
        int p1 = Find(c1);
        int p2 = Find(c2);
        if(p1 == p2) return false;
        count--;
        parent[p1] = p2;
        return true;
    }
};


class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), [](vector<int>& c1, vector<int>& c2){ return c1[2] < c2[2]; });
        
        UnionFind uf(N);
        int sum = 0;
        for(auto& c : connections){
            if(uf.Union(c[0], c[1])){
                sum += c[2];
            }
        }
        return uf.count == 1? sum : -1;
    }
};
