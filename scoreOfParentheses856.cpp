class Solution {
public:
    int scoreOfParentheses(string S) {
        int ans = 0, temp = -1, count;
        vector<char>parenthese;
        vector<int>num;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '(') {
                parenthese.emplace_back(S[i]);
                count = -1;
            } else if (S[i] == ')') {
                temp = 0;
                while (parenthese.back() != '(') {
                    temp+=num.back();
                    num.pop_back();
                    parenthese.pop_back();
                }
                parenthese.pop_back();
                count++;
                if (temp == 0) {
                    temp = pow(2,count);
                } else {
                    temp = temp<<1;
                }  
                parenthese.emplace_back('$');
                num.emplace_back(temp);
            } 
        }
        for (int i = 0; i < num.size(); i++) {
            ans+=num[i];
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    int scoreOfParentheses(string S) {
        int n=S.length();
        if(!n) return 0;
        stack<int> s;
        s.push(0);
        int i=0;
        while(i<n)
        {
            if(S[i]=='(')
                s.push(0);
            else
            {
                int v=s.top();
                s.pop();
                int w=s.top();
                s.pop();
                s.push(w+max(2*v,1));
            }
            i++;
        }
        return s.top();
    }
};
