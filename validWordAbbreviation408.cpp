/*
 *  Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.

A string such as "word" contains only the following valid abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]

Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".

Note:
Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.

Example 1:

Given s = "internationalization", abbr = "i12iz4n":

Return true.

Example 2:

Given s = "apple", abbr = "a2e":

Return false.
"internationalization", abbr = "i12iz4n"

"hi"
"1"

wrong test case

"a"
"01"

"a"
"2"

"hi"
"1"
 */
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int index = 0, num = 0;
        for (int i = 0; i < abbr.size(); i++) {
            if (isalpha(abbr[i])) {
                //cout << "abbr: "<<i <<" index is " << index<< endl;
                index+=num;
                if (abbr[i] != word[index]) {

                    //cout <<abbr[i] <<" is not equal to " << word[index+num] << endl;
                    return false;
                }
                index++;
                num = 0;
            } else {
                num = num*10+(abbr[i]-'0');
                if (num == 0 && ((i > 0 &&  isalpha(abbr[i-1])) || i == 0)) return false;
                //cout << "shift to "<<num << endl;
            }
        }
        if (index + num != word.size()) return false;
        return true;
    }
};

