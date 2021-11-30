class Solution {
public:
	class UnionFind {
			vector<int>id;
		public:
			UnionFind(int n): id(n) {
				iota(begin(id), end(id), 0);
			}
			void connect (int a, int b) {
				id[find(b)] = find(a);
			}
			int find(int i) {
				return id[i] == i? i : (id[i] = find(id[i]));
			}
			bool connected (int a, int b) {
				return find(a) == find(b);
			}
			void reset(int i) {
				id[i] = i;
			}
	};
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
  		sort(begin(meetings), end(meetings), [](auto &a, auto &b) {return a[2] < b[2];});
		int i = 0, len = meetings.size(), cur;
		UnionFind uf(n);
		uf.connect(0, firstPerson);
		vector<int>ppl;
		while (i < len) {
			ppl.clear();
			cur = meetings[i][2];
			while (i < len && meetings[i][2] == cur) {
				uf.connect(meetings[i][0], meetings[i][1]);
				ppl.push_back(meetings[i][0]);
				ppl.push_back(meetings[i][1]);
				i++;
			}
			for (int j : ppl) if (!uf.connected(0,j)) uf.reset(j);
		}
		vector<int>ans;
		for (int j = 0; j < n; j++) {
			if (uf.connected(0, j)) ans.push_back(j);
		}
		return ans;
    }
};
