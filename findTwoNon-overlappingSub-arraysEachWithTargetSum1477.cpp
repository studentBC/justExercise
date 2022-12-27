class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int>pos;
        int sum = 0, ans = INT_MAX, len = INT_MAX;
        pos[0] = -1;
        for (int i = 0; i < arr.size(); i++) {
            sum+=arr[i];
            pos[sum] = i;
        }
        sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum+=arr[i];
            if (pos.count(sum-target)) {
                len = min(len, i-pos[sum-target]);
            }
            if (pos.count(sum+target) && len != INT_MAX) ans = min(ans, pos[sum+target]-i+len);
        }
        return ans == INT_MAX? -1: ans;
    }
};
