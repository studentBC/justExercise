class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        int size = num.size(), left = num.size()-k, pos = 0, chosen, small;
        vector<pair<int,int>>temp;
        for (int i = 0; i < num.size(); i++) {
            temp.emplace_back(pair<int,int>((num[i]-'0'),i));
        }
        while (left) {
            small = INT_MAX;
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i].first != INT_MAX && pos <= temp[i].second && size - temp[i].second >= left ) {
                    if (small > temp[i].first) {
                        chosen = i;
                        small = temp[i].first;
                    }
                }
            }
            ans+=to_string(temp[chosen].first);
            pos = temp[chosen].second;
            temp[chosen].first = INT_MAX;
            left--;
        }
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i]!='0') return &ans[i];
        }
        if (ans[0] == '0' || ans == "") return "0";
        return ans;
    }
};
//the fatest method
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        for(char c : num) {
            while(res.size() && res.back() > c && k) {
                res.pop_back();
                k--;
            }
            res += c;
        }
        while(k--) {
            res.pop_back();
        }
        int i = 0;
        while(i < res.size() && res[i] == '0') i++;
        if(i == res.size()) return "0";
        return res.substr(i);
    }
    
};
