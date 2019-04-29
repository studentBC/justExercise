class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int>input;
        input.emplace_back(a);
        input.emplace_back(b);
        input.emplace_back(c);
        sort(input.begin(), input.end());
        int count = 0;
        vector<int>ans;
        int up = input[2]-input[1]-1;
        int low = input[1]-input[0]-1;
        if (up == 1) {
            ans.emplace_back(1);
            ans.emplace_back(up+low);
            return ans;
        } else if (up > 1) {
            count++;
        }
        if (low == 1) {
            ans.emplace_back(1);
            ans.emplace_back(up+low);
            return ans;
        } else if (low > 1) {
            count++;
        }
        ans.emplace_back(count);
        ans.emplace_back(up+low);
        return ans;
    }
};

