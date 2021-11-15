class Solution {
public:
    int len;
    int check (vector<int> quantities, int target, int n) {
        int ans = 0, tmp, i = 0;
        while (n && i < len) {
            if (quantities[i] >= target) {
                quantities[i]-=target;
                if (quantities[i] == 0) i++;
            } else {
                quantities[i] = 0;
                i++;
            }
            n--;
        }
        //cout << target <<" , " << quantities.back() << endl;
        return quantities.back();
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        int left = 1, right = 0, mid, big = 0, ans;
        len = quantities.size();
        for (int i : quantities) big = max(big, i);
        ans = right = big;
        //if (len == 1) return big;
        while (left <= right) {
            mid = (left+right)/2;
            //cout << mid <<" , ";
            if (check(quantities, mid, n)) {
                left = mid+1;
            } else {
                ans = min (mid, ans);
                right = mid-1;
            }
            //cout << ans << endl;
        }
        return ans;
    }
};
