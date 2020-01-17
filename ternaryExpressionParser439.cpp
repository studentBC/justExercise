/*
Given a string representing arbitrarily nested ternary expressions, calculate the result of the expression. You can always assume that the given expression is valid and only consists of digits 0-9, ?, :, T and F (T and F represent True and False respectively).

Note:

The length of the given string is ≤ 10000.
Each number will contain only one digit.
The conditional expressions group right-to-left (as usual in most languages).
The condition will always be either T or F. That is, the condition will never be a digit.
The result of the expression will always evaluate to either a digit 0-9, T or F.
Example 1:

Input: "T?2:3"

Output: "2"

Explanation: If true, then result is 2; otherwise result is 3.
Example 2:

Input: "F?1:T?4:5"

Output: "4"

Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:

             "(F ? 1 : (T ? 4 : 5))"                   "(F ? 1 : (T ? 4 : 5))"
          -> "(F ? 1 : 4)"                 or       -> "(T ? 4 : 5)"
          -> "4"                                    -> "4"
Example 3:

Input: "T?T?F:5:3"

Output: "F"

Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:

             "(T ? (T ? F : 5) : 3)"                   "(T ? (T ? F : 5) : 3)"
          -> "(T ? F : 3)"                 or       -> "(T ? F : 5)"
          -> "F"                                    -> "F"

wrong test case:
"T?T:F?T?1:2:F?3:4"
*/
class Solution {
public:
    string parseTernary(string expression) {
        string next = expression;
        int end = next.size();
        bool found = false;
        while (next.size()>4) { 
            string temp;
            found = false;
            for (int i = 0; i <= end; i++) {
                if (next[i]!=' ') temp.push_back(next[i]);
                if (!found && next[i+1] == '?' && (next[i] == 'T' || next[i] == 'F') && next[i+3] == ':') {
                    if (i+5 <= end && next[i+5]!='?' || (i+5 > end && next[i+5]!= '?')) {
                        if (next[i] == 'T') {
                            temp.pop_back();
                            temp.push_back(next[i+2]);
                        } else {
                            temp.pop_back();
                            temp.push_back(next[i+4]);
                        }
                        i+=4;
                        found = true;
                    }
                }   
            }
	        end-=4;
            //cout << temp <<" , "<< temp.size() << endl;
            next = temp;
        }
        return next;
    }
};
//the fatest solution
class Solution {
public:
    string parseTernary(string expression) {
        //cout<<expression<<endl;
        if(expression.size()<5||expression[1]!='?') return expression;
        stack<int> si;
        si.push(1);
        int i =2;
        for(; i<expression.size(); ++i){
            if(expression[i]=='?') si.push(i);
            if(expression[i]==':'){
                if(si.top()==1) break;
                si.pop();
            }
        }
        if(expression[0]=='T') return parseTernary(expression.substr(2, i-2));
        else return parseTernary(expression.substr(i+1));
    }
};
