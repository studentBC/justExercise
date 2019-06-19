class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        queue<int>place, step, cost;
        place.push(src);step.push(0);cost.push(0);
        int p, ans = INT_MAX, k = 0, c = 0;
        K+=2;
        bool visited[n] = {false};
        while (!place.empty()) {
            queue<int>temp, ts, tc;
            while(!place.empty()) {
                p = place.front();
                k = step.front();
                c = cost.front();
                k++;
                //cout <<"start: " << p <<" push: ";
                place.pop();step.pop();cost.pop();
                //visited[p] = true;
                if (k <= K) {
                    if (p == dst) {
                        if (c < ans) {
                            ans = c;
                        }
                    }
                    for (int i = 0; i < flights.size(); ++i) {
                        if (p == flights[i][0]) {
                            //cout <<flights[i][1] <<" , ";
                            temp.push(flights[i][1]);
                            ts.push(k);
                            tc.push(c+flights[i][2]);
                        }
                    }
                }
            }
            step = ts;cost = tc;place = temp;
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};
//bellman ford method
/*In the original Bellman-Ford algorithm, C[e[1]] = min(C[e[1]], c[e[0]] + e[2]); or Relaxation as it is called in the CLRS is called (|G.V| -1) times which is the longest possible stops in the whole graph. The proof of Bellman-Ford lies in Path-Relaxation Property(Lemma 24.15 in CLRS) .So in this problem we have only "relaxed" for k+1 times. If such a path( shortest path within k stops) truly exists then yes, no problem. If not,, two cases: one, the destination is unreachable from src, which gives infinite distance; case two, a shortest path exists with more than k stops. k+1 times of relaxation may and may not find such a path(this is highly related to how the subvectors inside flights vector are arranged) , so you have to double check that.

But notice here you used two vector storing shortest paths, c being the last time's shortest path, C being the current one. In this way, you cannot successively get two shortest path along the line! This means with k+1 times relaxations you cannot even change c[dest]'s value of infinity if theoretical shortest path has more than k stops. You can prove this by induction. I have to say this c and C is a very brilliant invention.*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
		vector<int>distance(n,1e8);
		distance[src] = 0;
		for (int i = 0; i <= K; ++i) {
			vector<int>temp(distance);
			for (int j = 0; j < flights.size(); ++j) {
				temp[flights[j][1]] = min(temp[flights[j][1]], flights[j][2]+distance[flights[j][0]]);
			}
			distance = temp;
		}
		if (distance[dst] == 1e8) return -1;
		return distance[dst];
    }
};
