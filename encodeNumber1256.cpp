class Solution {
public:
    string encode(int num) {
        string ans = "";
        if (num == 0) return ans;
        int sum = 0, start;
        for (start = 1; start <= num && sum < num; start++) {
            sum+=pow(2,start);
        }
        //cout << start <<" , " << sum << endl;
        if (sum == num) {
            for (int i = 1; i < start; i++) ans+="1";
            return ans;
        } else {
            start--;
            sum-=pow(2,start);
        }
        //cout << start <<" , " << sum << endl;
        num = num-sum-1;
        for (int i = 0; i < start; i++) {
            if (num >> i&1) {
                ans+="1";
            } else {
                ans+="0";
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
//the fatest solution
class Solution2 {
public:
    string encode(int num) {
        string s = bitset<32>(num+1).to_string();
        for (int i = 0 ; i < 32 ; ++i)
            if (s[i] == '1') return s.substr(i+1);
        return "";
    }
};

class Solution {
public:
    string encode(int num) {
        string s = bitset<32>(num+1).to_string();
        return s.substr(s.find('1')+1);
    }
};
