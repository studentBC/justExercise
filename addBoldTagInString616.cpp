/*
Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.
Example 1:
Input: 
s = "abcxyz123"
dict = ["abc","123"]
Output:
"<b>abc</b>xyz<b>123</b>"
Example 2:
Input: 
s = "aaabbcc"
dict = ["aaa","aab","bc"]
Output:
"<b>aaabbc</b>c"
Note:
The given dict won't contain duplicates, and its length won't exceed 100.
All the strings in input have length in range [1, 1000].
*/
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<bool> isBold(s.size());
        for (string word: dict) {
            std::size_t found = s.find(word);
            while (found != string::npos) {
                for (size_t i = found; i < found + word.size(); ++i) {
                   isBold[i] = true;
                }
                found = s.find(word, found+1);
            }
        }

        string boldS;

        for (size_t i = 0; i < s.size(); ++i) {
            if (isBold[i] == true && (i == 0 || isBold[i-1] == false)) {
                boldS.append("<b>");
            }

            boldS.push_back(s[i]);

            if (isBold[i] == true && (i == s.size()-1 || isBold[i+1] == false)){
                boldS.append("</b>");
            }
        }
        return boldS;
    }
}; 
//the fatest method
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int n=s.size();
        vector<int> mark(n, 0);
        for(auto str: dict){
            int p=-1;
            while(true){
                p=s.find(str, p+1);
                if(p==-1) break;
                for(int i=p; i<p+str.size(); i++) mark[i]=1;
            }
        }
        
        string res;
        int i=0;
        while(i<n){
            if(mark[i]){
                res+="<b>";
                while(i<n && mark[i]) res+=s[i++];
                res+="</b>";
            }
            else res+=s[i++];
        }
        
        return res;
    }
};
