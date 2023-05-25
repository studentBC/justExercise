class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int left = 1, right = 1e9/(k+1), mid, cur, cut;
        while (left < right) {
            mid = (left+right+1)/2;
            cur = cut = 0;
            for (int s : sweetness) {
                if ((cur+=s) >= mid) {
                    cur = 0;
                    if (++cut > k) break;
                }
            }
            if (cut > k) left = mid;
            else right = mid-1;
        }
        return left;
    }
};
