class Solution {
public:
    string trim (string S) {
        vector<char>del;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '#') {
                if (!del.empty() && del.back()!='#')
                    del.pop_back();
            } else {
                del.emplace_back(S[i]);
            }
        }
        string temp = "";
        for (int i = 0; i < del.size(); i++) {
            if (del[i] !='#') temp+=del[i];
        }
        return temp;
    }
    bool backspaceCompare(string S, string T) {
        string s = trim (S);
        string t = trim (T);
        //cout <<"s " << s << " t " << t << endl;
        return s.compare(t) == 0;
    }
};

