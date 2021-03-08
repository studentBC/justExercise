class Solution {
public:
    int beautySum(string s) {
        vector<vector<int>>count;
        vector<int>tmp(26,0);
        tmp[s[0]-'a']++;
        count.push_back(tmp);
        for (int i = 1; i < s.size(); i++) {
            vector<int>temp(count.back().begin(), count.back().end());
            temp[s[i]-'a']++;
            //for (int i : temp) cout << i <<" , ";
            //cout << endl;
            count.push_back(temp);
        }
        int temp, big, small, ans = 0, b, sm;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i+1; j < s.size(); j++) {
                big = -1; small = INT_MAX;
                b = sm = -1;
                for (int k = 0; k < 26; k++) {
                    if (i) temp = count[j][k]-count[i-1][k];
                    else temp = count[j][k];
                    if (temp) {
                        if (big < temp) {
                            big = temp;
                            b = k;
                        }
                        if (small > temp) {
                            small = temp;
                            sm = k;
                        }
                    }
                }
                //cout <<i <<" , " << j << " : "<< big <<" , " << small << endl;
                if (sm!=b) ans+=(big-small);
            }
        }
        return ans;
    }
};
//360 ms solution
class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), m = 26, ans = 0;
        for(int i = 0; i < n; i++){
            vector<int> cnt(26, 0);
            for(int j = i + 1; j <= n; j++){
                // s[i, j)
                cnt[s[j-1]-'a']++;
                int minNum = INT_MAX, maxNum = INT_MIN;
                for(int k = 0; k < m; k++){
                    if(cnt[k] > 0){
                        minNum = min(minNum, cnt[k]);
                        maxNum = max(maxNum, cnt[k]);
                    }
                }
                if(maxNum != INT_MIN){
                    ans += maxNum - minNum;
                }
            }
        }
        return ans;
    }
};
