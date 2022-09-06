class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<bitset<20000>>up(7), down(7);
        int len = tops.size(), ans = INT_MAX, turn, uc, dc;
        for (int i = 0; i < len; i++) {
            up[tops[i]][i] = 1;
            down[bottoms[i]][i] = 1;
        }
        for (int i = 1; i <= 6; i++) {
            bitset<20000>result = up[i] | down[i];
            //cout << result.count() << endl;
            if (result.count() >= len) {
                //cout <<"enter " << endl;
                uc = (result^up[i]).count();
                dc = (result^down[i]).count();
                ans = min(ans, min(uc, dc));
                
            }
        }
        return ans == INT_MAX?-1: ans;
    }
};
