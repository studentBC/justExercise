class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int>number;
        vector<char>op;
        int n1,n2;
        for (int i = 0; i < tokens.size(); i++) {
            if (isdigit(tokens[i][0]) || (tokens[i].size() > 1 && tokens[i][0] == '-' && isdigit(tokens[i][1])) ) {
                //cout << "push " << tokens[i] << endl;
                number.emplace_back(stoi(tokens[i]));
            } else {
                    n2 = number.back();
                    number.pop_back();
                    n1 = number.back();
                    number.pop_back();
                    //cout << "pop " << n1 << " and " << n2 << endl;
                if (tokens[i][0] == '-') {
                    number.emplace_back(n1-n2);
                } else if (tokens[i][0] == '+') {
                    number.emplace_back(n1+n2);
                } else if (tokens[i][0] == '*') {
                    number.emplace_back(n1*n2);
                } else {
                    number.emplace_back(n1/n2);
                }
            }
        }
        return number.back();
    }
};

