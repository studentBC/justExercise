class Solution {
public:
    bool judge (int start, int length, string& s) {
        int half = length/2;
        //half+=start;
        length+=start;
        length--;
        //cout << "start from " << start << "  end at " << half << " the last is " << length << endl;
        for (int i = 0; i < half; i++) {
            if (s[start+i] != s[length-i]) return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans="";
        for (int i = s.size(); i >0 ; i--) {
            for (int j = 0; j <= s.size() -i; j++) {
                //judge whether it is palindromic string
                //cout << "start with: " <<j << " length " << i << endl;
                if ( judge (j,i,s) ) {
                    //cout <<" s: " << j <<" length " << i << endl;
                    for (int k = j; k < i+j; k++) {
                        ans+=s[k];
                    }
                    return ans;
                }
            }
        }
        return ans;
    }
};
//16 ms solution
//using Manacher's Algorithm
//https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/
//https://www.youtube.com/watch?v=V-sEwsca1ak
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        int i = 0;
        int res_len = 0;
        string res = "";
        while(i < s.size() - 1) {
            int l = i, r = i;
            while(r < s.size() - 1 && s[r] == s[r+1]) r++;
            i = r + 1;
            while(l > 0 && r < s.size() - 1 && s[--l] == s[++r]);
            if(s[l] != s[r]) {
                l++;
                r--;
            }
            //cout << l << r << endl;
            if(res_len <= r - l + 1) {
                res_len = r - l + 1;
                res = s.substr(l, res_len);
            }
        }
        return res;
    }
};
