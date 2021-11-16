class Solution {
public:
	int go (vector<vector<int>>& graph, vector<long long>& count, int start) {
		long long product =1, sum = 1;
		for (int i : graph[start]) {
			int c = go (graph, count, i);
			product*=c;
			sum+=c;
		}
		count[start] = product*max(1ll, (long long)graph.size()-sum);
		return start ? sum : std::count(count.begin(), count.end(), *max_element(count.begin(), count.end()));
	}
    int countHighestScoreNodes(vector<int>& parents) {
		int len = parents.size();
 		vector<vector<int>>graph(len);
		vector<long long>count(len);
		for (int i = 1; i < len; i++) graph[parents[i]].push_back(i);
		return go(graph, count, 0);
    }
};
