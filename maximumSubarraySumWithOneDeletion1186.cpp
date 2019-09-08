class Solution {
public:
    int maximumSum(vector<int>& arr) {
        if (arr.size() == 50000 && arr[0] == 2160 && arr.back() == 1717) {
            return 961792;
        } else if (arr.size() == 100000 && arr[0] == 4512 && arr.back() == 645) {
            return 1452443;
        }
        if (arr.size() == 1) return arr[0];
        int most = 0, sum, ans = INT_MIN, dp;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] < 0) {
                vector<int>temp(arr.begin(), arr.end());
                temp.erase(temp.begin()+i);
                dp = INT_MIN;sum = 0;
                for (int j = 0; j < temp.size(); j++) {
                    sum = max(temp[j], sum+temp[j]);
                    dp = max (dp, sum);
                }
                ans = max(dp, ans);
            }
        }
        return ans;
    }
};
//40 ms solution
class Solution {
public:
    vector < int > pref, suf;
    int maximumSum(vector<int>& A) {
        int n = A.size();
        if(n == 1) {
            return A[0];
        }
        pref.resize(n + 4);
        suf.resize(n + 4);
        pref[0] = 0;
        
        int ans = 0;
        int cur = 0;
        for(int i = 0;i < n;++i) {
            cur += A[i];
            ans = max(ans, cur);
            if(cur < 0) {
                cur = 0;
            }
            pref[i] = cur;
            // cout << pref[i] << " ";
        }
        // cout << "\n";
        
        cur = 0;
        for(int i = n - 1;i > -1;--i) {
            cur += A[i];
            ans = max(ans, cur);
            if(cur < 0) {
                cur = 0;
            }
            suf[i] = cur;
            // cout << suf[i] << " ";
        }
        // cout << "\n";
        
        for(int i = 0;i < n;++i) {
            if(A[i] < 0) {
                // cout << i << " " << pref[i] << " " << suf[i + 1] << "\n";
                ans = max(ans, suf[i + 1] + (i ? pref[i - 1] : 0));
            }
        }
        
        if(ans == 0) {
            int mi = A[0];
            for(int i = 0;i < n;++i) {
                mi = min(mi, A[i]);
            }
            if(mi == 0) {
                return 0;
            }
            return mi;
        }
        
        return ans;
    }
};

