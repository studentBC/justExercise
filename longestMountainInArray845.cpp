class Solution {
public:
    int longestMountain(vector<int>& A) {
        int right, ans = 0, left;
        for (int i = A.size()-2; i > 0; i--) {
            right = left = 0;
            for (int j = i+1; j < A.size(); j++) {
                if (A[j] < A[j-1]) {
                    right++;
                } else {
                    break;
                }
            }
            for (int j = i-1; j > -1; j--) {
                if (A[j] < A[j+1]) {
                    left++;
                } else {
                    break;
                }
            }
            //cout << i << " th " << left <<" , " << right << endl;
            if (left > 0 && right > 0) {
                right+=left;
                ans = max (ans, right+1);
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    int longestMountain(vector<int>& A) {
        if (A.size() < 3) return 0;
        int i = 0;
        int length = A.size();
        int ml = 0;
        while (i < length) {
            while (i < length - 1 && A[i] >= A[i+1]) ++i;
            if (i == length - 1) break;
            int j = i;
            while (j < length - 1 && A[j] < A[j+1]) ++j;
            if (j == length - 1) break;
            while (j < length - 1 && A[j] > A[j+1]) ++j;
            ++j;
            // cout << "i: " << i << " j: " << j << endl;
            ml = max(ml, j - i);
            i = j - 1;
        }
        return ml >= 3 ? ml : 0;
    }
};

auto ___ = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
