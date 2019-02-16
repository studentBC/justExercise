class Solution {
public:
    bool isMatch(string s, string p) {
        //if (s.compare("ab") == 0 && p.compare("*?*?*") == 0)return true;
        if (s.size() == 0 && p.size() == 0) {
            return true;
        } else if (p.size() == 0 && s.size() != 0) {
            return false;
        } else if (p.size()!=0 && s.size() == 0) {
            for (int i = 0; i < p.size(); i++) {
                if (p[i]!='*')return false;
            }  
            return true;
        }
        vector<vector<int>>dp(p.size(),vector<int>(s.size(),-1));
        int start = 0 , count = 0, firstone = 0; bool found = false;
        for (int i = 0; i < p.size(); i++) {
            if (isalpha(p[i])) {
                found = true;
                break;
            } else if (p[i] == '?')count++;
        }
        if (!found) {
            if (count <= s.size() && p.size()-count > 0)
                return true;
            if (count > s.size())return false;
        }
        count = 0;
        for (int i = 0; i < p.size(); i++) {
            if (i > 0) {
                found = false;
                for (int a = 0; a < s.size(); a++) {
                    if (dp[i-1][a] == i-1) {
                        start = a;
                        found = true;
                        break;
                    }
                }
                if (!found)return false;
            }
            if (p[i] == '*') {
                for (int j = start; j < s.size(); j++) {
                    dp[i][j] = i;
                }
            } else if (p[i] == '?') {
                if (p[i-1] == '*') {
                    for (int j = i-2; j > -1; j--) {
                        if (p[j] != '*') {
                            for (int k = 0; k < s.size(); k++) {
                                if (dp[j][k] == j) {
                                    firstone = k+1;
                                    break;
                                }
                            }
                            for (int k = s.size()-1; k > -1; k--) {
                                if (dp[j][k] == j && k>= start) {
                                    start = k+1;
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    start = min (firstone , start);
                    for (int j = start; j < s.size(); j++) {
                        dp[i][j] = i;
                    }
                } else if (i < 1) {
                    dp[i][0] = i;
                } else {
                    if (start+1 >= s.size()) return false;
                    for (int k = start; k < s.size()-1; k++) {
                        if (dp[i-1][k] == i-1) {
                            dp[i][k+1] = i;
                        }
                    }
                }
                count++;
            } else {
                count++;
                if (i>0) {
                    if (p[i-1] == '*') {
                        //cout <<"check "<<i <<"th:  " << p[i] << " start " << start << "   ";
                        for (int j = i-2; j > -1; j--) {
                            if (p[j] != '*') {
                                for (int k = 0; k < s.size(); k++) {
                                    if (dp[j][k] == j && k>= start) {
                                        start = k+1;
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                        //cout << " start become " << start << endl;
                        for (int k = start; k < s.size(); k++) {
                            if (dp[i-1][k] == i-1) {
                                if (s[k] == p[i]) {
                                    dp[i][k] = i;
                                }
                            }
                        }
                    } else {
                        for (int k = start; k < s.size()-1; k++) {
                            if (dp[i-1][k] == i-1) {
                                if (s[k+1] == p[i]) {
                                    dp[i][k+1] = i;
                                }
                            }
                        }
                    }
                } else {
                    if (s[0] == p[i]) {
                        dp[i][0] = i;
                    } else {
                        return false;
                    }
                }
            }
        }
        if (count > s.size())return false;
        /*
         for (int i = 0; i < p.size(); i++) {
             for (int j = 0; j < s.size(); j++) {
                 cout << dp[i][j] << " , ";
             }
             cout << endl;
         }*/
        return dp[p.size()-1][s.size()-1] == p.size()-1;
    }
};
//the fatest method
class Solution {
public:
    bool isMatch(string s, string p) {
        
        int n = s.length();
        int m = p.length();
    
        if(n == 0 && m == 0)
            return true;
            
            
        
        int i = 0, j = 0, txt = 0, star = -1;
        
        while(i < n )
        {
            if(s[i] == p[j] || p[j] == '?')
            {
                i++;
                j++;
            }
            else if(p[j] == '*')
            {
                star = j;
                txt = i;
                j++;
            }
            else if( star >= 0)
            {
                i = txt + 1;
                j = star + 1;
                txt++;
            }
            else
                return 0;
        }
        
        while(j < m && p[j] == '*')
            j++;
        
        if(j == m)
            return 1;
        
        return 0;
 
 }
        
};
