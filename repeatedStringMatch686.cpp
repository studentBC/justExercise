class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        if (A.compare(B) == 0 || B.size() == 0) return 1;
        int target[26] = {0};
        int origin[26] = {0};
        for (char c:B) {
            target[c-'a']++;
        }
        for (char c:A) {
            origin[c-'a']++;
        }
        int longest = 0;
        for (int i = 0; i < 26; i++) {
            if (target[i] > 0 && origin[i] > 0) {
                longest = max (longest, target[i]/origin[i]);
            } else if (target[i] != 0 && origin[i] == 0) {
                return -1;
            }
        }
        string temp = "";
        for (int i = 0; i < longest; ++i) {
            temp+=A;
        }
        if (temp.find(B) == string::npos) {
            for (int i = 0; i < 100; ++i) {
                temp+=A;
                longest++;
                if (temp.find(B) != string::npos) return longest;
            }  
            return -1;
        } else {
            return longest;
        }
    }
};
//the fatest method
class Solution
{
public:
    int repeatedStringMatch(string A, string B){
        if (A.empty() || B.empty()) return 0;

        vector<int> prefix(B.size());

        for (int pp=0, sp=1;sp<B.size();){
            if (B[pp] == B[sp]){
                prefix[sp++] = ++pp;
            } else if (pp == 0){
                sp++;
            } else {
                pp = prefix[pp-1];
            }
        }

        
        string t;
        int count = 0;
        while (t.size()<B.size()) {
            count++;
            t += A;
        }
        

        int i=0, j=0;
        while (i<t.size()){
            if (t[i] == B[j]){
                i++; j++;
            }
            if (j == B.size()){
                return count;
            } else if (i<t.size() && t[i]!=B[j]) {
                if (j==0){
                    i++;
                } else {
                    j = prefix[j-1];
                }
            }
        }

        i=0; j=0; t += A; count++;
        while (i<t.size()){
            if (t[i] == B[j]){
                i++; j++;
            }
            if (j == B.size()){
                return count;
            } else if (i<t.size() && t[i]!=B[j]) {
                if (j==0){
                    i++;
                } else {
                    j = prefix[j-1];
                }
            }
        }

        return -1;

    }

    int repeatedStringMatchNxM(string A, string B)
    {
        int a = A.size(), b = B.size();
        int n = b / a + 2; // at least 2 times of A
        int cnt = 1;
        string t = A;
        for (int i = 1; i <= n; ++i)
        {
            if (t.find(B)!=string::npos){
                return i;
            }
            t += A;
        }
        return -1;
    }
};
