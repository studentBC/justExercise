class Solution {
public:
    bool buddyStrings(string A, string B) {
        vector<int>pos;
        vector<int>la(26,0);
        vector<int>lb(26,0);
        if (A.size()!=B.size()) {
            return false;
        } else {
            
            for (int i = 0; i < B.size(); ++i) {
                la[A[i]-'a']++;
                lb[B[i]-'a']++;
                if (A[i]!=B[i]) pos.emplace_back(i);
            }
            if (pos.size()!= 2) {
                if (pos.size() == 0) {
                    for (int i = 0; i < 26; ++i) {
                        if (la[i] > 1) return true;
                    }
                }
                return false;
            }
            for (int i = 0; i < 26; ++i) {
                if (la[i]!=lb[i]) return false;
            }
            return true;
        }
        return true;
    }
};
//the fatest method
class Solution {
public:
    bool buddyStrings(string A, string B) {
        int t[26] = {0};
        if(A.size()!=B.size()) return 0;
        
        int flag=0;
        int prev=-1;
        int i;
        for(i=0;i<A.size();i++) { 
            if(++t[A[i]-'a']>1) flag = 1; 
            if(A[i]!=B[i]) {prev=i; break;}
        }
        for(i++;i<A.size();i++) {
            if(++t[A[i]-'a']>1) flag = 1; 
            if(A[i]!=B[i]) {
                if(A[prev]!=B[i]||A[i]!=B[prev]) return 0;
            }
        }
        for(i++;i<A.size();i++) {
            if(++t[A[i]-'a']>1) flag = 1; 
            if(A[i]!=B[i]) return 0;
        }
        return (prev==-1) ? flag : 1;
    }
};
