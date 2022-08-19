// https://leetcode.com/problems/strings-differ-by-one-character/discuss/802871/Rabin-Karp-O(nm)
/*
Given a list of strings dict where all the strings are of the same length.

Return true if there are 2 strings that only differ by 1 character in the same index, otherwise return false.

 

Example 1:

Input: dict = ["abcd","acbd", "aacd"]
Output: true
Explanation: Strings "abcd" and "aacd" differ only by one character in the index 1.
Example 2:

Input: dict = ["ab","cd","yz"]
Output: false
Example 3:

Input: dict = ["abcd","cccc","abyd","abab"]
Output: true
 

Constraints:

The number of characters in dict <= 105
dict[i].length == dict[j].length
dict[i] should be unique.
dict[i] contains only lowercase English letters.
 

Follow up: Could you solve this problem in O(n * m) where n is the length of dict and m is the length of each string.
*/
/*
1. Compute a hash for each string i in [0, n) as hash[i] = a[0] * 26 ^ (m - 1) + a[1] * 26 ^ (m - 2) + ... + a[m - 2] * 26 + a[m - 1]

2. For each char position, we compute the hash without that char for each string, check if that string has seen before.

3. We are using mod. So, there might be collisions. We use vector<int> to solve collisions.

//*/
class Solution3 {
public:
    bool differByOne(vector<string>& dict) {
        int MOD = 1e9+7, n = dict.size(), m = dict[0].size();
        vector<int> hash(n);
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                hash[i] = (1ll*hash[i]*26 + dict[i][j] - 'a') % MOD;
        for(int j=m-1, mult=1; j>=0; --j){
            unordered_map<int, vector<int>> um;
            for(int i=0; i<n; ++i){
                int h = (hash[i] + MOD - 1ll*(dict[i][j] - 'a')*mult % MOD ) % MOD;
                auto it = um.find(h);
                if(it!=um.end())
                    for(auto k:it->second)
                        if(dict[i].substr(0,j)==dict[k].substr(0,j) && dict[i].substr(j+1) == dict[k].substr(j+1))
                            return true;
                um[h].push_back(i);
            }
            mult = 1ll*mult*26 % MOD;
        }
        return false;
    }
};
//MLE now
class Solution {
public:
    bool differByOne(vector<string>& dict) {
        unordered_map<string, bool>dic;
        int len = dict.back().size();
        for (string& s: dict) {
            for (int j = 0; j < len; j++) {
                string temp = s;
                temp[j] = '*';
                if (dic.count(temp)) return true;
                else dic[temp] = true;
            }
        }
        return false;
    }
};
