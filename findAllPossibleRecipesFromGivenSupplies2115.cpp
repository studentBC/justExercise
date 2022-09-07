class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string>sup(supplies.begin(), supplies.end());
        unordered_map<string, unordered_set<string>> graph;
        unordered_map<string, int>count;
        queue<string>next;
        vector<string>ans;
        //for (string& s : supplies) next.push()
        for (int i = 0; i < recipes.size(); i++) {
            for (int j = 0; j < ingredients[i].size(); j++) {
                if (sup.count(ingredients[i][j])) continue;
                else {
                    count[recipes[i]]++;
                    graph[ingredients[i][j]].insert(recipes[i]);
                }
            }
            if (!count.count(recipes[i])) {
                next.push(recipes[i]);
                ans.push_back(recipes[i]);
            }
        }
        while (!next.empty()) {
            for (string s : graph[next.front()]) {
                count[s]--;
                if (count[s] == 0) {
                    next.push(s);
                    count.erase(s);
                    ans.push_back(s);
                }
            }
            next.pop();
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>>graph;
        unordered_map<string, int> indegree;
        unordered_set<string>sup(supplies.begin(), supplies.end());
        int len = ingredients.size();
        for (string& s : recipes) indegree[s] = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < ingredients[i].size(); j++) {
                if (!sup.count(ingredients[i][j])) {
                    graph[ingredients[i][j]].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }
        queue<string>next;
        vector<string>ans;
        for (auto& it: indegree) {
            if (it.second == 0) {
                next.push(it.first);
                ans.push_back(it.first);
            }
        }
        string n;
        
        while (!next.empty()) {
            n = next.front();
            for (string& s: graph[n]) {
                indegree[s]--;
                if (indegree[s] == 0) {
                    next.push(s);
                    ans.push_back(s);
                }
            }
            next.pop();
        }
        return ans;
    }
};
