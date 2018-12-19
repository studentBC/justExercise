class Solution {
public:
    bool isSubsequence(string s, string t) {
        int map[63] = {0};
        for (int i = 0; i < t.size(); i++) {
            map[t[i]-'A']++;
        }
        int index;
        for (int i = 0; i < s.size(); i++) {
            index = s[i]-'A';
            map[index]--;
            if (map[index] < 0) {  
                //cout << index << endl;
                return false;
            }
        }
        int count = 0;
        bool judge = false;
        for (int i = 0; i < s.length(); i++) {
            count = 0;
            judge = false;
            for (int j = 0; j < t.length(); j++) {
                if (t[j] == ' ') {
                    count++;
                }
                if (s[i] == t[j]) {
                    if (count==i) {
                        t[j] = ' ';
                        //cout <<s[i] <<" : " << count;
                        judge = true;
                        break;
                    } else {
                        //cout <<t[j] <<" : " << count;
                        if (count > i) {
                            return false;
                        }
                    }
                }
            }
            if (!judge)return false;
        }

        return true;
    }
};
//the fatest method
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pos = 0;
        for(int i = 0; i < s.size(); i++){
            if(t.find(s[i], pos) == string::npos) return false;
            pos = t.find(s[i], pos) + 1;
        }
        return true;
    }
};
