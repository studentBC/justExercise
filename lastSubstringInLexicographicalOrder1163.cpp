class Solution {
public:
    string lastSubstring(string s) {
        // Pick starting point 
        int n = s.size(), j = 0, i;
        for (int len = 1; len < n; len++)  
        {     
            // Pick ending point 
            for (i = 0; i + len < n; i++) {
				if (s[j+i] == s[len+i])	continue;
				j = s[i+len] > s[j+i] ? len:j;
				break;
            }
			if (len+i == s.size()) break;
        }       
        return s.substr(j);
    }
};
//the 12 ms solution
static int x=[](){std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}(); // NOLINT

class Solution1 {
public:
    string lastSubstring(string s) {
        int i = 0;
        int sz = 0;

        for (auto j = 1; j < s.size(); ++j) {
            for (sz = 0; j + sz < s.size(); ++sz) {
                if (s[i + sz] == s[j + sz]) {
                    continue;
                }
                i = s[j + sz] > s[i + sz] ? j : i;
                break;
            }
            if (j + sz == s.size()) {
                break;
            }
        }

        return s.substr(i);
    }
};

class Solution2 {
public:
    string lastSubstring(string s) {
        int n = s.length();
        // i is the first candidate start position
        // j is the second one (can not be candidate)
        // k is the len when we have two candidates
        int i = 0;
        int j = 1;
        int k = 0;

        while (i < n && j < n && k < n) {
            if (i + k >= n || j + k >= n) {
                break;
            }
            // they have same start point, then increase the length
            if (s[i + k] == s[j + k]) {
                k++;
            } else {
                // now two candidates are different, then which one is larger
                if (s[i + k] < s[j + k]) {
                    i = i + k + 1; // j becomes the candidate, i need move forward
                } else {
                    j = j + k + 1; // i becomes the candidate
                }
                if (i == j) {
                    j++; // potational i, j stay at the same position, j move forward(i also can move) // NOLINT
                }
                k = 0; // r
            }
        }

        int l = min(i, j);
        return s.substr(l);
    }
};

class Solution3 {
public:
    string lastSubstring(string s) {
        char highest = '@';
        vector<int> indexes;

        int distinct = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] > highest) {
                highest = s[i];
                indexes.clear();
                distinct++;
            }

            if (s[i] == highest) {
                indexes.push_back(i);
            } else {
                distinct++;
            }
        }

        if (distinct == 1) {
            return s;
        }

        int shift = 1;

        vector<int> next_level;

        while (indexes.size() > 1) {
            char shift_highest = '@';

            for (int ind : indexes) {
                if (ind + shift < s.length()) {
                    if (s[ind + shift] > shift_highest) {
                        shift_highest = s[ind + shift];
                        next_level.clear();
                    }

                    if (s[ind + shift] == shift_highest) {
                        next_level.push_back(ind);
                    }
                }
            }

            indexes = next_level;
            next_level.clear();
            shift++;
        }

        return s.substr(indexes[0]);
    }
};

using Solution = Solution1;

