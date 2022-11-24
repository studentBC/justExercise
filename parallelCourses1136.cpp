class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<unordered_set<int>>graph(n+1);
        vector<int>count(n+1, 0);
        unordered_set<int>next;
        for (int i = 1; i <= n; i++) next.insert(i);
        for (int i = 0; i < relations.size(); i++) {
            graph[relations[i][0]].insert(relations[i][1]);
            count[relations[i][1]]++;
            next.erase(relations[i][1]);
        }
        if (next.empty()) return -1;
        int ans = 0;
        while (!next.empty()) {
            unordered_set<int>tmp;
            for (int i : next) {
                for (int j : graph[i]) {
                    count[j]--;
                    if (count[j] == 0) tmp.insert(j);
                }
                n--;
            }
            next = tmp;
            ans++;
        }
        if(n) return -1;
        return ans;
    }
};
