class Solution {
public:
    string convertToBase7(int num) {
        int temp = abs(num);
        string ans = "";
        while (temp>6) {
            //cout << temp%7;
            ans+=to_string(temp%7);
            temp/=7;
        }
        ans+=to_string(temp);
        if (num < 0) ans+="-";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
