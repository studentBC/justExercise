class Solution {
public:
    static bool compare(pair<char,int>&a , pair<char,int>&b) {
        if (a.second > b.second) {
            return true;
        } else if (a.second == b.second) {
            if (a.first > b.first) {
                return true;
            }
            return false;
        } else {
            return false;
        }
        //return a.second > b.second;
    }
    string frequencySort(string s) {
        string temp = s;
        int count = 1;
        int dict[91] = {0};
        vector<pair<char,int>>word;
        for (int i = 0; i < temp.length(); i++) {
            count = 1;
            if (temp[i]!='@') {
                for (int j = 0; j < temp.length(); j++) {
                    if ( i!=j && temp[i] == temp[j]) {
                        count++;
                        temp[j] = '@';
                    }
                }
                //cout << temp[i] <<":  " << count << endl;
                dict[temp[i]-' '] = count;
                temp[i] = '@';
                //word.push_back(make_pair(temp[i] , count));
            }
        }
        for (int i = 0; i < s.length(); i++) {
            //cout << s[i] <<":  " << dict[s[i]-'A'] << endl;
            word.push_back(make_pair(s[i] , dict[s[i]-' ']));
        }
        sort(word.begin() , word.end(), compare);
        string ans;
        for (int i = 0; i < word.size(); i++) {
            ans+=word[i].first;
        }
        return ans;
    }
};
//the fatest method
#define SIGMA 128

int any = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

bool initialized = false;
int fr[SIGMA];
int v[SIGMA];

inline bool cmp(const int& a, const int& b) {
    return fr[a] > fr[b];
}

class Solution {
public:
    string frequencySort(string s) {
        
        if (!initialized) {
            for (int i = 0; i < SIGMA; ++i)
                v[i] = i;
            initialized = true;
        }
        
        memset(fr, 0, sizeof(fr));
        
        for (const char& ch : s)
            fr[ch]++;
        
        sort(v, v+SIGMA, cmp);

        string ans = s;
        int poz = 0;
        for (int i = 0; i < SIGMA; ++i) {
            for (int j = 0; j < fr[v[i]]; ++j)
                ans[poz++] = v[i];
        }
        return ans;
    }
};
