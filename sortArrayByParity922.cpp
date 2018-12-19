class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
		//even
 		for (int i = 0; i < A.size(); i+=2) {
			if (A[i]%2 == 1) {
				for (int j = 1; j < A.size(); j+=2) {
					if (A[j]%2 == 0) {
						swap(A[i], A[j]);
						break;
					}
				}
			}
		}
		return A;
    }
};
//fatest method
static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std:cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> res(A.size());
        int odd = 1, even = 0;
        for(int i = 0; i < res.size(); ++i) {
            if(A[i] % 2 == 0) {
                res[even] = A[i];
                even += 2;
            } else {
                res[odd] = A[i];
                odd += 2;
            }
        }
        return res;
    }
};
