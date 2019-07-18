/*
 * Given an input string , reverse the string word by word.

Example:

Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]

Note:

    A word is defined as a sequence of non-space characters.
    The input string does not contain leading or trailing spaces.
    The words are always separated by a single space.

Follow up: Could you do it in-place without allocating extra space?
 */
class Solution {
public:
    void reverseWords(vector<char>& s) {
        if(s.size() == 0) return;
        string str(s.begin(), s.end()), temp;
        istringstream data(str);
        vector<string>outcome;
        s.clear();
        while (data >> temp) {
            outcome.emplace_back(temp);
        }
        for (int i = outcome.size()-1; i > -1; i--) {
            for (char c:outcome[i]) {
                s.push_back(c);
            }
            s.push_back(' ');
        }
        s.pop_back();
        return;
    }
};
//the fatest method
static const auto fast = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
} ();

class Solution {
public:
    void reverse(vector<char>& s, int i, int j) {
        while (i < j)
            swap(s[i++], s[j--]);
    }
    
    void reverseWords(vector<char>& s) {
        reverse(s, 0, s.size() - 1);
        
        int i = 0, j = 0;
        while (i < s.size()) {
            while (j < s.size() && s[j] != ' ')
                ++j;
            reverse(s, i, j - 1);
            ++j;
            i = j;
        }
    }
};
