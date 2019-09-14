class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string temp, ans;
        vector<string>words;
        while (ss>>temp) {
            cout << temp <<" , ";
            words.emplace_back(temp);
        }
        for (int i = words.size()-1; i > 0; i--) {
            ans+=words[i];
            ans+=" ";
        }
        if (words.size()) ans+=words[0];
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    string reverseWords(string s) {
        if(s.size() == 0)
            return "";
        stack<string> sta;
        int i = 0;
        int start = 0;
        int count = 0;
        while(i < s.size())
        {
            if(i == s.size() - 1)
            {
                if(s[i] == ' ')
                    break;
                count = i - start + 1;
                sta.push(s.substr(start, count));
            }
            if(s[i] == ' ' && s[i + 1] != ' ')
            {
                i++;
                start = i;
                continue;
            }
            if(s[i] != ' ' && s[i + 1] == ' ')
            {
                i++;
                count = i - start;
                sta.push(s.substr(start, count));
                continue;
            }
            i++;
        }
        string result;
        int k = sta.size();
        if(k == 0)
            return "";
        for(int j = 0;j < k - 1;j++)
        {
            result += sta.top();
            sta.pop();
            result += ' ';
        }
        result += sta.top();
        return result;
    }
};

