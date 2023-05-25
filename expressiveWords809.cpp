class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        char prev = s[0];
        vector<int>count;
        int cc = 1;
        string target="";
        target.push_back(s[0]);
        s.push_back('$');
        for (int i = 1; i < s.size(); i++) {
            if (s[i]!=prev) {
                target.push_back(s[i]);
                count.push_back(cc);
                cc = 1;
            } else {
                cc++;
            }
            prev = s[i];
        }
        int ans = 0;
        for (string& s: words) {
            string temp;
            vector<int>tc;
            cc = 1;
            prev = s[0];
            temp.push_back(s[0]);
            s.push_back('$');
            for (int i = 1; i < s.size(); i++) {
                if (s[i]!=prev) {
                    temp.push_back(s[i]);
                    tc.push_back(cc);
                    cc = 1;
                } else {
                    cc++;
                }
                prev = s[i];
            }
            
            if (temp == target) {

                // for (int i = 0; i < count.size(); i++) {
                //     cout << count[i] <<", ";
                // }
                // cout << endl;
                // for (int i = 0; i < tc.size(); i++) {
                //     cout << tc[i] <<", ";
                // }
                // cout <<endl<<"--------------------" << endl;
                bool valid = true;
                for (int i = 0; i < count.size(); i++) {
                    if (count[i] > tc[i]) {
                        if (count[i] < 3) {
                            valid = false;
                            break;
                        }
                    } else if (count[i] < tc[i]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    //cout << s << endl;
                    ans++;
                }
            }
        }
        return ans;
    }
};
