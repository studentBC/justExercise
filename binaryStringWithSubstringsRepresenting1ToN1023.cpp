class Solution {
public:
    string convert (int a) {
        int digit = 0, temp = a;
        while (temp > 0) {
            temp = temp>>1;
            digit++;
        }
        
        string ans = "";
        for (int i = digit-1; i > -1; i--) {
            ans+=to_string(a>>i&1);
        }
        //cout << ans << endl;
        return ans;
    }
    bool queryString(string S, int N) {
        string target;
        int j = S.size()-1;
        std::size_t found;
        for (int i = 1; i <= N ; i++) {
            target = convert(i);
            found = S.find(target);
            if (found==std::string::npos) return false;
        }
        return true;
    }
};

