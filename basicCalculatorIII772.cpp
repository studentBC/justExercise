/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].

Some examples:

"1 + 1" = 2
" 6-4 / 2 " = 4
"2*(5+5*2)/3+(6/2+8)" = 21
"(2+6* 3+5- (3*14/7+2)*5)+3"=-12
"(  (2   *( (  9 +  6   )   -  ( 2 *   2 ) )   )*   ((1 *   (   5 +5) ) -   ( (   10  +  1)   -4) )   )"
"-1+3*4/3/3"

[reference]
https://www.geeksforgeeks.org/expression-evaluation/
https://en.wikipedia.org/wiki/Shunting-yard_algorithm
http://www.learn4master.com/interview-questions/leetcode/leetcode-evaluate-reverse-polish-notation-java
http://www.learn4master.com/data-structures/stack/convert-infix-notation-to-reverse-polish-notation-java
*/
class Solution {
public:
    long evaculate(long a, long b, string o) {
        if (o == "+") return a+b;
        else if (o == "-") return a-b;
        else if (o == "*") return a*b;
        else return a/b;
    }
    int calculate(string s) {
        std::string::iterator end_pos = std::remove(s.begin(), s.end(), ' ');
        s.erase(end_pos, s.end());
        //cout << s << endl;
        stack<long>value;
        stack<string>op;
        unordered_map<string,int>precedence;
        vector<string>equation;
        string tmp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') equation.push_back("(");
            //else if (s[i] == ' ') continue;
            else if (s[i] == ')') equation.push_back(")");
            else if (s[i] == '+') equation.push_back("+");
            else if (s[i] == '*') equation.push_back("*");
            else if (s[i] == '/') equation.push_back("/");
            else if (s[i] == '-') {
                if (i == 0 || (i && !isdigit(s[i-1]) && s[i-1] != ')')) {
                    i++;
                    string num = "-";
                    while (i < s.size() && isdigit(s[i])) {
                        num += s[i];
                        i++;
                    }
                    i--;
                    equation.push_back(num);
                } else {
                    equation.push_back("-");
                }
            } else {
                string num = "";
                while (i < s.size() && isdigit(s[i])) {
                    num += s[i];
                    i++;
                }
                i--;
                equation.push_back(num);
            }
        }
        precedence["*"]=5;
        precedence["/"]=5;
        precedence["+"]=4;
        precedence["-"]=4;
        precedence["("]=0;
        int i, val1, val2;
        //for (int j = 0; j < equation.size(); j++) cout << equation[j];
//cout << endl;
        for (i = 0; i < equation.size(); i++) {
            if (equation[i] == "(") {
                op.push(equation[i]);
            } else if (isdigit(equation[i].back())) {
                bool negative = false;
                int j = 0;
                if (equation[i][0] == '-') {
                    negative = true;
                    j = 1;
                }
                long num = 0;
                for (; j < equation[i].size(); j++) {
                    num = num*10+(equation[i][j]-'0');
                }
                if (negative) {
                    value.push(-num);
                } else value.push(num);
            } else if (equation[i] == ")") {
                while (!op.empty() && op.top() != "(") {
                    val2 = value.top();
                    value.pop();
                    val1 = value.top();
                    value.pop();
                    string ops = op.top();
                    op.pop();
                    value.push(evaculate(val1, val2, ops));
                }
                if (!op.empty())op.pop();
            } else {
                while (!op.empty() && precedence[op.top()] >= precedence[equation[i]]) {
                    val2 = value.top();
                    value.pop();
                    val1 = value.top();
                    value.pop();
                    string ops = op.top();
                    op.pop();
                    value.push(evaculate(val1, val2, ops));
                }
                op.push(equation[i]);
            }
        }
        while (!op.empty()) {
            val2 = value.top();
            value.pop();
            val1 = value.top();
            value.pop();
            string ops = op.top();
            op.pop();
            value.push(evaculate(val1, val2, ops));
        }
        return value.top();
    }
};
//the fatest solution
class Solution {
public:
    long cal(long num1, long num2, char op) {
        switch (op) {
            case '+': return num1+num2;
            case '-': return num1-num2;
            case '*': return num1*num2;
            case '/': return num1/num2;
            default: return 0;
        }
        return 0;
    }
    
    bool check(char op1, char op2) {
        if (op1=='(') return false;
        if ((op2=='*' || op2=='/') && (op1=='+' || op1=='-')) return false;
        return true;
    }
    
    void operations(stack<long>& nums, stack<char>& ops) {
        long n1=nums.top();
        nums.pop();
        long n2=nums.top();
        nums.pop();
        long op=ops.top();
        ops.pop();
        nums.push(cal(n2,n1,op));
    }
    
    int calculate(string s) {
        stack<long> nums;
        stack<char> ops;
        
        int i=0;
        for (int i=0; i<s.size(); i++) {
            if (s[i]==' ') continue;
            else if (isdigit(s[i])) {
                long val=s[i]-'0';
                while (i+1<s.size() && isdigit(s[i+1])) {
                    val=val*10+(s[i+1]-'0');
                    i++;
                }
                nums.push(val);
            } else if (s[i]=='(') {
                ops.push(s[i]);
            } else if (s[i]==')') {
                while (!ops.empty() && ops.top()!='(') {
                    operations(nums,ops);
                }
                ops.pop();
            } else {
                int j=i-1;
                while (j>=0 && s[i]==' ') j--;
                if (j<0 || s[j]=='(') nums.push(0);
                while (!ops.empty() && check(ops.top(),s[i])) {
                    operations(nums,ops);
                }
                ops.push(s[i]);
            }
        }
        while (!ops.empty()) {
            operations(nums,ops);
        }
        return nums.top();
    }
};
