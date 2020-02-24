class Solution {
public:
    int numberOfSubstrings(string s) {
 		int ans = 0, end = s.size()-3;
		unordered_set<char>uniq;
		for (int i = 0; i <= end; i++) {
			uniq.clear();
			for (int j = i; j < s.size(); j++) {
				uniq.insert(s[j]);
				if (uniq.size() == 3) {
					ans+=s.size()-j;
					break;
				}
			}
		}
		return ans;
    }
};
//the 24 ms solution
/* 
    Maintain a sliding window (lo, hi], where lower bound exclusively and upper bound inclusively;
    Traverse string s, use upper bound hi to count the number of the 3 characters, a, b, & c; once the sliding window includes all of the 3, we find s.length() - hi substrings (lo, hi], (lo, hi + 1], ..., (lo, s.length() - 1];
    Increase the lower bound lo by 1 (denote it as lo'), decrease the count accordingly, if the sliding window still includes all of the 3 characters, we count in substrings (lo', hi], (lo', hi + 1], ..., (lo', s.length() - 1];
    Repeat 3 till the sliding window short of at least 1 of the 3 characters, go to step 2;
    Repeat 2 - 4 till the end of the string s.
*/
class Solution {
public:
    int numberOfSubstrings(string A) {
        long long n = A.size();
        int st = 0;
        long long ans = 0;
        vector < int > cnt(4, 0);
        for(int i = 0;i < n;++i) {
            int ch = A[i] - 'a';
            ++cnt[ch];
            while(cnt[0] and cnt[1] and cnt[2]) {
                --cnt[A[st] - 'a'];
                ++st;
            }
            ans += i - st + 1;
        }
        return (n * (n + 1)) / 2 - ans;
    }
};


