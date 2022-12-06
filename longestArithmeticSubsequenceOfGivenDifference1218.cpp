class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int>count;
        int target, ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            target = arr[i]-difference;
            if (count.count(target)) {
                count[arr[i]] = count[target]+1;
            } else {
                count[arr[i]] = 1;
            }
            ans = max(ans, count[arr[i]]);
        }
        return ans;
    }
};
