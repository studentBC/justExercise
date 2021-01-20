class Solution {
public:
    static bool compare(pair<int,int>&a, pair<int,int>& b) {
        if (a.first == b.first) return a.second > b.second;
        else return a.first < b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int>count;
        for (int i : nums) count[i]++;
        vector<pair<int, int>>c;
        for (int i = 0; i < nums.size(); i++) {
            c.push_back(make_pair(count[nums[i]], nums[i]));
        }
        sort(c.begin(), c.end(), compare);
        vector<int>ans;
        for (auto& it : c) ans.push_back(it.second);
        return ans;
    }
};
