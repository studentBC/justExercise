class Solution {
public:
    bool contain (vector<int>& temp, vector<vector<int>>& ans) {
        bool same;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i].size() == temp.size()) {
                same = true;
                for (int j = 0; j < temp.size(); j++) {
                    if (temp[j] != ans[i][j]) {
                        same = false;
                        break;
                    } 
                }  
                if (same) return true;
            }  
        }  
        return false;
    }
    void go (int start, int sum, vector<int>& candidates, int& target, vector<int>& temp, vector<vector<int>>& ans) {
        if (sum == target) {
            if (!contain(temp,ans)) ans.emplace_back(temp);
        } else {
            for (int i = start; i < candidates.size(); i++) {
                if (sum+candidates[i]<= target) {
                    temp.emplace_back(candidates[i]);
                    go (i+1, sum+candidates[i], candidates, target, temp, ans);
                    temp.pop_back();
                }  
            }  
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(), candidates.end());
        go (0, 0, candidates,target,temp,ans); 
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty())
        {
            return {};
        }
        vector<vector<int>> ans;
        vector<int> cur;
        std::sort(candidates.begin(),candidates.end());
        dfs(candidates,target, 0,cur,ans);
        return ans;        
    }
    void dfs(vector<int> & candidates, int target, int d, vector<int> &cur, vector<vector<int>> &ans)
    {
        if (target==0)
        {
            ans.push_back(cur);
            return;
        }
        for (int i=d;i<candidates.size();i++)
        {
            if (target<candidates[i])
                break;
            if (i > d && candidates[i] == candidates[i - 1]) continue; //check mechansim is here
            cur.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],i+1,cur,ans);
            cur.pop_back();
        }
    }
};
