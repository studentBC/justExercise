class Solution {
public:
    bool check (string s) {
        int mid = s.size()>>1;
        for (int i = 0, end = s.size()-1; i < mid; i++,end--) {
            if (s[i] != s[end]) {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int mid = s.size()>>1;
        string temp = s;
        for (int i = 0,end = s.size()-1; i < mid; i++,end--) {
            if (s[i] != s[end]) {
                //start trying to delete one        
                temp = s;
                temp.erase(temp.begin()+i);
                if (check(temp)) return true;
                temp = s;
                temp.erase(temp.begin()+end);
                if (check(temp)) return true;
                return false;
            }
        }
        return true;
    }
};
//the fatest method 20ms
class Solution {
public:
    bool validPalindrome(string &s) {
	int i = 0;
	int len = s.size();
	int flag = 0;
	while (flag<2 && i<len / 2) {
		if (s[i] != s[len - 1 - i]) {
			flag++;
			break;
		}
		i++;
	}
	if (flag) {
		int j = i;
		int flag1 = 0;
		int flag2 = 0;
		while (flag1 < 1 && j < len / 2) {
			if (s[j] != s[len - 2 - j]) {
				flag1++;
				break;
			}
			j++;
		}

		j = i+1;
		while (flag2 < 1 && j < (len+1) / 2) {
			if (s[j] != s[len - j]) {
				flag2++;
				break;
			}
			j++;
		}
		return !(flag1 && flag2);
	}

	return true;
    }
};
