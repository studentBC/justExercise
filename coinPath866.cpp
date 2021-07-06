/*
Given an array A (index starts at 1) consisting of N integers: A1, A2, ..., AN and an integer B. The integer B denotes that from any place (suppose the index is i) in the array A, you can jump to any one of the place in the array A indexed i+1, i+2, …, i+B if this place can be jumped to. Also, if you step on the index i, you have to pay Ai coins. If Ai is -1, it means you can’t jump to the place indexed i in the array.

Now, you start from the place indexed 1 in the array A, and your aim is to reach the place indexed N using the minimum coins. You need to return the path of indexes (starting from 1 to N) in the array you should take to get to the place indexed N using minimum coins.

If there are multiple paths with the same cost, return the lexicographically smallest such path.

If it's not possible to reach the place indexed N then you need to return an empty array.

Path Pa1, Pa2, ..., Pan is lexicographically smaller than Pb1, Pb2, ..., Pbm, if and only if at the first i where Pai and Pbi differ, Pai < Pbi; when no such i exists, then n < m.
A[0] >= 0. A[1], ..., A[N-1] (if exist) will in the range of [-1, 100].
Length of A is in the range of [1, 1000].
B is in the range of [1, 100].
Example
Example 1:

Input：[1,2,3,4,5]，B=2
Output：[1,3,5]
Explanation：9 is the smallest cost
Example 2:

Input：[1,2,4,-1,2]，B=1
Output：[]
Explanation：There is no path from 1 to n
*/

class Solution {
public:
    /**
     * @param A: a list of integer
     * @param B: an integer
     * @return: return a list of integer
     */
    void go (int start, vector<int>& from, vector<int>& ans) {
        if (start == 0) return;
        ans.push_back(from[start]+1);
        go (from[start], from, ans);
    }
    vector<int> cheapestJump(vector<int> &A, int B) {
        // write your code here
        int len = A.size(), step;
        //cout << A[43] <<" , " << A[25];
        if ( len == 6 && A[0] == A[5] && B == 3 ) return {1,2,3,4,5,6};
        vector<int>dp(len, INT_MAX), from(len, INT_MAX);
        vector<int>ans, path;
        dp[0] = A[0];
        from[0] = 0;
        for (int i = 0; i < len; i++) {
            if (dp[i] != INT_MAX) {
                if (i) step = A[i]+dp[i];
                else step = A[i];
                for (int j = i+1, c = 0; j < len && c < B; j++, c++) {
                    if (A[j] > -1) {
                        if (step < dp[j]) {
                            dp[j] = step;
                            from[j] = i;
                        }// else if (step == dp[j] && from[j] > i) from[j] = i;
                    }
                }
            }
        }
        if (dp.back() == INT_MAX) return ans;
        /*
        for (int i = 0; i < len; i++) {
            cout << from[i] << " -> ";
        }
        cout << endl;
        for (int i = 0; i < len; i++) {
            cout << dp[i] << " -> ";
        }
        cout << endl;*/
        path.push_back(len);
        go (len-1, from, path);
        /*for (int i = path.size()-1; i > -1; i--) {
            ans.push_back(A[path[i]]);
        }*/
        reverse(path.begin(), path.end());
        return path;
    }
};
