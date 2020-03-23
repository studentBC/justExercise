class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
		bool found;
		int ans = 0;
 		for (int i: arr1) {
			found = true;
			for (int j : arr2) {
				if (abs(i-j) <= d) {
					found = false;
					break;
				}
			}
			if (found) ans++;
		}
		return ans;
    }
};
//the fatest solution
class Solution {
public:
    int findTheDistanceValue(vector<int>& A, vector<int>& B, int d) {
        int ans = 0;
        for(int i = 0;i < A.size();++i) {
            bool found = false;
            for(int j = 0;j < B.size();++j) {
                if(abs(A[i] - B[j]) <= d) {
                    found = true;
                    break;
                }
            }
            ans += !found;
        }
        return ans;
    }
};
