class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        if (S.size() < K) return 0;
        vector<int> alpha(26,0);
        unordered_set<int>invalid;
        for (int i = 0; i < K; i++) {
            alpha[S[i]-'a']++;
            if (alpha[S[i]-'a'] > 1) {
                invalid.insert(S[i]-'a');
            }
        }
        int end = S.size()-K, ans;
        if (invalid.size()) {
            ans = 0;
        } else {
            ans = 1;
        }
        for (int i = 1, j = K; i <= end; i++,j++) {
            alpha[S[i-1]-'a']--;
            if (alpha[S[i-1]-'a'] == 1) {
                invalid.erase(invalid.find(S[i-1]-'a'));
            }
            alpha[S[j]-'a']++;
            if (alpha[S[j]-'a'] > 1) {
                invalid.insert(S[j]-'a');
            }
            if (invalid.size() == 0) ans++;
        }
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        if (K > S.size())
            return 0;
        if (K == 1)
            return S.size();
        
        vector<int> chars(128, -1);
        int end = 1;
        int start = 0;
        chars[S[start]] = start;
        int total = 0;
        while (start <= S.size()-K && end < S.size())
        {
            while(start <= chars[S[end]])
            {
                chars[S[start]] = -1;
                start++;
            }
            
            chars[S[end]] = end;
            end++;
            
            if (end-start >= K)
            {
                total++;
                chars[S[start]] = -1;
                start++;
            }
        }
        
        return total;
    }
};

