class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) return true;
        unordered_map<char, char>dp;
        for (int i = 0; i < str1.size(); i++) {
            if (dp.count(str1[i]) && dp[str1[i]] != str2[i]) return false;
            dp[str1[i]] = str2[i];
        }
        //whenever the conversion mappings make a cyclic linked list, 
        //we must have a temporary character to break the loop. 
        //The temporary character should not be present in the string str1; 
		//otherwise, the other instances of that character in the string str1 will also change.
        return set(str2.begin(), str2.end()).size() < 26; 
        return true;
    }
};
