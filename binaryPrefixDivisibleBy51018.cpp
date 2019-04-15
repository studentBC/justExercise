class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
		int number = 0;
		vector<bool>ans;
 		for (int i = 0; i < A.size(); i++) {
			number = number << 1;
			number = number%10;
			number+=A[i];
			if (number%5 == 0) {
				ans.push_back(true);
			} else {
				ans.push_back(false);
			}
		}
		return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) 
    {
        vector<bool> out;
        out.reserve(A.size());
        int value = 0;
        for (int a : A) {
            value = ((value * 2) + a) % 5;
            out.emplace_back(0 == value);
        }
        return out;
    }
};
