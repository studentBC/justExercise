class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int ans = 0, big = -1, sum;
        char prev = '$';
        s+="$";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == prev) {
                if (big == -1) {
                    big = cost[i-1]; 
                    sum+=cost[i-1];
                }
                big = max(big, cost[i]);
                sum+=cost[i];
            } else {
                if (big != -1) {
                    //cout << sum <<" , " << big << endl;
                    ans+=(sum-big);
                }
                big = -1;
                sum = 0;
            }
            prev = s[i];
        }
        return ans;
    }
};
