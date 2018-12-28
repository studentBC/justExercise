class Solution {
public:
    int calculate(string s) {
        stack<char>op;
        stack<int>num;
		s.push_back('$');
		op.push('+');
		int number = 0, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                number = number*10 + s[i]-'0';
            } else if (isspace(s[i])) continue;
			else {
				if (op.top() == '*') {
					number*=num.top();
					op.pop();
					number.pop();
				} else if (op.top() == '/') {
					number = num.top()/number;
					op.pop();
					number.pop();
				}
				num.push(number);
				number = 0;
				op.push(s[i]);
			}
		}
		op.pop();
		while (!op.empty()) {
			if (op.top() == '-') {
				ans-=num.top();
			} else {
				ans+=num.top();
			}
			num.pop();op.pop();
		}
        return ans;
    }
};
//the fatest method
static const auto speedup = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
class Solution {
public:
    int calculate(string s) {
        stack<int> st; 
        int num = 0, res = 0;
        char sign = '+';
        for (int i = 0; i < s.length(); i++) {
            // cout << "loop char[" << i << "]: " << s[i] << endl;
            if (isdigit(s[i])) {
                num = num*10 + s[i] - '0';
                // cout << "-- it's a digit. num: " << num << endl;
            } 
            
            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.length() - 1) {
                if (sign == '+')
                    st.push(num);
                else if (sign == '-')
                    st.push(-num);
                else if (sign == '*') {
                    num *= st.top();
                    st.pop();
                    st.push(num);
                }
                else if (sign == '/') {
                    num = st.top() / num;
                    st.pop();
                    st.push(num);
                }
                sign = s[i];
                num = 0;
                // cout << "-- inserted: " << st.top() << endl;
            }
        }
        
        while (!st.empty()) {
            // cout << "stack element: " << st.top() << endl;
            res += st.top();
            st.pop();
        }
        return res;
    }
};
