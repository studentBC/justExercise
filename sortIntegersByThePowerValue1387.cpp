class Solution {
public:
    static bool compare(pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
    unordered_map<int, int>dp;
    int get(int num) {
        if (dp.count(num)) return dp[num];
        if (num%2) dp[num] = get(3*num+1)+1;
        else dp[num] = get(num/2) +1;
        return dp[num];
    }
    int getKth(int lo, int hi, int k) {
        dp[1] = 0;
        vector<pair<int, int>>num;
        for (int i = lo; i <= hi; i++) {
            dp[i] = get(i);
            num.push_back({dp[i] , i});
        }
        sort(num.begin(), num.end());
        return num[k-1].second;
    }
};
