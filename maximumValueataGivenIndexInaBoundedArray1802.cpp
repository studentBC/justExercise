class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long right = maxSum, left = maxSum/n, mid, r = n-index-1, l = index, sum, ls, rs, ans = -1;
        while (left <= right) {
            sum = mid = (right+left)/2;
            if (l == mid-1) ls = l*mid/2;
            else if (l < mid-1) ls = (2*mid-1-l)*l/2;
            else ls = mid*(mid-1)/2+l-mid+1;
            
            if (r == mid-1) rs = mid*r/2;
            else if (r < mid-1) rs = (2*mid-1-r)*r/2;
            else rs = mid*(mid-1)/2+r-mid+1;
            //cout << ls <<" , " << rs << endl;
            sum += (ls + rs);
            //cout <<"mid: " << mid <<" sum: " << sum << endl;
            if (sum < maxSum) {
                left = mid+1;
                if (mid*n >= maxSum) {
                    ans = max(ans, mid);
                }
            } else if (sum > maxSum) {
                right = mid-1;
            } else {
                //cout << mid <<" , ";
                return mid;
            }
        }
        return ans;
    }
};
