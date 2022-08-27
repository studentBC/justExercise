class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>>child;
        for (int i = 0; i < n; i++) {
            child[manager[i]].push_back(i);
        }
        queue<pair<int, int>>next;
        next.push({headID, 0});
        int time, ans = 0;
        while (!next.empty()) {
            queue<pair<int, int>>temp;
            //time = temp.front().second;
            while (!next.empty()) {
                time = next.front().second+informTime[next.front().first];
                for (int i : child[next.front().first]) {
                    temp.push({i, time});
                }
                ans = max(ans, time);
                next.pop();
            }
            next = temp;
        }
        return ans;
    }
};
