class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>map;
        vector<string>ans;
        queue<string>temp;
        map.push_back("abc");
        map.push_back("def");
        map.push_back("ghi");
        map.push_back("jkl");
        map.push_back("mno");
        map.push_back("pqrs");
        map.push_back("tuv");
        map.push_back("wxyz");
        string tem;
        int count;
        for (int a = 0; a < map[digits[0]-'2'].size(); a++) {
            tem = map[digits[0]-'2'][a];
            temp.push(tem);
        }
        for (int i = 1; i < digits.size(); i++) {
            count = temp.size();
            //cout << i <<" : " << count << endl;
             for (int a = 0; a < count; a++) {
                tem = temp.front();
                temp.pop();
                 //cout << a << " : " << tem << endl;
                for (int j = 0; j < map[digits[i]-'2'].size(); j++) {
                    //cout << tem << " + " << map[digits[i]-'2'][j] << endl;
                    temp.push(tem+map[digits[i]-'2'][j]);
                }
            }
        }
        while (!temp.empty()) {
            ans.push_back(temp.front());
            temp.pop();
        }
        return ans;
    }
};

