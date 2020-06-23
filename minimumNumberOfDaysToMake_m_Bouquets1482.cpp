class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left = 1, right = 1e9, mid = (left+right)/2, count, flower, ans = 1e9;
        if (bloomDay.size() < m*k) return -1;
        while (left <= right) {
            flower = count = 0;mid = (left+right)/2;
            for (int f: bloomDay) {
                if (mid >= f) {
                    count++;
                    if (count >= k) {
                        flower++;
                        count = 0;
                    }
                } else {
                    count = 0;
                }
            }
            if (flower >= m) {
                right = mid-1;
                ans = min(mid, ans);
            } else { 
                left = mid+1;
            }
        }
        return ans;
    }
};
