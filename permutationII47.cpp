class Solution {
public:
    void go (int l, int r, vector<int>& nums, vector<vector<int>>& ans) {
        if (l == r) {
            ans.emplace_back(nums);
        } else {
            for (int i = l; i <= r; i++) {
                swap(nums[i],nums[l]);
                go (l+1,r,nums,ans);
                swap(nums[i],nums[l]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        //vector<int>temp;
        sort(nums.begin(), nums.end());
        do {
            ans.emplace_back(nums);
        } while ( std::next_permutation(nums.begin(), nums.end()) );
        //go (0,nums.size()-1,nums,ans);
        return ans;
    }
};
//the fatest method
class Solution {
public:
    void permute (vector<int>& nums, vector<vector<int>>& ans, vector<int>& cur, vector<bool>& used) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }
        
        for (int i=0; i<nums.size(); i++) {
            if (i>0 && nums[i]==nums[i-1] && !used[i-1]==true)
                continue;
            
            if (!used[i]) {
                used[i] = true;
                cur.push_back(nums[i]);
                permute(nums, ans, cur, used);
                used[i] = false;
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        vector<bool> used (nums.size(), false);
        
        if (nums.size() == 0)
            return ans;
        
        sort(nums.begin(), nums.end());
        
        permute(nums, ans, cur, used);
        
        return ans;
        
    }
};
