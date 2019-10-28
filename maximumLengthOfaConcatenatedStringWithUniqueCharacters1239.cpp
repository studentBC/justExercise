class Solution {
public:
    void go (int s, long start, vector<long>& number, vector<int>& length, int len, int& ans) {
        for (int i = s; i < number.size(); i++) {
            long outcome = start&number[i];
            if (!outcome) {
                ans = max(ans, len+length[i]);
                long next = start|number[i];
                go (i+1, next, number, length, len+length[i], ans);
            }
        }
    }
    int maxLength(vector<string>& arr) {
        long bit;bool legal = false;
        int ans = 0;
        vector<int>length;vector<long> number;
        for (string s:arr) {
            bit = 0;
			legal = true;
			bool visited[26] = {false};
            for (char c:s) {
				if (!visited[c-'a']) {
                	bit+=pow(2,c-'a');
					visited[c-'a'] = true;
				} else {
					legal = false;
				}
            }
			if (legal) {
            	number.emplace_back(bit);
            	length.emplace_back(s.size());
			}
        }
        go (0, 0, number, length, 0, ans);
        return ans;
    }
};

