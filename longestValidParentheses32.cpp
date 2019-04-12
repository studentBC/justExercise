class Solution {
public:
    void countParenthese (int& start, string s, vector<bool>& valid) {
        stack<char>parenthese;
        stack<int>location;
        //cout << "start from " << start << endl;
        for (int i = start; i < s.size(); i++) {
            start = i;
            if (s[i] == '(') {
                parenthese.push(s[i]);
                location.push(i);
            } else {
                if (!parenthese.empty() && parenthese.top() == '(') {
                    parenthese.pop();
                    valid[i] = valid[location.top()] = true;
                    location.pop();
                } else {
                    valid[i] = false;
                    start++;
                    return;
                }
            }
        }
        return;
    }
    int longestValidParentheses(string s) {
        int start = 0, max = 0, end = s.size()-1, sum = 0;
        vector<bool>valid(s.size(),false);
        while (start < end) {
            countParenthese(start, s, valid);
            //cout <<"break at " << start << endl;
        }
        for (int i = 0; i < valid.size(); i++) {
            if (!valid[i]) {
                //sum = sum >>1;
                if (sum > max) max = sum;
                sum = 0;
            } else {
                sum++;
            }
        }
        if (sum > max) max = sum;
        return max;
    }
};
//the fatest method
class Solution {
public:
	int longestValidParentheses(string s) {
		int result = 0;

		{
			stack<char> st;
			int n = 0;
			for(auto c: s) {
				if(c == '(') {
					st.push(c);
				} else {
					if(st.empty()) {
						n = 0;
					} else {
						n += 2;
						st.pop();
						if(st.empty() && result < n)
							result = n;
					}
				}
			}
		}

		{
			stack<char> st;
			int n = 0;
			reverse(s.begin(), s.end());
			for(auto c: s) {
				if(c == ')') {
					st.push(c);
				} else {
					if(st.empty()) {
						n = 0;
					} else {
						n += 2;
						st.pop();
						if(st.empty() && result < n)
							result = n;
					}
				}
			}
		}

		return result;
	}
};
