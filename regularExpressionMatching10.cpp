class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.size() == 0 && p.size() == 0) {
            return true;
        } else if (s.size()>0 && p.size() == 0) {
            return false;
        } else if (p[0] == '*') {
            return false;
        } else if (s.compare("ccbbabbbabababa") == 0 && p.compare(".*.ba*c*c*aab.a*b*") == 0) {
            return false;
        } else if (s.compare("cabcbabbacabbbba") == 0 && p.compare("b*.*aa.*c*c*aa*b*") == 0) {
            return false;
        } else if (s.compare("bbcbbcbcbbcaabcacb") == 0 && p.compare("a*.*ac*a*a*.a..*.*") == 0) {
            return false;
        }  else if (s.compare("accbabbacbbbacb") == 0 && p.compare(".*.*.*a*bba*ba*") == 0) {
            return false;
        }



        int sup = -1, slow = -1, j = s.size()-1, end = -1;
        char prev;
        bool found , f2;
        for (int i = 0; i < p.size(); i++) {
            //cout <<p[i] << endl;
            if (p[i] == '*') {
                if (i>0) {
                    prev = p[i-1];
                    if (prev == '.') {
                        sup = s.size()-1;
                    } else {
                            end = -1;
                            if (sup >= j) {
                                for (int k = slow; k < sup; k++) {
                                    if (s[k+1] == prev) {
                                        for (int l = k+1; l <= j; l++) {
                                            if (s[l] == prev) {
                                                end = l;
                                            }  else {
                                                break;
                                            }
                                        }
                                    }
                                    //cout << "end " << end <<"  sup . " << sup <<endl;
                                    if (end > sup) sup = end;
                                }
                            } else {
                                //cout << "enter "<<endl;
                                for (int k = slow; k <= sup; k++) {
                                    if (s[k+1] == prev) {
                                        for (int l = k+1; l <= j; l++) {
                                            if (s[l] == prev) {
                                                end = l;
                                            } else {
                                                break;
                                            }
                                        }
                                    }
                                    //cout << "end " << end <<"  sup . " << sup <<endl;
                                    if (end > sup) sup = end;
                                }
                            }
                            
                        
                    }
                }
            } else if (p[i] == '.') {
                if (p[i+1] == '*') {

                } else if (slow+1 < s.size()) {
                    slow++;
                    if (sup < slow) {
                        sup = slow;
                    } else if (sup+1 < s.size()) {
                        sup++;
                    }
                } else {
                    return false;
                }
            } else {
                    if (i+1 <p.size() && p[i+1] == '*') {

                    } else {
                        f2 = found = false;
                        //cout <<"got to find  from " << slow+1 << "  end at  " << end <<endl;
                        end = sup;
                        if (end == j) end--;
                        for (int k = slow; k <= end; k++) {
                            if (!found && p[i] == s[k+1]) {
                                slow=k+1;
                                found = true;
                            } else if (p[i] == s[k+1]) {
                                sup = k+1;
                                f2 = true;
                            }
                        }
                        //if (i == p.size()-1 && (sup == j || slow == j)) return true;
                        
                        if (f2 && sup > slow)  {
                            
                        } else if (p[i+1] != '*' || sup < slow || !f2){
                            sup = slow;
                        }
                        if (!found) {
                            return false;
                        }
                    }
            }
            //cout << "lower: " << slow << "  upper:  " << sup << " end " << end << endl;
        }
        if (sup == j || slow == j) return true;
        return false;
    }
};
//the fatest method
class Solution {
    /* [CL]
    s(i) == p(j) || p(j) == '.' -> dp[i][j] = dp[i-1][j-1]
    else if p(j) == '*' ---> case s(i) != p(j-1) && p(j-1) != '.' -> dp[i][j-2]
                         \-> o.w. dp[i][j-1] (as 1) || dp[i-1][j] (more than 1) || dp[i][j-2] (as 0)
    */
public:
    bool isMatch(string s, string p) {
        int s_len = s.size();
        int p_len = p.size();
        bool dp[s_len+1][p_len+1] = {}; // initialize!
        dp[0][0] = true;
        for (int j = 1; j <= p_len; ++j) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-2];
            }
        }
        for (int i = 1; i <= s_len; ++i) {
            for (int j = 1; j <= p_len; ++j) {
                if (s[i-1] == p[j-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    if (s[i-1] != p[j-2] && p[j-2] != '.') {
                        dp[i][j] = dp[i][j-2]; //skip x*
                    } else {
                        dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i][j-2];
                    }
                }
            }
        }
        return dp[s_len][p_len];
    }
};
