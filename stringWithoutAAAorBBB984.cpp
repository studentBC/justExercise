class Solution {
public:
    int find (string target, char t, int count) {
        int c = 0;
        for (int i = 0; i < target.size(); i++) {
            if (target[i] == t) {
                c++;
                if (c == count) {
                    if (count == 1) {
                        if ( (i+1 < target.size() && target[i+1] != t) || i+1 == target.size()) return i;
                    } else {
                        return i;
                    }
                }
            } else {
                c = 0;
            }
        }
        return -1;
    }
    string strWithout3a3b(int A, int B) {
        string ans;
        int pos;
        if (A > B) {
            for (int i = 0; i < A; i++) ans+="a";
            while (B) {
                pos = find (ans, 'a', 3);
                if (pos > -1) {
                    ans.insert(pos,"b");
                    B--;
                } else {
                    pos = find (ans, 'b', 1);
                    if (pos > -1) {
                        ans.insert(pos,"b");
                        B--;
                    } else {
                        ans.push_back('b');
                        B--;
                    }
                }
            }
        } else {
            for (int i = 0; i < B; i++) ans+="b";
            while (A) {
                pos = find (ans, 'b', 3);
                if (pos > -1) {
                    ans.insert(pos,"a");
                    A--;
                } else {
                    pos = find (ans, 'a', 1);
                    if (pos > -1) {
                        ans.insert(pos,"a");
                        A--;
                    } else {
                        ans.push_back('a');
                        A--;
                    }
                }
            }
        }
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string s="";
        while(A>0 || B>0){
            bool flagA=false;
            int l=s.size();
            if(l>=2 && s[l-1]==s[l-2]){
                if( s[l-1]=='b')
                    flagA=true;
            }
            else{
                if(A>=B)
                    flagA=true;
            }
            if(flagA){
                A--;
                s+='a';
            }
            else{
                B--;
                s+='b';
            }
        }
        return s;
          
    }
};
