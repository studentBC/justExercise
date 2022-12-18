class Solution {
public:
    unordered_set<int>ans, visited;
    void go (int start, int n, int k, int sum) {
        if (start < 0 || start > 9 ) return;
        if (n == 0) {
            ans.insert(sum);
            return;
        }
        sum*=10;
        sum+=start;
        go (start+k, n-1, k, sum);
        go (start-k, n-1, k, sum);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for (int i = 1; i < 10; i++) {
            go (i, n, k, 0);
        }
        vector<int>answer(ans.begin(), ans.end());
        return answer;
    }
};
