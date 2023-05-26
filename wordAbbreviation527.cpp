/*
Given an array of distinct strings words, return the minimal possible abbreviations for every word.

The following are the rules for a string abbreviation:

The initial abbreviation for each word is: the first character, then the number of characters in between, followed by the last character.
If more than one word shares the same abbreviation, then perform the following operation:
Increase the prefix (characters in the first part) of each of their abbreviations by 1.
For example, say you start with the words ["abcdef","abndef"] both initially abbreviated as "a4f". Then, a sequence of operations would be ["a4f","a4f"] -> ["ab3f","ab3f"] -> ["abc2f","abn2f"].
This operation is repeated until every abbreviation is unique.
At the end, if an abbreviation did not make a word shorter, then keep it as the original word.
 

Example 1:

Input: words = ["like","god","internal","me","internet","interval","intension","face","intrusion"]
Output: ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]
Example 2:

Input: words = ["aa","aaa"]
Output: ["aa","aaa"]
 

Constraints:

1 <= words.length <= 400
2 <= words[i].length <= 400
words[i] consists of lowercase English letters.
All the strings of words are unique.
*/

class Solution {
public:
    string abbrev(string& s, int start) {
        int l = s.size();
        if (l-start <= 3) return s;
        string tmp;
        tmp+=s.substr(0, start+1);
        tmp+=to_string(l-start-2);
        tmp.push_back(s.back());
        return tmp;
    }
    vector<string> wordsAbbreviation(vector<string>& words) {
        int len = words.size();
        vector<int>prefix(len, 0);
        vector<string>ans(len);
        for (int i = 0; i < len; i++) ans[i] = abbrev(words[i], 0);
        for (int i = 0; i < len; i++) {
            while (1) {
                unordered_set<int>repeat;
                for (int j = i+1; j < len; j++) {
                    if (ans[i] == ans[j]) repeat.insert(j);
                }
                if (repeat.empty()) break;
                repeat.insert(i);
                for (int j : repeat) ans[j] = abbrev(words[j], ++prefix[j]);
            }
        }
        return ans;
    }
};
