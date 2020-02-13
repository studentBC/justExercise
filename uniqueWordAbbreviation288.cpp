/*
An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
     ↓
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
     ↓   ↓    ↓    ↓  ↓    
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
     ↓   ↓    ↓
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example:

Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true




wrong test case:

["ValidWordAbbr","isUnique"]
[[["hello"]],["hello"]]
Output
[null,false]
Expected
[null,true]

Input:
["ValidWordAbbr","isUnique","isUnique","isUnique"]
[[["ab","bc"]],["ac"],["ab"],["bc"]]
Output:
[null,true,false,false]
Expected:
[null,true,true,true]

Input
["ValidWordAbbr","isUnique","isUnique","isUnique","isUnique"]
[[["deer","door","cake","card"]],["dear"],["door"],["cart"],["cake"]]
Output
[null,false,true,true,true]
Expected
[null,false,false,true,true]
*/
class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string>& dictionary) {
        string key;
        count = dictionary.size();
        for (string s: dictionary) {
            key = "";
            if (s.size() <= 1) {
                key +=s.back();
            } else {
                key += s[0];
                key += s.back();
            }
            //cout << key <<" , ";
            abbreviation[key].push_back(s.size()-2);
            uw.insert(s);
        }
    }
    bool check (vector<int>& number, int target) {
        int count = 0;
        for (int i: number) {
            if (i == target) count++;
        }  
        return count == 1;
    }
    bool isUnique(string word) {
        //if (count <= 1) return true;
        string key =""; key += word[0]; key+=word.back();
        int len = word.size()-2;
        if (abbreviation.find(key)!=abbreviation.end()) {
            if (find(abbreviation[key].begin(), abbreviation[key].end(), len) == abbreviation[key].end()) return true;
            else {
                if ( check(abbreviation[key], len) && uw.count(word)) return true;
            }
            return false;
        } else {
            return true;
        }

    }
    unordered_map<string, vector<int>>abbreviation;
    unordered_set<string>uw;
    int count;
}; 
   
/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */

