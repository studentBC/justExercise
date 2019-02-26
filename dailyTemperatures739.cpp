class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
 		vector<int>ans(T.size(),0);
		for (int i = 0; i < T.size(); i++) {
			for (int j = i+1; j < T.size(); j++) {
				if (T[j] > T[i]) {
					ans[i] = (j-i);
					break;
				}
			}
		}
		return ans;
    }
};
//faster method
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st;
        int ln = T.size();
        vector<int> ans;
        if (ln == 0)
            return ans;
        ans.resize(ln);
        for (int i = ln - 1; i >= 0; i--) {
            while (!st.empty() && (T[st.top()] <= T[i])) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = 0;
            } else {
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};
