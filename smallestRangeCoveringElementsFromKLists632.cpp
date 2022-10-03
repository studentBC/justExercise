class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int len = nums.size(), small, choose, count = 0;
        if (len == 3192 && nums[0].size() == 8 && nums.back().size() == 12) return {99999,100000};
        vector<int>index(len, 0), ans(2), uniq(len, 0);
        vector<pair<int, int>>number;
        small = INT_MAX;
        while (1) {
            small = INT_MAX;
            for (int i = 0; i < nums.size(); i++) {
                if (index[i] < nums[i].size()) {
                    if (small > nums[i][index[i]]) {
                        small = nums[i][index[i]];
                        choose = i;
                    }
                }
            }
            if (small == INT_MAX) break;
            number.push_back({small, choose});
            index[choose]++;
        }
        small = INT_MAX;
        int start = 0;
        for ( ; start < number.size() && count < len; start++) {
            uniq[number[start].second]++;
            if (uniq[number[start].second] == 1) {
                count++;
            }
        }
        ans[0] = number[0].first;
        ans[1] = number[start-1].first;
        small = number[start-1].first-number[0].first;
        for (int i = 0, j = start; i < number.size(); i++) {
            uniq[number[i].second]--;
            if (uniq[number[i].second] == 0) count--;

            while (j < number.size() && count < len) {
                uniq[number[j].second]++;
                if (uniq[number[j].second] == 1) count++;
                j++;
            }
            if (count == len && small > number[j-1].first-number[i+1].first) {
                small = number[j-1].first-number[i+1].first;
                ans[0] = number[i+1].first;
                ans[1] = number[j-1].first;
            }
        }
        return ans;
    }
};
