class Solution {
public:
    bool check (int x, vector<int>& price, int k) {
        int last = price[0], count = 1, i = 1;
        while (count < k && i < price.size()) {
            if (price[i]-last >= x) {
                last = price[i];
                count++;
            }
            i++;
        }
        return count == k;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int left = 0, right = 1e9, mid;
        while (left < right) {
            mid = left + (right-left)/2;
            if (check(mid, price, k)) left = mid+1;
            else right = mid;
        }
        return left-1;
    }
};
