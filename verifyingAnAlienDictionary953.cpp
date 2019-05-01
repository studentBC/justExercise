class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>wo(order.size(),-1);
        for (int i = 0; i < order.size(); i++) {
            wo[order[i]-'a'] = i;
        }
        bool match = false;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i+1; j < words.size(); j++) {
                match = false;
                if (words[i].size() > words[j].size()) {
                    for (int k = 0; k < words[j].size(); k++) {
                        if (wo[words[i][k]-'a'] > wo[words[j][k]-'a']) {
                            return false;
                        } else if (wo[words[i][k]-'a'] < wo[words[j][k]-'a']) {
                            match = true;
                            break;
                        }
                    }
                    if (match) {
                        break;
                    } else {
                        return false;
                    }
                } else {
                    match = false;
                    for (int k = 0; k < words[i].size(); k++) {
                        if (wo[words[i][k]-'a'] > wo[words[j][k]-'a']) {
                            return false;
                        } else if (wo[words[i][k]-'a'] < wo[words[j][k]-'a']) {
                            match = true;
                            break;
                        }
                    }
                    if (match) {
                        break;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
//the fatest method
typedef long long int64;
const int INF = 0x3f3f3f3f;
template <class T> inline int len (const T &a) { return a.size (); }
int key[256];

bool cmp(const string &e1, const string &e2) {
    int N = len (e1), M = len (e2);
    for (int i = 0; i < min(N, M); i++)
        if (key[e1[i] - 'a'] != key[e2[i] - 'a'])
            return key[e1[i] - 'a'] < key[e2[i] - 'a'];
    return N < M;
}

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < len (order); i++) key[order[i] - 'a'] = i + 1;
        for (int i = 1; i < words.size(); i++) 
            if (!cmp(words[i - 1], words[i])) return false;
        return true;
        /*
        
        vector<string> copy = words;
        sort(words.begin(), words.end(), cmp);
        for (string c: words) cout << c << " ";
        return copy == words;
        */
    }
};

static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
