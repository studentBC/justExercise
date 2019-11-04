class Solution {
public:
    int minimumSwap(string s1, string s2) {
        vector<pair<char, char>>change;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                change.emplace_back(make_pair(s1[i], s2[i]));
            }
        }
        int ans = 0, choose;
        bool found = true;
        while (!change.empty()) {
            found = false;
            if (change[0].first == change[0].second) {
                for (int i = 1; i < change.size(); i++) {
                    if (change[i].first == change[i].second && change[i].first != change[0].first) {
                        change.erase(change.begin()+i);
                        change.erase(change.begin());
                        found = true;
                        ans++;
                        break;
                    }
                }
                if (!found) return -1;
            } else {
                for (int i = 1; i < change.size(); i++) {
                    if (change[i].first != change[i].second) {
                        if (change[i].first != change[0].first) {
                            choose = i;
                            found = true;
                        } else {
                            ans++;
                            found = true;
                            choose = -1;
                            change.erase(change.begin()+i);
                            change.erase(change.begin());
                            break;
                        }
                    }
                }
                if (!found) {
                    return -1;
                } else {
                    if (choose > 0) {
                        ans+=2;
                        change.erase(change.begin()+choose);
                        change.erase(change.begin());
                    }
                }
            }
        }
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int len = s1.length();
        int non_match[2] = {0};
        for(int i = 0; i < len; ++i){
            if(s1[i] == s2[i]) {
                continue;
            }
            else {
                non_match[s1[i] - 'x']++;
            }
        }
        int ans = 0;
        ans += non_match[0]/2; non_match[0] %= 2;
        ans += non_match[1]/2; non_match[1] %= 2;
        if((non_match[0] + non_match[1]) % 2 == 1){
            return -1;
        }
        else{
            ans += (non_match[0] + non_match[1])/2 * 2;
        }
        return ans;
    }
};
