class Solution {
public:
    int len, mod = 1e9+7;
    vector<long long>power;
    string verify (int length, string& s) {
        if (length == 0) return "";
        long long hash = 0;
        //Polynomial rolling hash
        //https://en.wikipedia.org/wiki/Rolling_hash
        for (int i = 0; i < length; i++) {
            hash = ((s[i]-'a')+26*hash%mod)%mod;
        }
        unordered_map<long long, vector<int>>used;
        used[hash] = vector<int>(1, 0); //its start index
        for (int i = length; i < len; i++) {
            hash = ((hash - (s[i-length]-'a')*power[length-1])%mod + mod)%mod;
            hash = (hash*26+s[i]-'a')%mod;
            if (used.count(hash)) {
                for (auto& it: used[hash]) {
                    if (s.substr(it, length) == s.substr(i-length+1, length) ) return s.substr(it, length);
                }
                used[hash].push_back(i-length+1);
            } else used[hash] = vector<int>(1, i-length+1);
        }
        return "";
    }
    string longestDupSubstring(string s) {
        len = s.size();
        int left = 0, right = len, mid;
        power = vector<long long>(len, 1);
        //1, 26, 26^2, 26^3 .... it is the opposite way for us to encode string
        for (int i = 1; i < len; i++) {
            power[i] = power[i-1]*26%mod;
        }
        string ss, ans;
        while (left <= right) {
            mid = (left+right)/2;
            ss = verify(mid, s);
            if (ss == "") {
                right = mid-1;
            } else {
                if (ss.size() > ans.size()) ans = ss;
                left = mid+1;
            }
        }

        return ans;
    }
};
