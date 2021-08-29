class Solution {
public:
	int len, time, end;
	int dp[1<<15][16];
	int go (vector<int>& task, int mask, int cur) {
		if (cur > time) return INT_MAX;
		if (mask == end) return 1;
		if (dp[mask][cur] > -1) return dp[mask][cur];
		int ans = INT_MAX;
		for (int i = 0; i < len; i++) {
			if ((mask & (1<<i)) == 0) {
				ans = min({ans, go(task, mask|(1<<i), cur+task[i]), 1+go(task, mask|(1<<i), task[i])});
			}
		}
		return dp[mask][cur] = ans;
	}
    int minSessions(vector<int>& tasks, int sessionTime) {
		time = sessionTime;
		len = tasks.size();
		end = (1<<len)-1;
		memset(dp, -1, sizeof(dp));
		return go (tasks, 0, 0);
    }
};
