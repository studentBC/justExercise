class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
 		for (int i = 0; i < A.size(); i++) {
			if (A[i][0] == 0) {
				for (int j = 0; j < A[i].size(); j++) {
					A[i][j] = 1-A[i][j];
				}
			}
		}
		int zero = 0, one = 0;
		for (int i = 0; i < A[0].size(); i++) {
			zero = 0, one = 0;
			for (int j = 0; j < A.size(); j++) {
				if (A[j][i] == 0) {
					zero++;	
				} else {
					one++;	
				}
			}
			if (zero > one) {
				for (int j = 0; j < A.size(); j++) {
					A[j][i] = 1-A[j][i];
				}
			}
		}
		/*for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < A[i].size(); j++) {
				cout << A[i][j] << " , ";
			}
			cout << endl;
		}*/
		int ans = 0, count = 0;
		for (int i = A[0].size()-1; i > -1 ; i--) {
			for (int j = 0; j < A.size(); j++) {
				if (A[j][i] == 1) {
					ans+=pow(2,count);
				}
			}
			count++;
		}
		return ans;
    }
};
