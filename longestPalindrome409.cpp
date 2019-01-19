class Solution {
public: 
    int longestPalindrome(string s) {
        int map[58] = {0};
        for (int i = 0; i < s.size(); i++) {
            map[s[i]-'A']++;
        }
        int mirror = 0 , odd = 0;
        for (int j = 0; j < 58; j++) {
            mirror+=(map[j]>>1);
			map[j] = map[j]%2;
        }
        cout << mirror << endl;
		bool hasone = false;
		for (int j = 0; j < 58; j++) {
			if (map[j] > 0) {
				hasone = true;
				break;
			}
		}
        if (hasone) {
            return (mirror<<1)+1;
        } else {
            return mirror<<1;
        }
    }
};
//the fatest method
#define isUp(c) ((c >= 'A') and (c <= 'Z'))
#define isLow(c) ((c >= 'a') and (c <= 'z'))
auto fast_io =[](){std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> map(52,0);
        for (auto c : s) {
            if (isLow(c))
                map[c-'a']++;
            else
                map[c-'A'+26]++;
        }
        bool single{false};
        int count{}, max{};
        for (auto i : map){
            if (!(i%2))
                count += i;
            else {
                if (!single)
                    single = true;
                count += i - 1;
            }
        }
        if (single)
            count++;
        return count;
    }
};
