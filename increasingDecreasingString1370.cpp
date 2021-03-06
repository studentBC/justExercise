class Solution {
public:
    string sortString(string s) {
        vector<int>count(26, 0);
        for (char c: s) {
            count[c-'a']++;
        }
        string ans;
        int n = s.size(), next;
        while (n) {
			next = 26;
            for (int j = 0; j < 26; j++) {
                if (count[j]) {
                    ans+='a'+j;
                    next = j+1;
					count[j]--;	
                    n--;
                    break;
                }
            }
            while (next < 26) {
                if (count[next]) {
                    ans+=next+'a';
					count[next]--;
                    n--;
                }
                next++;
            }
			next = -1;
            for (int j = 25; j > -1; j--) {
                if (count[j]) {
                    ans+='a'+j;
                    next = j-1;
					count[j]--;	
                    n--;
                    break;
                }
            }
            while (next > -1) {
                if (count[next]) {
                    ans+=next+'a';
					count[next]--;
                    n--;
                }
                next--;
            }
        }
        return ans;
    }
};
//the fatest solution
// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string sortString(string s) {
        string result;
        auto count = counter(s);
        while(result.length() != s.length()) {
            for (int c = 0; c < count.size(); ++c) {
                if (count[c]) {
                    result += ('a' + c);
                    --count[c];
                }
            }
            for (int c = count.size() - 1; c >= 0; --c) {
                if (count[c]) {
                    result += ('a' + c);
                    --count[c];
                }
            }
        }
        return result;
    }

private:
    vector<int> counter(const string& word) {
        vector<int> count(26);
        for (const auto& c : word) {
            ++count[c - 'a'];
        }
        return count;
    }
};


// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    string sortString(string s) {
        string result;
        for (auto [count, desc] = tuple{counter(s), false}; !count.empty(); desc = !desc) {
            if (!desc) {
                for (auto it = begin(count); it != end(count);) {
                    result.push_back(it->first);
                    if (!--it->second) {
                        it = count.erase(it);
                    } else {
                        ++it;
                    }
                }
            } else {
                for (auto rit = rbegin(count); rit != rend(count);) {
                    result.push_back(rit->first);
                    if (!--rit->second) {
                        rit = reverse_iterator(count.erase(next(rit).base()));
                    } else {
                        ++rit;
                    }
                }
            }
        }
        return result;
    }

private:
    map<int, int> counter(const string& word) {
        map<int, int> count;
        for (const auto& c : word) {
            ++count[c];
        }
        return count;
    }
};
