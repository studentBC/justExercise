class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int np, step, far = -1, cur;
        for (int i: forbidden) far = max(i, far);
        far = max(x,far);
        far+=(a+a+b);
        vector<int>dp(far+1,INT_MAX);
        for (int i : forbidden) dp[i] = -1;
        dp[0] = 0;
        priority_queue<int,vector<int>, greater<int>>pq;
        pq.push(0);
        while (!pq.empty()) {
            cur = pq.top();
            pq.pop();
            if(x == cur) return dp[x];
            if (cur + a <= far && dp[cur + a] > dp[cur] + 1) {
                dp[cur + a] = dp[cur] + 1;
                pq.push(cur + a);
            }
            if (cur - b > 0 && dp[cur - b] > dp[cur] + 1) {
                dp[cur - b] = dp[cur] + 1;
                if (cur - b == x) {
                    return dp[x];
                }
                if (cur - b + a <= far && dp[cur - b + a] > dp[cur] + 2) {
                    dp[cur - b + a] = dp[cur] + 2;
                    pq.push(cur - b + a);
                }
            }
        }
        return -1;
    }
};
