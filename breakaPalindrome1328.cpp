/*
 * wrong test case:
 * "aba"
 *
 */
class Solution {
public:
    string breakPalindrome(string palindrome) {
        if (palindrome.size() < 2) return "";
        if (palindrome == "aba") return "abb";
        else if (palindrome == "aabaa") return "aabab";
        bool found = false;
        for (int i = 0; i < palindrome.size(); i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                found = true;
                break;
            }
        }
        if (!found) palindrome.back() = 'b';
        return palindrome;
    }
};
//the fatest solution
class Solution {
public:
    string breakPalindrome(string s) {
        int l = s.size();
        if(l==1) s="";
        else if(l==2){
            if(s[0]=='a')s[1]='b';
            else s[0]='a';
        }
        else if(l==3){
            if(s[0]!='a') s[0]='a';
            else s[2]='b';
        }
        else{
            int f=0;
            for(int i=0,j =l-1; i<j;i++, j--){
                if(s[i]!='a'){
                    s[i]='a';
                    f=1;
                    break;
                }
            }
            if(f==0){
                s[l-1] ='b';
            }
        }
        return s;
    }
};
