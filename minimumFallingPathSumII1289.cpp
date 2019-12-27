class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        vector<vector<int>>dp(arr.size(), vector<int>(arr[0].size(), 0));
        int acc;
        for (int j = 0; j < arr[0].size(); j++) dp[0][j] = arr[0][j];
        for (int i = 1; i < arr.size(); i++) {
            for (int j = 0; j < arr[0].size(); j++) {
                acc = INT_MAX;
                for (int k = 0; k < arr[0].size(); k++) {
                    if (j!=k) acc = min (dp[i-1][k], acc);
                }
                dp[i][j] = acc+arr[i][j];
            }
        }
        acc = INT_MAX;
        for (int j = 0; j < arr[0].size(); j++) acc = min(dp.back()[j], acc);
        return acc;
    }
};
//the fatest solution
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        if(arr.size() == 1)
            return arr[0][0];
        pair<int, int> min_1st = {arr[0][0], 0}, min_2nd = {arr[0][1], 1};
        for(int i = 1; i < (int)arr[0].size(); i++)
        {
            if(min_1st.first > arr[0][i])
            {
                min_2nd = min_1st;
                min_1st = {arr[0][i], i};
            }
            else if(min_2nd.first > arr[0][i])
                min_2nd = {arr[0][i], i};
        }
        for(int i = 1; i < (int)arr.size(); i++)
        {
            pair<int, int> cur_min_1st = {INT_MAX, 0},
                    cur_min_2nd = {INT_MAX, 0};
            for(int j = 0; j < (int)arr[0].size(); j++)
            {
                int sum = arr[i][j] + (j == min_1st.second ? min_2nd.first : min_1st.first);
                if(cur_min_1st.first > sum)
                {
                    cur_min_2nd = cur_min_1st;
                    cur_min_1st = {sum, j};
                }
                else if(cur_min_2nd.first > sum)
                    cur_min_2nd = {sum, j};
            }
            min_1st = cur_min_1st;
            min_2nd = cur_min_2nd;

        }
        return min_1st.first;
    }
};
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
