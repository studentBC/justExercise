class Solution {
public:
    void swap (char& a, char& b) {
        char temp = a;
        a = b;
        b = temp;
    }
    string reverseWords(string s) {
        vector<int>blank;
        s+=" ";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                blank.push_back(i);
            }
        }
        int start = 0 , end , k;
        for (int i = 0; i < blank.size(); i++) {
            end = (blank[i]+start)/2;
            k = 1;
            for (int j = start; j < end; j++) {
                swap(s[j] , s[blank[i] - k]);
                k++;
            }
            start = blank[i]+1;
        }
        s[s.size()-1] = '\0';
        return s;
    }
};
//the fatest method
class Solution {
public:
	string reverseWords(string s) {
		auto itr_prev = s.begin();
		auto itr = s.end();
		do {
			itr = find(itr_prev, s.end(), ' ');
			reverse(itr_prev, itr);
			if (itr != s.end()) {
				itr_prev = ++itr;
			}
		} while (itr != s.end());

		return s;
	}
};

