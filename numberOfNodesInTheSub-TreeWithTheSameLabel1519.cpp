class Solution {
public:
    vector<int> go (int start, unordered_map<int,vector<int>>& path, vector<bool>& beenTo, vector<int>& ans, string& labels) {
        beenTo[start] = true;
        vector<int>temp(26, 0);
        temp[labels[start]-'a']++;
        for (int i : path[start]) {
            if (!beenTo[i]) {
                vector<int>tmp = go (i, path, beenTo, ans, labels);
                for (int i = 0; i < 26; i++) temp[i]+=tmp[i];
            }
        }
        ans[start]+=temp[labels[start]-'a'];
        return temp;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int>ans(n, 0);
        vector<bool>beenTo(n, false);
        unordered_map<int,vector<int>>path;
        for (auto& it: edges) {
            path[it[0]].push_back(it[1]);
            path[it[1]].push_back(it[0]);
        }
        
        go (0, path, beenTo, ans, labels);
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> next(n);
        for(const auto& edge : edges){
            next[edge[0]].push_back(edge[1]);
            next[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        vector<vector<int>> childLabels(n, vector<int>(26, 0));
        for(int i = 0; i < n; i++){
            childLabels[i][labels[i]-'a']++;
        }
        dfs(0, -1, next, childLabels);
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            ans[i] = childLabels[i][labels[i]-'a'];
        }
        return ans;
    }
private:
    void dfs(int cur, int parent, vector<vector<int>>& next, vector<vector<int>>& childLabels){
        for(int i : next[cur]){
            if(i != parent){
                dfs(i, cur, next, childLabels);
                for(int j = 0; j < 26; j++){
                    childLabels[cur][j] += childLabels[i][j];
                }
            }
        }
    }
};
