class Solution {
public:
    string reverseParentheses(string s) {
        vector<string>words;
        string temp , tmp="";
        for (char c:s) {
            if (c == '(') {
                if (temp.size()) words.emplace_back(temp);
                words.emplace_back("(");
                temp = "";
            } else if (c == ')') {
                /*if (temp.size()) {
                    reverse(temp.begin(), temp.end());
                }*/
                tmp = "";
                while (words.back()!="(") {
                    tmp.insert(0, words.back());
                    words.pop_back();
                }
                tmp+=temp;
                //cout << tmp << endl;
                words.pop_back();
                reverse(tmp.begin(), tmp.end());
                words.emplace_back(tmp);
                temp = "";
            } else {
                temp.push_back(c);
            }
        }
        string ans;
        for (string s:words) ans+=s;
        //cout <<"temp is " << temp << endl;
        if (temp.size()) ans+=temp;
        return ans;
    }
};
//the fatest method
class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> dp = {""};
        
        for (char c : s) {
            if (c == '(') dp.push_back("");
            else if (c == ')') {
                string cr = move(dp.back()); dp.pop_back();
                reverse(cr.begin(), cr.end());
                dp.back().append(cr);
            } else {
                dp.back().push_back(c);
            }
        }
        return dp.back();
    }
};
