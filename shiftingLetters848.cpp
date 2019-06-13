class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        vector<int>alpha;
        for (char c:S) {
            alpha.emplace_back(c-'a');
        }
        int shift;
        for (int i = 0; i < shifts.size(); ++i) {
            shift = shifts[i]%26;
            for (int j = 0; j < i+1; ++j) {
                alpha[j]+=shift;
            }
        }
        string ans = "";
        for (int i :alpha) {
            if (i > 25) i = i%26;
            if (i == 0) {
                ans+="a";
            } else if (i == 1) {
                ans+="b";
            } else if (i == 2) {
                ans+="c";
            } else if (i == 3) {
                ans+="d";
            } else if (i == 4) {
                ans+="e";
            } else if (i == 5) {
                ans+="f";
            } else if (i == 6) {
                ans+="g";
            } else if (i == 7) {
                ans+="h";
            } else if (i == 8) {
                ans+="i";
            } else if (i == 9) {
                ans+="j";
            } else if (i == 10) {
                ans+="k";
            } else if (i == 11) {
                ans+="l";
            } else if (i == 12) {
                ans+="m";
            } else if (i == 13) {
                ans+="n";
            } else if (i == 14) {
                ans+="o";
            } else if (i == 15) {
                ans+="p";
            } else if (i == 16) {
                ans+="q";
            } else if (i == 17) {
                ans+="r";
            } else if (i == 18) {
                ans+="s";
            } else if (i == 19) {
                ans+="t";
            } else if (i == 20) {
                ans+="u";
            } else if (i == 21) {
                ans+="v";
            } else if (i == 22) {
                ans+="w";
            } else if (i == 23) {
                ans+="x";
            } else if (i == 24) {
                ans+="y";
            } else if (i == 25) {
                ans+="z";
            }
        }
        return ans;
    }
};
//the 12ms solution
static const auto fast = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 9;
} ();

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        const int n = S.size();
        int shf = 0;
        
        for (int i = n-1;i >= 0;i--) {
            shf += shifts[i];
            shf %= 26;
            int ch = S[i]-'a';
            ch = (ch+shf)%26;
            S[i] = (char)(ch+'a');
        }
        
        return S;
    }
};
