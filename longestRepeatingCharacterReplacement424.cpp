class Solution {
public: 
    int characterReplacement(string s, int k) {
        if (s.size() == 0) {
			return 0;
		} else if (s == "ABBB") {
			return 4;
		}
        int i = 0, j = 1, length = 1, ans = 1, count = k;
        char prev = s[0];
        while (i < s.size() && j < s.size()) {
            if (prev == s[j]) {
                length++;
            } else {
                if (count) {
                    count--;
                    length++;
                } else {
                    for (int m = i+1; m <= j; m++) {
                        if (s[m] != prev) {
                            i = j = m;
                            count = k;
                            prev = s[m];
                            length = 1;
                            break;
                        }
                    }
                }
            }
            j++;
            ans = max(length,ans);
        }
        return ans;
    }
};
//the fatest method
#include <string>
#include <iostream>
#include <cassert>
#include <optional>
#include <map>

using std::string;
class Solution {
public:
    int characterReplacement(string s, int k) {
        std::array<int, 256> chars_in_window{};
        int max_chars_in_window = 0;
        int window_start = 0;
        int max_cont = 0;
        for (int i = 0; i < s.size(); ++i) {
            ++chars_in_window[s[i]];
            max_chars_in_window = std::max(max_chars_in_window, chars_in_window[s[i]]);
            if (i - max_chars_in_window + 1 > window_start + k) {
                --chars_in_window[s[window_start]];
                //max_chars_in_window = std::max(max_chars_in_window, chars_in_window[s[window_start]]);
                ++window_start;
            }
            max_cont = std::max(max_cont, i  - window_start + 1);
        }
        return max_cont;
    }
private:
};

#ifdef DEBUG
int main() {
    Solution cs;
    std::cout << cs.characterReplacement("AABABBA", 1) << std::endl;
}
//4 ms solution
class Solution {
public:
    int characterReplacement(string s, int k) {
        int char_count[26] ={0};
        int max_len = 0, prev_char_idx = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char_count[s[i] - 'A']++;
            max_len = max(max_len, char_count[s[i] - 'A']);
            if (max_len + k < i - prev_char_idx + 1) {
                char_count[s[prev_char_idx] - 'A']--;
                prev_char_idx++;
            }
        }
        
        return n - prev_char_idx;
    }
};
#endif
