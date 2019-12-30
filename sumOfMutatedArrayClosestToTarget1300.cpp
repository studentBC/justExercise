class Solution {
public:
    int sum (int target, vector<int>& arr) {
        int s = 0;
        for (int i:arr) {
            if (i >= target) s+=target;
            else s+=i;
        }
        return s;
    }
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int r = arr.back(), dis = INT_MAX, l = 0, mid, diff, ans = INT_MAX;
        while (l <= r) {
            mid = (l+r)/2;
            diff = sum(mid, arr)-target;
            if (diff == 0) {
                dis = 0;
                //ans = min(mid, ans);
                return mid;
            } else if (diff < 0) {
                if (-diff < dis) {
                    dis = -diff;
                    ans = mid;
                } else if (-diff == dis && mid < ans) {
                    ans = mid;
                }
                l = mid+1;
            } else {
                if (diff < dis) {
                    dis = diff;
                    ans = mid;
                } else if (diff == dis && mid < ans) {
                    ans = mid;
                }
                r = mid-1;
            }
        }
        return ans;
    }
};
//8 ms solution
auto ds = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution {
public:
    int findBestValue(vector<int> &arr, int target) {
        int l, r, mi, s = 0, m = -1;
        for (int v:arr) s += v, m = max(m, v);

        if (s == target) return m; // return the max value since we will keep all nums as is

        for (l = 1, r = m; l < r;) {
            mi = (l + r) / 2;
            s = 0;
            for (int v:arr) s += (v > mi) ? mi : v;
            if (s >= target) r = mi;
            else l = mi + 1;
        }
        // check if we are 1 step off the target
        int s1 = 0, s2 = 0;
        for (int v:arr) s1 += (v > l) ? (l) : v, s2 += (v > l - 1) ? (l - 1) : v;

        return (abs(s2 - target) <= abs(s1 - target)) ? l - 1 : l;
    }
};
