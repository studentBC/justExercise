/*
 * Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"

Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

Example:

Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Output:
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]

wrong test case
["az","yx"]

 */
class Solution {
public:
        vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>>ans;
        int diff;
        char tmp;
        string match;
        for (int i = 0; i < strings.size(); ++i) {
            if (strings[i][0] != '$') {
                vector<string>temp;
                temp.emplace_back(strings[i]);
                for (int j = 0; j < strings.size(); j++) {
                    if (i!=j && strings[j][0]!='$' && strings[i].size() == strings[j].size()) {
                        diff = strings[i][0]-strings[j][0];
                        //cout <<i <<" , "<<j <<" diff: " << diff << endl;
                        match = "";
                        if (diff > 0) {
                            for (int k = 0; k < strings[j].size(); k++) {
                                if (strings[j][k]+diff > 127 || strings[j][k]+diff > 'z') {
                                    tmp = strings[j][k]+diff-26;
                                } else {
                                    tmp = strings[j][k]+diff;
                                }
                                /*
                                tmp = strings[j][k]+diff;
                                if (tmp > 'z') {
                                    tmp-=26;
                                }*/
                                //cout <<"1. tmp becomes "<<tmp<<endl;
                                match+=tmp;
                            }
                            if (strings[i] == match) {
                                temp.emplace_back(strings[j]);
                                strings[j][0] = '$';
                            }
                        } else if (diff == 0) {
                            if (strings[i] == strings[j]) {
                                temp.emplace_back(strings[j]);
                                strings[j][0] = '$';
                            }
                        } else {
                            for (int k = 0; k < strings[i].size(); k++) {
                                if (strings[i][k]-diff > 127 || strings[i][k]-diff > 'z') {
                                    tmp = strings[i][k]-diff-26;
                                } else {
                                    tmp = strings[i][k]-diff;
                                }
                                /*
                                if (tmp > 'z') {
                                    tmp-=26;
                                }*/
                                //cout <<"2. tmp becomes "<<tmp<<endl;
                                match+=tmp;
                            }
                            if (strings[j] == match) {
                                temp.emplace_back(strings[j]);
                                strings[j][0] = '$';
                            }
                        }
                    }
                }
                strings[i][0] = '$';
                ans.emplace_back(temp);
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
    string getShift(string const &s)
    {
        string res= "";
        for(int i = 1; i < s.size();++i)
        {
            int n = (s[i]-s[i-1]+26) % 26;
            res+=to_string(n)+',';
        }
        return res;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> data;
        for (auto const & s:strings)
        {
            data[getShift(s)].push_back(s);
        }
        vector<vector<string>> res;
        for (auto & d:data)
        {
            res.push_back(move(d.second));
        }
        return res;
    }
};
