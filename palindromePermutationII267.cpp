/*
Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

Example 1:

Input: "aabb"
Output: ["abba", "baab"]
Example 2:

Input: "abc"
Output: []
company: Uber

wrong test case:
"AaBb//a"
"aaa"
*/
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        //if(s.size() == 1) return {s};
        int odd = 0, even = 0;
        unordered_map<char , int>alpha;
        char od;
        vector<char>c;
        vector<string>ans;
        for (char c: s) {
            alpha[c]++;
        }
        for (auto& it : alpha) {
            if (it.second%2) {
                odd++;
                od = it.first;
                while (it.second > 2) {
                    c.push_back(od);
                    it.second-=2;
                }
            } else {
                even = it.second>>1;
                for (int j = 0; j < even; j++) c.push_back(it.first);
            }
        }
        sort(c.begin(), c.end());
        if (s.size()%2) {
            if (odd > 1) return ans;
            do {
                string s(c.begin(), c.end());
                string rs = s;reverse(s.begin(), s.end());
                //cout << rs <<" , " << s << endl;
                ans.push_back(rs+od+s);
            } while (next_permutation(c.begin(), c.end()));
        } else {
            if (odd) return ans;
            do {
                string s(c.begin(), c.end());
                string rs = s;reverse(s.begin(), s.end());
                ans.push_back(rs+s);
            } while (next_permutation(c.begin(), c.end()));
        }
        return ans;
    }
};

