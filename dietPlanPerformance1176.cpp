class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int sum = 0, ans = 0;
        for (int i = 0; i < k; i++) {
            sum+=calories[i];
        }
        if (sum > upper) ans++;
        else if (sum < lower) ans--;
        for (int i = 0, j = k; j < calories.size(); j++,i++) {
            sum-=calories[i];
            sum+=calories[j];
            if (sum > upper) ans++;
            else if (sum < lower) ans--;
        }
        return ans;
    }
};
//the fatest solution
auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int points(0);
        int sum(0);
        const int n = calories.size();
        
        for (int i = 0;i < n;i++) {
            sum += calories[i];
            
            if (i >= k) {
                sum -= calories[i-k];
            }
            
            if (i >= k-1) {
                if (sum > upper) {
                    points++;
                }
                
                if (sum < lower) {
                    points--;
                }
            }
        }
        
        return points;
    }
};
