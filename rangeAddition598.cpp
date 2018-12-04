class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.size() == 0) return m*n;
        int length = INT_MAX , width = INT_MAX;
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i][0] < length) length = ops[i][0];
            if (ops[i][1] < width) width = ops[i][1];
        }
        return length*width;
    }
};
