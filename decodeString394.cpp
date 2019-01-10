class Solution {
public:
    string getString(char x)
    {
        // string class has a constructor
        // that allows us to specify size of
        // string as first parameter and character
        // to be filled in given size as second
        // parameter.
        string s(1, x);
        
        return s;
    }

    string decodeString(string s) {
        vector<int>num;
        vector<string>letters , temp;
        int number = 0;
        string  tem, cs;
        for (int i = 0; i < s.size(); i++) {
            //cout << s[i] << " , ";
            if (isdigit(s[i])) {
                number = number*10+s[i]-'0';
            } else if (s[i] == '['){
                num.push_back(number);
                number = 0;
                letters.push_back(getString(s[i]));
                //cout << endl<< letters.back() << endl;
            } else if (s[i] == ']') {
                tem = cs = "";
                while (letters.back()!="[") {
                    temp.push_back(letters.back());
                    //cout << endl << temp << endl;
                    letters.pop_back();
                }
                letters.pop_back();
                while (!temp.empty()) {
                    tem+=temp.back();
                    temp.pop_back();
                }
                for (int i = 0; i < num.back(); i++) {
                    cs+=tem;
                }
                letters.push_back(cs);
                num.pop_back();
            } else {
                letters.push_back(getString(s[i]));
            }

        }
        string ans;
        for (int i = 0; i < letters.size(); i++) {
            ans+=letters[i];
        }
        return ans;
    }
};

