/*
Easy to understand, max from left, right sides in O(1) for each cell of a row

Now we know that for each element P[i][j], we need to traverse the whole previous row, but it will lead to O(m) time for one element and O(m^2) time for one complete row, and O(m^2 n) for whole matrix

So for each element in a row, instead of traversing prev whole row
what we can do is that keep left and right vectors to get max from 0 to i-1th in left side, and i+1th to n-1 in right side

left[i] = max(point[i], left[i-1] - 1)
now why this?

Now for each cell max is one of when same col, from left side, from right side

using left we will get max from left side, using right vector we will get max from right side
and at each step we will also compare them with same col val

so for left[0] = prev[0], because there is no element in left side
for left[1] = max(prev[1], left[0] - 1), this -1 is the difference in cols (0 - 1)

Now next step is important
for left[2] = max(prev[2], left[1]-1)

at this step, if left[1] had value of just above then we had only subtracted 1 from it, and only 1 should be subtracted only
but if left[1] had left[0]-1 in it, then left[2] = left[0] - 2, now we can see it automatically subtracted 2 if 0th was max

hence in this logic it subtracts correct absolute difference of columns while choosing the maximum value
try running this more, you will understand better

// Let's try it with an example

[1,  3,  4,  2,  5] 
__  __  __  __  __
 0   1   2   3   4

what is max in left side of 0th element nothing, so it should have just above value
 1   __  __  __  __
 0   1   2   3   4

for 1th element, we have two choices, {above - 0, 0th - (1 - 0) }
0th = left[0]
left[1] = max { 3, 1 - 1 } = 3
 1   3  __  __  __
 0   1   2   3   4

for 2nd element, we have two choices, {above - 0, 0th - (2 - 0), 1st - (2 - 1) }
max of  0th - (1 - 0), 1st - (0)  = left[1] 
max of  0th - (1 - 0) - 1, 1st - (0) - 1  = left[1] - 1
left[1] = max { 4, 3 - 1 } = 4
 1   3   4  __  __
 0   1   2   3   4

for 3rd element, we have two choices, {above - 0, 0th - (3 - 0), 1st - (3 - 1), 2nd - (3 - 2) }
0th - (2 - 0), 1st - (2 - 1), 2nd - (0)  = left[2] 
max of  0th - (2 - 0) - 1, 1st - (2 - 1) - 1, 2nd - (0) - 1  = left[2] - 1
left[1] = max { 2, 4 - 1 } = 3
 1   3   4   3  __
 0   1   2   3   4

continue this, and now you will understand why left gives the max of all left elements
similarly, right[m-1] = prev[m-1], nothing in right side
else right[i] = max(prev[i], right[i+1] - 1)

When we have build left and right arrays for a column,
then just find the max from left or right side and add it to the current cell value 
 */
#define ll long long

class Solution {
public:
    long long maxPoints(vector<vector<int>>& P) {
      ll n = P.size(), m = P[0].size();

      vector<ll> prev(m); 
      for(int i=0; i<m; ++i) prev[i] = P[0][i];
      
      for(int i = 1; i < n; ++i){
        vector<ll> curr(m, 0);
        auto right = curr, left = curr;
        
        // traverse left to right
        left[0] = prev[0];
        for(int j=1; j<m; ++j) {
          left[j] = max(left[j-1]-1, prev[j]);
        }
        
        // traverse right to left
        right[m-1] = prev[m-1];
        for(int j=m-2; j>=0; --j) {
          right[j] = max(right[j+1]-1, prev[j]);
        }
        
        // update current with max from left, right + value
        for(int j=0; j<m; ++j){
          curr[j] = P[i][j] + max(left[j], right[j]);
        }
        
        prev = curr;
      }
      
      ll ans = prev[0];
      for(auto &i: prev) ans = max(ans, i);
      return ans;
    }
};

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        long long ans = -1, score;
        vector<vector<long long>>dp(m, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) dp[0][i] = points[0][i];
        for (int i = 1; i < m; i++) {
			vector<long long>lp (n, -1), rp(n, -1);
			lp[0] = dp[i-1][0];
            for (int j = 1; j < n; j++) {
                lp[j] = max(lp[j-1], dp[i-1][j]+j);
            }
			rp.back() = dp[i-1].back()-n+1;
			for (int j = n-2; j > -1; j--) {
				rp[j] = max(rp[j+1], dp[i-1][j]-j);
			}
			for (int j = 0; j < n; j++) dp[i][j] = max(lp[j]-j, rp[j]+j)+points[i][j];
        }
        for (int i = 0; i < n; i++) {
            ans = max(dp.back()[i], ans);
        }
        return ans;
    }
};
//2022/8/21
//https://leetcode.com/problems/maximum-number-of-points-with-cost/discuss/1344908/C%2B%2BJavaPython-3-DP-Explanation-with-pictures-O(MN)-Time-O(N)-Space

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int row = points.size(), col = points[0].size(), dist;
        long long ans = 0;
        vector<long long>cur(col, 0), left(col, 0), right(col, 0), prev(col, 0);
        for (int i = 0; i < col; i++) {
            prev[i] = points[0][i];
            ans = max(prev[i], ans);
        }
        row--;
        for (int i = 0; i < row; i++) {
            left[0] = prev[0];
            right.back() = prev.back();
            for (int j = 1; j < col; j++) {
                left[j] = max(prev[j], left[j-1]-1);
            }
            for (int j = col-2; j > -1; j--) {
                right[j] = max(prev[j], right[j+1]-1);
            }
            for (int j = 0; j < col; j++) {
                cur[j] = points[i+1][j] + max(left[j], right[j]);
            }
            prev = cur;
        }
        for (long long i : cur) ans = max(ans, i);
        return ans;
    }
};
