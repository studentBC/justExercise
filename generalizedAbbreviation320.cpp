/*
A word's generalized abbreviation can be constructed by taking any number of non-overlapping and non-adjacent 
substrings
 and replacing them with their respective lengths.

For example, "abcde" can be abbreviated into:
"a3e" ("bcd" turned into "3")
"1bcd1" ("a" and "e" both turned into "1")
"5" ("abcde" turned into "5")
"abcde" (no substrings replaced)
However, these abbreviations are invalid:
"23" ("ab" turned into "2" and "cde" turned into "3") is invalid as the substrings chosen are adjacent.
"22de" ("ab" turned into "2" and "bc" turned into "2") is invalid as the substring chosen overlap.
Given a string word, return a list of all the possible generalized abbreviations of word. Return the answer in any order.

 

Example 1:

Input: word = "word"
Output: ["4","3d","2r1","2rd","1o2","1o1d","1or1","1ord","w3","w2d","w1r1","w1rd","wo2","wo1d","wor1","word"]
Example 2:

Input: word = "a"
Output: ["1","a"]
 

Constraints:

1 <= word.length <= 15
word consists of only lowercase English letters.
*/
class Solution {
public:
    int total;
    void go (int start, int& count, vector<int>& tmp, vector<vector<int>>& temp) {
        if (tmp.size() == count) {
            temp.push_back(tmp);
            return;
        }
        for (int i = start; i < total; i++) {
            tmp.push_back(i);
            go (i+1, count, tmp, temp);
            tmp.pop_back();
        }
    }
    vector<string> generateAbbreviations(string word) {
        vector<int>tmp;
        vector<string>ans;
        total = word.size();
        ans.push_back(to_string(total));
        int prev;
        for (int i = 1; i <= total; i++) {
            vector<vector<int>>temp;
            go (0, i, tmp, temp);
            for (int j = 0; j < temp.size(); j++) {
                prev = -1;
                string s;
                for (int k = 0; k < temp[j].size(); k++) {
                    if (temp[j][k]-prev > 1) s+=(to_string(temp[j][k]-prev-1));
                    s.push_back(word[temp[j][k]]);
                    prev = temp[j][k];
                }
                if (prev+1 < total) s+=(to_string(total-prev-1));
                ans.push_back(s);
            }
        }
        return ans;
    }
};
