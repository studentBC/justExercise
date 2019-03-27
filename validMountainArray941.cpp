class Solution {
public:
    bool validMountainArray(vector<int>& A) {
 		if (A.size()<3) return false;
		int max = INT_MIN, mindex;
		for (int i = 0; i < A.size(); i++) {
			if (max < A[i]) {
				max = A[i];
				mindex = i;
			}
		}
		if (mindex == 0 || mindex == A.size()-1) return false;
		for (int i = 0; i < mindex; i++) {
			if (A[i] >= A[i+1]) {
				return false;
			}
		}
		for (int i = mindex; i < A.size()-1; i++) {
			if (A[i] <= A[i+1]) {
				return false;
			}
		}
		return true;
    }
};
//the fatest method
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        return 1 == distance(
            adjacent_find( A.cbegin(), A.cend(), greater_equal<int>() ),
            adjacent_find( A.crbegin(), A.crend(), greater_equal<int>() ).base() 
        );
    }
};
