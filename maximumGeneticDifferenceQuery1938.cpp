struct TrieNode {
	TrieNode* child[2] = {};
	int count = 0;
	void add (int number, int d) {
		TrieNode* cur = this;
		for (int i = 17; i > -1; i--) {
			int bit = (number>>i)&1;
			if (cur->child[bit] == nullptr) cur->child[bit] = new TrieNode();
			cur = cur->child[bit];
			cur->count+=d;
		}
	}
	int find (int num) {
		TrieNode* cur = this;
		int ans = 0;
		for (int i = 17; i > -1; i--) {
			int bit = (num>>i)&1;
			if (cur->child[1-bit]!=nullptr && cur->child[1-bit]->count > 0) {
				cur = cur->child[1-bit];
				ans |= (1<<i);
			} else cur = cur->child[bit];
		}
		return ans;
	}
};
class Solution {
public:
	TrieNode tr;
	void go (int node, vector<vector<int>>& graph, vector<vector<pair<int,int>>>& qbn, vector<int>& ans) {
		tr.add(node, 1);
		for (auto& p: qbn[node]) ans[p.second] = tr.find(p.first);
		for (int& v : graph[node]) go (v, graph, qbn, ans);
		tr.add(node, -1);
	}
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n = parents.size(), m = queries.size(), root = -1;
		vector<vector<int>>graph(n);
		for (int i = 0; i < n; i++) {
			if (parents[i] < 0) root = i;
			else graph[parents[i]].push_back(i);
		}
		vector<vector<pair<int,int>>>qbn(n);
		for (int i = 0; i < m; i++) qbn[queries[i][0]].push_back({queries[i][1], i});
		vector<int>ans(m);
		go (root, graph, qbn, ans);
		return ans;
    }
};
