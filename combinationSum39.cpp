class Solution {
public:
    void construct(vector<int>& candidates, vector<int>& temp, vector<vector<int>>& ans, int target, int start) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        } else {
            for (int i = start; i < candidates.size(); i++) {
                if (candidates[i]<=target) {
                    temp.push_back(candidates[i]);
                    construct(candidates, temp, ans, target-candidates[i], i);
                    temp.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int start = 0; 
        construct(candidates, temp, ans, target, start);
        return ans;
    }
};
