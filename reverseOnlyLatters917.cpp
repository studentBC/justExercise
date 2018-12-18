class Solution {
public:
    string reverseOnlyLetters(string S) {
 		vector<int>index;
		int asc;
		for (int i = 0; i < S.length(); i++) {
			asc = S[i] -'A'; 
			if (asc>=0 && asc<=57) {
				if (asc < 27 || asc > 31) {
					index.push_back(i);
				}
			}
		}
		int mid = index.size()/2, end = index.size()-1;
		char temp;
		for (int i = 0; i < mid; i++) {
			temp = S[index[i]];
			S[index[i]] = S[index[end-i]];
			S[index[end-i]] = temp;
		}
		return S;
    }
};
//the fatest method
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0, j = S.size() - 1;
        while (i < j)
        {
            if (!isalpha(S[i])) i++;
            else if (!isalpha(S[j])) j--;
            else
            {
                char temp = S[i];
                S[i] = S[j];
                S[j] = temp;
                i++;
                j--;
            }
        }
        return S;
    }
};
