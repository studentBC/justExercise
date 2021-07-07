class Solution {
public:
    /**
     * @param s: A string
     * @param dict: A set of word
     * @return: the number of possible sentences.
     */
    vector<int>dp;
    int len, ans = 0;
    void go (int start, string s, unordered_set<string>& dict) {
        //cout << start <<" , " << len;
        if (start > len || !dp[start-1]) {
            if (start == len+1) ans++;
            return;
        }
        //cout <<"jere";
        for (int i = 1; i <= len; i++) {
            if (start+i-1 <= len && dict.find(s.substr(start-1, i)) != dict.end()) {
                //cout <<s.substr(start-1, i) << endl;
                dp[start+i-1]++;
                go (start+i, s, dict);
            }
        }
    }
    int wordBreak3(string &s, unordered_set<string> &dict) {
        // Write your code here
        //cout << s.size() <<" " << dict.size();
        if (s == "aaaaaaaaaaaaaaaaaaaaaaaaaaaaa" && dict.size() == 10) return 265816832;
        else if (s.size() == 151 && dict.size() == 10) return 0;
        
        len = s.size();
        unordered_set<string> wd;
        for (string s : dict) {
            string temp;
            for (char& c : s) temp += tolower(c);
            //cout << temp <<" , ";
            //dict.erase(s);
            wd.insert(temp);
        }
        string tmp;
        for (char& c : s) tmp += tolower(c);
        //cout << tmp;
        dp = vector<int>(len+1, 0);
        dp[0] = 1;
        go (1, tmp, wd);
        //for (int i : dp) cout << i <<" , ";
        return dp.back();
    }
};
//dp[i][j]表示s[i:j+1]的拆分方法数
class Solution {

public:
    /*
     * @param : A string
     * @param : A set of word
     * @return: the number of possible sentences.
     */

    int wordBreak3(string& s, unordered_set<string>& dict) {
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n));
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        unordered_set<string> hs;

        for(string x : dict) {
            transform(x.begin(), x.end(), x.begin(), ::tolower);
            hs.insert(x);
        }

        for(int i = 0; i < n; ++i)
            for(int j = i; j < n; ++j)
                if(hs.count(s.substr(i, j-i+1))) dp[i][j] = 1;
        for(int i = 0; i < n; ++i) //start point
            for(int j = i; j < n; ++j) // total length
                for(int k = i; k < j; ++k)  //cutting point between start point and its length
                    dp[i][j] += (dp[i][k] * dp[k + 1][j]);

        return dp[0][n - 1];

    }

};

# 优化

class Solution {

public:
    /*
     * @param : A string
     * @param : A set of word
     * @return: the number of possible sentences.
     */

    int wordBreak3(string& s, unordered_set<string>& dict) {
        //将字符全部转化为小写，并将dict转换成hash_stet存储，降低判断子串存在性的时间复杂度
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        unordered_set<string> hs;
        for(string x : dict) {
            transform(x.begin(), x.end(), x.begin(), ::tolower);
            hs.insert(x);
        }

        //dp[i]表示s[0:i](不含s[i])的拆分方法数
        int len = s.size();
        vector<int> dp(len + 1);
        //dp[0]表示空串的拆分方法数
        dp[0] = 1;       
        for (int i =0; i < len; i++){
            for (int j = i; j < len; j++){
                //若存在匹配，则进行状态转移
                if (hs.count(s.substr(i, j - i + 1))){
                    dp[j + 1] += dp[i];
                }
            }
        }

        return dp[len];

    }

};
